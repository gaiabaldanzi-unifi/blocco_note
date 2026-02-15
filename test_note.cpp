//
// Created by Gaia Baldanzi on 15/02/26.
//

#include <gtest/gtest.h>
#include "Note.h"
#include "NoteImportanti.h"

TEST(NoteTest, CostruttoreEGetter) {
    Note n("Titolo Prova", "Contenuto della nota", false);
    EXPECT_EQ(n.getTitolo(), "Titolo Prova");
    EXPECT_EQ(n.getTesto(), "Contenuto della nota");
    EXPECT_FALSE(n.isBloccata());
    EXPECT_FALSE(n.isImportante());
}

TEST(NoteTest, ModificaSenzaBlocco) {
    Note n("Titolo", "Testo", false);
    n.setTitolo("Nuovo Titolo");
    n.setTesto("Nuovo Testo");
    EXPECT_EQ(n.getTitolo(), "Nuovo Titolo");
    EXPECT_EQ(n.getTesto(), "Nuovo Testo");
}

TEST(NoteTest, VincoloBlocco) {
    Note n("Originale", "Testo Originale", false);
    n.setBloccata(true);
    n.setTitolo("Hacker");
    n.setTesto("Modifica");
    EXPECT_EQ(n.getTitolo(), "Originale");
    EXPECT_EQ(n.getTesto(), "Testo Originale");
    EXPECT_TRUE(n.isBloccata());
}

TEST(NoteTest, TestImportanzaESingleton) {
    Note n("Nota Importante", "Contenuto", false);
    n.setImportante(true);
    EXPECT_TRUE(n.isImportante());
    auto importanti = NoteImportanti::getInstance();
}

TEST(NoteTest, ModificaImportanzaBloccata) {
    Note n("Nota", "Testo", false);
    n.setBloccata(true);
    n.setImportante(true);
    EXPECT_FALSE(n.isImportante());
}