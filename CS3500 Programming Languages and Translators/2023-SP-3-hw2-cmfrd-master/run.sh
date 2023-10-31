#!/bin/bash
flex mylexer.l
g++ lex.yy.c -lfl -o lexer.ex
./lexer.ex < sampleinput.txt
