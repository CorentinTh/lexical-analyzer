/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */


#include "Automate.h"
#include "Lexer.h"
#include <iostream>

int main() {

  string input;

  cout << "Please type a sentence to analyze:" << endl;

  cin >> input;

  (new Automate(input))->run();

  return 0;
}
