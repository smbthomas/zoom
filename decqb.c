//
//  main.c
//  decqb - program to decode Mandelbrot qb files
//  and outputs a JavaScript text array
//  Created by Stephen Martin Beynon Thomas on 28/05/2023.
//
// Useage: ./decqb zoom1.qb > zoom1.js

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
  FILE *f;
  unsigned char *buffer; 
  double number;
  long f_size;

  if (argc == 2) {
    if ((f = fopen(argv[1], "rb")) == NULL) {
      printf("Error! Unable to open '%s' file.\n", argv[1]);
      // Program exits if the file pointer returns NULL.
      // return 1;
    }

    fseek(f, 0L, SEEK_END);
    f_size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    // printf("%ld\n", f_size);

    buffer = (unsigned char *)  malloc(sizeof(unsigned char) * f_size);
    fread(buffer, f_size, 1, f);
    fclose(f);

    printf("const info = new Array(");
    for (int i = 0; i < f_size; i++) {
      int c = buffer[i];
      if (c != 0x0f) {
        if (c != 0x20) {
          printf("%c", buffer[i]);
        }
      }
      else {
        if ((i > 0) && (i < f_size - 1)) {
          printf(", ");
        }
      }	
    }
    printf(");\n");
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

