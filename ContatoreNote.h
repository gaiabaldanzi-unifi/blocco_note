//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_CONTATORENOTE_H
#define BLOCCONOTE_CONTATORENOTE_H

#include "Observer.h"

#include <iostream>
using namespace std;

class ContatoreNote: public Observer {
public:
    ContatoreNote();
    virtual ~ContatoreNote();
    void update(bool b, const string &n, const string &c, int i) override;
};

#endif //BLOCCONOTE_CONTATORENOTE_H