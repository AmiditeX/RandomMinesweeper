#include "uidisplay.h"
#include "ui_uidisplay.h"

UIDisplay::UIDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIDisplay)
{
    ui->setupUi(this);
    QObject::connect(ui->reset, SIGNAL(clicked(bool)), this, SLOT(reset()));
    QObject::connect(this, SIGNAL(checkwin()), this, SLOT(winCheck()));
    QObject::connect(this, SIGNAL(end()), this, SLOT(lose()));
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void UIDisplay::reset()
{
    Generator g(ui->multiplier->text().toULongLong(), ui->increment->text().toULongLong(),
                ui->modulo->text().toULongLong(), ui->seed->text().toULongLong(),
                Type::linearCongruentialBasic, ui->shift->text().toULongLong());
    ui->genSeed->setText(ui->seed->text());
    Minesweeper s;
    map_ = s.generateMap(g);
    minesPlace = s.getMines();

    if(!init)
    {
        QObject::connect(ui->pushButton_00, SIGNAL(clicked(bool)), this, SLOT(zerozero()));
        QObject::connect(ui->pushButton_01, SIGNAL(clicked(bool)), this, SLOT(zeroone()));
        QObject::connect(ui->pushButton_02, SIGNAL(clicked(bool)), this, SLOT(zerotwo()));
        QObject::connect(ui->pushButton_03, SIGNAL(clicked(bool)), this, SLOT(zerothree()));
        QObject::connect(ui->pushButton_04, SIGNAL(clicked(bool)), this, SLOT(zerofour()));

        QObject::connect(ui->pushButton_10, SIGNAL(clicked(bool)), this, SLOT(onezero()));
        QObject::connect(ui->pushButton_11, SIGNAL(clicked(bool)), this, SLOT(oneone()));
        QObject::connect(ui->pushButton_12, SIGNAL(clicked(bool)), this, SLOT(onetwo()));
        QObject::connect(ui->pushButton_13, SIGNAL(clicked(bool)), this, SLOT(onethree()));
        QObject::connect(ui->pushButton_14, SIGNAL(clicked(bool)), this, SLOT(onefour()));

        QObject::connect(ui->pushButton_20, SIGNAL(clicked(bool)), this, SLOT(twozero()));
        QObject::connect(ui->pushButton_21, SIGNAL(clicked(bool)), this, SLOT(twoone()));
        QObject::connect(ui->pushButton_22, SIGNAL(clicked(bool)), this, SLOT(twotwo()));
        QObject::connect(ui->pushButton_23, SIGNAL(clicked(bool)), this, SLOT(twothree()));
        QObject::connect(ui->pushButton_24, SIGNAL(clicked(bool)), this, SLOT(twofour()));

        QObject::connect(ui->pushButton_30, SIGNAL(clicked(bool)), this, SLOT(threezero()));
        QObject::connect(ui->pushButton_31, SIGNAL(clicked(bool)), this, SLOT(threeone()));
        QObject::connect(ui->pushButton_32, SIGNAL(clicked(bool)), this, SLOT(threetwo()));
        QObject::connect(ui->pushButton_33, SIGNAL(clicked(bool)), this, SLOT(threethree()));
        QObject::connect(ui->pushButton_34, SIGNAL(clicked(bool)), this, SLOT(threefour()));

        QObject::connect(ui->pushButton_40, SIGNAL(clicked(bool)), this, SLOT(fourzero()));
        QObject::connect(ui->pushButton_41, SIGNAL(clicked(bool)), this, SLOT(fourone()));
        QObject::connect(ui->pushButton_42, SIGNAL(clicked(bool)), this, SLOT(fourtwo()));
        QObject::connect(ui->pushButton_43, SIGNAL(clicked(bool)), this, SLOT(fourthree()));
        QObject::connect(ui->pushButton_44, SIGNAL(clicked(bool)), this, SLOT(fourfour()));
        init = true;
    }
    ui->pushButton_00->setText("");
    ui->pushButton_01->setText("");
    ui->pushButton_02->setText("");
    ui->pushButton_03->setText("");
    ui->pushButton_04->setText("");
    ui->pushButton_10->setText("");
    ui->pushButton_11->setText("");
    ui->pushButton_12->setText("");
    ui->pushButton_13->setText("");
    ui->pushButton_14->setText("");
    ui->pushButton_20->setText("");
    ui->pushButton_21->setText("");
    ui->pushButton_22->setText("");
    ui->pushButton_23->setText("");
    ui->pushButton_24->setText("");
    ui->pushButton_30->setText("");
    ui->pushButton_31->setText("");
    ui->pushButton_32->setText("");
    ui->pushButton_33->setText("");
    ui->pushButton_34->setText("");
    ui->pushButton_40->setText("");
    ui->pushButton_41->setText("");
    ui->pushButton_42->setText("");
    ui->pushButton_43->setText("");
    ui->pushButton_44->setText("");
    ui->win->setText("");
}

void UIDisplay::winCheck()
{
    QStringList flag;
    if(ui->pushButton_00->text() == "►") {flag.append(ui->pushButton_00->objectName());}
    if(ui->pushButton_01->text() == "►") {flag.append(ui->pushButton_01->objectName());}
    if(ui->pushButton_02->text() == "►") {flag.append(ui->pushButton_02->objectName());}
    if(ui->pushButton_03->text() == "►") {flag.append(ui->pushButton_03->objectName());}
    if(ui->pushButton_04->text() == "►") {flag.append(ui->pushButton_04->objectName());}
    if(ui->pushButton_10->text() == "►") {flag.append(ui->pushButton_10->objectName());}
    if(ui->pushButton_11->text() == "►") {flag.append(ui->pushButton_11->objectName());}
    if(ui->pushButton_12->text() == "►") {flag.append(ui->pushButton_12->objectName());}
    if(ui->pushButton_13->text() == "►") {flag.append(ui->pushButton_13->objectName());}
    if(ui->pushButton_14->text() == "►") {flag.append(ui->pushButton_14->objectName());}
    if(ui->pushButton_20->text() == "►") {flag.append(ui->pushButton_20->objectName());}
    if(ui->pushButton_21->text() == "►") {flag.append(ui->pushButton_21->objectName());}
    if(ui->pushButton_22->text() == "►") {flag.append(ui->pushButton_22->objectName());}
    if(ui->pushButton_23->text() == "►") {flag.append(ui->pushButton_23->objectName());}
    if(ui->pushButton_24->text() == "►") {flag.append(ui->pushButton_24->objectName());}
    if(ui->pushButton_30->text() == "►") {flag.append(ui->pushButton_30->objectName());}
    if(ui->pushButton_31->text() == "►") {flag.append(ui->pushButton_31->objectName());}
    if(ui->pushButton_32->text() == "►") {flag.append(ui->pushButton_32->objectName());}
    if(ui->pushButton_33->text() == "►") {flag.append(ui->pushButton_33->objectName());}
    if(ui->pushButton_34->text() == "►") {flag.append(ui->pushButton_34->objectName());}
    if(ui->pushButton_40->text() == "►") {flag.append(ui->pushButton_40->objectName());}
    if(ui->pushButton_41->text() == "►") {flag.append(ui->pushButton_41->objectName());}
    if(ui->pushButton_42->text() == "►") {flag.append(ui->pushButton_42->objectName());}
    if(ui->pushButton_43->text() == "►") {flag.append(ui->pushButton_43->objectName());}
    if(ui->pushButton_44->text() == "►") {flag.append(ui->pushButton_44->objectName());}

    QStringList flagged;
    for(int i = 0 ; i < flag.size(); i++)
    {
        QString element =  flag.at(i);
        element.remove("pushButton_");
        flagged.append(element);
    }

    minesPlace.removeDuplicates();
    flag.sort();
    minesPlace.sort();
    if(flagged == minesPlace)
    {
        ui->win->setText("Vous avez remporté la partie !");
    }
}

void UIDisplay::lose()
{
    reset();
    ui->win->setText("<b>Vous avez perdu la partie ! Relancez.</b>");
}

void UIDisplay::update()
{
    QDateTime t = QDateTime::currentDateTime();
    uint timestamp = t.toTime_t();
    ui->seed->setText(QString::number(timestamp));
}

/// FIRST BLOCK ZERO X
void UIDisplay::zerozero()
{
    emit checkwin();
    int v = map_[0][0];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_00->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_00->setText(QString::number(v));
    }
}
void UIDisplay::zeroone()
{
    emit checkwin();
    int v = map_[0][1];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_01->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_01->setText(QString::number(v));
    }
}
void UIDisplay::zerotwo()
{
    emit checkwin();
    int v = map_[0][2];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_02->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_02->setText(QString::number(v));
    }
}
void UIDisplay::zerothree()
{
    emit checkwin();
    int v = map_[0][3];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_03->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_03->setText(QString::number(v));
    }
}
void UIDisplay::zerofour()
{
    emit checkwin();
    int v = map_[0][4];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_04->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_04->setText(QString::number(v));
    }
}
/// FIRST BLOCK ZERO X
///
/// SECOND BLOCK ONE X
void UIDisplay::onezero()
{
    emit checkwin();
    int v = map_[1][0];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_10->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_10->setText(QString::number(v));
    }
}
void UIDisplay::oneone()
{
    emit checkwin();
    int v = map_[1][1];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_11->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_11->setText(QString::number(v));
    }
}
void UIDisplay::onetwo()
{
    emit checkwin();
    int v = map_[1][2];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_12->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_12->setText(QString::number(v));
    }
}
void UIDisplay::onethree()
{
    emit checkwin();
    int v = map_[1][3];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_13->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_13->setText(QString::number(v));
    }
}
void UIDisplay::onefour()
{
    emit checkwin();
    int v = map_[1][4];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_14->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_14->setText(QString::number(v));
    }
}
/// SECOND BLOCK ONE X
///
/// THIRD BLOCK TWO X
void UIDisplay::twozero()
{
    emit checkwin();
    int v = map_[2][0];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_20->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_20->setText(QString::number(v));
    }
}
void UIDisplay::twoone()
{
    emit checkwin();
    int v = map_[2][1];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_21->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_21->setText(QString::number(v));
    }
}
void UIDisplay::twotwo()
{
    emit checkwin();
    int v = map_[2][2];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_22->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_22->setText(QString::number(v));
    }
}
void UIDisplay::twothree()
{
    emit checkwin();
    int v = map_[2][3];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_23->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_23->setText(QString::number(v));
    }
}
void UIDisplay::twofour()
{
    emit checkwin();
    int v = map_[2][4];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_24->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_24->setText(QString::number(v));
    }
}
/// THIRD BLOCK TWO X
///
/// FOURTH BLOCK THREE X
void UIDisplay::threezero()
{
    emit checkwin();
    int v = map_[3][0];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_30->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_30->setText(QString::number(v));
    }
}
void UIDisplay::threeone()
{
    emit checkwin();
    int v = map_[3][1];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_31->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_31->setText(QString::number(v));
    }
}
void UIDisplay::threetwo()
{
    emit checkwin();
    int v = map_[3][2];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_32->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_32->setText(QString::number(v));
    }
}
void UIDisplay::threethree()
{
    emit checkwin();
    int v = map_[3][3];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_33->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_33->setText(QString::number(v));
    }
}
void UIDisplay::threefour()
{
    emit checkwin();
    int v = map_[3][4];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_34->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_34->setText(QString::number(v));
    }
}
/// FOURTH BLOCK THREE X
///
/// FIFTH BLOCK FOUR X
void UIDisplay::fourzero()
{
    emit checkwin();
    int v = map_[4][0];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_40->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_40->setText(QString::number(v));
    }
}
void UIDisplay::fourone()
{
    emit checkwin();
    int v = map_[4][1];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_41->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_41->setText(QString::number(v));
    }
}
void UIDisplay::fourtwo()
{
    emit checkwin();
    int v = map_[4][2];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_42->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_42->setText(QString::number(v));
    }
}
void UIDisplay::fourthree()
{
    emit checkwin();
    int v = map_[4][3];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_43->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_43->setText(QString::number(v));
    }
}
void UIDisplay::fourfour()
{
    emit checkwin();
    int v = map_[4][4];
    if(ui->reveale->isChecked())
    {
        ui->pushButton_44->setText("►");
        emit checkwin();
        return;
    }
    if(v == -1)
    {
        emit end();
    }
    else
    {
        ui->pushButton_44->setText(QString::number(v));
    }
}
/// FIFTH BLOCK FOUR X

UIDisplay::~UIDisplay()
{
    delete ui;
    delete timer;
}
