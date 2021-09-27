#include "tabdama.h"

tabDama::tabDama(QColor c1, QColor c2):Tabuleiro(c1, c2)
{

}

tabDama *tabDama::getInstacia()
{
    if(instanciaDama == nullptr)
    {
        instanciaDama = new tabDama("#80330a", "#e6a35c");
    }

    return instanciaDama;
}

tabDama *tabDama::instanciaDama = nullptr;



