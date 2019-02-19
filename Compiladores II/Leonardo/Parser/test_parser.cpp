#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "lexer.h"
#include "error.h"
#include <fstream>

void * ParseAlloc(void*(*mallocProc)(size_t));
void Parse(void*, int yymayor, int yyminor);
void ParseFree(void*, void (*freeProc)(void*));

Lexer * l;

void parse(istream & file){
    void * pParse = ParseAlloc(malloc);

    l = new Lexer(file);
    int tok = l->getNextToken();

    while(tok != 0){
        Parse(pParse, tok, 0);
        tok = l->getNextToken();
    }
    Parse(pParse, 0, 0);
    ParseFree(pParse, free);
}

TEST_CASE("Id-Method Declaration"){
    string filename = "../test_parser/Files/Id-Method Declaration.txt";
    ifstream file(filename);
    REQUIRE(file.is_open());

    bool parseSuccess;

    try{
        parse(file);
        parseSuccess = true;
    }catch(TError &err){
        cout << err.getErrorMessage() << endl;
        parseSuccess = false;
    }

    CHECK(parseSuccess);
}

TEST_CASE("Assign Test"){
    string filename = "../test_parser/Files/Assign Test.txt";
    ifstream file(filename);
    REQUIRE(file.is_open());

    bool parseSuccess;

    try{
        parse(file);
        parseSuccess = true;
    }catch(TError &err){
        cout << err.getErrorMessage() << endl;
        parseSuccess = false;
    }

    CHECK(parseSuccess);
}

TEST_CASE("For Test"){
    string filename = "../test_parser/Files/For Test.txt";
    ifstream file(filename);
    REQUIRE(file.is_open());

    bool parseSuccess;

    try{
        parse(file);
        parseSuccess = true;
    }catch(TError &err){
        cout << err.getErrorMessage() << endl;
        parseSuccess = false;
    }

    CHECK(parseSuccess);
}

TEST_CASE("While Test"){
    string filename = "../test_parser/Files/While Test.txt";
    ifstream file(filename);
    REQUIRE(file.is_open());

    bool parseSuccess;

    try{
        parse(file);
        parseSuccess = true;
    }catch(TError &err){
        cout << err.getErrorMessage() << endl;
        parseSuccess = false;
    }

    CHECK(parseSuccess);
}

TEST_CASE("If Test"){
    string filename = "../test_parser/Files/If Test.txt";
    ifstream file(filename);
    REQUIRE(file.is_open());

    bool parseSuccess;

    try{
        parse(file);
        parseSuccess = true;
    }catch(TError &err){
        cout << err.getErrorMessage() << endl;
        parseSuccess = false;
    }

    CHECK(parseSuccess);
}