#ifndef PECASDAMA_H
#define PECASDAMA_H

#include<QPaintEvent>
#include<QPainter>

class tabDama;

class pecasDama
{

    int tipoPeca;
    int posicaoX, posicaoY;
    bool mov, turno;

public:

    pecasDama(int px, int py);

    void setPosicaoX_Y(int x, int y, int pAtualX, int pAtualY,  tabDama *tab);
    void setMov(bool M){mov = M;}
    void setTurno(bool T){turno = T;}
    void setTipo(int ti){tipoPeca = ti;}

    int getPosicaoX(){return posicaoX;}
    int getPosicaoY(){return posicaoY;}
    int getTipoPeca(){return tipoPeca;}

    bool getMov(){return mov;}
    bool getTurno(){return turno;}

    virtual void criaPeca(QPainter &painter, tabDama *tab) = 0;
    virtual void movimento(QPainter &painter, tabDama *tab) = 0;
    virtual bool podeIr(int x, int y, tabDama *tab) = 0;

};

#endif // PECASDAMA_H
