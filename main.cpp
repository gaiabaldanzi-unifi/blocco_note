/*  Classi che rappresentano note (es. Bear / Evernote).
Ogni nota è composta da titolo e testo, può essere bloccata per evitarne cancellazione/modifica
e fa parte di una collezione specificata con nome. Può anche far parte di una collezione di note importanti
oltre che di una collezione specifica. Usare Observer per indicare quante note stanno in una collezione. */

#include <iostream>
#include <string>
#include <list>

#include "Note.h"
#include "Collezione.h"
#include "NoteImportanti.h"
#include "ContatoreNote.h"

using namespace std;

int main() {
    ContatoreNote* obs = new ContatoreNote();
    Collezione* Tutte = new Collezione("Tutte");
    Tutte->attach(obs);

    NoteImportanti* singletonImp = NoteImportanti::getInstance();
    singletonImp->attach(obs);

    list<Collezione*> altreCollezioni;
    altreCollezioni.push_back(Tutte);

    char a;
    cout << "Crea una nuova nota" << endl;
    do {
        string tit, tes;
        cout << "Inserisci il titolo: ";
        getline(cin,tit);
        cout << "Inserisci il testo: ";
        getline(cin,tes);

        Note* nuovaNota = new Note(tit, tes, false);
        Tutte->aggiungiNota(nuovaNota);

        cout << "Vuoi aggiungerla a una collezione specifica? (s/n): ";
        char rispSpec;
        cin >> rispSpec;
        cin.ignore();
        if (rispSpec == 's' || rispSpec == 'S') {
            cout<<"Inserisci il nome della collezione: ";
            string nomeColl;
            getline(cin, nomeColl);

            Collezione* destinazione = nullptr;

            for (Collezione* c : altreCollezioni) {
                if (c->getNome() == nomeColl) {
                    destinazione = c;
                    break;
                }
            }
            if (destinazione == nullptr) {
                cout << "-> Creazione nuova collezione: " << nomeColl << endl;
                destinazione = new Collezione(nomeColl);
                destinazione->attach(obs);
                altreCollezioni.push_back(destinazione);
            }
            destinazione->aggiungiNota(nuovaNota);
        }

        char rispImp;
        cout << "Vuoi renderla importante? (s/n): ";
        cin >> rispImp;
        if (rispImp == 's' || rispImp == 'S') nuovaNota->setImportante(true);

        char rispBlocco;
        cout << "Vuoi bloccare la nota? (s/n): ";
        cin >> rispBlocco;
        if (rispBlocco == 's' || rispBlocco == 'S') nuovaNota->setBloccata(true);

        cout<<"Vuoi modificare una nota? (s/n): ";
        char rispMod;
        cin>>rispMod;
        cin.ignore();
        if(rispMod == 's' || rispMod == 'S') {
            char g;
            do{
                cout<<"Inserisci il titolo della nota da modificare: ";
                string titMod;
                getline(cin,titMod);

                Note* notaDaModificare = nullptr;
                for (Collezione* c : altreCollezioni) {
                    for (Note* n : c->getNoteCollezionate()) {
                        if (n->getTitolo() == titMod) {
                            c->modificaNota(n);
                            notaDaModificare = n;
                        }
                    }
                }
                if (notaDaModificare == nullptr) cout << "Nota non trovata." << endl;
                cout<<"Vuoi modificare un'altra nota? (s/n): ";
                cin>>g;
                cin.ignore();
            }while(g != 'n' && g != 'N');
        }

        cout<<"Vuoi eliminare una nota? (s/n): ";
        char rispEl;
        cin>>rispEl;
        cin.ignore();
        if(rispEl == 's' || rispEl == 'S') {
            char g;
            do{
                cout<<"Inserisci il titolo della nota da eliminare: ";
                string titEl;
                getline(cin, titEl);

                bool trovata=false;
                for (Collezione* c : altreCollezioni) {
                    list <Note*> noteAttuali=c->getNoteCollezionate();
                    for (Note* n : noteAttuali) {
                        if (n->getTitolo() == titEl) {
                            trovata=true;
                            if (n->isBloccata()) {
                                cout << "Impossibile eliminare la nota perchè è bloccata. Vuoi sbloccarla? (s/n): ";
                                char rispSblocca;
                                cin >> rispSblocca;
                                if (rispSblocca == 's' || rispSblocca == 'S') n->setBloccata(false);
                            }
                            if (!n->isBloccata()) {
                                if (n->isImportante()) n->setImportante(false);
                                c->rimuoviNota(n);
                            }
                        }
                    }
                }

                if (trovata==false) cout << "Nota non trovata." << endl;
                cout<<"Vuoi eliminare un'altra nota? (s/n): ";
                cin>>g;
                cin.ignore();
            }while(g != 'n' && g != 'N');
        }

        cout<< "Vuoi creare un'altra nota? (s/n): ";
        cin >> a;
        cin.ignore();
    }while (a != 'n' && a != 'N');

    cout << "NOTE" << endl;
    for (Collezione* c : altreCollezioni) {
        c->visualizzaNote();
    }

    cout<< "vuoi visualizzare le note importanti? (s/n): ";
    char rispVisImp;
    cin >> rispVisImp;
    if (rispVisImp == 's' || rispVisImp == 'S') {
        cout << "NOTE IMPORTANTI:" << endl;
        singletonImp->visualizzaNote();
    }

    delete obs;

    return 0;
}

