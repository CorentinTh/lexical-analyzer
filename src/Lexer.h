/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#pragma once

#include "Symbol.h"
#include <string>

using namespace std;

class Lexer {

public:
    Lexer(string &s) : flux(s), head(0), buffer(nullptr) {}

    ~Lexer() = default;

    Symbol *consult();

    void step();

    void add(Symbol *symbol);

protected:
    string flux;
    int head;
    Symbol *buffer;
};