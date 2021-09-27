#include "tabuleiro.h"
#include <QPainter>
#include <QPaintEvent>
#include "mainwindow.h"

Tabuleiro::Tabuleiro(QColor c1, QColor c2, bool V, int P)
{
    selecionado = false;
    visivel = V;
    posicao = P;
    cor1 = c1;
    cor2 = c2;
}

void Tabuleiro::criaTabuleiro(QPainter &painter)
{
    int i, j;
    QBrush Brush1(cor1);
    QBrush Brush2(cor2);

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i%2==0)&&(j%2==0))
                painter.setBrush(Brush1);
            else if((i%2!=0)&&(j%2!=0))
                painter.setBrush(Brush1);
            else
            {
                painter.setBrush(Brush2);
            }
            painter.drawRect(QRect(getPosicao()+getPosicao()*i,(getPosicao())+getPosicao()*j,getPosicao(),getPosicao()));
        }
    }

}

bool Tabuleiro::temPecaXadrez(int x, int y)
{
    for(unsigned int i = 0; i < vetorPecas.size(); i++)
    {
        if(vetorPecas[i]->getPosicaoX()==x and vetorPecas[i]->getPosicaoY()==y)
        {
            return true;
        }
    }
    return false;
}


bool Tabuleiro::temPecaDama(int x, int y)
{
    for(unsigned int i = 0; i < vetorPecasDama.size(); i++)
    {
        if(vetorPecasDama[i]->getPosicaoX()==x and vetorPecasDama[i]->getPosicaoY()==y)
        {
            return true;
        }
    }
    return false;
}
