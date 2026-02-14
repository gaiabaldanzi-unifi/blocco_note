//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_NOTE_H
#define BLOCCONOTE_NOTE_H

#include <iostream>
#include <string>
using namespace std;

class Note {
private:
    string Titolo;
    string Testo;
    bool Bloccata;
    bool Importante;
public:
    Note (const string &ti, const string &te, bool im);
    ~Note();

    const string getTitolo() const {return Titolo;}
    const string getTesto() const {return Testo;}
    bool isBloccata() const {return Bloccata;}
    //const bool isImportante() const {return Importante;}

    void bloccata(bool a);
    void setTesto(const string &te);
    void setTitolo(const string &ti);
};

#endif //BLOCCONOTE_NOTE_H