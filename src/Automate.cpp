//
// Created by corentin on 27/01/2020.
//

#include "Automate.h"
#include "State.h"

Automate::Automate(string &input) {
    this->lexer = new Lexer(input);
    this->stateStack.push(new State0());
}

void Automate::shift(Symbol *symbol, State *state) {
    this->symbolStack.push(symbol);
    this->stateStack.push(state);
}

void Automate::reduction(int n, Symbol *symbol) {
    stack<Symbol *> aEnlever;

    for (int i = 0; i < n; ++i) {
        delete (stateStack.top());
        stateStack.pop();
        aEnlever.push(symbolStack.top());
        symbolStack.pop();
    }

    int val;

    if (n == 1) {
        val = aEnlever.top()->getValeur();
    } else if (n == 3) {
        if (*aEnlever.top() == OPENPAR) {
            aEnlever.pop();
            val = aEnlever.top()->getValeur();
        } else {
            val = aEnlever.top()->getValeur();
            aEnlever.pop();
            if (*aEnlever.top() == MULT) {
                aEnlever.pop();
                val = val * aEnlever.top()->getValeur();
            } else {
                //aEnlever.pop();
                Entier tmp =  (Entier) *aEnlever.top();
                val = tmp.eval();
                cout << val << endl;
                aEnlever.pop();
                //val = val + aEnlever.top()->getValeur();
            }
        }
    }


    stateStack.top()->transition(*this, new Expression(val));
    lexer->putSymbol(symbol);
}

void Automate::run() {
    bool nextState = true;

    while (nextState) {
        Symbol *symbol = this->lexer->Consulter();
        this->lexer->Avancer();
        auto stateStackTop = this->stateStack.top();
        nextState = stateStackTop->transition(*this, symbol);
    }

    Symbol* symbolStackTop = this->symbolStack.top();

    if(*symbolStackTop != ERREUR){
        cout << "result: " << symbolStackTop->getValeur() << endl;
    }else{
        cout << "Invalid character" << endl;
    }

}

