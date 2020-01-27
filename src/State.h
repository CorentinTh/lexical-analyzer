//
// Created by corentin on 27/01/2020.
//

#ifndef LEXICAL_ANALYZER_STATE_H
#define LEXICAL_ANALYZER_STATE_H


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
    bool transition(Automate &automate, Symbol *symbol);
    virtual int state();
};

#endif //LEXICAL_ANALYZER_STATE_H
