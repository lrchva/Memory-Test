#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_NumberMem_clicked()
{
    numberMem = new NumberMem();
    numberMem->show();
}


void MainWindow::on_button_VisualMem_clicked()
{
    visualMem = new VisualMem();
    visualMem->show();
}

