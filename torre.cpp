#include "torre.h"
#include "tabxadrez.h"
#include "imagens.h"
#include<QStandardPaths>

using namespace std;
torre::torre(int px, int py, int tipo):pecasxadrez(px,py,tipo)
{

}

void torre::criaPeca(QPainter &painter, TabXadrez *tab)
{
   /* QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    caminho.append("/ImagensTrabalho/torre.png");*/
    painter.drawImage(QRect(tab->getPosicao()+tab->getPosicao()*getPosicaoX(),tab->getPosicao()+tab->getPosicao()*getPosicaoY(),tab->getPosicao()
                            ,tab->getPosicao()), QImage(img_torre));
}

void torre::movimento(QPainter &painter, TabXadrez *tab)
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
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,tab->getPosicao(),tab->getPosicao()));
                }
                else
                {
                    painter.setBrush(MovimentoTorre);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,tab->getPosicao(),tab->getPosicao()));
                }
            }
        }
    }
}

bool torre::podeIr(int x, int y, TabXadrez *tab)
{
    if(x<0 or y<0 or x>7 or y>7)
    {
        return false;
    }

    //esquerda
    if(x<getPosicaoX() and y==getPosicaoY())
    {
        for(int i = getPosicaoX()-1; i>=0; i--)
        {
            if(tab->temPecaXadrez(i, getPosicaoY()) == true and i>x)
            {
                return false;
            }
        }
    }

    // direita
    if(getPosicaoX()<x and y==getPosicaoY())
    {
        for(int i = getPosicaoX()+1; i<8; i++)
        {
            if(tab->temPecaXadrez(i, getPosicaoY()) == true and i<x)
            {
                return false;
            }
        }

    }

    // pra cima
    if(getPosicaoX()==x and y<getPosicaoY())
    {
        for(int j = getPosicaoY()-1; j>=0; j--)
        {
            if(tab->temPecaXadrez(getPosicaoX(), j) == true and j>y)
            {
                return false;
            }
        }
    }

    // pra baixo

    if(getPosicaoX()==x and y>getPosicaoY())
    {
        for(int j = getPosicaoY()+1; j<8; j++)
        {
            if(tab->temPecaXadrez(getPosicaoX(), j) == true and j<y)
            {

                return false;
            }
        }
    }

    if(x == getPosicaoX() and y == getPosicaoY())
    {
        return false;
    }
    if(x != getPosicaoX() and y != getPosicaoY())
    {
        return false;
    }
    return true;
}
