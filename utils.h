#ifndef UTILS_H
#define UTILS_H

/* tipi di comodità */

typedef char* string;
typedef char bool;
enum boolean{false,true};

#define PROGNAME argv[0]

/* macro per stringhe */

#define newstring(len) (char*)calloc(len,sizeof(char))
#define startWith(str,chr) (str[0]==chr)
#define isFlag(str) startWith(str,'-')
#define eql(str1,str2) (strcmp(str1,str2)==0)

#endif