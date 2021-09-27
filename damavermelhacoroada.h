#ifndef DAMAVERMELHACOROADA_H
#define DAMAVERMELHACOROADA_H

#include "pecasdama.h"

class damaVermelhaCoroada: public pecasDama
{

public:

    damaVermelhaCoroada(int px, int py);
    void criaPeca(QPainter &painter, tabDama *tab) override;
    void movimento(QPainter &painter,  tabDama *tab) override;
    bool podeIr(int x, int y, tabDama *tab) override;
};

#endif // DAMAVERMELHACOROADA_H
