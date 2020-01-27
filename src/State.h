//
// Created by corentin on 27/01/2020.
//

#ifndef LEXICAL_ANALYZER_STATE_H
#define LEXICAL_ANALYZER_STATE_H

#include "Automate.h"

class State {
public:
    State(string name);
    virtual ~State();
    void print() const;
    virtual bool transition(Automate &automate, Symbol *symbol) = 0;

protected:
    string name;
};


class State0 : public State {
public:
    State0();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State1 : public State {
public:
    State1();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State2 : public State {
public:
    State2();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State3 : public State {
public:
    State3();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State4 : public State {
public:
    State4();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State5 : public State {
public:
    State5();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State6 : public State {
public:
    State6();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State7 : public State {
public:
    State7();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State8 : public State {
public:
    State8();
    bool transition(Automate &automate, Symbol *symbol) override;
};

class State9 : public State {
public:
    State9();
    bool transition(Automate &automate, Symbol *symbol) override;
};


#endif //LEXICAL_ANALYZER_STATE_H
