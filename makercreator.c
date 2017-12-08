#include "stdio.h"
#include <stdlib.h>

void generateMaker(){
  FILE *fptr;
  char name[100];

  char script[512];
  snprintf(script, sizeof script, "%s", 

      "#!/bin/bash\n"
      "function getStat(){\n"
      "  declare -a ARRAY\n"
      "  count=0;\n"
      "  for file in *.cpp\n"
      "  do\n"
      "    ARRAY[$count]=$file;\n"
      "    ((count++));\n"
      "  done\n"
      "  for((i=0;i<${#ARRAY[@]};i++)){\n"
      "    printf \"%s -- \" \"${ARRAY[$i]}\";\n"
      "    stat -c %Z ${ARRAY[$i]};\n"
      "  }\n"
      "}\n"
      "while :\n"
      "do\n"
      "  getStat;\n"
      "  sleep 2;\n"
      "  clear\n"
      "done\n");
  fptr = fopen("program.txt", "w");
  if(fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  printf("Enter a sentence:\n");
  fgets(name,100,stdin);

  fprintf(fptr,"%s%s", name,script);
  fclose(fptr);
}

int main(){
  generateMaker();
}
