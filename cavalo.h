#ifndef CAVALO_H
#define CAVALO_H


#include"pecasxadrez.h"


class cavalo:public pecasxadrez
{
public:
    cavalo(int x1, int y1, int tipo);
    void criaPeca(QPainter &painter,TabXadrez *tab) override;
    void movimento(QPainter &painter,  TabXadrez *tab) override;
    bool podeIr(int x, int y, TabXadrez *tab) override;
};

#endif // CAVALO_H
