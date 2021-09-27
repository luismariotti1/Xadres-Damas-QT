#ifndef TORRE_H
#define TORRE_H

#include "pecasxadrez.h"

class torre : public pecasxadrez
{
public:
    torre(int px, int py, int tipo);
    void criaPeca(QPainter &painter, TabXadrez *tab) override;
    void movimento(QPainter &painter,TabXadrez *tab) override;
    bool podeIr(int x, int y, TabXadrez *tab) override;
};

#endif // TORRE_H
