#include "lexer.h"

Symbol *Lexer::Consulter() {
    if (!tampon) {

        if (tete == flux.length()) {
            tampon = new Symbol(FIN);
        } else {

            switch (flux[tete]) {
                case '(':
                    tampon = new Symbol(OPENPAR);
                    tete++;
                    break;
                case ')':
                    tampon = new Symbol(CLOSEPAR);
                    tete++;
                    break;
                case '*':
                    tampon = new Symbol(MULT);
                    tete++;
                    break;
                case '+':
                    tampon = new Symbol(PLUS);
                    tete++;
                    break;
                default:
                    if (flux[tete] <= '9' && flux[tete] >= '0') {
                        int resultat = flux[tete] - '0';
                        int i = 1;
                        while (flux[tete + i] <= '9' && flux[tete + i] >= '0') {
                            resultat = resultat * 10 + (flux[tete + i] - '0');
                            i++;
                        }
                        tete = tete + i;
                        tampon = new Entier(resultat);
                    } else {
                        tampon = new Symbol(ERREUR);
                    }
            }
        }
    }
    return tampon;
}

void Lexer::Avancer() {
    tampon = nullptr;
}

void Lexer::putSymbol(Symbol *s) {

    switch (*s) {
        case PLUS:
        case MULT:
        case OPENPAR:
        case CLOSEPAR:
            tampon = s;
            break;
    }
}