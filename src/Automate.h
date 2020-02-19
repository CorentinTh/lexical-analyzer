/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#pragma once

#include "Lexer.h"
#include "Symbol.h"
#include <stack>
#include <string>

class State;

using namespace std;

class Automate {

public:
    Automate(string &input);

    void shift(Symbol *symbol, State *state);

    void reduce(int n, Symbol *symbol);

    void run();

protected:
    stack<Symbol *> symbolsStack;
    stack<State *> statesStack;
    Lexer *lexer;
    string input;
};

