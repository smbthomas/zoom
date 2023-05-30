//
//  main.c
//  decfile - program to decode Mandelbrot binary files
//  and outputs a JavaScript text array
//  Created by Stephen Martin Beynon Thomas on 28/05/2023.
//
// Useage: ./decfile zoom1.dat > zoom1.js

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
  FILE *f;
  unsigned char byte;
  long f_size;
  
  if (argc == 2) {
    if ((f = fopen(argv[1], "rb")) == NULL) {
      printf("Error! Unable to open '%s' file.\n", argv[1]);
      // Program exits if the file pointer returns NULL.
      return 1;
    }
    fseek(f, 0L, SEEK_END);
    f_size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    
    printf("const data = new Array(");
    for (int i = 0; i < f_size; i++) {
      fread(&byte, sizeof(byte), 1, f);
      if (i < (f_size - 1))
        printf("%u,", byte);
      else
        printf("%u);\n", byte);
    }
    fclose(f);
  }
  else if (argc > 2) {
    printf("Too many arguments supplied.\n");
    return 1;
  }
  else {
    printf("One argument expected.\n");
    return 1;
  }
  return 0;
}

