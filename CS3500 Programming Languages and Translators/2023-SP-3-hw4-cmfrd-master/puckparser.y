%{
#include <iostream>
using namespace std;

extern int yylex();
extern int linenum;
extern char* yytext;
int yyerror(const char *p);
%}


%token INTEGER;
%token DECIMAL;
%token STRING;

%token COLON;
%token PERIOD;
%token LBRAC;
%token RBRAC;
%token LPAREN;
%token RPAREN;
%token PRINT;
%token Assign;
%token NEG;

%token Relation;
%token AddOperator;
%token MulOperator;

%token IDENT;

%%
StatementSequence : Statement { COLON Statement }
Statement : Assignment | PrintStatement

Assignment : Designator Assign Expression
PrintStatement :  PRINT LPAREN Expression RPAREN

Expression : SimpleExpression [ Relation SimpleExpression ]
SimpleExpression : Term { AddOperator Term }

Term : Factor { MulOperator Factor }
Factor : INTEGER | DECIMAL | STRING | IDENT | LPAREN Expression RPAREN | NEG Factor

Designator : IDENT { Selector }
Selector : PERIOD IDENT | KEYWORD Expression KEYWORD

%%

int yyerror(const char *p)
{
  cout << "ERROR: In line " << linenum << " with token \'"
  << yytext << "\'" << endl;
  return 0;
}

int main()
{
  int failcode;
  failcode = yyparse();

  if (failcode)
    cout << "INVALID!" << endl;
  else
    cout << "CORRECT" << endl;
  return 0;
}