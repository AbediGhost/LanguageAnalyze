#ifndef MAINFEN_H
#define MAINFEN_H

#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <string>
#include "resultat.h"
class MaFenetre : public QWidget
{
    Q_OBJECT
public:
    MaFenetre();
private slots:
    void choisirFichier();
    void analyzer();
private:
    std::ifstream abedi;
    float valeur[26];
    std::string lettres = "abcdefghijklmnopqrstuvwxyz";
    std::string maj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QPushButton *checkfile;
    QString fileWay;
    QLabel *droits;
    QPushButton *quitter;
    QTextEdit *flux;
    QVBoxLayout *finLay;
    QVBoxLayout *monLay;
    QHBoxLayout *Hlay;
    QHBoxLayout *Blay;
    QLabel *logo;
    QLineEdit *fileName;
    QPushButton *matching;
    double but;
    QLabel *source;
};

#endif // MAINFEN_H
