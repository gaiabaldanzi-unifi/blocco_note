//
// Created by Gaia Baldanzi on 15/02/26.
//

#include <gtest/gtest.h>
#include "Collezione.h"
#include "Note.h"
#include "ContatoreNote.h"

TEST(CollezioneTest, AggiuntaNota) {
    Collezione c("Test");
    Note* n = new Note("Titolo", "Testo", false);
    c.aggiungiNota(n);
    EXPECT_EQ(c.getNoteCollezionate().size(), 1);
    EXPECT_EQ(c.getNoteCollezionate().front()->getTitolo(), "Titolo");
    delete n;
}

TEST(CollezioneTest, RimozioneNota) {
    Collezione c("Test");
    Note* n = new Note("Titolo", "Testo", false);
    c.aggiungiNota(n);
    c.rimuoviNota(n);
    EXPECT_TRUE(c.getNoteCollezionate().empty());
    delete n;
}

TEST(CollezioneTest, AggiuntaNotaBloccata) {
    Collezione c("Test");
    Note* n = new Note("Bloccata", "Testo", false);
    n->setBloccata(true);
    c.aggiungiNota(n);
    EXPECT_TRUE(c.getNoteCollezionate().empty());
    delete n;
}

TEST(CollezioneTest, TestNotificaObserver) {
    Collezione c("Lavoro");
    ContatoreNote* obs = new ContatoreNote();
    c.attach(obs);
    Note* n = new Note("Urgent", "Compila i test", false);
    c.aggiungiNota(n);
    c.rimuoviNota(n);
    c.detach(obs);
    delete n;
    delete obs;
}

TEST(CollezioneTest, VisualizzazioneVuota) {
    Collezione c("Vuota");
    EXPECT_NO_THROW(c.visualizzaNote());
}