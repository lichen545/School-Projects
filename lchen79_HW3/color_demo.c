#include <stdio.h>

#define TT_COLOR_CODE 0x1B
#define TT_COLOR_RED "[1;31m"
#define TT_COLOR_GREEN "[1;32m"
#define TT_COLOR_RESET "[0m"



void pstring_red(char s) {
  printf("%c%s%c%c%s", 
			TT_COLOR_CODE, TT_COLOR_RED, s, 
			TT_COLOR_CODE, TT_COLOR_RESET);
}

void pstring_green(char *s) {
  printf("%c%s%s%c%s", 
			TT_COLOR_CODE, TT_COLOR_GREEN, s, 
			TT_COLOR_CODE, TT_COLOR_RESET);
}

/*
int main(int argc, char *argv[]){
int i;

  pstring_red("RED:");
  for(i=1; i<argc; i++)
      pstring_red(argv[i]);
  pstring_green("GREEN:");
  for(i=1; i<argc; i++)
      pstring_green(argv[i]);
}*/
