#pragma once

#include <string>

using namespace std;

enum Identificateurs {
    OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
};

const string Flags[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR"};

class Symbol {
public:
    Symbol(int i) : ident(i) {}

    virtual ~Symbol() {}

    operator int() const { return ident; }

    virtual void Affiche();

    virtual int getValeur() const;

protected:
    int ident;
};

class Entier : public Symbol {
public:
    Entier(int v) : Symbol(INT), valeur(v) {}

    ~Entier() {}

    virtual void Affiche();

    int getValeur() const;

protected:
    int valeur;
};

