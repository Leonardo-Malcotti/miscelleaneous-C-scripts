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
#define isLowerCase(chr) (chr>='a' && chr<='z')
#define ToUp(chr) (chr - ('a'-'A'))
#define ToLow(chr) (chr + ('a'-'A'))


string strToUpper(string s){
	string ret = newstring(strlen(s));
	int i;
	for(i=0;i<strlen(s);i++){
		ret[i] = (isLowerCase(s[i])) ? ret[i] = ToUp(s[i]) : s[i];
	}
	return ret;
}

#endif
