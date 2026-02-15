//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "Collezione.h"

#include <iostream>
#include <list>
using namespace std;

Collezione::Collezione (const string &no): Nome(no){};
Collezione::~Collezione(){};

void Collezione::aggiungiNota(Note *n) {
    if (n->isBloccata()) { cout<<"Impossibile aggiungere la nota "<<n->getTitolo()<<", è bloccata"<<endl; }
    else {
        NoteCollezionate.push_back(n);
        int i=NoteCollezionate.size();
        notify(true, n->getTitolo(), Nome, i);
    }
}

void Collezione::rimuoviNota(Note *n) {
    if (n->isBloccata()) cout<<"Impossibile rimuovere la nota "<<n->getTitolo()<<", è bloccata"<<endl;
    else {
        NoteCollezionate.remove(n);
        int i=NoteCollezionate.size();
        notify(false, n->getTitolo(), Nome, i);
    }
}

void Collezione::modificaNota(Note *n) {
    if (n->isBloccata()) {
        cout<<"Impossibile modificare la nota "<<n->getTitolo()<<", è bloccata. Vuoi sbloccarla? (s/n)";
        char c;
        cin>>c;
        if (c=='s' || c=='S') n->setBloccata(false);
    }
    if (!n->isBloccata()) {
        cout<<"Vuoi modificare il titolo? (s/n): ";
        char c;
        cin>>c;
        if (c=='s' || c=='S') {
            cin.ignore();
            cout<<"Inserisci il nuovo titolo: ";
            string nuovoTitolo;
            getline(cin, nuovoTitolo);
            n->setTitolo(nuovoTitolo);
        }

        cout<<"Vuoi modificare il testo? (s/n): ";
        char a;
        cin>>a;
        if (a=='s' || a=='S') {
            cin.ignore();
            cout<<"Inserisci il nuovo testo: ";
            string nuovoTesto;
            getline(cin, nuovoTesto);
            n->setTesto(nuovoTesto);
        }

        if (n->isImportante()) cout<<"La nota è attualmente importante. Vuoi renderla non importante? (s/n): ";
        else cout<<"Attualmente non è importante. Vuoi modificarla? (s/n): ";
        char b;
        cin>>b;
        if (b=='s' || b=='S') n->setImportante(!n->isImportante());

        cout<<"Vuoi bloccare la nota? (s/n): ";
        char d;
        cin>>d;
        if (d=='s' || d=='S') n->setBloccata(true);
    }
}

void Collezione::visualizzaNote() const {
    cout<<"Collezione "<<Nome<<":"<<endl;
    if (NoteCollezionate.empty()) cout<<"- Nessuna nota presente"<<endl;
    else {
        for (Note *n : NoteCollezionate) {
            cout<<"- "<<n->getTitolo();
            if (n->isBloccata()) cout<<" bloccata";
            if (n->isImportante()) cout<<" importante";
            cout<<endl;
            cout<<"Vuoi vedere il contenuto della nota? (s/n) ";
            char c;
            cin>>c;
            cin.ignore();
            if (c=='s' || c=='S') cout<<n->getTesto()<<endl;
        }
    }
}

void Collezione::notify(bool b, const string &n, const string &c, int i){
    for (Observer *o : Obs) o->update(b, n, c, i);
}

void Collezione::attach(Observer *o){Obs.push_back(o);}
void Collezione::detach(Observer *o){Obs.remove(o);}
