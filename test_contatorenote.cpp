//
// Created by Gaia Baldanzi on 15/02/26.
//

#include <gtest/gtest.h>
#include "Collezione.h"
#include "Note.h"
#include "ContatoreNote.h"

TEST(ObserverTest, NotificaContatore) {
    Collezione miaCollezione("Università");
    ContatoreNote* contatore = new ContatoreNote();
    miaCollezione.attach(contatore);
    Note* n1 = new Note("Esame C++", "Studiare Google Test", false);
    miaCollezione.aggiungiNota(n1);
    miaCollezione.rimuoviNota(n1);
    miaCollezione.detach(contatore);
    delete n1;
    delete contatore;
    SUCCEED();
}