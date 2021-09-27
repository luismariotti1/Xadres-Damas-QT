#include "pecasxadrez.h"
#include "tabxadrez.h"


using namespace std;

pecasxadrez::pecasxadrez(int px, int py, int tipo)
{
    tipoPeca = tipo;
    posicaoX = px;
    posicaoY = py;
    mov = false;
}

void pecasxadrez::setPosicaoX_Y(int x, int y, TabXadrez *tab)
{
    if(podeIr(x, y, tab)==true)
    {
        if(tab->temPecaXadrez(x,y)==true)
        {
            for(unsigned int i = 0; i < tab->vetorPecas.size(); i++)
            {
                if(tab->vetorPecas[i]->getPosicaoX()==x and tab->vetorPecas[i]->getPosicaoY()==y)
                {

                    tab->vetorPecas.erase(tab->vetorPecas.begin()+i);
                    break;
                }
            }
            posicaoX = x;
            posicaoY = y;
        }
        else
        {
            posicaoX = x;
            posicaoY = y;
        }

    }
}
