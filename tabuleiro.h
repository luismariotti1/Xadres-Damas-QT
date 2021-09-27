
#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <vector>
#include "pecasxadrez.h"
#include "pecasdama.h"

using namespace std;

class Tabuleiro
{

private:
    bool visivel;
    bool selecionado;
    int posicao;
    QColor cor1;
    QColor cor2;

public:

    vector<pecasxadrez*> vetorPecas;
    vector<pecasDama*> vetorPecasDama;

    Tabuleiro(QColor c1, QColor c2, bool V = false, int P = 50);

    void criaTabuleiro(QPainter &painter);

    void setVisivel(bool V){visivel = V;}
    void setSelecionado(bool S){selecionado = S;}
    void setPosicao(int P){posicao = P;}

    bool getVisivel(){return visivel;}
    bool getSelecionado(){return selecionado;}

    int getPosicao(){return posicao;}

    bool temPecaXadrez(int x, int y);
    bool temPecaDama(int x, int y);

};

#endif // TABULEIRO_H
