#ifndef DAMAVERMELHA_H
#define DAMAVERMELHA_H

#include "pecasdama.h"


class damaVermelha: public pecasDama
{

public:

    damaVermelha(int px, int py);
    void criaPeca(QPainter &painter, tabDama *tab) override;
    void movimento(QPainter &painter,  tabDama *tab) override;
    bool podeIr(int x, int y, tabDama *tab) override;
};

#endif // DAMAVERMELHA_H
