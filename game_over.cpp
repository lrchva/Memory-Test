#include "game_over.h"
#include "ui_game_over.h"

Game_Over::Game_Over(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_Over)
{
    ui->setupUi(this);
}

Game_Over::~Game_Over()
{
    delete ui;
}

void Game_Over::on_button_PlayAgain_clicked()
{
    /*mainWindow = new MainWindow();
    mainWindow->show();
    this->close();*/
}

