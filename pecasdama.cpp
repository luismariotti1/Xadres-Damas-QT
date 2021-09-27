#include "pecasdama.h"
#include "tabdama.h"


pecasDama::pecasDama(int px, int py)
{
    posicaoX = px;
    posicaoY = py;
    mov = false;
}

void pecasDama::setPosicaoX_Y(int x, int y, int pAtualX, int pAtualY, tabDama *tab)
{
    if(podeIr(x, y, tab)==true)
    {
        if(tab->temPecaDama(x,y)==true)
        {
            for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
            {
                if(tab->vetorPecasDama[i]->getPosicaoX()==x and tab->vetorPecasDama[i]->getPosicaoY()==y)
                {
                    tab->vetorPecasDama.erase(tab->vetorPecasDama.begin()+i);
                    break;
                }
            }
            if((x < pAtualX) and (y > pAtualY))
            {
                posicaoX = x-1;
                posicaoY = y+1;

                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }
                }


            }
            if((x > pAtualX) and (y > pAtualY))
            {
                posicaoX = x+1;
                posicaoY = y+1;
                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }
                }

            }

            if((x < pAtualX) and (y < pAtualY))
            {
                posicaoX = x-1;
                posicaoY = y-1;

                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }
                }

            }
            if((x > pAtualX) and (y < pAtualY))
            {
                posicaoX = x+1;
                posicaoY = y-1;
                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }
                }

            }
        }
        /////////////////////////////////////////////////////////////////////////////////
        else
        {
            if((x < pAtualX) and (y > pAtualY))
            {
                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }
                }

            }
            if((x > pAtualX) and (y > pAtualY))
            {
                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {
                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }
                }
            }

            if((x < pAtualX) and (y < pAtualY))
            {

                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }
                }

            }
            if((x > pAtualX) and (y < pAtualY))
            {


                for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
                {

                    if((tab->vetorPecasDama[i]->getTurno() == true)and(tab->vetorPecasDama[i]->getTipoPeca()==1))
                    {
                        tab->vetorPecasDama[i]->setTurno(false);

                    }

                    if((tab->vetorPecasDama[i]->getTurno() == false)and(tab->vetorPecasDama[i]->getTipoPeca()==0))
                    {
                        tab->vetorPecasDama[i]->setTurno(true);

                    }
                }
            }
            posicaoX = x;
            posicaoY = y;
        }

    }
}
