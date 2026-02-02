/* Classi che rappresentano note (es. Bear / Evernote).
Ogni nota è composta da titolo e testo, può essere bloccata per evitarne cancellazione/modifica e
fa parte di una collezione specificata con nome. Può anche far parte di una collezione di note importanti
oltre che di una collezione specifica. Usare Observer per indicare quante note stanno in una collezione. */

#include <iostream>
#include <string>
using namespace std;

class Observer {
public:
    virtual ~Observer() {};
    virtual void update()=0;
};
class Subject {
public:
    virtual ~Subject() {};
    virtual void attach(Observer *o)=0;
    virtual void detach(Observer *o)=0;
    virtual void notify()=0;
};


class Collezione {
private:
    string Nome;
};

class Note: public Subject {
private:
    string Titolo;
    string Testo;
    bool Bloccata;
    Collezione* C;
    bool Importante;
public:
    Note (const string &ti, const string &te, Collezione* cc, bool im): Titolo(ti), Testo(te), Bloccata(false), C(cc), Importante(im) {};
    ~Note() {};

    const string getTitolo() const { return Titolo; }
    const string getTesto() const { return Testo; }
    bool isBloccata() const { return Bloccata; }
    //string getCollezione() const { return Collezione; }
    //const bool isImportante() const { return Importante; }

    void bloccata(bool a) {
        if (Bloccata = a) {cout<<"La nota è già ad "<<a<<endl;}
        else Bloccata = a;
    }
    void setTesto(const string &te) {
        if (!Bloccata) Testo = te;
        else cout<<"Impossibile modificare il testo, la nota è bloccata"<<endl;
    }
    //void setCollezione(const string &co) { if (!Bloccata) Collezione = co;  }
    void setTitolo(const string &ti) {
        if (!Bloccata) Titolo = ti;
        else cout<<"Impossibile modificare il titolo, la nota è bloccata"<<endl;
    }
};