#ifndef RESULTAT_H
#define RESULTAT_H

#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QSpinbox>
#include <QDoubleSpinBox>

class Resultat : public QDialog
{
public:
    Resultat(float donnee[], int tailleTab,QWidget *parent);
private:
    QDoubleSpinBox taunt[26];
    QFormLayout contein[2];
    std::string adeline[26];
    QHBoxLayout *RHLay;
    QVBoxLayout *RVLay;
    QHBoxLayout *RBLay;
    QLabel *droits;
    int reste;
    int reste1;
    std::string kote;
    std::string tempo;
    const QString lado;
};

#endif // RESULTAT_H
