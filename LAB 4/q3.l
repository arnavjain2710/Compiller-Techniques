%{
#include<stdio.h>
#include<stdlib.h>
int a=0,b=0,c=0,d;
%}
%x COMMENT   
 /* an exclusive state that does not also match normal stuff */
%%
"//".*   {a++;}
"/*"     { BEGIN COMMENT; }
<COMMENT>"*/" {c++; BEGIN INITIAL; }
<COMMENT>.    ;
%%
void main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    yylex();
    printf("single line %d \nmultiline %d \n",a,c);
    d=a+c;
    printf("total %d \n",d);
}

// commands:
// lex -o q3.c q3.l
// gcc q3.c -ll -o q3
// ./q3 dum.c