#include "resultat.h"

Resultat::Resultat(float donnee[], int tailleTab, QWidget *parent=0):QDialog(parent)
{
    setWindowTitle("Abedi_Analyseur");
    reste = 0;
    reste1 = 0;
    kote = "abcdefghijklmnopqrstuvwxyz";
    parent->setEnabled(false);
    RHLay = new QHBoxLayout;
    RVLay = new QVBoxLayout;
    RBLay = new QHBoxLayout;
    droits = new QLabel;
    droits->setText("Copyright © 2016 Abedi_Technology !Tous Droits Réservés\nVersion: 1.0.0.1");
    for(int i=0;i<tailleTab;i++)
    {
        taunt[i].setValue(donnee[i]);
    }
    for(int i=0;i<14;i++)
    {
        tempo = toupper(kote[i]);
        contein[reste1].addRow(lado.fromStdString(tempo),&taunt[i]);
        reste +=1;
    }
    reste1 +=1;
    for(int i=reste;i<tailleTab;i++)
    {
        tempo = toupper(kote[i]);
        contein[reste1].addRow(lado.fromStdString(tempo),&taunt[i]);
    }
    for(int i=0;i<26;i++)
    {
        taunt[i].setSuffix("%");
    }
    RHLay->addLayout(&contein[0]);
    RHLay->addLayout(&contein[1]);
    RBLay->addWidget(droits);
    RVLay->addLayout(RHLay);
    RVLay->addLayout(RBLay);
    setLayout(RVLay);
}
