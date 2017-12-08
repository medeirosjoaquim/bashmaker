#include "stdio.h"
#include <stdlib.h>

void generateMaker(){
  FILE *fptr;
  char name[100];

  fptr = fopen("program.txt", "w");
  if(fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  printf("Enter a sentence:\n");
   fgets(name,100,stdin);

 fprintf(fptr,"%s", name);
  fclose(fptr);
}

int main(){
  generateMaker();
}
