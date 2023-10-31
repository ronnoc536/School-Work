/********************************************************
* Connor Marler
********************************************************/
// -- PREAMBLE ------------------------------------------
%{
#include <iostream>
using namespace std;
// Things from Flex that Bison needs to know
extern int yylex();
extern int numLines;
extern char* yytext;

// Prototype for Bison's error message function
int yyerror(const char *p);
%}
//-- TOKEN DEFINITIONS --
// what tokens to expect from Flex
%token T_INTEGER
%token T_DECIMAL
%token T_STRING
%token T_IDENT

%token K_IF
%token K_THEN
%token K_ELSE
%token K_ENDIF
%token K_SC
%token K_WHILE
%token K_DO
%token K_ENDW
%token K_LPAREN
%token K_RPAREN
%token K_PRINT

%token OP_ASSIGN
%token OP_NEG
%token OP_RELATION
%token OP_ADD
%token OP_MULT

%%


//-- GRAMMAR RULES ------------------------------------
/* NOTE: Bison likes the start symbol to be the first rule */
StatementSequence : Statement
{ cout << "RULE: StatementSequence ::= Statement" << endl; }
| Statement K_SC StatementSequence
{ cout << "RULE: StatementSequence ::= Statement ; StatementSequence" << endl; }
Statement : Assignment
{ cout << "RULE: Statement ::= Assignment" << endl; }
| PrintStatement
{ cout << "RULE: Statement ::= PrintStatement" << endl; }
| IfStatement
{cout << "RULE: Statement ::= IfStatement" << endl;}
| WhileStatement
{cout << "RULE: Statemenr ::= WhileStatement" << endl;}
;
Assignment : T_IDENT OP_ASSIGN Expression
{ cout << "RULE: Assignment ::= T_IDENT := Expression" << endl; }
;
PrintStatement : K_PRINT K_LPAREN Expression K_RPAREN
{ cout << "RULE: PrintStatement ::= PRINT ( Expression )" << endl;}
;
Expression : SimpleExpression
{cout << "RULE: Expression ::= SimpleExpression" << endl;}
| SimpleExpression OP_RELATION Expression
{cout << "RULE: Expression ::= SimpleExpression OP_RELATION Expression" << endl;}
;
SimpleExpression : Term
{cout << "RULE: SimpleExpression ::= Term" << endl;}
| Term OP_ADD SimpleExpression
{cout << "RULE: SimpleExpression ::= Term OP_ADD SimpleExpression" << endl;}
;
Term : Factor
{cout << "RULE: Term ::= Factor" << endl;}
| Factor OP_MULT Term
{cout << "RULE: Term  ::= Factor OP_MULT Term" << endl;}
;
Factor : T_INTEGER
{cout << "RULE: Factor ::= T_INTEGER" << endl;}
| T_DECIMAL
{cout << "RULE: Factor ::= T_DECIMAL" << endl;}
| T_STRING
{cout << "RULE: Factor ::= T_STRING" << endl;}
| T_IDENT
{cout << "RULE: Factor ::= T_IDENT" << endl;}
| K_LPAREN Expression K_RPAREN
{cout << "RULE: Factor ::= ( Expression )" << endl;}
| OP_NEG Factor
{cout << "RULE: Factor ::= ~ Factor" << endl;}
;
IfStatement : K_IF Expression K_THEN StatementSequence K_ENDIF
{cout << "RULE: IfStatement ::= IF Expression THEN StatementSequence ENDIF" << endl;}
| K_IF Expression K_THEN StatementSequence K_ELSE StatementSequence K_ENDIF
{cout << "RULE: IfStatement ::= IF Expression THEN StatementSequence ELSE StatementSequence ENDIF" << endl;}
;
WhileStatement : K_WHILE Expression K_DO StatementSequence K_ENDW
{cout << "RULE: WhileStatement ::= WHILE Expression DO StatementSequence ENDW" << endl;}
;
%% //-- EPILOGUE ---------------------------------------------
// Bison error function
int yyerror(const char *p)
{
cout << "ERROR: In line " << numLines << " with token \'"
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