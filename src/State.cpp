/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#include "State.h"
#include "Symbol.h"

State::State() = default;

State::~State() = default;

bool State0::transition(Automate &automate, Symbol *symbol) {
    switch (*symbol) {
        case INT:
            automate.shift(symbol, new State3);
            break;
        case OPENPAR:
            automate.shift(symbol, new State2);
            break;
        case EXPR:
            automate.shift(symbol, new State1);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }
    return true;
}

bool State1::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.shift(symbol, new State4);
            break;
        case MULT:
            automate.shift(symbol, new State5);
            break;
        case END:
            return false;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State2::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case INT:
            automate.shift(symbol, new State3);
            break;
        case OPENPAR:
            automate.shift(symbol, new State2);
            break;
        case EXPR:
            automate.shift(symbol, new State6);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State3::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.reduce(1, new SymbolPlus);
            break;
        case MULT:
            automate.reduce(1, new SymbolMult);
            break;
        case CLOSEPAR:
            automate.reduce(1, new SymbolClosepar);
            break;
        case END:
            automate.reduce(1, new SymbolFin);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State4::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case INT:
            automate.shift(symbol, new State3);
            break;
        case OPENPAR:
            automate.shift(symbol, new State2);
            break;
        case EXPR:
            automate.shift(symbol, new State7);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State5::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case INT:
            automate.shift(symbol, new State3);
            break;
        case OPENPAR:
            automate.shift(symbol, new State2);
            break;
        case EXPR:
            automate.shift(symbol, new State8);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State6::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.shift(symbol, new State4);
            break;
        case MULT:
            automate.shift(symbol, new State5);
            break;
        case CLOSEPAR:
            automate.shift(symbol, new State9);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State7::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.reduce(3, new SymbolPlus);
            break;
        case MULT:
            automate.shift(symbol, new State5);
            break;
        case CLOSEPAR:
            automate.reduce(3, new SymbolClosepar);
            break;
        case END:
            automate.reduce(3, new SymbolFin);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State8::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.reduce(3, new SymbolPlus);
            break;
        case MULT:
            automate.reduce(3, new SymbolMult);
            break;
        case CLOSEPAR:
            automate.reduce(3, new SymbolClosepar);
            break;
        case END:
            automate.reduce(3, new SymbolFin);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

bool State9::transition(Automate &automate, Symbol *symbol) {

    switch (*symbol) {
        case PLUS:
            automate.reduce(3, new SymbolPlus);
            break;
        case MULT:
            automate.reduce(3, new SymbolMult);
            break;
        case CLOSEPAR:
            automate.reduce(3, new SymbolClosepar);
            break;
        case END:
            automate.reduce(3, new SymbolFin);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }

    return true;
}

