/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#include "State.h"
#include <iostream>

Automate::Automate(string &input) {
    this->input = input;
    this->lexer = new Lexer(input);
    this->statesStack.push(new State0());
}

void Automate::run() {
    bool nextState;

    do {
        Symbol *symbol = this->lexer->consult();
        this->lexer->step();
        nextState = this->statesStack.top()->transition(*this, symbol);
    } while (nextState);

    Symbol *topSymbol = this->symbolsStack.top();

    if (*topSymbol != ERREUR) {
        cout << "The syntax is correct." << endl;
        cout << this->input << " = " << topSymbol->getValue() << endl;
    } else {
        cout << "Invalid characters" << endl;
    }
}

void Automate::shift(Symbol *symbol, State *state) {
    this->symbolsStack.push(symbol);
    this->statesStack.push(state);
}

void Automate::reduce(int n, Symbol *symbol) {
    stack<Symbol *> toRemove;

    for (int i = 0; i < n; ++i) {
        delete (statesStack.top());
        statesStack.pop();
        toRemove.push(symbolsStack.top());
        symbolsStack.pop();
    }

    int val = -1;

    if (n == 1) {
        val = toRemove.top()->getValue();
    } else if (n == 3) {
        if (*toRemove.top() == OPENPAR) {
            toRemove.pop();
            val = toRemove.top()->getValue();
        } else {
            val = toRemove.top()->getValue();
            toRemove.pop();
            if (*toRemove.top() == MULT) {
                toRemove.pop();
                val = val * toRemove.top()->getValue();
            } else {
                toRemove.pop();
                val = val + toRemove.top()->getValue();
            }
        }
    }

    statesStack.top()->transition(*this, new SymbolExpr(val));
    lexer->add(symbol);
}
 