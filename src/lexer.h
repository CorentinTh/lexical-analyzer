#pragma once

#include <string>
#include "Symbol.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      Symbol * Consulter();
      void Avancer();

   protected:
      string flux;
      int tete;
      Symbol * tampon;
};
