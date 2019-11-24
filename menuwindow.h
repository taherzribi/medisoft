#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "connection.h"
namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_Connect_clicked();

private:
    Ui::MenuWindow *ui;
    Connection *connect;
};

#endif // MENUWINDOW_H
