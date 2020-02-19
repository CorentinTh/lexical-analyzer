/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#include "Symbol.h"
#include <iostream>

void Symbol::print() { cout << Etiquettes[ident]; }

void SymbolInt::print() {
    Symbol::print();
    cout << "(" << value << ")";
}



int Symbol::getValue() { return -1; }

int SymbolInt::getValue() { return value; }

int SymbolExpr::getValue() { return value; }
