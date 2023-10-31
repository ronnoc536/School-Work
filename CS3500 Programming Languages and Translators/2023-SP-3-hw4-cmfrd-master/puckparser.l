%{
  #include <iostream>
  #include "puckparser.tab.h"
  using namespace std;
  int linenum = 1;
%}

%option noyywrap

%%

[ \t] {}
[\n] {linenum++;}
[+-]*[0-9]+ {
  printf("TOKEN: INTEGER     LEXEME: %s\n", yytext);
  return INTEGER;
  }
[+-]*[0-9]+[.][0-9]+ {
  printf("TOKEN: DECIMAL      LEXEME: %s\n", yytext);
  return DECIMAL;
  }
["][^""]+["] {
  printf("TOKEN: STRING      LEXEME: %s\n", yytext);
  return STRING;
  }
; {
  printf("TOKEN: KEYWORD      LEXEME: %s\n", yytext);
  return COLON;
}
. {
  printf("TOKEN: KEYWORD      LEXEME: %s\n", yytext);
  return PERIOD;
}
[[] {
  printf("TOKEN: K_LBRAC      LEXEME: %s\n", yytext);
  return LBRAC;
  }
[]] {
  printf("TOKEN: K_RBRAC      LEXEME: %s\n", yytext);
  return RBRAC;
  }
[(] {
  printf("TOKEN: K_LPAREN      LEXEME: %s\n", yytext);
  return LPAREN;
  }
[)] {
  printf("TOKEN: K_RPAREN      LEXEME: %s\n", yytext);
  return RPAREN;
  }
PRINT {
  printf("TOKEN: K_PRINT       LEXEME: %s\n", yytext);
  return PRINT;
  }
:= {
  printf("TOKEN: OP_ASSIGN    LEXEME: %s\n", yytext);
  return Assign;
}
~ {
  printf("TOKEN: OP_NEG    LEXEME: %s\n", yytext);
  return NEG;
}
[<>=#] {
  printf("TOKEN: OP_RELATION   LEXEME: %s\n", yytext);
  return Relation;
}
[+&-]|OR {
  printf("TOKEN: OP_ADD        LEXEME: %s\n", yytext);
  return AddOperator;
}
[*/]|AND {
  printf("TOKEN: OP_MULT       LEXEME: %s\n", yytext);
  return MulOperator;
}
[a-zA-Z][a-zA-z0-9_]* {
  printf("TOKEN: IDENT       LEXEME: %s\n", yytext);
  return IDENT;
}

%%