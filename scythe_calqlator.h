#ifndef SCYTHE_CALQLATOR_H
#define SCYTHE_CALQLATOR_H

#include <QWidget>
#include <QPushButton>//przyciski
#include <QLabel>//etykiety
#include <QLineEdit>//pole do wprowadzania
#include <QTextCodec>//kodowanie
#include <QSignalMapper>//mapa sygnałów
#include <QDesktopServices>
#include <QUrl>
#include <QKeyEvent>

#include <cmath>


const QChar MathSymbolSquareRoot(0x221A);
const QChar MathSymbolPlusOrMinus(0xB1);
const QChar MathSymbolDivision(0xF7);
const QChar MathSymbolMultiplication(0x00D7);

namespace Ui {
class Scythe_calqlator;
}


class Scythe_calqlator : public QWidget
{
    Q_OBJECT

private:
    Ui::Scythe_calqlator *ui;

    QSignalMapper *signalMapper;//map for my signals



    //additional widget with information about
    QWidget *aboutWidget;

    //displayer
    QLabel *label;

    //label with some info
    QLabel *info;
    //label with link to my page
    QLabel *myLink;

    QPushButton *aboutButton;

    //calculator's memory
    QPushButton *mcButton;
    QPushButton *mrButton;
    QPushButton *msButton;
    QPushButton *mplusButton;
    QPushButton *mminusButton;

    //cleaning
    QPushButton *clearButton;
    QPushButton *clearenterButton;


    //actions
    QPushButton *inverseButton;
    QPushButton *sqrootButton;
    QPushButton *percentButton;
    QPushButton *addictionButton;
    QPushButton *substractionButton;
    QPushButton *divisionButton;
    QPushButton *multiplicationButton;


    //digits
    QPushButton *nullButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;

    //other buttons
    QPushButton *dotButton;
    QPushButton *signchangeButton;
    QPushButton *equalButton;




    double result;
    double temp;
    double previous;
    QString strresult;
    QString strtemp;

    QString fractionstr;
    int fraction;
    double memory;

    QString mbuttonstyle;

    int action;
    int previousaction;
    bool is_certain;
    bool is_dot;


    void change(const QString &line);
    double pow(double a, int b);
    double sqrootcalc(double number);
    unsigned int how_many_digits(double a);
    unsigned int how_many_digits_in_fraction(double a);
    void summary(QString &str, double data);
    inline void toshort(int a);



protected:
    void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *);



public:
    explicit Scythe_calqlator(QWidget *parent = 0);
    ~Scythe_calqlator();


public slots:
    void add();
    void substract();
    void multiply();
    void divide();
    void inverse();
    void percent();
    void sqroot();
    void equal();

    void sign_change();
    void totemp(int a);
    void dot();

    void clear();
    void clearenter();


    void mc();
    void mr();
    void ms();
    void mplus();
    void mminus();

    void showabout();

};

#endif // SCYTHE_CALQLATOR_H
