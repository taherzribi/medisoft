#ifndef NEWACOUNT_H
#define NEWACOUNT_H
#include "medecin.h"
#include <QDialog>

namespace Ui {
class NewAcount;
}

class NewAcount : public QDialog
{
    Q_OBJECT

public:
    explicit NewAcount(QWidget *parent = nullptr);
    ~NewAcount();

private slots:
    void on_create_accepted();

private:
    Ui::NewAcount *ui;
    Medecin * tmp_med;
};

#endif // NEWACOUNT_H
