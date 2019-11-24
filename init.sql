CREATE DATABASE med;
USE med;

CREATE TABLE IF NOT EXISTS medecin(
	id_med int AUTO_INCREMENT PRIMARY KEY,
	nom varchar(256) NOT NULL,
	prenom varchar(256) NOT NULL,
	mtp varchar(256) NOT NULL
);

CREATE TABLE IF NOT EXISTS personnels(
	cin_per varchar(256) PRIMARY KEY,
	tel int,
	nom varchar(256) NOT NULL,
	prenom varchar(256) NOT NULL
);

CREATE TABLE IF NOT EXISTS  patients(
	cin_pat int NOT NULL PRIMARY KEY,
	nom varchar(256) NOT NULL,
	prenom varchar(256) NOT NULL,
	tel int
);

CREATE TABLE IF NOT EXISTS conges(
	id_conge int AUTO_INCREMENT PRIMARY KEY,
	date_conge DATETIME NOT NULL,
	cin_per varchar(256),

	CONSTRAINT `FK_cin_conges` FOREIGN KEY (cin_per)
    REFERENCES personnels(cin_per) ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS typeRdv(
	id_type int AUTO_INCREMENT PRIMARY KEY,
	des varchar(256)
);

CREATE TABLE IF NOT EXISTS rdv(
	id_rdv int AUTO_INCREMENT PRIMARY KEY,
	cin_pat int,
	date_rdv DATETIME NOT NULL,
	type_rdv int, 
	
	CONSTRAINT `FK_cin_rdv` FOREIGN KEY (cin_pat)
    REFERENCES patients(cin_pat) ON DELETE NO ACTION,
	
	CONSTRAINT `FK_id_type_rdv` FOREIGN KEY (type_rdv) 
	REFERENCES typeRdv(id_type) ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS TypeConsultations(
	id_type int AUTO_INCREMENT PRIMARY KEY,
	description varchar(256) NOT NULL
);

CREATE TABLE IF NOT EXISTS  consultations(
	id_cons int AUTO_INCREMENT PRIMARY KEY,
	description LONGTEXT NOT NULL,
	cin_pat int NOT NULL,
	id_med int NOT NULL,
	date_cons DATETIME DEFAULT (CURDATE()),
	type_cons int NOT NULL,
	
	CONSTRAINT `FK_cin_cons`
	FOREIGN KEY (cin_pat) REFERENCES patients(cin_pat) ON DELETE NO ACTION,

	CONSTRAINT `FK_id_med_cons` 
	FOREIGN KEY (id_med) REFERENCES medecin(id_med) ON DELETE NO ACTION,

	CONSTRAINT `FK_id_type_cons` 
	FOREIGN KEY (type_cons) REFERENCES TypeConsultations(id_type) ON DELETE NO ACTION
);


CREATE TABLE IF NOT EXISTS TypeArticle(
	id_type int AUTO_INCREMENT PRIMARY KEY,
	description varchar(256) NOT NULL
);

CREATE TABLE IF NOT EXISTS articles(
	id_art int AUTO_INCREMENT PRIMARY KEY,
	titre varchar(256) NOT NULL,
	description LONGTEXT,
	type_art int NOT NULL,

	CONSTRAINT `FK_type_art` 
	FOREIGN KEY (type_art) REFERENCES TypeArticle(id_type) ON DELETE NO ACTION	
);

