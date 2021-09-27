#ifndef DAMABRANCA_H
#define DAMABRANCA_H

#include "pecasdama.h"



class damaBranca: public pecasDama
{

public:

    damaBranca(int px, int py);
    void criaPeca(QPainter &painter, tabDama *tab) override;
    void movimento(QPainter &painter,  tabDama *tab) override;
    bool podeIr(int x, int y, tabDama *tab) override;
};

#endif // DAMABRANCA_H
