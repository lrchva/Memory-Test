#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QWidget>

namespace Ui {
class Game_Over;
}

class Game_Over : public QWidget
{
    Q_OBJECT

public:
    explicit Game_Over(QWidget *parent = nullptr);
    ~Game_Over();

private slots:
    void on_button_PlayAgain_clicked();

private:
    Ui::Game_Over *ui;
};

#endif // GAME_OVER_H
