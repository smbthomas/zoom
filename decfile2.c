//
//  main.c
//  decfile2 - program to decode Mandelbrot binary files
//  and outputs a JavaScript text array
//  Created by Stephen Martin Beynon Thomas on 28/05/2023.
//
// Useage: ./decfile zoom1.dat > zoom1.js

#include <stdio.h>
#include <stdlib.h>

// function to convert two hex chars into an integer
int convert(int b0, int b1) {
  char *word_buff = (char *) malloc(sizeof(char) * 5);
  // printf("%02x  ", b0);
  // printf("%02x\n", b1);

  sprintf(word_buff, "%02x%02x", b1, b0);
  // printf("%s\n", word_buff);

  return (int) strtol(word_buff, NULL, 16);
}

int main(int argc, const char * argv[]) {
  FILE *f;
  unsigned char word[2];
  long f_size;

  if (argc == 2) {
    if ((f = fopen(argv[1], "rb")) == NULL) {
      printf("Error! Unable to open '%s' file.\n", argv[1]);
      // Program exits if the file pointer returns NULL.
      return 1;
    }
    // get the size of the file
    fseek(f, 0L, SEEK_END);
    f_size = ftell(f);
    // re-set the file ptr to start of file
    fseek(f, 0L, SEEK_SET);
    // printf("%ld bytes\n", f_size);

    printf("const data = new Array(");
    for (int i = 0; i < f_size; i+=2) {
      fread(word, sizeof(word), 1, f);
      if (i < (f_size - 2)) {
        // printf("%02x%02x,", word[1], word[0]);
	// not the end of file so print number & comma
        printf("%d,", convert(word[0], word[1]));
      }
      else {
        // printf("%02x%02x);\n", word[1], word[0]);
	// end of file so print number followed by closing bracket & semi-colon
        printf("%d);\n", convert(word[0], word[1]));
      }
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
