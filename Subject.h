//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_SUBJECT_H
#define BLOCCONOTE_SUBJECT_H
#include <string>
#include <iostream>
#include "Observer.h"
using namespace std;

class Subject {
public:
    virtual ~Subject() {};
    virtual void attach(Observer *o)=0;
    virtual void detach(Observer *o)=0;
    virtual void notify(bool b, const string &n, const string &c, int i)=0;
};

#endif //BLOCCONOTE_SUBJECT_H