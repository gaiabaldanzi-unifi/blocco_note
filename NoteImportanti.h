//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_NOTEIMPORTANTI_H
#define BLOCCONOTE_NOTEIMPORTANTI_H

#include "Collezione.h"

class NoteImportanti: public Collezione{
private:
    static NoteImportanti* instance;
    NoteImportanti();
public:
    static NoteImportanti* getInstance();

    NoteImportanti(const NoteImportanti&)=delete;
    void operator=(const NoteImportanti&)=delete;
};

#endif //BLOCCONOTE_NOTEIMPORTANTI_H