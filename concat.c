//
//  concat.c
//
//  Program to test joining hex values of two char variables
//  as char* and printing out result as an int
//  Created by Stephen Martin Beynon Thomas on 30/05/2023.
//

#include <stdio.h>
#include <stdlib.h>

int convert(int b0, int b1) {
  char *word = (char *) malloc(sizeof(char) * 5);
  printf("%02x  ", b0);
  printf("%02x\n", b1);

  sprintf(word, "%02x%02x", b1, b0);
  printf("%s\n", word);

  return (int) strtol(word, NULL, 16);
}

int main() {
  printf("%d\n", convert(0xce, 0x01));
  printf("%d\n", convert(0x40, 0x01));
  printf("%d\n", convert(0xe2, 0x00));
  printf("%d\n", convert(0x2c, 0x01));
  printf("%d\n", convert(0xc7, 0x00));

  return 0;
}

