#include "MainFen.h"

MaFenetre::MaFenetre()
{
    setWindowTitle("Abedi_Analyseur");
    QMessageBox::information(this,"Hello","Bienvenue dans le statisticien de Abedi_Technology");
    checkfile = new QPushButton;
    droits = new QLabel;
    quitter = new QPushButton;
    flux = new QTextEdit;
    finLay = new QVBoxLayout;
    monLay = new QVBoxLayout;
    Hlay = new QHBoxLayout;
    Blay = new QHBoxLayout;
    logo = new QLabel;
    source = new QLabel;
    fileName = new QLineEdit;
    matching = new QPushButton;
    matching->setText("Procéder");
    checkfile->setText("Choisir_un_fichier");
    droits->setText("Copyright © 2016 Abedi_Technology !Tous droits Réservés\nVersion: 1.0.0.1");
    quitter->setText("Quitter");
    logo->setPixmap(QPixmap("logo.png"));
    flux->setReadOnly(true);
    Hlay->addWidget(flux);
    monLay->addWidget(logo);
    monLay->addWidget(checkfile);
    monLay->addWidget(fileName);
    monLay->addWidget(matching);
    monLay->addWidget(source);
    Hlay->addLayout(monLay);
    Blay->addWidget(droits);
    Blay->addWidget(quitter);
    finLay->addLayout(Hlay);
    finLay->addLayout(Blay);
    setLayout(finLay);
    flux->append("frequence des lettres en francais !");
    flux->append("A->9,42%");
    flux->append("B->1,02%");
    flux->append("C->2,64%");
    flux->append("D->3,39%");
    flux->append("E->15,87%");
    flux->append("F->0,95%");
    flux->append("G->1,04%");
    flux->append("H->0,77%");
    flux->append("I->8,41%");
    flux->append("J->0,89%");
    flux->append("K->0,01%");
    flux->append("L->5,34%");
    flux->append("M->3,24%");
    flux->append("N->7,15%");
    flux->append("O->5,14%");
    flux->append("P->2,86%");
    flux->append("Q->1,06%");
    flux->append("R->6,46%");
    flux->append("S->7,90%");
    flux->append("T->7,26%");
    flux->append("U->6,24%");
    flux->append("V->2,15%");
    flux->append("W->0,01%");
    flux->append("X->0,30%");
    flux->append("Y->0,24%");
    flux->append("Z->0,32%");
    source->setText("Sources : <a href=https://fr.m.wikipedia.org/wikiAnalyse_fr%C3%A9quentielle>Wikipedia</a>");
    source->setOpenExternalLinks(true);
    QObject::connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(checkfile,SIGNAL(clicked()),this,SLOT(choisirFichier()));
    QObject::connect(matching,SIGNAL(clicked()),this,SLOT(analyzer()));
}
void MaFenetre::choisirFichier()
{
    fileWay = QFileDialog::getOpenFileName(this,"Choisir un fichier",QString(),"Textes (*.txt)");
    fileName->setText(fileWay);
    fileName->setReadOnly(true);
}
void MaFenetre::analyzer()
{
    if(fileName->text().toStdString() == "")
    {
        QMessageBox::critical(this,"Grrrr","Veuillez choisir un fichier à analyser !!!");
        return;
    }
    std::string addresse = fileName->text().toStdString();
    abedi.open(addresse.c_str());
    if(!abedi)
    {
        QMessageBox::critical(this,"Oupps","Le fichier specifie est inexistant");
        return;
    }
    char c;
    std::map<char,int> taux;
    while(abedi.get(c))
    {
        for(int i=0;i<26;i++)
        {
            if(c == maj[i])
            {
                c = tolower(c);
                i=26;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(c == lettres[i])
            {
                taux[c] += 1;
                but++;
                i=26;
            }
        }
    }
    abedi.close();
    int i=0;
    while(i<26)
    {
        valeur[i] = ((taux[lettres[i]]*100)/but);
        i++;
    }
    Resultat seni(valeur,26,this);
    seni.exec();
    setEnabled(true);
}
