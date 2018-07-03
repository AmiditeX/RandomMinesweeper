#include "minesweeper.h"

Minesweeper::Minesweeper()
{
    for(int x = 0; x < 5; x++) //Fill vector with 0 to initiate every case
    {
        QVector<short int> v;
        v << 0 << 0 << 0 << 0 << 0;
        map_.append(v);
    }
}

//Generate a minesweep map
QVector<QVector<short int>> Minesweeper::generateMap(Generator &gen)
{
    //We set up 8 bombs for 25 cases (or less if the same coordinates are generated twice or more)
    for(int i = 0 ; i < 8 ; i++)
    {
        int x = gen.generateNumber() % 5;
        int y = gen.generateNumber() % 5;
        map_[x][y] = -1; //Set case as mine
        QString mineNumber;
        mineNumber.append(QString::number(x));
        mineNumber.append(QString::number(y));
        mines.append(mineNumber);
    }

    //Parse the whole map and set the number of mines nearby
    for(int x = 0 ; x < 5 ; x++) //Parse abscissa (x)
    {
        for(int y = 0 ; y < 5 ; y++) //Parse ordinate (y)
        {
            if(map_[x][y] != -1) //If case doesn't contain a bomb
            {
                //Search for bombs on each adjacent case
                if(y + 1 <= 4)
                {
                    if(map_[x][y + 1] == -1) //UP
                    {
                        map_[x][y]++;
                    }
                }
                if(x + 1 <= 4 && y + 1 <= 4)
                {
                    if(map_[x + 1][y + 1] == -1) //DIAGONAL UP RIGHT
                    {
                        map_[x][y]++;
                    }
                }
                if(x + 1 <= 4)
                {
                    if(map_[x + 1][y] == -1) //RIGHT
                    {
                        map_[x][y]++;
                    }
                }
                if(x + 1 <= 4 && y - 1 >= 0)
                {
                    if(map_[x + 1][y - 1] == -1) //DIAGONAL DOWN RIGHT
                    {
                        map_[x][y]++;
                    }
                }
                if(y - 1 >= 0)
                {
                    if(map_[x][y - 1] == -1) //DOWN
                    {
                        map_[x][y]++;
                    }
                }
                if(x - 1 >= 0 && y - 1 >= 0)
                {
                    if(map_[x - 1][y - 1] == -1) //DIAGONAL DOWN LEFT
                    {
                        map_[x][y]++;
                    }
                }
                if(x - 1 >= 0)
                {
                    if(map_[x - 1][y] == -1) //LEFT
                    {
                        map_[x][y]++;
                    }
                }
                if(x - 1 >= 0 && y + 1 <= 4)
                {
                    if(map_[x - 1][y + 1] == -1) //DIAGONAL UP LEFT
                    {
                        map_[x][y]++;
                    }
                }
            }
        }
    }
    return map_;
}

QStringList Minesweeper::getMines()
{
    return mines;
}
