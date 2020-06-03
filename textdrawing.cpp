#include "textdrawing.h"
#include "sqlwraper.h"
#include <QDebug>

TextDrawing::TextDrawing()
{
    over=false;
    w=350;
    h=50;
    x=450/2-w/2;
    y=480/2-h/2;
    score=0;
    playing=false;
    paused=false;

}
// setting locations on the screen for the writting
QRectF TextDrawing::boundingRect() const
{
    return QRect(x, y, w, h);
}
// a bool to check if the game over
void TextDrawing::SetOver(bool over)
{
    this->over=over;
}

// this method draws all the text at the beginning, during, end of the game.
void TextDrawing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::blue);
    painter->setPen(pen);
    QFont font=painter->font() ;


    if(!playing){
        font.setPointSize ( 18 );
        painter->setFont(font);


        if(over){

            //Let's get the DB connection
            SQLWrapper *sql = new SQLWrapper();

            //Let's request the relative position based on name, score and difficulty
            QList<QList<QString>> results = sql->getRelativePosition(name, score, difficultyInt);

            font.setPointSize ( 32 );
            QPen pen(Qt::red);
            painter->setPen(pen);
            painter->setFont(font);
            painter->drawText( x+80,y-180, "GAME OVER" );
            font.setPointSize ( 18 );
            QPen highPen(Qt::yellow);
            painter->setPen(highPen);
            painter->setFont(font);

            painter->drawText( x+120,y-110, "HIGHSCORE - " + QString(difficulty).toUpper());
            QList<QString> result = results[0];
            if (result[4].toInt() == 1)
            {
                QPen highPen(Qt::red);
                painter->setPen(highPen);
            }
            else
            {
                QPen highPen(Qt::yellow);
                painter->setPen(highPen);
            }
            painter->drawText( x+0, y-70, QString::number(result.value(0).toInt()) + ".");
            painter->drawText( x+80, y-70, QString(result.value(1)));
            painter->drawText( x+140,y-70, QString::number(result.value(2).toInt()));
            painter->drawText( x+250,y-70, QString::number(result.value(3).toInt()) + "s");
            if (results.length() > 1)
            {
                QList<QString> result = results[1];
                if (result[4].toInt() == 1)
                {
                    QPen highPen(Qt::red);
                    painter->setPen(highPen);
                }
                else
                {
                    QPen highPen(Qt::yellow);
                    painter->setPen(highPen);
                }

                painter->drawText( x+0, y-50, QString::number(result.value(0).toInt()) + ".");
                painter->drawText( x+80, y-50, QString(result.value(1)));
                painter->drawText( x+140,y-50, QString::number(result.value(2).toInt()));
                painter->drawText( x+250,y-50, QString::number(result.value(3).toInt()) + "s");
            }
            if (results.length() > 2)
            {
                QList<QString> result = results[2];
                if (result[4].toInt() == 1)
                {
                    QPen highPen(Qt::red);
                    painter->setPen(highPen);
                }
                else
                {
                    QPen highPen(Qt::yellow);
                    painter->setPen(highPen);
                }

                painter->drawText( x+0, y-30, QString::number(result.value(0).toInt()) + ".");
                painter->drawText( x+80, y-30, QString(result.value(1)));
                painter->drawText( x+140,y-30, QString::number(result.value(2).toInt()));
                painter->drawText( x+250,y-30, QString::number(result.value(3).toInt()) + "s");
            }
            if (results.length() > 3)
            {
                QList<QString> result = results[3];
                if (result[4].toInt() == 1)
                {
                    QPen highPen(Qt::red);
                    painter->setPen(highPen);
                }
                else
                {
                    QPen highPen(Qt::yellow);
                    painter->setPen(highPen);
                }

                painter->drawText( x+0, y-10, QString::number(result.value(0).toInt()) + ".");
                painter->drawText( x+80, y-10, QString(result.value(1)));
                painter->drawText( x+140,y-10, QString::number(result.value(2).toInt()));
                painter->drawText( x+250,y-10, QString::number(result.value(3).toInt()) + "s");
            }
            if (results.length() > 4)
            {
                QList<QString> result = results[4];
                if (result[4].toInt() == 1)
                {
                    QPen highPen(Qt::red);
                    painter->setPen(highPen);
                }
                else
                {
                    QPen highPen(Qt::yellow);
                    painter->setPen(highPen);
                }

                painter->drawText( x+0, y+10, QString::number(result.value(0).toInt()) + ".");
                painter->drawText( x+80, y+10, QString(result.value(1)));
                painter->drawText( x+140,y+10, QString::number(result.value(2).toInt()));
                painter->drawText( x+250,y+10, QString::number(result.value(3).toInt()) + "s");
            }
            //painter->drawText( x+80,y-300, "Press Space to play again" );

        }else{

            painter->drawText( boundingRect(),Qt::AlignCenter, "PRESS SPACE TO START" );
            font.setPointSize ( 32 );
            QPen pen(Qt::yellow);
            painter->setPen(pen);
            painter->setFont(font);
            painter->drawText( x+100,y-180, "Pac Man" );





        }


    }

    if(paused  && !over)
   {
          font.setPointSize ( 18 );
           painter->setFont(font);
           QPen pen(Qt::red);
           painter->setPen(pen);
                   painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
      }


}

