%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {CP}
%define parser_class_name {Parser}

%code requires{
   namespace CP {
      class Driver;
      class Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
    #include "driver.hpp"
    #include "parser.hpp"
    #include "scanner.hpp"

    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token               END    0     "end of file"
%token               UPPER
%token               LOWER
%token <std::string> WORD
%token               NEWLINE
%token               CHAR

%locations

%%

list_option : END | list END;

list
  : item
  | list item
  ;

item
  : UPPER   {  }
  | LOWER   {  }
  | WORD    {  }
  | NEWLINE {  }
  | CHAR    {  }
  ;

%%


void 
CP::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
