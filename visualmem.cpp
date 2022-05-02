#include "visualmem.h"
#include "ui_visualmem.h"

VisualMem::VisualMem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualMem)
{
    ui->setupUi(this);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(get_buttons()));

    ui->button_check->setVisible(false);
    buttons = {ui->button_1, ui->button_2, ui->button_3, ui->button_4, ui->button_5, ui->button_6,
              ui->button_7, ui->button_8, ui->button_9, ui->button_10, ui->button_11, ui->button_12,
              ui->button_13, ui->button_14, ui->button_15, ui->button_16,
              ui->button_17, ui->button_18, ui->button_19, ui->button_20 };
    for (size_t i = 0; i < buttons.size(); i++){
        buttons[i]->setVisible(false);
        buttons[i]->setStyleSheet("background-color: grey }");
    }
    for (size_t i = 0; i < buttons.size(); i++)
    {
        QObject::connect(buttons[i], SIGNAL(clicked()), this, SLOT(button_clicked()));
    }


}

VisualMem::~VisualMem()
{
    delete ui;
}

void VisualMem::on_button_Start_clicked()
{
    ui->button_Start->setVisible(false);
    level = 5;
    bool correct = 1;
    next_level(level);
}

void VisualMem::show_buttons(int level){
    numbers.clear();
    clicked_b.clear();
    srand(time(nullptr));
    if (level < 3){
        for (size_t i = 0; i < level; i++){
            number = rand() % 6;
            numbers.push_back(number);
            buttons[number]->setStyleSheet("background-color: blue");
        }
        for (size_t i = 0; i < 6; i++){
             buttons[i]->setVisible(true);
        }
    }
    else if (level < 7){
        for (size_t i = 0; i < level - 1; i++){
            number = rand() % 9;
            numbers.push_back(number);
            buttons[number]->setStyleSheet("background-color: blue");
        }
        for (size_t i = 0; i < 9; i++){
             buttons[i]->setVisible(true);
        }
    }
    else if (level < 12){
        for (size_t i = 0; i < level - 3; i++){
            number = rand() % 16;
            numbers.push_back(number);
            buttons[number]->setStyleSheet("background-color: blue");
        }
        for (size_t i = 0; i < 16; i++){
             buttons[i]->setVisible(true);
        }
    }
}

void VisualMem::next_level(int level){
    ui->label_Level->setText("Level: " + QString::number(level));
    show_buttons(level);

    timer->setInterval((level + 2) * 1000);
    timer->start();
}

void VisualMem::get_buttons(){
    timer->stop();
    for (size_t i = 0; i < buttons.size(); i++){
        buttons[i]->setStyleSheet("background-color: grey");
    }
    ui->button_check->setVisible(true);
}

void VisualMem::button_clicked(){
    QString button_name = sender()->objectName();
    button_name.remove(0, 7);
    int cl = button_name.toInt() - 1;
    clicked_b.push_back(cl);
    ui->label->setText(button_name);
}

void VisualMem::on_button_check_clicked()
{
    std::sort(numbers.begin(), numbers.end());
    std::sort(clicked_b.begin(), clicked_b.end());
    /*QString s1;
    QString s2;
    for (int i = 0; i < numbers.size(); i++){
        s1 = s1 + " " + QString::number(numbers[i]);
    }
    for (int i = 0; i < clicked_b.size(); i++){
        s2 = s2 + " " + QString::number(clicked_bs[i]);
    }
    ui->label->setText(s1);
    ui->label_2->setText(s2);*/
    if (clicked_b == numbers){
        level++;
        next_level(level);
    }
    else {
        ui->label_TestName->setText("Try again");
    }
}

