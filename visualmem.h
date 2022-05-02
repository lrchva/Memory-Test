#ifndef VISUALMEM_H
#define VISUALMEM_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QTimer>
#include <ctime>
#include <QString>
#include <QObject>


namespace Ui {
class VisualMem;
}

class VisualMem : public QWidget
{
    Q_OBJECT

public:
    explicit VisualMem(QWidget *parent = nullptr);
    ~VisualMem();
    QTimer* timer;
    int number = 0;
    int level = 1;
    QVector<int> numbers;
    QVector<int> clicked_b;
    QVector<QPushButton*> buttons;

private slots:
    void on_button_Start_clicked();
    void on_button_check_clicked();
    void next_level(int level);
    void show_buttons(int level);
    void get_buttons();
    void button_clicked();

private:
    Ui::VisualMem *ui;

};

#endif // VISUALMEM_H
