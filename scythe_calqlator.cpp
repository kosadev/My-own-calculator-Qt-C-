#include "scythe_calqlator.h"
#include "ui_scythe_calqlator.h"


Scythe_calqlator::Scythe_calqlator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scythe_calqlator)
{
    ui->setupUi(this);


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //character encoding


    //I set dimension of main widget
    this->setGeometry(700,500,290,370);
    this->setFixedWidth(290);
    this->setFixedHeight(370);


    qApp->setStyleSheet("QLabel {background-color: white; font-size:40px; border: 1px solid #F7C699; border-top-style:none; border-left-style:none; border-right-style:none; padding-top:15px;} QPushButton { background-color: #F9F9F9; border:0px; font-size:25px; font-family: Arial; } QPushButton:hover { background-color: #F7C699 }");
    mbuttonstyle="QPushButton {background-color:#F6F6F6; font-size:25px; font-family: Arial; border-bottom: 1px solid #F7C699;} QPushButton:hover{background-color:#F7C699;}";


    //here I initialize variables
    result=0;
    temp=0;
    previous=0;
    fraction=0;
    memory=0;
    strresult.setNum(result);
    action=0;
    previousaction=0;

    is_certain=false;
    is_dot=false;




    aboutWidget= new QWidget;//new widget with about information

    //now  create label and buttons
    //I also set geometry and alignment for them

    label= new QLabel(strresult, this);
    label->setGeometry(0,0,290,70);
    label->setAlignment(Qt::AlignRight);

    aboutButton= new QPushButton("?", this);
    aboutButton->setGeometry(0,5,20,20);
    aboutButton->setStyleSheet("background-color:white; color: gray; font-size:15px;");

    mcButton=new QPushButton("MC", this);
    mcButton->setGeometry(0,70,58,50);
    mcButton->setStyleSheet(mbuttonstyle);

    mrButton=new QPushButton("MR", this);
    mrButton->setGeometry(58,70,58,50);
    mrButton->setStyleSheet(mbuttonstyle);

    msButton=new QPushButton("MS", this);
    msButton->setGeometry(116,70,58,50);
    msButton->setStyleSheet(mbuttonstyle);

    mplusButton=new QPushButton("M+", this);
    mplusButton->setGeometry(174,70,58,50);
    mplusButton->setStyleSheet(mbuttonstyle);

    mminusButton=new QPushButton("M-", this);
    mminusButton->setGeometry(232,70,58,50);
    mminusButton->setStyleSheet(mbuttonstyle);

    ////////////////////////

    clearButton= new QPushButton("C", this);
    clearButton->setGeometry(0,120, 58, 50);

    clearenterButton= new QPushButton("CE", this);
    clearenterButton->setGeometry(58,120, 58, 50);

    inverseButton= new QPushButton("1/x", this);
    inverseButton->setGeometry(116,120, 58, 50);

    sqrootButton=new QPushButton(MathSymbolSquareRoot, this);
    sqrootButton->setGeometry(174,120, 58, 50);

    percentButton= new QPushButton("%", this);
    percentButton->setGeometry(232,120, 58, 50);

    //////////////////////

    sevenButton= new QPushButton("7", this);
    sevenButton->setGeometry(0,170, 58, 50);

    eightButton= new QPushButton("8", this);
    eightButton->setGeometry(58,170, 58, 50);

    nineButton= new QPushButton("9", this);
    nineButton->setGeometry(116,170, 58, 50);

    addictionButton= new QPushButton("+", this);
    addictionButton->setGeometry(174,170, 58, 50);

    multiplicationButton= new QPushButton(MathSymbolMultiplication, this);
    multiplicationButton->setGeometry(232,170, 58, 50);

    //////////////////////

    fourButton= new QPushButton("4", this);
    fourButton->setGeometry(0,220, 58, 50);

    fiveButton= new QPushButton("5", this);
    fiveButton->setGeometry(58,220, 58, 50);

    sixButton= new QPushButton("6", this);
    sixButton->setGeometry(116,220, 58, 50);

    substractionButton= new QPushButton("-", this);
    substractionButton->setGeometry(174,220, 58, 50);

    divisionButton= new QPushButton(MathSymbolDivision, this);
    divisionButton->setGeometry(232,220, 58, 50);

    //////////////////////

    oneButton= new QPushButton("1", this);
    oneButton->setGeometry(0,270, 58, 50);

    twoButton= new QPushButton("2", this);
    twoButton->setGeometry(58,270, 58, 50);

    threeButton= new QPushButton("3", this);
    threeButton->setGeometry(116,270, 58, 50);

    //////////////////////


    signchangeButton= new QPushButton(MathSymbolPlusOrMinus, this);
    signchangeButton->setGeometry(0,320, 58, 50);

    nullButton= new QPushButton("0", this);
    nullButton->setGeometry(58,320, 58, 50);

    dotButton= new QPushButton(".", this);
    dotButton->setGeometry(116,320, 58, 50);

    //////////////////////

    equalButton= new QPushButton("=", this);
    equalButton->setGeometry(174,270, 116, 100);




    //I used signal map for buttons with digits, it's easier to me
    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(oneButton, int(1));
    signalMapper->setMapping(twoButton, int(2));
    signalMapper->setMapping(threeButton, int(3));
    signalMapper->setMapping(fourButton, int(4));
    signalMapper->setMapping(fiveButton, int(5));
    signalMapper->setMapping(sixButton, int(6));
    signalMapper->setMapping(sevenButton, int(7));
    signalMapper->setMapping(eightButton, int(8));
    signalMapper->setMapping(nineButton, int(9));
    signalMapper->setMapping(nullButton, int(0));



    connect(nullButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(oneButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(twoButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(threeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(fourButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(fiveButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(sixButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(sevenButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(eightButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(nineButton, SIGNAL(clicked()), signalMapper, SLOT(map()));


    connect(signalMapper, SIGNAL(mapped(int)),
           this, SLOT(totemp(int)));
    //every button has own value, this value is sent sent to totemp slot



    //here I connect action buttons with suitable slots
    connect(addictionButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(substractionButton, SIGNAL(clicked()), this, SLOT(substract()));
    connect(multiplicationButton, SIGNAL(clicked()), this, SLOT(multiply()));
    connect(divisionButton, SIGNAL(clicked()), this, SLOT(divide()));
    connect(signchangeButton, SIGNAL(clicked()), this, SLOT(sign_change()));
    connect(sqrootButton, SIGNAL(clicked()), this, SLOT(sqroot()));
    connect(percentButton, SIGNAL(clicked()), this, SLOT(percent()));

    //here I connect buttons to memory service with suitable slots
    connect(mcButton, SIGNAL(clicked()), this, SLOT(mc()));
    connect(mrButton, SIGNAL(clicked()), this, SLOT(mr()));
    connect(msButton, SIGNAL(clicked()), this, SLOT(ms()));
    connect(mplusButton, SIGNAL(clicked()), this, SLOT(mplus()));
    connect(mminusButton, SIGNAL(clicked()), this, SLOT(mminus()));

    //here I connect cleaning buttons with suitable slots
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
    connect(clearenterButton, SIGNAL(clicked()), this, SLOT(clearenter()));

    //here I connect others buttons with suitable slots
    connect(inverseButton, SIGNAL(clicked()), this, SLOT(inverse()));
    connect(dotButton, SIGNAL(clicked()), this, SLOT(dot()));
    connect(equalButton, SIGNAL(clicked()), this, SLOT(equal()));

    //here I connect aboutButton with showabout() slot, which shows new widget with about information
    connect(aboutButton, SIGNAL(clicked()), this, SLOT(showabout()));

}





Scythe_calqlator::~Scythe_calqlator()
{
    delete ui;
}



//slots & functions

void Scythe_calqlator::totemp(int a)
{


    if(action==0)
        {
        if(is_certain==false)
        {
            result=0;
            strresult.setNum(result);
            fraction=0;
            fractionstr.clear();
            is_certain=true;
            previousaction=0;
            action=0;
        }

            if(strresult.length()<10)
            {



                if(is_dot==true)
                {

                    if(fractionstr.length()!=0)result-=fraction/pow(10,fractionstr.length());

                    if(fraction==0)
                    {
                        fraction+=a;
                    }else
                    {
                        fraction*=10;
                        fraction+=a;
                    }


                   fractionstr+='-';

                   result+=fraction/pow(10,fractionstr.length());



                }else
                {
                    if(result==0)
                    {
                        result+=a;
                    }else
                    {
                        result*=10;
                        result+=a;
                    }

                }

                strresult.setNum(result, 'f',fractionstr.length());
                change(strresult);
            }






        }else
        {
        if(strtemp.length()<10)
        {
            if(is_dot==true)
            {

                if(fractionstr.length()!=0)temp-=fraction/pow(10,fractionstr.length());

                if(fraction==0)
                {
                    fraction+=a;
                }else
                {
                    fraction*=10;
                    fraction+=a;
                }



               fractionstr+='-';

               temp+=fraction/pow(10,fractionstr.length());

            }else
            {
                if(temp==0)
                {
                    temp+=a;
                }else
                {
                    temp*=10;
                    temp+=a;
                }

            }

            strtemp.setNum(temp, 'f',fractionstr.length());
            change(strtemp);
            }
        }




}



//slot for equalButton


void Scythe_calqlator::equal()
{
    switch(action)
    {
    case 0:
        if(temp==0)
        {
            switch(previousaction)
            {
            case 1:
                result+=previous;
                summary(strresult, result);
                break;

            case 2:
                result-=previous;
                summary(strresult, result);
                break;

            case 3:
                result*=previous;
                summary(strresult, result);
                break;

            case 4:
                result/=previous;
                summary(strresult, result);
                break;

            default:
                break;
            }

        }
       break;
    case 1:
        add();
        break;

    case 2:
        substract();
        break;

    case 3:
        if(temp==0)
        {
          previous=result;
          result=pow(result,2);
          summary(strresult, result);
          previousaction=3;
        }else
        multiply();
        break;

    case 4:
       /* if(temp==0)
        {
          previous=result;
          result/=previous;
          summary(strresult, result);
          previousaction=4;
        }else*/
        divide();
        break;

    default:
        break;
    }


    toshort(0);

}


//slots for actions

void Scythe_calqlator::add()
{
    if(action!=0)
    {
        if(action==1)
        {
            if(temp==0)//in case, we didn't enter second number
            {
                      previous=result;
            }else
            {
                previous=temp;
                temp=0;
                strtemp.setNum(temp);
            }
            result+=previous;
            summary(strresult, result);
            previousaction=action;
            action=0;
        }else
        {
         equal();
        }
    }
     toshort(1);

}


void Scythe_calqlator::substract()
{


    if(action!=0)
    {
        if(action==2)
        {
            if(temp==0)//in case, we didn't enter second number
            {
                      previous=result;
            }else
            {
                previous=temp;
                temp=0;
                strtemp.setNum(temp);
            }
            result-=previous;
            summary(strresult, result);
            previousaction=action;
            action=0;
        }else
        {
         equal();
        }
    }

     toshort(2);


}


void Scythe_calqlator::multiply()
{


    if(action!=0)
    {
        if(action==3)
        {
            if(temp==0)//in case, we didn't enter multiplier
            {
                      previous=result;
            }else
            {
                previous=temp;
                temp=0;
                strtemp.setNum(temp);
            }
            result*=previous;
            summary(strresult, result);
            previousaction=action;
            action=0;
        }else
        {
         equal();
        }
    }

    toshort(3);



}


void Scythe_calqlator::divide()
{

    if(action!=0)
    {
        if(action==4)
        {
            if(temp==0)//in case, we didn't enter divisor
            {
                      previous=result;
            }else
            {
                previous=temp;
                temp=0;
                strtemp.setNum(temp);
            }
            result/=previous;
            summary(strresult, result);
            previousaction=action;
            action=0;

        }else
        {
         equal();
        }
    }


    toshort(4);

}



void Scythe_calqlator::inverse()
{

    if(action==0)
    {
        if(result!=0)
        {
            result/=pow(result,2);
            summary(strresult, result);
        }

    }else
    {
        if(temp!=0)
        {
            temp/=pow(temp,2);
            summary(strtemp, temp);
        }

    }
}


void Scythe_calqlator::percent()
{
    if(action==3)
    {
        result*=temp/100;
        summary(strresult, result);
        action=0;
    }
}



void Scythe_calqlator::sqroot()
{

    if(action==0)
    {
        if(result>=0)
        {
            result=sqrootcalc(result);
            summary(strresult, result);
        }else
        {
            change("no way...");
            toshort(0);
            is_certain=false;
        }

    }else
    {
        if(temp>=0)
        {
            temp=sqrootcalc(temp);
            summary(strtemp, temp);
        }else
        {
            change("no way...");
            toshort(0);
            is_certain=false;
        }

    }

}


//modifiers

void Scythe_calqlator::clear()
{
    action=0;
    result=0;
    temp=0;
    fraction=0;
    fractionstr.clear();
    is_dot=0;
    strresult.setNum(result);
    change(strresult);
}


void Scythe_calqlator::clearenter()
{
    temp=0;
    fraction=0;
    fractionstr.clear();
    is_dot=0;
    change(strresult);
}



void Scythe_calqlator::sign_change()
{
    if(action==0)
    {
        result*=-1;
        strresult.setNum(result);
        change(strresult);
    }else
    {
        temp*=-1;
        strtemp.setNum(temp);
        change(strtemp);
    }


}



void Scythe_calqlator::dot()
{
    is_dot=true;
}


//slots for memory buttons

void Scythe_calqlator::mc()
{
    memory=0;
}



void Scythe_calqlator::mr()
{
    if(action!=0)
    {
        temp=memory;
        summary(strtemp, temp);
    }else
    {
        result=memory;
        summary(strresult, result);
    }
}


void Scythe_calqlator::ms()
{
    mc();
    mplus();
}


void Scythe_calqlator::mplus()
{
    if(action!=0 && temp!=0) memory+=temp;
    else memory+=result;
}


void Scythe_calqlator::mminus()
{
    if(action!=0 && temp!=0) memory-=temp;
    else memory-=result;
}




//this slot shows new widget

void Scythe_calqlator::showabout()
{
    aboutWidget->setWindowTitle("About Scythe_calqlator");
    aboutWidget->setGeometry(750,550,280,110);
    aboutWidget->setStyleSheet("background-color:white;");
    aboutWidget->setFixedWidth(280);
    aboutWidget->setFixedHeight(110);



    info=new QLabel("Łukasz Kosiński\nBeta Version\n© Łukasz Kosiński. All rights reserved.\n",aboutWidget);
    info->setGeometry(10,0,260,65);
    info->setAlignment(Qt::AlignLeft);
    info->setStyleSheet("color:gray; font-size:12px;");


    myLink=new QLabel(aboutWidget);
    myLink->setText("<a href=\"http://binarnie.pl/\">Click Here!</a>");
    myLink->setTextFormat(Qt::RichText);
    myLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    myLink->setOpenExternalLinks(true);
    myLink->setStyleSheet("font-size:12px; border:0px;");
    myLink->setGeometry(10,65,260,30);




    aboutWidget->show();
}


//others functions

//this function is used to short others. Here is determined, how write out number
void Scythe_calqlator::summary(QString &str, double data)
{
    if(how_many_digits(data)+how_many_digits_in_fraction(data)>10)
    {
    str.setNum(data, 'e', 6);
    }else
    {
    if(fractionstr.length()==0 && fmod(data,1)==0)
    str.setNum(data, 'f', 0);
    else
    str.setNum(data, 'f', how_many_digits_in_fraction(data));
    }


    //str.setNum(data,'f', 0);
    change(str);
    is_certain=false;
}

//this function calculate square root using Newtona-Raphson method
double Scythe_calqlator::sqrootcalc(double number)
{

    double x;
    if(number==0)return 0;

    x=number*0.5;

    for(int i=0; i<26; i++)
    {
        x=0.5*(x+number/x);
        if(x*x==number) return x;
    }


    return x;

}

//this function calculate a power
double Scythe_calqlator::pow(double a, int b)
{
    if(b==0)return 1;
        else return a*pow(a, b-1);
}

//this function checks how many digits has number
unsigned int Scythe_calqlator::how_many_digits(double a)
{
    int x=0;
    for(;a>=1; a/=10)x++;

    if(x==0 && a<1)x++;

    return x;

}

//this function checks how many digits has number in fraction
unsigned int Scythe_calqlator::how_many_digits_in_fraction(double a)
{

    QString *temporarystr=new QString[2];
    temporarystr[0].setNum(a,'f');


    temporarystr[1] = temporarystr[0].mid(how_many_digits(a)+1);

    int x=temporarystr[1].length();
    for(int i=temporarystr[1].length()-1;i>=0; i--)
    {

        if(temporarystr[1][i].digitValue()==0)
            x--;
        else
            break;

    }

    delete [] temporarystr;

    return x;
}


void Scythe_calqlator::change(const QString &line)
{
    label->setText(line);
}

inline void Scythe_calqlator::toshort(int a)
{
    action=a;
    fraction=0;
    fractionstr.clear();
    is_dot=false;
}






//keyboard's service

void Scythe_calqlator::keyPressEvent(QKeyEvent *event)
{
   int keyvalue=event->key();
   if(keyvalue<48 || keyvalue>57)
   {
       switch (keyvalue)
       {
       case Qt::Key_Enter:
           equal();
           break;

       case Qt::Key_Plus:
           add();
           break;

       case Qt::Key_Minus:
          substract();
          break;

       case Qt::Key_Asterisk:
          multiply();
          break;

       case Qt::Key_Slash:
          divide();
          break;

       case Qt::Key_Comma:
          dot();
          break;

       case Qt::Key_Period:
          dot();
          break;








       default:
           break;

       }
   }
   else
   {
       keyvalue-=48;
       totemp(keyvalue);

   }
}
