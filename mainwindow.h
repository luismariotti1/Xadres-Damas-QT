#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QPaintEvent>
#include <QObject>
#include "tabuleiro.h"
#include "tabdama.h"
#include "tabxadrez.h"
#include "torre.h"
#include "rainha.h"
#include "bispo.h"
#include "cavalo.h"
#include "damavermelha.h"
#include "damavermelhacoroada.h"
#include "damabranca.h"
#include "damabrancacoroada.h"
#include "pecasdama.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QDir>
#include "stdio.h"
#include <QStandardPaths>
#include <QFrame>
#include <QFormLayout>
#include <QPalette>
#include<QPixmap>
#include "imagens.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    MainWindow(QWidget *parent = nullptr);

signals:

public slots:

    void salvaJogo();
    void abrirJogo();

    void salvaJogo_trocaTab_xadrez_Dama();
    void naoSalvaJogo_trocaTab_xadrez_Dama();

    void trocaTab_Dama_xadrez();
    void cancela_trocaTab_Dama_xadrez();

    void salvaJogo_janelaSair();
    void naoSalvaJogo_janelaSair();
    void cancelar_janelaSair();

    void criaTabXadrez();
    void criaTabDama();

    void criaDamaV();
    void criaDamaB();

    void fecharPrograma();

    void addPecasX();

    void escolherPosicao();

    void criaRainha(int x, int y);
    void criaTorre(int x, int y);
    void criaBispo(int x, int y);
    void criaCavalo(int x, int y);


    void paintEvent(QPaintEvent *) override;

    void mousePressEvent(QMouseEvent *event) override;

    void turno(QPainter &painter, tabDama *tab);

    void alterarZoom();
    void zoom();


private:

    QMenuBar * MenuBar;
    QMenu *Menu;
    QMenu *Menu2;

    QAction *JogoXadrez;
    QAction *JogoDama;
    QAction *addPecasXadrez;
    QAction *AbrirJogo;
    QAction *SalvarJogo;
    QAction *Sair;
    QAction *Zoom;

    TabXadrez *TX;
    tabDama *TD;

    rainha *novaRainha;
    torre *novaTorre;
    bispo *novoBispo;
    cavalo *novoCavalo;

    damaVermelha *novaDamaV;
    damaBranca *novaDamaB;

    QWidget *janelaSair;
    QWidget *janelaAddPX;
    QWidget *janela_trocar_tab;
    QWidget *janela_alterar_zoom;

    QPushButton *salvar;
    QPushButton *naoSalvar;
    QPushButton *continuar;
    QPushButton *cancelar;
    QPushButton *adicionarPeca;
    QPushButton *confirmarZoom;

    QHBoxLayout * layout1;
    QFormLayout * layout2;


    QComboBox *opcaoDePecas;

    QSpinBox *selecionarPosX;
    QSpinBox *selecionarPosY;
    QSpinBox *selecionarZoom;

    QLabel *texto1;
    QLabel *texto2;
    QLabel *texto3;

    int valorZoom=100;
};

#endif // MAINWINDOW_H
