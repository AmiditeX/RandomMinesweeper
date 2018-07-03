#ifndef UIDISPLAY_H
#define UIDISPLAY_H

#include <QMainWindow>
#include "generator.h"
#include "minesweeper.h"

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
    void generateMap();

private:
    Ui::UIDisplay *ui;
};

#endif // UIDISPLAY_H
