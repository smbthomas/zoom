//
//  main.c
//  decfile - program to decode Mandelbrot binary files
//  and outputs a JavaScript text array
//  Created by Stephen Martin Beynon Thomas on 28/05/2023.
//
// Useage: ./decfile zoom1.dat > zoom1.js

#include <stdio.h>
#include <stdlib.h>

int main() {
  int counter = 0;

  printf("const redp = new Array(");
  for(int i = 0; i <= 255; i++) {
    printf("%d,", 0);
    counter++;
  }
  for(int i = 256; i < 511; i++) {
    printf("%d,", i-256);
    counter++;
  }
  counter++;
  printf("%d);\n", 255);
  printf("// counter = %d\n\n", counter);
  
  counter = 0;
  printf("const greenp = new Array(");
  for(int i = 0; i <= 255; i++) {
    printf("%d,", 0);
    counter++;
  }
  for(int i = 0; i < 255; i++) {
    printf("%d,", 0);
    counter++;
  }
  counter++;
  printf("%d);\n\n", 0);
  printf("// counter = %d\n\n", counter);

  counter = 0;
  printf("const bluep = new Array(");
  for(int i = 0; i <= 255; i++) {
    printf("%d,", i);
    counter++;
  }
  for(int i = 0; i < 255; i++) {
    printf("%d,", 255);
    counter++;
  }
  counter++;
  printf("%d);\n\n", 255);
  printf("// counter = %d\n\n", counter);

  return 0;
}
