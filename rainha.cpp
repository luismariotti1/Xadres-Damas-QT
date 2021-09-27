#include "rainha.h"
#include "tabxadrez.h"
#include<QStandardPaths>
#include "imagens.h"

rainha::rainha(int px, int py, int tipo):pecasxadrez(px,py,tipo)
{

}

void rainha::criaPeca(QPainter &painter, TabXadrez *tab)
{
   /* QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    caminho.append("/ImagensTrabalho/rainha.png");*/

    painter.drawImage(QRect(tab->getPosicao()+tab->getPosicao()*getPosicaoX(),tab->getPosicao()+tab->getPosicao()*getPosicaoY(),tab->getPosicao()
                            ,tab->getPosicao()), QImage(img_rainha));
}

void rainha::movimento(QPainter &painter, TabXadrez *tab)
{
    QBrush MovimentoRainha("#0aa0c2");
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

                    painter.setBrush(MovimentoRainha);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));
                }
            }
        }
    }
}

bool rainha::podeIr(int x, int y, TabXadrez *tab)
{
    if(x<0 or y<0 or x>7 or y>7)
    {
        return false;
    }

    if(x == getPosicaoX() and y == getPosicaoY())
        return false;


    //ESQUERDA
    if(x<getPosicaoX() and y==getPosicaoY())
    {
        for(int i = getPosicaoX()-1; i>=0; i--)
        {
            if(tab->temPecaXadrez(i, getPosicaoY()) == true and i>x)
            {
                return false;
            }
        }
        return true;
    }

    // DIREITA
    if(getPosicaoX()<x and y==getPosicaoY())
    {
        for(int i = getPosicaoX()+1; i<8; i++)
        {
            if(tab->temPecaXadrez(i, getPosicaoY()) == true and i<x)
            {
                return false;
            }
        }
        return true;
    }

    // CIMA
    if(getPosicaoX()==x and y<getPosicaoY())
    {
        for(int j = getPosicaoY()-1; j>=0; j--)
        {
            if(tab->temPecaXadrez(getPosicaoX(), j) == true and j>y)
            {
                return false;
            }
        }
        return true;
    }

    // BAIXO

    if(getPosicaoX()==x and y>getPosicaoY())
    {
        for(int j = getPosicaoY()+1; j<8; j++)
        {
            if(tab->temPecaXadrez(getPosicaoX(), j) == true and j<y)
            {

                return false;
            }
        }
        return true;
    }

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
