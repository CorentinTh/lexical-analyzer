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
