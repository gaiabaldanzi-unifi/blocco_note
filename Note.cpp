//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "Note.h"
#include "NoteImportanti.h"

Note::Note (const string &ti, const string &te, bool im): Titolo(ti), Testo(te), Bloccata(false), Importante(im) {};
Note::~Note(){};

void Note:: setBloccata(bool a) {
    if (Bloccata == a) cout<<"La nota è già ad "<<a<<endl;
    else Bloccata = a;
}
void Note:: setTesto(const string &te) {
    if (!Bloccata) Testo = te;
    else cout<<"Impossibile modificare il testo, la nota è bloccata"<<endl;
}

void Note:: setTitolo(const string &ti) {
    if (!Bloccata) Titolo = ti;
    else cout<<"Impossibile modificare il titolo, la nota è bloccata"<<endl;
}

void Note::setImportante(bool im) {
    if (Bloccata) cout<<"Impossibile modificare l'importanza, la nota è bloccata"<<endl;
    else if (Importante == im)cout<<"La nota è già ad "<<im<<endl;
    else {
        Importante = im;
        if (Importante) NoteImportanti::getInstance()->aggiungiNota(this);
        else NoteImportanti::getInstance()->rimuoviNota(this);
    }
}

