#include <QApplication>
#include <QtWidgets>
#include "fenetre.h"
//#include <QWidget>
//#include <QPushButton>
//#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window1;
    window1.setFixedSize(200,200);

    QPushButton bouton("Yo James", &window1); //&window1 est le widget parent, le contenant
    QLabel labelo("James", &window1);
    bouton.setText("Click for finish");
    bouton.setToolTip("Click for Help");
    bouton.setCursor(Qt::PointingHandCursor);
    bouton.move(80, 160);
    //bouton.show();
    //labelo.show();
    window1.show();
    QObject::connect(&bouton, SIGNAL(clicked()), &app, SLOT(quit()));

    QWidget window2;
    window2.setMinimumSize(400, 400);
    Fenetre my_win(&window2);
    window2.show();

    return app.exec();
}
