//
// Created by corentin on 27/01/2020.
//

#include "State.h"

bool State0::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol){
        case INT:
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            automate.shift(symbol, new State1());
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }

    return true;
}

bool State1::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.shift(symbol,new State4());
            break;
        case MULT:
            automate.shift(symbol,new State5());
            break;
        case FIN:
            return FALSE;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State2::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case INT:
            automate.shift(symbol,new State3());
            break;
        case OPENPAR:
            automate.shift(symbol,new State2());
            break;
        case EXP:
            automate.shift(symbol,new State6());
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State3::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.reduction(1, symbol);
            break;
        case MULT:
            automate.reduction(1, symbol);
            break;
        case CLOSEPAR:
            automate.reduction(1, symbol);
            break;
        case FIN:
            automate.reduction(1, symbol);
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State4::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol){
        case INT:
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            automate.shift(symbol, new State7());
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }

    return true;
}

bool State5::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol){
        case INT:
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            automate.shift(symbol, new State8());
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }

    return true;
}

bool State6::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.shift(symbol,new State4());
            break;
        case MULT:
            automate.shift(symbol,new State5());
            break;
        case CLOSEPAR:
            automate.shift(symbol, new State9());
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State7::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.reduction(3, symbol);
            break;
        case MULT:
            automate.shift(symbol, new State5());
            break;
        case CLOSEPAR:
            automate.reduction(3, symbol);
            break;
        case FIN:
            automate.reduction(3, symbol);
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State8::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.reduction(3, symbol);
            break;
        case MULT:
            automate.reduction(3, symbol);
            break;
        case CLOSEPAR:
            automate.reduction(3, symbol);
            break;
        case FIN:
            automate.reduction(3, symbol);
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}

bool State9::transition(Automate &automate, Symbol *symbol){
    switch (*symbol){
        case PLUS:
            automate.reduction(3, symbol);
            break;
        case MULT:
            automate.reduction(3, symbol);
            break;
        case CLOSEPAR:
            automate.reduction(3, symbol);
            break;
        case FIN:
            automate.reduction(3, symbol);
            break;
        default:
            automate.shift(new Symbol(ERROR), NULL);
            return false;
    }
    
    return true;
}
