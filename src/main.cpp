#include <iostream>
#include "lexer.h"


int main(void) {
    string chaine("(1+34)*123");

    Lexer l(chaine);

    Symbol * s;
    while(*(s=l.Consulter())!=FIN) {
        s->Affiche();
        cout<<endl;
        l.Avancer();
    }
    return 0;
}

