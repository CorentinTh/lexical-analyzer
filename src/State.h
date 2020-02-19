/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#include "Automate.h"
#include <string>

using namespace std;

class State {

public:
    State();

    virtual ~State();

    virtual bool transition(Automate &automate, Symbol *symbol) = 0;

};

class State0 : public State {
public:
    State0() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State1 : public State {
public:
    State1() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State2 : public State {
public:
    State2() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State3 : public State {
public:
    State3() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State4 : public State {
public:
    State4() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State5 : public State {
public:
    State5() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State6 : public State {
public:
    State6() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State7 : public State {
public:
    State7() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State8 : public State {
public:
    State8() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};

class State9 : public State {
public:
    State9() = default;

    bool transition(Automate &automate, Symbol *symbol) override;

};
