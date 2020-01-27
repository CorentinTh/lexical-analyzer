#include "Symbol.h"
#include <iostream>

void Symbol::Affiche() {
   cout<<Flags[ident];
}

void Entier::Affiche() {
   Symbol::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValeur() const {
    return valeur;
}

