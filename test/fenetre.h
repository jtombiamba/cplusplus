#ifndef FENETRE_H
#define FENETRE_H

#include <QtWidgets>
#include <QWidget>

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    explicit Fenetre();
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();

signals:

public slots:

private:
    QPushButton * m_bouton1;
    QPushButton * m_bouton2;
    QPushButton * m_bouton3;
};

#endif // FENETRE_H
