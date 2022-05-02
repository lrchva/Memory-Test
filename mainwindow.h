#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "numbermem.h"
#include "visualmem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_NumberMem_clicked();

    void on_button_VisualMem_clicked();

private:
    Ui::MainWindow *ui;
    NumberMem* numberMem;
    VisualMem* visualMem;
};
#endif // MAINWINDOW_H
