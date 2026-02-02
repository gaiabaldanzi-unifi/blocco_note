/* Classi che rappresentano note (es. Bear / Evernote).
Ogni nota è composta da titolo e testo, può essere bloccata per evitarne cancellazione/modifica e
fa parte di una collezione specificata con nome. Può anche far parte di una collezione di note importanti
oltre che di una collezione specifica. Usare Observer per indicare quante note stanno in una collezione. */

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(bool b, const string &n, const string &c)=0;
};
class Subject {
public:
    virtual ~Subject() {};
    virtual void attach(Observer *o)=0;
    virtual void detach(Observer *o)=0;
    virtual void notify(bool b, const string &n, const string &c)=0;
};

class Note {
private:
    string Titolo;
    string Testo;
    bool Bloccata;
    bool Importante;
public:
    Note (const string &ti, const string &te, bool im): Titolo(ti), Testo(te), Bloccata(false), Importante(im) {};
    ~Note() {};

    const string getTitolo() const { return Titolo; }
    const string getTesto() const { return Testo; }
    bool isBloccata() const { return Bloccata; }
    //const bool isImportante() const { return Importante; }

    void bloccata(bool a) {
        if (Bloccata = a) {cout<<"La nota è già ad "<<a<<endl;}
        else Bloccata = a;
    }
    void setTesto(const string &te) {
        if (!Bloccata) Testo = te;
        else cout<<"Impossibile modificare il testo, la nota è bloccata"<<endl;
    }

    void setTitolo(const string &ti) {
        if (!Bloccata) Titolo = ti;
        else cout<<"Impossibile modificare il titolo, la nota è bloccata"<<endl;
    }
};

class Collezione: public Subject {
private:
    string Nome;
    list <Note*> NoteCollezionate;
    list <Observer*> Obs;
public:
    Collezione (const string &no): Nome(no) {};
    ~Collezione() {};

    const string getNome() const { return Nome; }
    void setNome(const string &no) { Nome = no; }

    void aggiungiNota(Note *n) {
        NoteCollezionate.push_back(n);
        notify(1, n->getTitolo(), Nome);
    }
    void rimuoviNota(Note *n) {
        NoteCollezionate.remove(n);
        notify(0, n->getTitolo(), Nome);
    }

    void notify(bool b, const string &n, const string &c) override {
        for (Observer *o : Obs) {
            o->update(b, n, c);
        }
    }
    void attach(Observer *o) override {
        Obs.push_back(o);
    }
    void detach(Observer *o) override {
        Obs.remove(o);
    }
};

class ContatoreNote: public Observer {
private:
    int count;
public:
    ContatoreNote(): count(0) {};
    ~ContatoreNote() {};
    void update(bool b, const string &n, const string &c) override {
        if (b) {
            count++;
            cout<<"Nella collezione "<<c<<" è stata aggiunta la nota "<<n<<". Ora ci sono "<<count<<" note."<<endl;
        }
        else {
            count--;
            cout<<"Nella collezione "<<c<<" è stata rimossa la nota "<<n<<". Ora ci sono "<<count<<" note."<<endl;
        }
    }
};