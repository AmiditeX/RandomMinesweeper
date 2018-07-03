#ifndef UIDISPLAY_H
#define UIDISPLAY_H

#include <QMainWindow>
#include <QTimer>
#include "minesweeper.h"
#include "generator.h"

namespace Ui {
class UIDisplay;
}

class UIDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIDisplay(QWidget *parent = 0);
    ~UIDisplay();

public slots:
    void reset();
    void winCheck();
    void lose();
    void update();

    void zerozero();
    void zeroone();
    void zerotwo();
    void zerothree();
    void zerofour();

    void onezero();
    void oneone();
    void onetwo();
    void onethree();
    void onefour();

    void twozero();
    void twoone();
    void twotwo();
    void twothree();
    void twofour();

    void threezero();
    void threeone();
    void threetwo();
    void threethree();
    void threefour();

    void fourzero();
    void fourone();
    void fourtwo();
    void fourthree();
    void fourfour();

signals:
    void end();
    void checkwin();

private:
    Ui::UIDisplay *ui;
    QVector<QVector<short int>> map_;
    QStringList minesPlace;
    QTimer *timer;
    bool init = false; //False if no map has been created yet
};

#endif // UIDISPLAY_H
