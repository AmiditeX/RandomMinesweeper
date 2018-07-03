#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QVector>
#include "generator.h"

class Minesweeper
{

public:
    Minesweeper();

public slots:
    //Generate a minesweep map
    QVector<QVector<short> > generateMap(Generator &gen);
    QStringList getMines();

private:
    QVector<QVector<short int>> map_; //Minesweep map
    QStringList mines;

};

#endif // MINESWEEPER_H
