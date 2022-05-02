#include "numbermem.h"
#include "ui_numbermem.h"

NumberMem::NumberMem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberMem)
{
    ui->setupUi(this);
    ui->label_Numbers->setVisible(false);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(get_number()));
}

NumberMem::~NumberMem()
{
    delete ui;
}

void NumberMem::on_button_Start_clicked()
{
    ui->button_Start->setVisible(false);
    level = 1;
    bool correct = 1;
    next_level(level);
}

void NumberMem::next_level(int level){
    ui->label_Level->setText("Level: " + QString::number(level));
    number = 0;
    srand(time(nullptr));
    for (int i = 0; i < level; i++){
        number = number * 10;
        number = number + 1 + rand() % 9;
    }
    ui->label_Numbers->setText(QString::number(number));
    ui->label_Numbers->setVisible(true);
    timer->setInterval((level + 2) * 1000);
    timer->start();
}


void NumberMem::get_number(){
    timer->stop();
    ui->label_Numbers->setVisible(false);
    bool ok;
    user_num = QInputDialog::getText(this, tr(""), tr("Enter number:"), QLineEdit::Normal, "-", &ok);

    if (QString::number(number) == user_num){
        level++;
        next_level(level);
    }
    else {
        ui->label_Numbers->setText("You reached level " + QString::number(level));

        ui->label_Numbers->setVisible(true);
        ui->button_Start->setText("Try Again!");
        ui->button_Start->setVisible(true);
    }
}


