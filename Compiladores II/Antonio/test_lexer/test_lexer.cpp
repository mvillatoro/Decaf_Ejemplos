#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <memory>
#include <cstring>
#include "doctest.h"
#include "lexer.h"

TEST_CASE(" Test Operators "){
    string filename = "../../inputs/operators_puntuations.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    Lexer l(file);
    
    int tk = l.getNextToken();
    CHECK( tk == OPEN_KEY);
    CHECK( l.getLexeme() == "{");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_KEY);
    CHECK( l.getLexeme() == "}");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_BRACKET);
    CHECK( l.getLexeme() == "[");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_BRACKET);
    CHECK( l.getLexeme() == "]");
    tk = l.getNextToken();

    
    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();

    
    CHECK( tk == COMMA);
    CHECK( l.getLexeme() == ",");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == OP_ASSING);
    CHECK( l.getLexeme() == "=");
    tk = l.getNextToken();

    
    CHECK( tk == OP_SUB);
    CHECK( l.getLexeme() == "-");
    tk = l.getNextToken();

    
    CHECK( tk == OP_NEGATE);
    CHECK( l.getLexeme() == "!");
    tk = l.getNextToken();

    
    CHECK( tk == OP_ADD);
    CHECK( l.getLexeme() == "+");
    tk = l.getNextToken();

    
    CHECK( tk == OP_MUL);
    CHECK( l.getLexeme() == "*");
    tk = l.getNextToken();

    
    CHECK( tk == OP_DIV);
    CHECK( l.getLexeme() == "/");
    tk = l.getNextToken();

    
    CHECK( tk == OP_LEFT_SHIFT);
    CHECK( l.getLexeme() == "<<");
    tk = l.getNextToken();

    CHECK( tk == OP_RIGHT_SHIFT);
    CHECK( l.getLexeme() == ">>");
    tk = l.getNextToken();

    CHECK( tk == OP_LESS);
    CHECK( l.getLexeme() == "<");
    tk = l.getNextToken();

    CHECK( tk == OP_HIGH);
    CHECK( l.getLexeme() == ">");
    tk = l.getNextToken();

    CHECK( tk == OP_MOD);
    CHECK( l.getLexeme() == "%");
    tk = l.getNextToken();

    CHECK( tk == OP_LESS_EQUAL);
    CHECK( l.getLexeme() == "<=");
    tk = l.getNextToken();

    CHECK( tk == OP_HIGH_EQUAL);
    CHECK( l.getLexeme() == ">=");
    tk = l.getNextToken();

    CHECK( tk == OP_EQUAL);
    CHECK( l.getLexeme() == "==");
    tk = l.getNextToken();

    CHECK( tk == OP_NOT_EQUAL);
    CHECK( l.getLexeme() == "!=");
    tk = l.getNextToken();
    
    CHECK( tk == OP_AND);
    CHECK( l.getLexeme() == "&&");
    tk = l.getNextToken();
    
    CHECK( tk == OP_OR);
    CHECK( l.getLexeme() == "||");
    tk = l.getNextToken();
    

    CHECK( tk == END);
    tk = l.getNextToken();
}

TEST_CASE(" Test Comments "){
    string filename = "../../inputs/comments.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    Lexer l(file);
    
    int tk = l.getNextToken();
    CHECK( tk == R_INT);
    CHECK( l.getLexeme() == "int");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "gcd");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == R_INT);
    CHECK( l.getLexeme() == "int");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "a");
    tk = l.getNextToken();

    
    CHECK( tk == COMMA);
    CHECK( l.getLexeme() == ",");
    tk = l.getNextToken();

    
    CHECK( tk == R_INT);
    CHECK( l.getLexeme() == "int");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "b");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_KEY);
    CHECK( l.getLexeme() == "{");
    tk = l.getNextToken();

    
    CHECK( tk == R_IF);
    CHECK( l.getLexeme() == "if");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "b");
    tk = l.getNextToken();

    
    CHECK( tk == OP_EQUAL);
    CHECK( l.getLexeme() == "==");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "0");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    CHECK( tk == OPEN_KEY);
    CHECK( l.getLexeme() == "{");
    tk = l.getNextToken();

    CHECK( tk == R_RETURN);
    CHECK( l.getLexeme() == "return");
    tk = l.getNextToken();

    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    CHECK( tk == ID);
    CHECK( l.getLexeme() == "b");
    tk = l.getNextToken();

    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

    CHECK( tk == CLOSE_KEY);
    CHECK( l.getLexeme() == "}");
    tk = l.getNextToken();
    
    CHECK( tk == CLOSE_KEY);
    CHECK( l.getLexeme() == "}");
    tk = l.getNextToken();

    CHECK( tk == END);
    tk = l.getNextToken();
}


TEST_CASE(" Test Reserved Functions "){
    string filename = "../../inputs/reserved_functions.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    Lexer l(file);
    
    int tk = l.getNextToken();
    CHECK( tk == R_SYSTEM);
    CHECK( l.getLexeme() == "System");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_OUT);
    CHECK( l.getLexeme() == "out");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
        
    CHECK( tk == R_PRINT);
    CHECK( l.getLexeme() == "print");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == STRINGCONSTANT);
    CHECK( l.getLexeme() == "\"Command \\nLine...\"");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

    
    CHECK( tk == R_SYSTEM);
    CHECK( l.getLexeme() == "System");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_OUT);
    CHECK( l.getLexeme() == "out");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
        
    CHECK( tk == R_PRINTLN);
    CHECK( l.getLexeme() == "println");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == CHARCONSTANT);
    CHECK( l.getLexeme() == "\'A\'");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

     
    CHECK( tk == R_SYSTEM);
    CHECK( l.getLexeme() == "System");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_OUT);
    CHECK( l.getLexeme() == "out");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_PRINTLN);
    CHECK( l.getLexeme() == "println");
    tk = l.getNextToken();

    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "0x121313");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

     
    CHECK( tk == R_SYSTEM);
    CHECK( l.getLexeme() == "System");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_IN);
    CHECK( l.getLexeme() == "in");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_READ);
    CHECK( l.getLexeme() == "read");
    tk = l.getNextToken();

    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();
    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

     
    CHECK( tk == R_RANDOM);
    CHECK( l.getLexeme() == "Random");
    tk = l.getNextToken();

    CHECK( tk == DOT);
    CHECK( l.getLexeme() == ".");
    tk = l.getNextToken();
    
    CHECK( tk == R_NEXTINT);
    CHECK( l.getLexeme() == "nextInt");
    tk = l.getNextToken();
    
    CHECK( tk == OPEN_PAR);
    CHECK( l.getLexeme() == "(");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "125");
    tk = l.getNextToken();

    
    CHECK( tk == CLOSE_PAR);
    CHECK( l.getLexeme() == ")");
    tk = l.getNextToken();

    
    CHECK( tk == SEMICOLON);
    CHECK( l.getLexeme() == ";");
    tk = l.getNextToken();

    CHECK( tk == END);
    tk = l.getNextToken();
}

TEST_CASE(" Test Reserved Words "){
    string filename = "../../inputs/reserved_words.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    Lexer l(file);
    
    int tk = l.getNextToken();
    CHECK( tk == R_BOOL);
    CHECK( l.getLexeme() == "bool");
    tk = l.getNextToken();

    
    CHECK( tk == R_BREAK);
    CHECK( l.getLexeme() == "break");
    tk = l.getNextToken();

    
    CHECK( tk == R_CONTINUE);
    CHECK( l.getLexeme() == "continue");
    tk = l.getNextToken();

    
    CHECK( tk == R_CLASS);
    CHECK( l.getLexeme() == "class");
    tk = l.getNextToken();

    
    CHECK( tk == R_ELSE);
    CHECK( l.getLexeme() == "else");
    tk = l.getNextToken();
    
    CHECK( tk == R_FALSE);
    CHECK( l.getLexeme() == "false");
    tk = l.getNextToken();

    
    CHECK( tk == R_FOR);
    CHECK( l.getLexeme() == "for");
    tk = l.getNextToken();

    
    CHECK( tk == R_IF);
    CHECK( l.getLexeme() == "if");
    tk = l.getNextToken();
    
    CHECK( tk == R_INT);
    CHECK( l.getLexeme() == "int");
    tk = l.getNextToken();

    CHECK( tk == R_RETURN);
    CHECK( l.getLexeme() == "return");
    tk = l.getNextToken();
    
    CHECK( tk == R_TRUE);
    CHECK( l.getLexeme() == "true");
    tk = l.getNextToken();

    
    CHECK( tk == R_VOID);
    CHECK( l.getLexeme() == "void");
    tk = l.getNextToken();

    CHECK( tk == R_WHILE);
    CHECK( l.getLexeme() == "while");
    tk = l.getNextToken();

    CHECK( tk == END);
    tk = l.getNextToken();
}

TEST_CASE(" Test Constants "){
    string filename = "../../inputs/constants.df";
    std::ifstream file(filename);
    REQUIRE(file.is_open());
    Lexer l(file);
    
    int tk = l.getNextToken();
    CHECK( tk == STRINGCONSTANT);
    CHECK( l.getLexeme() == "\"hello, world\"");
    tk = l.getNextToken();

    
    CHECK( tk == STRINGCONSTANT);
    CHECK( l.getLexeme() == "\"bye\"");
    tk = l.getNextToken();

    
    CHECK( tk == STRINGCONSTANT);
    CHECK( l.getLexeme() == "\"hey\\t you \\n \\'\"");
    tk = l.getNextToken();

    
    CHECK( tk == CHARCONSTANT);
    CHECK( l.getLexeme() == "\'h\'");
    tk = l.getNextToken();

    
    CHECK( tk == CHARCONSTANT);
    CHECK( l.getLexeme() == "\'Z\'");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "while333");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "43434");
    tk = l.getNextToken();

    
    CHECK( tk == ID);
    CHECK( l.getLexeme() == "lksdfsdalfj");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "99755752");
    tk = l.getNextToken();

    
    CHECK( tk == INTCONSTANT);
    CHECK( l.getLexeme() == "0x586FFF");
    tk = l.getNextToken();
    
    CHECK( tk == -1);
    tk = l.getNextToken();

}