#ifndef PECASXADREZ_H
#define PECASXADREZ_H

#include<QPaintEvent>
#include<QPainter>

class TabXadrez;

class pecasxadrez
{
    int tipoPeca;
    int posicaoX, posicaoY;
    bool mov;

public:

    pecasxadrez(int px, int py, int tipo);

    void setPosicaoX_Y(int x, int y, TabXadrez *tab);
    void setMov(bool M){mov = M;}

    int getPosicaoX(){return posicaoX;}
    int getPosicaoY(){return posicaoY;}
    int getTipoPeca(){return tipoPeca;}
    bool getMov(){return mov;}

    virtual void criaPeca(QPainter &painter, TabXadrez *tab) = 0;
    virtual void movimento(QPainter &painter, TabXadrez *tab) = 0;
    virtual bool podeIr(int x, int y, TabXadrez *tab) = 0;

};

#endif // PECASXADREZ_H
