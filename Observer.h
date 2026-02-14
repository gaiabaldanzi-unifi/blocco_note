//
// Created by Gaia Baldanzi on 14/02/26.
//

#ifndef BLOCCONOTE_OBSERVER_H
#define BLOCCONOTE_OBSERVER_H
#include <string>
using namespace std;

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(bool b, const string &n, const string &c, int i)=0;
};

#endif //BLOCCONOTE_OBSERVER_H