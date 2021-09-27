#ifndef RAINHA_H
#define RAINHA_H
#include "pecasxadrez.h"

class rainha : public pecasxadrez
{

public:

    rainha(int px, int py, int tipo);
    void criaPeca(QPainter &painter,TabXadrez *tab) override;
    void movimento(QPainter &painter,TabXadrez *tab) override;
    bool podeIr(int x, int y, TabXadrez *tab) override;

};

#endif // RAINHA_H
