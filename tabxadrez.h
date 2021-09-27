#ifndef TABXADREZ_H
#define TABXADREZ_H

#include "tabuleiro.h"


class TabXadrez : public Tabuleiro
{
    TabXadrez(const TabXadrez &t);
    TabXadrez operator = (TabXadrez t);
    TabXadrez(QColor c1, QColor c2);
    static TabXadrez *instanciaXadrez;
public:
    void defineCasa(QPainter &painter);
    static TabXadrez *getInstacia();
};

#endif // TABXADREZ_H
