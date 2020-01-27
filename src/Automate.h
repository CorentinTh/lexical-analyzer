//
// Created by corentin on 27/01/2020.
//

#ifndef LEXICAL_ANALYZER_AUTOMATE_H
#define LEXICAL_ANALYZER_AUTOMATE_H

#include "lexer.h"
#include "Symbol.h"
#include <stack>
#include <iostream>

class State;

using namespace std;

class Automate {
public:
    Automate(string &input);
    void shift(Symbol *symbol, State *state);
    void reduction(int n, Symbol *symbol);
    void run();

protected:

    stack<Symbol *> symbolStack;
    stack<State *> stateStack;
    Lexer *lexer;
};


#endif //LEXICAL_ANALYZER_AUTOMATE_H
