/*
 *             Lexical analyzer
 *      Tania Oudinet & Corentin Thomasset
 *          Language et grammaire
 *         INSA Lyon - Janvier 2020
 *
 */

#pragma once

#include <map>
#include <string>

using namespace std;

enum Identificateurs {
    OPENPAR,
    CLOSEPAR,
    PLUS,
    MULT,
    INT,
    END,
    ERREUR,
    EXPR
};

const string Etiquettes[] = {
        "OPENPAR",
        "CLOSEPAR",
        "PLUS",
        "MULT",
        "INT",
        "END",
        "ERREUR",
        "EXPR"
};

class Symbol {
public:
    explicit Symbol(int i) : ident(i) {}

    virtual ~Symbol() = default;

    operator int() const { return ident; }

    virtual void print();

    virtual int getValue();

protected:
    int ident;
};

class SymbolOpenpar : public Symbol {
public:
    SymbolOpenpar() : Symbol(OPENPAR) {}

    ~SymbolOpenpar() override = default;

};

class SymbolClosepar : public Symbol {
public:
    SymbolClosepar() : Symbol(CLOSEPAR) {}

    ~SymbolClosepar() override = default;

};

class SymbolPlus : public Symbol {
public:
    SymbolPlus() : Symbol(PLUS) {}

    ~SymbolPlus() override = default;

};

class SymbolMult : public Symbol {
public:
    SymbolMult() : Symbol(MULT) {}

    ~SymbolMult() override = default;

};

class SymbolInt : public Symbol {
public:
    explicit SymbolInt(int v) : Symbol(INT), value(v) {}

    ~SymbolInt() override = default;

    void print() override;

    int getValue() override;

protected:
    int value;
};

class SymbolFin : public Symbol {
public:
    SymbolFin() : Symbol(END) {}

    ~SymbolFin() override = default;

};

class SymbolExpr : public Symbol {
public:
    explicit SymbolExpr(int val) : Symbol(EXPR), value(val) {}

    ~SymbolExpr() override = default;

    int getValue() override;

protected:
    int value;
};
