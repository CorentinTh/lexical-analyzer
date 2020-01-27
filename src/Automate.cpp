//
// Created by corentin on 27/01/2020.
//

#include "Automate.h"
#include "State.h"

Automate::Automate(string &input) {
    this->lexer = new Lexer(input);
    auto *depart = new State0();
    this->stateStack.push(depart);
}

void Automate::shift(Symbol *symbol, State *state) {
    this->symbolStack.push(symbol);
    this->stateStack.push(state);
}

void Automate::reduction(int n, Symbol *symbol) {
    for (int i = 0; i < n; ++i) {
        delete (stateStack.top());
        stateStack.pop();
    }

    stateStack.top()->transition(*this, symbol);
}

void Automate::run() {
    bool nextState;

    do {
        Symbol *symbol = this->lexer->Consulter();
        this->lexer->Avancer();
        nextState = this->stateStack.top()->transition(*this, symbol);
    } while (nextState);

    Symbol* symbolStackTop = this->symbolStack.top();

    if(*symbolStackTop != ERREUR){
        symbolStackTop->Affiche();
    }else{
        cout << "Invalid character" << endl;
    }

}

