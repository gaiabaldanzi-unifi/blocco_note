//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "NoteImportanti.h"
#include "Collezione.h"

NoteImportanti* NoteImportanti::instance=nullptr;

NoteImportanti::NoteImportanti(): Collezione("Note Importanti"){};

NoteImportanti* NoteImportanti::getInstance() {
    if(instance==nullptr) instance=new NoteImportanti();
    return instance;
}