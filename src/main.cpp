#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
    string chaine("(1+34)*123");

    (new Automate(chaine))->run();

    return 0;
}

