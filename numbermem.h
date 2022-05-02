#ifndef NUMBERMEM_H
#define NUMBERMEM_H

#include <QWidget>
#include <QTimer>
#include <ctime>
#include <QString>
#include <QInputDialog>

namespace Ui {
class NumberMem;
}

class NumberMem : public QWidget
{
    Q_OBJECT

public:
    explicit NumberMem(QWidget *parent = nullptr);
    ~NumberMem();
    QTimer* timer;
    QString user_num = "-";
    int number = 0;
    int level = 1;


private slots:
    void on_button_Start_clicked();
    void get_number();
    void next_level(int level);

private:
    Ui::NumberMem *ui;
};

#endif // NUMBERMEM_H
