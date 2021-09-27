#ifndef BISPO_H
#define BISPO_H

#include"pecasxadrez.h"


class bispo:public pecasxadrez
{
public:
    bispo(int x1, int y1, int tipo);
    void criaPeca(QPainter &painter, TabXadrez *tab) override;
    void movimento(QPainter &painter,  TabXadrez *tab) override;
    bool podeIr(int x, int y, TabXadrez *tab) override;
};

#endif // BISPO_H
