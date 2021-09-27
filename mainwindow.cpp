#include "mainwindow.h"



using namespace std;
// MainWindow função que gera a tela inicial do jogo onde sao construidos os tabuleiros, e controla o toolbar,  menus e ações.
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    QPalette palette;

    setFixedSize(valorZoom*10,valorZoom*10);


    this->setStyleSheet(
                "background-color: #6b5b95;"
                "font-family: Arial;"
                "font-size: 14px;"
                "font-weight: bold;"
                );
    MenuBar = new QMenuBar(this);
    MenuBar->setGeometry(0,0,valorZoom*10,30);
    Menu = new QMenu("&File",this);
    Menu2 = new QMenu("&Visualizar",this);
    MenuBar->addMenu(Menu);
    MenuBar->addMenu(Menu2);
    MenuBar->setStyleSheet(
                "QMenuBar{"
                " background-color: #feb236;"
                "width:174px;"
                "height: 26px;}"
                "QMenuBar::item{"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: black;"
                "}"

                );

    Menu->setStyleSheet(
                " background-color: #feb236;"

                );
    Menu2->setStyleSheet(
                " background-color: #feb236;"

                );

    JogoXadrez = new QAction("Jogo &Xadrez", this);
    JogoXadrez->setShortcut(Qt::CTRL + Qt::Key_X);
    JogoXadrez->setIcon(QIcon(QPixmap(ico_xadrez)));

    addPecasXadrez = new QAction("Add &Peça Xadrez", this);
    addPecasXadrez->setShortcut(Qt::CTRL + Qt::Key_P);
    addPecasXadrez->setIcon(QIcon(QPixmap(ico_nova_peca)));

    JogoDama = new QAction("Jogo &Dama", this);
    JogoDama->setShortcut(Qt::CTRL + Qt::Key_D);
    JogoDama->setIcon(QIcon(QPixmap(ico_dama)));

    AbrirJogo = new QAction("&Abrir", this);
    AbrirJogo->setShortcut(Qt::CTRL + Qt::Key_A);
    AbrirJogo->setIcon(QIcon(QPixmap(ico_abrir)));

    SalvarJogo = new QAction("&Salvar", this);
    SalvarJogo->setShortcut(Qt::CTRL + Qt::Key_S);
    SalvarJogo->setIcon(QIcon(QPixmap(ico_salvar)));

    Sair = new QAction("Sai&r", this);
    Sair->setShortcut(Qt::ALT + Qt::Key_F4);
    Sair->setIcon(QIcon(QPixmap(ico_sair)));

    Zoom = new QAction("Alterar &Zoom", this);
    Zoom->setShortcut(Qt::CTRL + Qt::Key_Z);
    Zoom->setIcon(QIcon(QPixmap(ico_zoom)));

    Menu->addAction(JogoXadrez);
    Menu->addAction(addPecasXadrez);
    Menu->addSeparator();
    Menu->addAction(JogoDama);
    Menu->addSeparator();
    Menu->addAction(AbrirJogo);
    Menu->addAction(SalvarJogo);
    Menu->addSeparator();
    Menu->addAction(Sair);

    Menu2->addAction(Zoom);


    addPecasXadrez->setEnabled(false);
    AbrirJogo->setEnabled(false);
    SalvarJogo->setEnabled(false);

    connect(JogoXadrez, SIGNAL(triggered()), this, SLOT(criaTabXadrez()));
    connect(addPecasXadrez, SIGNAL(triggered()), this, SLOT(addPecasX()));
    connect(JogoDama, SIGNAL(triggered()), this, SLOT(criaTabDama()));
    connect(Sair, SIGNAL(triggered()), this, SLOT(fecharPrograma()));
    connect(SalvarJogo, SIGNAL(triggered()), this, SLOT(salvaJogo()));
    connect(AbrirJogo, SIGNAL(triggered()), this, SLOT(abrirJogo()));

    connect(Zoom, SIGNAL(triggered()), this, SLOT(zoom()));


    TX = TabXadrez::getInstacia();
    TX->setPosicao(valorZoom);
    TD = tabDama::getInstacia();
    TD->setPosicao(valorZoom);

}

// fecharPrograma: cria uma Qwidget janelaSair, com Qpushbutons para as opcoes, salvar, nao salvar, cancelar
void  MainWindow::fecharPrograma()
{
    janelaSair = new QWidget(this);
    janelaSair->setWindowTitle("Deseja realmente sair?");
    janelaSair->setGeometry((TX->getPosicao()+(TX->getPosicao()*2)),(TX->getPosicao()*4)+TX->getPosicao()/3,(TX->getPosicao()*4)
                            ,TX->getPosicao());
    janelaSair->setStyleSheet(
                "background-color: #FF8C00;"
                "font-family: Arial;"
                "font-size: 14px;"
                "font-weight: bold;"

                "border-width: 2px;"
                "border-style: solid;"
                "border-color: black;"

                );

    salvar = new QPushButton("Salvar");
    naoSalvar = new QPushButton("Nao Salvar");
    cancelar = new QPushButton("Cancelar");

    layout1 = new QHBoxLayout;

    layout1->addWidget(salvar);
    layout1->addWidget(naoSalvar);
    layout1->addWidget(cancelar);

    connect(salvar, SIGNAL(clicked()), this, SLOT(salvaJogo_janelaSair()));
    connect(naoSalvar, SIGNAL(clicked()), this, SLOT(naoSalvaJogo_janelaSair()));
    connect(cancelar, SIGNAL(clicked()), this, SLOT(cancelar_janelaSair()));

    if (!(TX->getVisivel())){
        naoSalvar->setText("Sim");
        salvar->setVisible(false);
    }

    janelaSair->setLayout(layout1);
    janelaSair->show();

}

// salvaJogo_janelaSair: chama a função salvar jogo e fecha a janelaSair
void MainWindow::salvaJogo_janelaSair()
{
    salvaJogo();
    janelaSair->close();
    this->close();
}

// naoSalvaJogo_janelaSair: fecha a janelaSair e fecha a MainWindow
void MainWindow::naoSalvaJogo_janelaSair()
{
    janelaSair->close();
    this->close();
}

// cancelar_janelaSair: fecha a janelaSair
void MainWindow::cancelar_janelaSair()
{
    janelaSair->close();
}

//addPecasX: cria a QWidget janelaAddPx, espera do usuario que escolha um tipo de peca na QComboBox, e defina a posicao através do
// QSpinBox, quando o usuario clicar no QPushButton adicionarPeca, chama os metodos que constroem as pecas
void MainWindow::addPecasX()
{
    janelaAddPX = new QWidget(this);
    janelaAddPX->setGeometry((TX->getPosicao()*3)+(TX->getPosicao()/2),(TX->getPosicao()*3)+TX->getPosicao()/2,TX->getPosicao()
                             ,TX->getPosicao());
    janelaAddPX->setStyleSheet(
                "background-color: #feb236;"
                "font-family: Arial;"
                "font-size: 14px;"
                "font-weight: bold;"

                );
    opcaoDePecas = new QComboBox;
    layout2 = new QFormLayout;
    adicionarPeca = new QPushButton("Adicionar", this);
    selecionarPosX = new QSpinBox;
    selecionarPosY = new QSpinBox;
    texto1 = new QLabel;
    texto2 = new QLabel;
    texto3 = new QLabel;

    texto1->setText("\n   Pos x:");
    texto2->setText("\n   Pos y:");
    texto3->setText("\n");

    selecionarPosX->setMaximum(7);
    selecionarPosX->setMinimum(0);
    selecionarPosY->setMaximum(7);
    selecionarPosY->setMinimum(0);

    janelaAddPX->setWindowTitle("Add Peça Xadrez");
    janelaAddPX->setFixedSize(225,225);

    opcaoDePecas->addItem("Torre");
    opcaoDePecas->addItem("Rainha");
    opcaoDePecas->addItem("Bispo");
    opcaoDePecas->addItem("Cavalo");

    layout2->addWidget(opcaoDePecas);
    layout2->addRow(texto1);
    layout2->addWidget(selecionarPosX);
    layout2->addRow(texto2);
    layout2->addWidget(selecionarPosY);
    layout2->addRow(texto3);
    layout2->addWidget(adicionarPeca);

    janelaAddPX->setLayout(layout2);


    janelaAddPX->show();

    connect(adicionarPeca, SIGNAL(clicked()),this, SLOT(escolherPosicao()));


}


void MainWindow::zoom()
{
    janela_alterar_zoom = new QWidget(this);
    janela_alterar_zoom->setGeometry((TX->getPosicao()*3)+(TX->getPosicao()/2),(TX->getPosicao()*3)+TX->getPosicao()/2,TX->getPosicao()
                             ,TX->getPosicao());
    janela_alterar_zoom->setStyleSheet(
                "background-color: #feb236;"
                "font-family: Arial;"
                "font-size: 14px;"
                "font-weight: bold;"

                );

    layout2 = new QFormLayout;
    confirmarZoom = new QPushButton("Alterar", this);
    selecionarZoom = new QSpinBox;

    texto1 = new QLabel;


    texto1->setText("\n Alterar Zoom (50-200):");


    selecionarZoom->setMaximum(200);
    selecionarZoom->setMinimum(50);
    selecionarZoom->setValue(valorZoom);


    janela_alterar_zoom->setWindowTitle("Alterar Zoom");
    janela_alterar_zoom->setFixedSize(225,120);



    layout2->addRow(texto1);
    layout2->addWidget(selecionarZoom);

    layout2->addWidget(confirmarZoom);

    janela_alterar_zoom->setLayout(layout2);


    janela_alterar_zoom->show();


    connect(confirmarZoom, SIGNAL(clicked()),this, SLOT(alterarZoom()));


}

void MainWindow::alterarZoom()
{
    valorZoom = selecionarZoom->value();

    setFixedSize(valorZoom*10,valorZoom*10);
    MenuBar->setGeometry(0,0,valorZoom*10,30);
    TX = TabXadrez::getInstacia();
    TX->setPosicao(valorZoom);
    TD = tabDama::getInstacia();
    TD->setPosicao(valorZoom);
    janela_alterar_zoom->close();
    update();
}


// salvaJogo: percorre o vetor pecasxadrez, e verifica se existe alguma peca, se existir guarda ela dentro de um txt, especificando o tipo da peca
void MainWindow::salvaJogo()
{

    QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar Jogo", caminho, "(*.txt)");
    string nomeJogo;
    nomeJogo = fileName.toStdString();
    FILE *saveGame;
    saveGame = fopen(nomeJogo.c_str(), "w");


    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(TX->temPecaXadrez(i,j)==true)
            {
                for(unsigned int k = 0; k<TX->vetorPecas.size(); k++)
                {
                    if(TX->vetorPecas[k]->getPosicaoX()==i and TX->vetorPecas[k]->getPosicaoY()==j)
                        fprintf(saveGame, "%d", TX->vetorPecas[k]->getTipoPeca());
                }

            }
            else
            {
                fprintf(saveGame, "%d", 0);
            }
        }
    }


    fclose(saveGame);
}


// salvaJogo: percorre o vetor pecasxadrez, e verifica se existe alguma peca, se existir chama o respectivo metodo de construcao, olhando para o valor
//do atributo tipo da peca
void MainWindow::abrirJogo()
{
    QString caminho = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, "Salvar Jogo", caminho, "(*.txt)");
    string nomeJogo;
    nomeJogo = fileName.toStdString();
    FILE *abrirGame;
    abrirGame = fopen(nomeJogo.c_str(), "r");

    if (abrirGame!=nullptr){
        TX->vetorPecas.clear();

        for(int i=0;i<8;i++){
            for(int j=0;j<8; j++){

                int pieceTest=fgetc(abrirGame);
                switch (pieceTest) {
                case '0':
                    break;
                case '1':
                    criaTorre(i,j);
                    break;
                case '2':
                    criaRainha(i, j);
                    break;
                case '3':
                    criaBispo(i, j);
                    break;
                case '4':
                    criaCavalo(i,j);
                    break;
                default:
                    break;
                }
            }
        }


    }
    else{
        QMessageBox err;
        err.setText("Save is Empty");
        err.setGeometry(100, 35, 80, 30);
        err.exec();
    }
    fclose(abrirGame);
}

// escolherPosicao: recebe qual peca deve ser construida atraves de um connect no metodo addPecasX e analisa qual o tipo de peca deve ser construido
// chama a funcao que constroi a peça especificada e fecha a janelaAddPX
void MainWindow::escolherPosicao()
{


    if(opcaoDePecas->currentText()=="Torre")
    {
        criaTorre(selecionarPosX->value(),selecionarPosY->value());
    }

    if(opcaoDePecas->currentText()=="Rainha")
    {
        criaRainha(selecionarPosX->value(),selecionarPosY->value());
    }

    if(opcaoDePecas->currentText()=="Bispo")
    {
        criaBispo(selecionarPosX->value(),selecionarPosY->value());
    }

    if(opcaoDePecas->currentText()=="Cavalo")
    {
        criaCavalo(selecionarPosX->value(),selecionarPosY->value());
    }

    janelaAddPX->close();
    update();
}


//criaRainha: verifica se existe uma peca ja existente na posicao usa um trycatch, se ja existir uma peca da trow em erro, que exibe uma QMessageBox
//explicando que é impossivel colocar uma peca naquela posição, caso contraio, aloca a peca, e guarda no vetor de pecas.
void MainWindow::criaRainha(int x, int y)
{
    try {
        string erro;
        if(TX->temPecaXadrez(x, y)==true)
            throw erro;
        else
        {
            novaRainha = new rainha(x, y, 2);
            TX->vetorPecas.push_back(novaRainha);
        }
    } catch (string erro) {
        QMessageBox *sobreposicao = new QMessageBox;
        sobreposicao->setGeometry((TX->getPosicao()*4),(TX->getPosicao()*5), 0, 0);
        sobreposicao->setText("Impossivel inserir Rainha");

        sobreposicao->setStyleSheet(
                    "background-color: #feb236;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    );

        sobreposicao->show();
    }
}

//criaTorre: identico ao criaRainha
void MainWindow::criaTorre(int x, int y)
{

    try {
        string erro;
        if(TX->temPecaXadrez(x, y)==true)
            throw erro;
        else
        {
            novaTorre = new torre(x, y, 1);
            TX->vetorPecas.push_back(novaTorre);
        }
    } catch (string erro) {
        QMessageBox *sobreposicao = new QMessageBox(this);
        sobreposicao->setGeometry((TX->getPosicao()*4),(TX->getPosicao()*5), 0, 0);
        sobreposicao->setText("Impossivel inserir Torre");

        sobreposicao->setStyleSheet(
                    "background-color: #feb236;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    );
        sobreposicao->show();
    }

}

//criaBispo: identico ao criaRainha
void MainWindow::criaBispo(int x, int y)
{
    try {
        string erro;
        if(TX->temPecaXadrez(x, y)==true)
            throw erro;
        else
        {
            novoBispo = new bispo(x, y, 3);
            TX->vetorPecas.push_back(novoBispo);
        }
    } catch (string erro) {
        QMessageBox *sobreposicao = new QMessageBox;
        sobreposicao->setGeometry((TX->getPosicao()*4),(TX->getPosicao()*5), 0, 0);
        sobreposicao->setText("Impossivel inserir Bispo");

        sobreposicao->setStyleSheet(
                    "background-color: #feb236;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    );
        sobreposicao->show();
    }
}

//criaCavalo: identico ao criaRainha
void MainWindow::criaCavalo(int x, int y)
{
    try {
        string erro;
        if(TX->temPecaXadrez(x, y)==true)
            throw erro;
        else
        {
            novoCavalo = new cavalo(x, y, 4);
            TX->vetorPecas.push_back(novoCavalo);
        }
    } catch (string erro) {
        QMessageBox *sobreposicao = new QMessageBox;
        sobreposicao->setGeometry((TX->getPosicao()*4),(TX->getPosicao()*5), 0, 0);
        sobreposicao->setText("Impossivel inserir Cavalo");

        sobreposicao->setStyleSheet(
                    "background-color: #feb236;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    );
        sobreposicao->show();
    }

}

//criaTabXadrez::verifica se existe um tabuleiro de dama ja existente, caso nao exista, cria o tabuleiro de xadrez, se existir cria
//uma janela trocar_tab_tab que da 2 opcoes de QPushButtons, sendo uma de continuar e outra de cancelar
void MainWindow::criaTabXadrez()
{

    if(TD->getVisivel()==true)
    {
        addPecasXadrez->setEnabled(true);

        janela_trocar_tab = new QWidget(this);
        janela_trocar_tab->setWindowTitle("Salvar Progresso?");
        janela_trocar_tab->setGeometry((TX->getPosicao()+(TX->getPosicao()*2)),(TX->getPosicao()*4)+TX->getPosicao()/3,(TX->getPosicao()*4)
                                       ,TX->getPosicao());
        janela_trocar_tab->setStyleSheet(
                    "background-color: #FF8C00;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    "border-width: 2px;"
                    "border-style: solid;"
                    "border-color: black;"


                    );
        continuar = new QPushButton("cotinuar");
        cancelar = new QPushButton("cancelar");

        layout1 = new QHBoxLayout;

        layout1->addWidget(continuar);
        layout1->addWidget(cancelar);

        janela_trocar_tab->setLayout(layout1);
        janela_trocar_tab->show();

        connect(continuar, SIGNAL(clicked()), this, SLOT(trocaTab_Dama_xadrez()));
        connect(cancelar, SIGNAL(clicked()), this, SLOT(cancela_trocaTab_Dama_xadrez()));


    }
    else
    {
        addPecasXadrez->setEnabled(true);

        TX->setVisivel(true);
        AbrirJogo->setEnabled(true);
        SalvarJogo->setEnabled(true);
        this->update();
    }

}

//criaTabDAma::verifica se existe um tabuleiro de xadrez ja existente, caso nao exista, cria o tabuleiro de dama, se existir cria
//uma janela trocar_tab_tab que da 2 opcoes de QPushButtons, sendo uma de salvar e outra de nao salvar
void MainWindow::criaTabDama()
{
    if(TX->getVisivel()==true)
    {

        addPecasXadrez->setEnabled(false);

        janela_trocar_tab = new QWidget(this);
        janela_trocar_tab->setWindowTitle("Salvar Progresso?");
        janela_trocar_tab->setGeometry((TX->getPosicao()+(TX->getPosicao()*2)),(TX->getPosicao()*4)+TX->getPosicao()/3,(TX->getPosicao()*4)
                                       ,TX->getPosicao());
        janela_trocar_tab->setStyleSheet(
                    "background-color: #FF8C00;"
                    "font-family: Arial;"
                    "font-size: 14px;"
                    "font-weight: bold;"

                    "border-width: 2px;"
                    "border-style: solid;"
                    "border-color: black;"


                    );
        salvar = new QPushButton("Salvar");
        naoSalvar = new QPushButton("Nao Salvar");

        layout1 = new QHBoxLayout;

        layout1->addWidget(salvar);
        layout1->addWidget(naoSalvar);

        janela_trocar_tab->setLayout(layout1);
        janela_trocar_tab->show();

        connect(salvar, SIGNAL(clicked()), this, SLOT(salvaJogo_trocaTab_xadrez_Dama()));
        connect(naoSalvar, SIGNAL(clicked()), this, SLOT(naoSalvaJogo_trocaTab_xadrez_Dama()));

    }
    else
    {

        addPecasXadrez->setEnabled(false);
        TD->vetorPecasDama.clear();
        TD->setVisivel(true);
        AbrirJogo->setEnabled(false);
        SalvarJogo->setEnabled(false);
        criaDamaV();
        criaDamaB();
        this->update();
    }

}

//salvaJogo_trocaTab_xadrez_Dama: salva o jogo de xadrez e cria o tabuleiro de dama
void MainWindow::salvaJogo_trocaTab_xadrez_Dama()
{
    janela_trocar_tab->close();
    salvaJogo();
    TX->vetorPecas.clear();
    TD->vetorPecasDama.clear();
    TD->setVisivel(true);
    TX->setVisivel(false);
    criaDamaV();
    criaDamaB();
    AbrirJogo->setEnabled(false);
    SalvarJogo->setEnabled(false);
    this->update();

}

//naoSalvaJogo_trocaTab_xadrez_Dama: nao salva o jogo de xadrez e cria o tabuleiro de dama
void MainWindow::naoSalvaJogo_trocaTab_xadrez_Dama()
{

    janela_trocar_tab->close();
    TX->vetorPecas.clear();
    TD->vetorPecasDama.clear();
    TD->setVisivel(true);
    TX->setVisivel(false);
    criaDamaV();
    criaDamaB();
    AbrirJogo->setEnabled(false);
    SalvarJogo->setEnabled(false);
    this->update();
}

//trocaTab_Dama_xadrez: apaga o tabuleiro de dama e constroi o de xadrez
void MainWindow::trocaTab_Dama_xadrez()
{
    janela_trocar_tab->close();
    TD->vetorPecasDama.clear();
    TX->setVisivel(true);
    TD->setVisivel(false);
    AbrirJogo->setEnabled(true);
    SalvarJogo->setEnabled(true);
    this->update();

}

//trocaTab_Dama_xadrez: fecha janale_trocar_tab
void MainWindow::cancela_trocaTab_Dama_xadrez()
{
    janela_trocar_tab->close();
    this->update();
}

//criaDamaV: alloca todas as peças de dama vermelhas e coloca elas na posicao de inicio de jogo
void MainWindow::criaDamaV()
{

    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<3;j++)
        {
            if((i%2==0)&&(j%2==0))
            {
                novaDamaV = new damaVermelha(i,j);
                TD->vetorPecasDama.push_back(novaDamaV);
            }
            else if((i%2!=0)&&(j%2!=0))
            {
                novaDamaV = new damaVermelha(i,j);
                TD->vetorPecasDama.push_back(novaDamaV);
            }
        }
    }

}

//criaDamaB: alloca todas as peças de dama brancas e coloca elas na posicao de inicio de jogo
void MainWindow::criaDamaB()
{
    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=7;j>4;j--)
        {
            if((i%2==0)&&(j%2==0))
            {
                novaDamaB = new damaBranca(i,j);
                TD->vetorPecasDama.push_back(novaDamaB);
            }
            else if((i%2!=0)&&(j%2!=0))
            {
                novaDamaB = new damaBranca(i,j);
                TD->vetorPecasDama.push_back(novaDamaB);
            }
        }
    }

}

//turno: verifica o atributo de turno, e pinta qual jogador que esta na vez de fazer a jogado
void MainWindow::turno(QPainter &painter, tabDama *tab)
{
    QBrush turno_damaVermelha (Qt::red);
    QBrush turno_damaBranca ("#524c4c");
    QBrush espera(Qt::black);

    for(unsigned int i = 0; i < tab->vetorPecasDama.size(); i++)
    {
        if(tab->vetorPecasDama[i]->getTurno()==true and tab->vetorPecasDama[i]->getTipoPeca()==0)
        {

            painter.setBrush(turno_damaVermelha);
            painter.drawRect(QRect(tab->getPosicao()-tab->getPosicao(),(tab->getPosicao()),tab->getPosicao(),tab->getPosicao()));
        }
        if(tab->vetorPecasDama[i]->getTurno()==false and tab->vetorPecasDama[i]->getTipoPeca()==0)
        {

            painter.setBrush(espera);
            painter.drawRect(QRect(tab->getPosicao()-tab->getPosicao(),(tab->getPosicao()),tab->getPosicao(),tab->getPosicao()));
        }
        if(tab->vetorPecasDama[i]->getTurno()==true and tab->vetorPecasDama[i]->getTipoPeca()==1)
        {

            painter.setBrush(turno_damaBranca);
            painter.drawRect(QRect(tab->getPosicao()+(tab->getPosicao()*8),(tab->getPosicao()+tab->getPosicao()*7),tab->getPosicao(),tab->getPosicao()));
        }
        if(tab->vetorPecasDama[i]->getTurno()==false and tab->vetorPecasDama[i]->getTipoPeca()==1)
        {

            painter.setBrush(espera);
            painter.drawRect(QRect(tab->getPosicao()+(tab->getPosicao()*8),(tab->getPosicao()+tab->getPosicao()*7),tab->getPosicao(),tab->getPosicao()));
        }
    }

}

//paintevent: sobrescreve o metodo do paintEvent e chama a pintura e do tabuleiro e das peças
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    if(TX->getVisivel()==true)
    {
        TX->criaTabuleiro(painter);
        TX->defineCasa(painter);
    }

    if(TD->getVisivel()==true)
    {
        TD->criaTabuleiro(painter);
        turno(painter, TD);

    }

    for(unsigned int i =0; i<TX->vetorPecas.size(); i++)
    {

        if(TX->vetorPecas[i]->getMov()==true)
        {
            TX->vetorPecas[i]->movimento(painter, TX);
        }
    }

    if(TX->getVisivel()==true)
    {

        for(unsigned int i =0; i<TX->vetorPecas.size(); i++)
        {
            TX->vetorPecas[i]->criaPeca(painter, TX);
        }
    }

    for(unsigned int i =0; i<TD->vetorPecasDama.size(); i++)
    {

        if(TD->vetorPecasDama[i]->getMov()==true)
        {
            TD->vetorPecasDama[i]->movimento(painter, TD);
        }
    }

    if(TD->getVisivel()==true)
    {

        for(unsigned int i =0; i<TD->vetorPecasDama.size(); i++)
        {
            TD->vetorPecasDama[i]->criaPeca(painter, TD);
        }
    }
}

//mousePressEvent: sobrescreve o metodo do mousePressEvent para verificar qual peça deve ser selecionada, e qual sera seu proximo movimento
void MainWindow::mousePressEvent(QMouseEvent *event)
{


    this->update();

    int x1, y1, x2, y2;

    x1 = event->x();
    y1 = event->y();

    x2 = event->x();
    y2 = event->y();


    x1 = (x1/TX->getPosicao())-1;
    y1 = (y1/TX->getPosicao())-1;

    x2 = (x2/TD->getPosicao())-1;
    y2 = (y2/TD->getPosicao())-1;


    if(TX->getSelecionado()==false)
    {

        for(unsigned int i =0; i<TX->vetorPecas.size(); i++)
        {

            if((TX->vetorPecas[i]->getPosicaoX()==x1) and (TX->vetorPecas[i]->getPosicaoY()==y1))
            {
                TX->setSelecionado(true);
                TX->vetorPecas[i]->setMov(true);

            }
        }
    }
    else
    {
        for(unsigned int i =0; i<TX->vetorPecas.size(); i++)
        {
            if(TX->vetorPecas[i]->getMov()==true)
            {
                TX->vetorPecas[i]->setMov(false);
                TX->vetorPecas[i]->setPosicaoX_Y(x1, y1, TX);
                TX->setSelecionado(false);
            }

        }
    }

    if(TD->getSelecionado()==false)
    {

        for(unsigned int i =0; i<TD->vetorPecasDama.size(); i++)
        {

                if((TD->vetorPecasDama[i]->getPosicaoX()==x2) and (TD->vetorPecasDama[i]->getPosicaoY()==y2))
                {
                    if(TD->vetorPecasDama[i]->getTurno()==true)
                    {
                    TD->setSelecionado(true);
                    TD->vetorPecasDama[i]->setMov(true);
                    }
                }

        }
    }
    else
    {
        for(unsigned int i =0; i<TD->vetorPecasDama.size(); i++)
        {
            if(TD->vetorPecasDama[i]->getMov()==true)
            {
                TD->vetorPecasDama[i]->setMov(false);
                TD->vetorPecasDama[i]->setPosicaoX_Y(x2, y2, TD->vetorPecasDama[i]->getPosicaoX(), TD->vetorPecasDama[i]->getPosicaoY(), TD);
                TD->setSelecionado(false);
            }

        }
    }

    update();
}
