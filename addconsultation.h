#ifndef ADDCONSULTATION_H
#define ADDCONSULTATION_H

#include <QDialog>
#include "consultation.h"

namespace Ui {
class AddConsultation;
}

class AddConsultation : public QDialog
{
    Q_OBJECT

public:
    explicit AddConsultation(QWidget *parent = nullptr);
    ~AddConsultation();

private slots:
    void on_buttonBox_accepted();

signals:
    void consultations_updated(QString cin, QString description, QString type_cons);

private:
    Ui::AddConsultation *ui;
};

#endif // ADDCONSULTATION_H
