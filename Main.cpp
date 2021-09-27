#include<QApplication>
#include "mainwindow.h"

int main (int argc, char* argv[])
{
        QApplication app(argc, argv);
        //app.setStyle("Fusion");
        MainWindow wnd;
        wnd.show();
        app.exec();
        return 0;

}
