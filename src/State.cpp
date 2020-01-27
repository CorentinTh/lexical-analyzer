//
// Created by corentin on 27/01/2020.
//

#include "State.h"

State::~State() = default;

State::State(string name) { name = name; }

State0::State0() : State("STATE0") {}

State1::State1() : State("STATE1") {}

State2::State2() : State("STATE2") {}

State3::State3() : State("STATE3") {}

State4::State4() : State("STATE4") {}

State5::State5() : State("STATE5") {}

State6::State6() : State("STATE6") {}

State7::State7() : State("STATE7") {}

State8::State8() : State("STATE8") {}

State9::State9() : State("STATE9") {}


bool State0::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            cout << "State 0 -> INT" << endl;
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            cout << "State 0 -> (" << endl;
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            cout << "State 0 -> E" << endl;
            automate.shift(symbol, new State1());
            break;
        default:
            cout << "State 0 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State1::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 1 -> +" << endl;
            automate.shift(symbol, new State4());
            break;
        case MULT:
            cout << "State 1 -> *" << endl;
            automate.shift(symbol, new State5());
            break;
        case FIN:
            cout << "State 1 -> $" << endl;
            return false;
        default:
            cout << "State 1 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State2::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            cout << "State 2 -> INT" << endl;
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            cout << "State 2 -> (" << endl;
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            cout << "State 2 -> E" << endl;
            automate.shift(symbol, new State6());
            break;
        default:
            cout << "State 2 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State3::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 3 -> +" << endl;
            automate.reduction(1, new Plus);
            break;
        case MULT:
            cout << "State 3 -> *" << endl;
            automate.reduction(1, new Mult);
            break;
        case CLOSEPAR:
            cout << "State 3 -> )" << endl;
            automate.reduction(1, new Closepar);
            break;
        case FIN:
            cout << "State 3 -> $" << endl;
            automate.reduction(1, new Fin);
            break;
        default:
            cout << "State 3 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State4::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            cout << "State 4 -> INT" << endl;
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            cout << "State 4 -> (" << endl;
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            cout << "State 4 -> E" << endl;
            automate.shift(symbol, new State7());
            break;
        default:
            cout << "State 4 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State5::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            cout << "State 5 -> INT" << endl;
            automate.shift(symbol, new State3());
            break;
        case OPENPAR:
            cout << "State 5 -> (" << endl;
            automate.shift(symbol, new State2());
            break;
        case EXPR:
            cout << "State 5 -> E" << endl;
            automate.shift(symbol, new State8());
            break;
        default:
            cout << "State 5 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State6::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 6 -> +" << endl;
            automate.shift(symbol, new State4());
            break;
        case MULT:
            cout << "State 6 -> *" << endl;
            automate.shift(symbol, new State5());
            break;
        case CLOSEPAR:
            cout << "State 6 -> )" << endl;
            automate.shift(symbol, new State9());
            break;
        default:
            cout << "State 6 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State7::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 7 -> +" << endl;
            automate.reduction(3, new Plus);
            break;
        case MULT:
            cout << "State 7 -> *" << endl;
            automate.shift(symbol, new State5());
            break;
        case CLOSEPAR:
            cout << "State 7 -> )" << endl;
            automate.reduction(3, new Closepar);
            break;
        case FIN:
            cout << "State 7 -> $" << endl;
            automate.reduction(3, new Fin);
            break;
        default:
            cout << "State 7 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State8::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 8 -> +" << endl;
            automate.reduction(3, new Plus);
            break;
        case MULT:
            cout << "State 8 -> *" << endl;
            automate.reduction(3, new Mult);
            break;
        case CLOSEPAR:
            cout << "State 8 -> )" << endl;
            automate.reduction(3, new Closepar);
            break;
        case FIN:
            cout << "State 8 -> $" << endl;
            automate.reduction(3, new Fin);
            break;
        default:
            cout << "State 8 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State9::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case PLUS:
            cout << "State 9 -> +" << endl;
            automate.reduction(3, new Plus);
            break;
        case MULT:
            cout << "State 9 -> *" << endl;
            automate.reduction(3, new Mult);
            break;
        case CLOSEPAR:
            cout << "State 9 -> )" << endl;
            automate.reduction(3, new Closepar);
            break;
        case FIN:
            cout << "State 9 -> $" << endl;
            automate.reduction(3, new Fin);
            break;
        default:
            cout << "State 9 -> ERROR" << endl;
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

