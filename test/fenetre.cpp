#include "fenetre.h"


Fenetre::Fenetre():
    QWidget()
{
    setFixedSize(300, 300);
    m_bouton1 = new QPushButton("clisk for end", this);
    m_bouton1->move(80,160);
    QObject::connect(m_bouton1, SIGNAL(clicked()), qApp, SLOT(quit()));

}


Fenetre::Fenetre(QWidget *parent) :
    QWidget(parent)
{
    //setFixedSize(300, 300);
    m_bouton1 = new QPushButton("super");
    m_bouton2 = new QPushButton("James");
    m_bouton3 = new QPushButton("TOMBI"); //simple déclaration

    //m_bouton3 = new QPushButton("TOMBI", this); //declaration de bouton dans la fenetre mm
    //m_bouton->move(80,160);

    //Le principe des layout est de permettre de positionner de manière relative les  widgets
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_bouton1, 0, 0);
    layout->addWidget(m_bouton2, 0, 1);
    layout->addWidget(m_bouton3, 2, 2);

    this->setLayout(layout);

    QObject::connect(m_bouton3, SIGNAL(clicked()), qApp, SLOT(close()));

}

Fenetre::~Fenetre()
{
    delete m_bouton1;
    delete m_bouton2;
    delete m_bouton3;
}
