/* Connor Marler */


/* A starting flex file */
		               /* ---- PROLOGUE ---- */
%{
#include <iostream>
using namespace std;

int no_lines = 0;
int no_tokens = 1;

void print_token_info(int no_tokens, const char* token_type, const char* lexeme);

%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap
WSPACE		[ \t\v\r]+
NEWLINE     \n
DIGIT		[0-9]
NONZERODIG  [1-9]
LETTER      [a-zA-Z]
HEX         [A-F]

INTCONST    (\+|-)?{DIGIT}+
NONZEROINT	(\+|-)?{NONZERODIG}+
DECCONST	{INTCONST}\.{DIGIT}+
SCICONST    {DECCONST}("E"){NONZEROINT}
HEXCONST    ({HEX}|{DIGIT})+("H")
BINCONST    [0-1]+("B")
STRCONST    \".*\"
CHCONST     [A-F0-9]][A-F0-9]("X")
IDENT       ({LETTER})+({LETTER}|{DIGIT}|_)* 
COMMENT     \%.*\n

%%  		              /* ---- REGULAR EXPRESSIONS ---- */

"+"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"-"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"*"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"/"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"<"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
">"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"="		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"&"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"#"		{
		print_token_info(no_tokens, "OPERATOR", yytext);
        no_tokens++;
		}
"FUNCTION"		{
		print_token_info(no_tokens, "KEYWORD", yytext);
        no_tokens++;
		}
"IF"		{
		print_token_info(no_tokens, "KEYWORD", yytext);
        no_tokens++;
		}
"WHILE"		{
		print_token_info(no_tokens, "KEYWORD", yytext);
        no_tokens++;
		}
"PRINT"		{
		print_token_info(no_tokens, "KEYWORD", yytext);
        no_tokens++;
		}
{INTCONST}	{
		print_token_info(no_tokens, "INTCONST", yytext);
        no_tokens++;
		}
{DECCONST}	{
		print_token_info(no_tokens, "DECCONST", yytext);
        no_tokens++;
		}
{SCICONST}	{
		print_token_info(no_tokens, "SCICONST", yytext);
        no_tokens++;
		}
{HEXCONST}	{
		print_token_info(no_tokens, "HEXCONST", yytext);
        no_tokens++;
		}
{BINCONST}	{
		print_token_info(no_tokens, "BINCONST", yytext);
        no_tokens++;
		}
{STRCONST}	{
		print_token_info(no_tokens, "STRCONST", yytext);
        no_tokens++;
		}
{CHCONST}	{
		print_token_info(no_tokens, "CHCONST", yytext);
        no_tokens++;
		}

{IDENT}	{
		print_token_info(no_tokens, "IDENT", yytext);
        no_tokens++;
		}
{COMMENT}       {}
{NEWLINE}   {
        no_lines++;
}
{WSPACE}	{}
.       {
        print_token_info(no_tokens, "?", yytext);
        no_tokens++;
}


%%  		              /* ---- EPILOGUE ---- */

void print_token_info(int no_tokens, const char* token_type, const char* lexeme) 
{
  printf("%i: TOKEN: %-20s LEXEME: %s\n", no_tokens, token_type, lexeme);
}

int main(void) 
{
  while ( yylex() ) ;
  cout << no_lines << " lines processed." << endl;
  return 0;
}

