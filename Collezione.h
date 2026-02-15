//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_COLLEZIONE_H
#define BLOCCONOTE_COLLEZIONE_H

#include "Note.h"
#include "Observer.h"
#include "Subject.h"

#include <list>

using namespace std;

class Collezione: public Subject {
private:
    string Nome;
    list <Note*> NoteCollezionate;
    list <Observer*> Obs;
public:
    Collezione (const string &no);
    virtual ~Collezione();

    const string& getNome() const {return Nome;}
    const list<Note*>& getNoteCollezionate() const {return NoteCollezionate;}
    void setNome(const string &no) {Nome = no;}

    void aggiungiNota(Note *n);
    void rimuoviNota(Note *n);
    void modificaNota(Note *n);

    void visualizzaNote() const;

    void notify(bool b, const string &n, const string &c, int i) override;
    void attach(Observer *o) override;
    void detach(Observer *o) override;
};

#endif //BLOCCONOTE_COLLEZIONE_H