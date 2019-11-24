#ifndef ADDRDV_H
#define ADDRDV_H

#include <QDialog>
#include"rdv.h"

namespace Ui {
class AddRdv;
}

class AddRdv : public QDialog
{
    Q_OBJECT

public:
    explicit AddRdv(QWidget *parent = nullptr);
    ~AddRdv();

private slots:
    void on_buttonBox_accepted();

signals:
    void rdv_updated(QString cin, QString date, QString type_rdv);

private:
    Ui::AddRdv *ui;
};

#endif // ADDRDV_H
