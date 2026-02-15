//
// Created by Gaia Baldanzi on 15/02/26.
//

#include <gtest/gtest.h>
#include "NoteImportanti.h"
#include "Note.h"

TEST(NoteImportantiTest, SingletonInstanceUniqueness) {
    NoteImportanti* istanza1 = NoteImportanti::getInstance();
    NoteImportanti* istanza2 = NoteImportanti::getInstance();
    EXPECT_EQ(istanza1, istanza2);
}

TEST(NoteImportantiTest, NomeCollezioneSingleton) {
    NoteImportanti* ni = NoteImportanti::getInstance();
    EXPECT_EQ(ni->getNome(), "Note Importanti");
}

TEST(NoteImportantiTest, AggiuntaNotaImportante) {
    NoteImportanti* ni = NoteImportanti::getInstance();
    int dimensioneIniziale = ni->getNoteCollezionate().size();
    Note* n = new Note("Test Singleton", "Contenuto", false);
    n->setImportante(true);
    EXPECT_EQ(ni->getNoteCollezionate().size(), dimensioneIniziale + 1);
    n->setImportante(false);
    EXPECT_EQ(ni->getNoteCollezionate().size(), dimensioneIniziale);
    delete n;
}
