#include "bispo.h"
#include "tabxadrez.h"
#include<QStandardPaths>
#include "imagens.h"

bispo::bispo(int px, int py, int tipo):pecasxadrez(px,py,tipo)
{

}

void bispo::criaPeca(QPainter &painter, TabXadrez *tab)
{
    /*QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    caminho.append("/ImagensTrabalho/bispo.png");*/

    painter.drawImage(QRect(tab->getPosicao()+tab->getPosicao()*getPosicaoX(),tab->getPosicao()+tab->getPosicao()*getPosicaoY(),tab->getPosicao()
                            ,tab->getPosicao()), QImage(img_bispo));
}

void bispo::movimento(QPainter &painter,  TabXadrez *tab)
{
    QBrush MovimentoTorre("#0aa0c2");
    QBrush PecaInimiga(Qt::red);


    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(podeIr(i, j, tab) == true)
            {

                if(tab->temPecaXadrez(i,j) and (i!=getPosicaoX() or j!=getPosicaoY()))
                {
                    painter.setBrush(PecaInimiga);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));
                }
                else
                {
                    painter.setBrush(MovimentoTorre);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));

                }
            }
        }
    }
}

bool bispo::podeIr(int x, int y, TabXadrez *tab)
{
    if(x<0 or y<0 or x>7 or y>7)
    {
        return false;
    }

    if(x == getPosicaoX() and y == getPosicaoY())
        return false;

    //DIAGONAL ESQUERDA SUPERIOR
    if(x<getPosicaoX() and y<getPosicaoY())
    {
        if((x - y) == (getPosicaoX()-getPosicaoY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosicaoX()-i)>=0 and (getPosicaoY()-i)>=0)
                {
                    if(tab->temPecaXadrez((getPosicaoX()-i), (getPosicaoY()-i)) == true and x<(getPosicaoX()-i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    //DIAGONAL DIREITA INFERIOR
    if(x>getPosicaoX() and y>getPosicaoY())
    {
        if((x - y) == (getPosicaoX()-getPosicaoY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosicaoX()+i)<8 and (getPosicaoY()+i)<8)
                {
                    if(tab->temPecaXadrez((getPosicaoX()+i), (getPosicaoY()+i)) == true and x>(getPosicaoX()+i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    //DIAGONAL DIREITA SUPERIOR
    if(x>getPosicaoX() and y<getPosicaoY())
    {
        if((x + y) == (getPosicaoX()+getPosicaoY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosicaoX()+i)<8 and (getPosicaoY()-i)>=0)
                {
                    if(tab->temPecaXadrez((getPosicaoX()+i), (getPosicaoY()-i)) == true and x>(getPosicaoX()+i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }


    //DIAGONAL ESQUERDA INFERIOR
    if(x<getPosicaoX() and y>getPosicaoY())
    {
        if((x + y) == (getPosicaoX()+getPosicaoY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosicaoX()-i)>=0 and (getPosicaoY()+i)<8)
                {
                    if(tab->temPecaXadrez((getPosicaoX()-i), (getPosicaoY()+i)) == true and x<(getPosicaoX()-i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }

    return  false;
}
