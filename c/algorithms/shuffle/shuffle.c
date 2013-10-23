/******************************************************************************
 * File: shuffle.c
 * Author: Patrick Payne
 * Date Created: Oct 22, 2013
 * Purpose: Shuffles an array of integers. Just the basic Fisher-Yates shuffle.
 * Copyright 2013 by Patrick Payne.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 20

/*! @brief Shuffles the array 'list' with number of elements 'size'. */
void Shuffle(int *list, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    int rand_index = (rand() % (size - i)) + i;
    int temp = list[rand_index];
    list[rand_index] = list[i];
    list[i] = temp;
  }
}

int main(void) {
  // Just do a test run of the program.
  int test_list[TEST_SIZE];
  for (int i = 0; i < TEST_SIZE; i++) {
    test_list[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    Shuffle(test_list, TEST_SIZE);

    // Now show the shuffled list.
    printf("[%d", test_list[0]);
    for (int j = 1; j < TEST_SIZE; j++) {
      printf(", %d", test_list[j]);
    }
    printf("]\n");
  }
}
