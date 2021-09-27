#include "tabxadrez.h"
#include<QString>

TabXadrez::TabXadrez(QColor c1, QColor c2):Tabuleiro(c1,c2)
{

}

TabXadrez *TabXadrez::getInstacia()
{
    if(instanciaXadrez == nullptr)
    {
        instanciaXadrez = new TabXadrez("#a8a7a2", Qt::white);
    }

    return instanciaXadrez;
}

TabXadrez *TabXadrez::instanciaXadrez = nullptr;

void TabXadrez::defineCasa(QPainter &painter)
{
    int i, j;
    int numerosX = '0';
    int numerosY = '0';

    QBrush b1(Qt::black);
    for(i=0;i<8;i++)
    {
        QString x(numerosX);
        painter.drawText((getPosicao()+(getPosicao()/2))+getPosicao()*i, (getPosicao()-(getPosicao()/8)),x);
        numerosX++;
    }
    for(j=0;j<8;j++)
    {
        QString y(numerosY);
        painter.drawText(getPosicao()-(getPosicao()/4),(getPosicao()+((getPosicao()*55)/100))+getPosicao()*j,y);
        numerosY++;
    }
}
