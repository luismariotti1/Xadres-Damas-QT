#include "cavalo.h"
#include "tabxadrez.h"
#include <QStandardPaths>
#include "imagens.h"

cavalo::cavalo(int px, int py, int tipo):pecasxadrez(px,py,tipo)
{

}

void cavalo::criaPeca(QPainter &painter,TabXadrez *tab)
{
    /*QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    caminho.append("/ImagensTrabalho/cavalo.png");*/

    painter.drawImage(QRect(tab->getPosicao()+tab->getPosicao()*getPosicaoX(),tab->getPosicao()+tab->getPosicao()*getPosicaoY(),tab->getPosicao()
                            ,tab->getPosicao()), QImage(img_cavalo));
}

void cavalo::movimento(QPainter &painter, TabXadrez *tab)
{
    QBrush MovimentoCavalo("#0aa0c2");
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
                    painter.setBrush(MovimentoCavalo);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));
                }
            }
        }
    }
}

bool cavalo::podeIr(int x, int y, TabXadrez *tab)
{
    //L SUPERIOR ESQUERDO DEITADO
    if(x>=0 and y>=0)
    {
        if((x==(getPosicaoX()-2))and(y==(getPosicaoY()-1)))
            return true;
    }

    //L SUPERIOR ESQUERDO EM PE
    if(x>=0 and y>=0)
    {
        if((x==(getPosicaoX()-1))and(y==(getPosicaoY()-2)))
            return true;
    }

    //L SUPERIOR DIREITO DEITADO
    if(x<8 and y>=0)
    {
        if((x==(getPosicaoX()+2))and(y==(getPosicaoY()-1)))
            return true;
    }

    //L SUPERIOR DIREITO EM PE
    if(x<8 and y>=0)
    {
        if((x==(getPosicaoX()+1))and(y==(getPosicaoY()-2)))
            return true;
    }

    //L INFERIOR ESQUERDO DEITADO
    if(x>=0 and y<8)
    {
        if((x==(getPosicaoX()-2))and(y==(getPosicaoY()+1)))
            return true;
    }


    //L INFERIOR ESQUERDO EM PE
    if(x>=0 and y<8)
    {
        if((x==(getPosicaoX()-1))and(y==(getPosicaoY()+2)))
            return true;
    }

    //L INFERIOR DIREITO DEITADO
    if(x<8 and y<8)
    {
        if((x==(getPosicaoX()+2))and(y==(getPosicaoY()+1)))
            return true;
    }

    //L INFERIOR DIREITO EM PE
    if(x<8 and y<8)
    {
        if((x==(getPosicaoX()+1))and(y==(getPosicaoY()+2)))
            return true;

    }

    return false;
}
