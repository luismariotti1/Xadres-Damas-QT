#ifndef TABDAMA_H
#define TABDAMA_H

#include "tabuleiro.h"

class pecasDama;

class tabDama: public Tabuleiro
{
    tabDama(const TabXadrez &t);
    tabDama operator = (tabDama t);
    tabDama(QColor c1, QColor c2);
    static tabDama *instanciaDama;
public:
    //void vezDoJogador(QPainter &painter);
    static tabDama *getInstacia();
};

#endif // TABDAMA_H
