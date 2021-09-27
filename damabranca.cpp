#include "damabranca.h"
#include "tabdama.h"
#include <QStandardPaths>
#include "imagensdama.h"


damaBranca::damaBranca(int px, int py):pecasDama(px,py)
{
        setTurno(true);
        setTipo(1);
}

void damaBranca::criaPeca(QPainter &painter,tabDama *tab)
{
    /*QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    caminho.append("/ImagensTrabalho/DamaPreta.png");*/

    painter.drawImage(QRect(tab->getPosicao()+tab->getPosicao()*getPosicaoX(),tab->getPosicao()+tab->getPosicao()*getPosicaoY(),tab->getPosicao()
                            ,tab->getPosicao()), QImage(img_damaPreta));
}


void damaBranca::movimento(QPainter &painter, tabDama *tab)
{
    QBrush MovimentoDama("#0aa0c2");
    QBrush PecaInimiga(Qt::red);


    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(podeIr(i, j, tab) == true)
            {

                if(tab->temPecaDama(i,j) and (i!=getPosicaoX() or j!=getPosicaoY()))
                {
                    painter.setBrush(PecaInimiga);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));
                }
                else
                {
                    painter.setBrush(MovimentoDama);
                    painter.drawRect(QRect(tab->getPosicao()+tab->getPosicao()*i,tab->getPosicao()+tab->getPosicao()*j,
                                           tab->getPosicao(),tab->getPosicao()));
                }
            }
        }
    }

}

bool damaBranca::podeIr(int x, int y, tabDama *tab)
{

    if(x>=0 and x<8 and y>=0 and y<8 )
    {
        if((x==getPosicaoX()+1)and(y==getPosicaoY()-1) and tab->temPecaDama(x,y)==false)
        {
            return true;
        }
        if(((x==(getPosicaoX()+1))and(y==(getPosicaoY()-1)))and tab->temPecaDama(x,y)==true)
        {
                if((tab->temPecaDama(getPosicaoX()+2,getPosicaoY()-2)==false)and((getPosicaoX()+2<8)and(getPosicaoY()-2>=0)))
                {
                    return true;
                }

        }
        if((x==(getPosicaoX()-1))and(y==(getPosicaoY()-1))and tab->temPecaDama(x,y)==false)
        {
            return true;
        }
        if(((x==(getPosicaoX()-1))and(y==(getPosicaoY()-1)))and tab->temPecaDama(x,y)==true)
        {
                if(tab->temPecaDama(getPosicaoX()-2,getPosicaoY()-2)==false and((getPosicaoX()-2)>=0)and((getPosicaoY()-2)>=0))
                {
                    return true;
                }

        }



    }
    return false;
}
