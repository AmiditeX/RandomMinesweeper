#include "uidisplay.h"
#include "ui_uidisplay.h"
UIDisplay::UIDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIDisplay)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(generateMap()));
}

void UIDisplay::generateMap()
{
    ui->plainTextEdit->clear();
    Generator g(ui->multiplier->text().toULongLong(), ui->increment->text().toULongLong(),
                ui->modulo->text().toULongLong(), ui->seed->text().toULongLong(),
                Type::linearCongruentialBasic, ui->shift->text().toULongLong());
    Minesweeper s;
    QVector<QVector<short int>> map;
    map = s.generateMap(g);
    for(int y = 0; y < 5 ; y++)
    {
        for(int x = 0 ; x < 5 ; x++)
        {
            ui->plainTextEdit->insertPlainText(QString::number(map[x][y]) + " | ");
        }
        ui->plainTextEdit->appendPlainText("\n");
    }
}

UIDisplay::~UIDisplay()
{
    delete ui;
}
