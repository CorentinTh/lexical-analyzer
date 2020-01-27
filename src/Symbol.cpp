#include "Symbol.h"
#include <iostream>

void Symbol::Affiche() {
    cout << Flags[ident];
}

int Symbol::getValeur() const {
    return -1;
}

void Entier::Affiche() {
    Symbol::Affiche();
    cout << "(" << valeur << ")";
}

int Entier::getValeur() const {
    return valeur;
}


void Expression::Affiche() {
    Symbol::Affiche();
    cout << "(" << valeur << ")";
}

int Expression::getValeur() const {
    cout << "getvaleur expression " << endl;
    return valeur;
}


void Plus::Affiche() { Symbol::Affiche(); }

void Mult::Affiche() { Symbol::Affiche(); }

void Openpar::Affiche() { Symbol::Affiche(); }

void Closepar::Affiche() { Symbol::Affiche(); }

void Fin::Affiche() { Symbol::Affiche(); }

void Erreur::Affiche() { Symbol::Affiche(); }

int Symbol::getValeur() { return -1; }

int Entier::getValeur() { cout << "Test: " << endl; return valeur; }

