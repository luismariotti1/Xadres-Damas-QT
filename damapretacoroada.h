#ifndef DAMAPRETACOROADA_H
#define DAMAPRETACOROADA_H



#include "pecasdama.h"

class damaPretaCoroada: public pecasDama
{

public:

    damaPretaCoroada(int px, int py);
    void criaPeca(QPainter &painter, tabDama *tab) override;
    void movimento(QPainter &painter,  tabDama *tab) override;
    bool podeIr(int x, int y, tabDama *tab) override;
};


#endif // DAMAPRETACOROADA_H
