#ifndef DAMABRANCACOROADA_H
#define DAMABRANCACOROADA_H

#include "pecasdama.h"

class damaBrancaCoroada : public pecasDama
{
public:

    damaBrancaCoroada(int px, int py);
    void criaPeca(QPainter &painter, tabDama *tab) override;
    void movimento(QPainter &painter,  tabDama *tab) override;
    bool podeIr(int x, int y, tabDama *tab) override;
};

#endif // DAMABRANCACOROADA_H
