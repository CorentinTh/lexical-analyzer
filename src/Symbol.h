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
    int getValeur();

protected:
    int ident;

};

class Openpar : public Symbol {
public:
    Openpar() : Symbol(OPENPAR) {}
    ~Openpar() {}
    virtual void Affiche();

};

class Closepar : public Symbol {
public:
    Closepar() : Symbol(CLOSEPAR) {}
    ~Closepar() {}
    virtual void Affiche();

protected:
};

class Plus : public Symbol {
public:
    Plus() : Symbol(PLUS) {}
    ~Plus() {}
    virtual void Affiche();

};

class Mult : public Symbol {
public:
    Mult() : Symbol(MULT) {}
    ~Mult() {}
    virtual void Affiche();

};

class Entier : public Symbol {
public:
    Entier(int v) : Symbol(INT), valeur(v) {}
    ~Entier() {}
    virtual void Affiche();
    int eval() { return valeur; }
    int getValeur() const;
    int getValeur();

protected:
    int valeur;

};

class Fin : public Symbol {
public:
    Fin() : Symbol(FIN) {}
    ~Fin() {}
    virtual void Affiche();

protected:
};

class Erreur : public Symbol {
public:
    Erreur() : Symbol(ERREUR) {}
    ~Erreur() {}
    virtual void Affiche();

protected:
};

class Expression : public Symbol {
public:
    Expression(int val) : Symbol(EXPR), valeur(val) {}
    ~Expression() {}
    virtual void Affiche();
    int getValeur() const;

protected:
    int valeur;

};
