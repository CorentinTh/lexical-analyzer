//
// Created by corentin on 27/01/2020.
//

#include "State.h"

bool State0::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol){
        case INT:
            automate.shift(symbol, new State3());
            break;
    }

    return false;
}
