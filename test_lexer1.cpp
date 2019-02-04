/* RENAN ZELAYA */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <memory>
#include <cstring>
#include <cstdlib>
#include "doctest.h"
#include "lexer.h"

const char *keywords = "else extends false bool break continue class for if Int int new null return rot true void while";
const char *operators = "{}[],;()=-!+*/<<>><>%<=>===!=&&|||";
const char *provided = "0x123food 0xfood123 123break 0x123while3 0x123while 3 1250x356 break123 breakwhile";
const char *stringConst = "\"hola\" \"h\\no\\tl\\ra\"\"\\\"hola\\\"\" \"ho\\la\"";
const char *charConst = "\'s\'\'\\n\' \'\\t\' \'\\r\' \'\\\'\' \'ñ\' \'ll\'";
const char *comments = "int x = 0 //comentario de linea hola\nx = x == x; /*comentario\n mas comment*/ _hola1";

TEST_CASE("Keywords")
{
    std::istringstream in;

    in.str(keywords);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::KW_ELSE);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_EXTENDS);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_FALSE);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_BOOL);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_BREAK);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_CONTINUE);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_CLASS);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_FOR);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_IF);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_INT);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_NEW);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_NULL);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_RETURN);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_ROT);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_TRUE);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_VOID);

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_WHILE);
}

TEST_CASE("Operators")
{
    std::istringstream in;

    in.str(operators);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::TK_OPENCURL);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_CLOSECURL);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_OPENBRACK);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_CLOSEBRACK);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_COMMA);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_SEMICOLON);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_OPENPAR);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_CLOSEPAR);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_EQUAL);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_SUB);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_NOT);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_ADD);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_MUL);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_DIV);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_SHIFTL);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_SHIFTR);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_LT);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_GT);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_MOD);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_LTE);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_GTE);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_EQ);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_NE);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_AND);
    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_OR);
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_UNK);
}

TEST_CASE("Provided Examples")
{
    std::istringstream in;

    in.str(provided);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_HEX);
    CHECK(l.getLexeme() == "0x123f");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "ood");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_HEX);
    CHECK(l.getLexeme() == "0xf");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "ood123");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_DEC);
    CHECK(l.getLexeme() == "123");

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_BREAK);
    CHECK(l.getLexeme() == "break");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_HEX);
    CHECK(l.getLexeme() == "0x123");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "while3");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_HEX);
    CHECK(l.getLexeme() == "0x123");

    tk = l.getNextToken();
    CHECK(tk == TokenID::KW_WHILE);
    CHECK(l.getLexeme() == "while");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_DEC);
    CHECK(l.getLexeme() == "3");

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_DEC);
    CHECK(l.getLexeme() == "1250");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "x356");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "break123");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "breakwhile");
}

TEST_CASE("String Constant")
{
    std::istringstream in;

    in.str(stringConst);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::STR_CONST);
    CHECK(l.getLexeme() == "hola");

    tk = l.getNextToken();
    CHECK(tk == TokenID::STR_CONST);
    CHECK(l.getLexeme() == "h\no\tl\ra");

    tk = l.getNextToken();
    CHECK(tk == TokenID::STR_CONST);
    CHECK(l.getLexeme() == "\"hola\"");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ERR);
}

TEST_CASE("Char Constant")
{
    std::istringstream in;

    in.str(charConst);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::CHAR_CONST);
    CHECK(l.getLexeme() == "s");

    tk = l.getNextToken();
    CHECK(tk == TokenID::CHAR_CONST);
    CHECK(l.getLexeme() == "\n");

    tk = l.getNextToken();
    CHECK(tk == TokenID::CHAR_CONST);
    CHECK(l.getLexeme() == "\t");

    tk = l.getNextToken();
    CHECK(tk == TokenID::CHAR_CONST);
    CHECK(l.getLexeme() == "\r");

    tk = l.getNextToken();
    CHECK(tk == TokenID::CHAR_CONST);
    CHECK(l.getLexeme() == "\'");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ERR);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ERR);
}

TEST_CASE("Comments")
{
    std::istringstream in;

    in.str(comments);
    Lexer l(in);

    TokenID tk = l.getNextToken();
    CHECK(tk == TokenID::KW_INT);
    
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "x");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_EQUAL);

    tk = l.getNextToken();
    CHECK(tk == TokenID::INT_CONST_DEC);
    CHECK(std::atol(l.getLexeme().c_str()) == 0);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "x");
    
    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_EQUAL);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "x");

    tk = l.getNextToken();
    CHECK(tk == TokenID::OP_EQ);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "x");

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_SEMICOLON);

    tk = l.getNextToken();
    CHECK(tk == TokenID::TK_ID);
    CHECK(l.getLexeme() == "_hola1");
}