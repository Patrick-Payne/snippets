/******************************************************************************
 * File: rod_cutting.c
 * Author: Patrick Payne
 * Date Created: May 18, 2014
 * Purpose: Carries out the rod-cutting algorithm. Based on the bottom up
 *     algorithm presented in chapter 15.1 of CLRS.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/

#include <stdlib.h>
#include "rod_cutting.h"

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))


/*! @brief Given the array of length costs, prints out the optimal rod cutting.
 *  @param prices The prices of each integer length of rod.
 *  @param max_cut_length The largest length customers will pay for.
 *  @param length The length of the full rod to be cut.
 *  @param cuts A pointer to the resulting list of cut lengths for the optimal
 *      case.
 *  @return The profit from this optimal cutting. -1 upon error.
 */
int RodCutting(int *prices, int max_cut_length, int length, int **cuts,
               int  *num_cuts) {
  /* Create the arrays into which we put the recursive results. We don't keep
   * an entry for a rod of length 0.
   */
  int *revenues = calloc(max_cut_length, sizeof(int));
  if (!revenues) {
    return -1;
  }

  int *first_piece = calloc(max_cut_length, sizeof(int));
  if (!first_piece) {
    free(revenues);
    return -1;
  }

  // Set the values for the base case of a rod of length 1.
  first_piece[0] = 1;
  revenues[0] = prices[0];

  for (int i = 1; i < length; i++) {
    int max_cut = MIN(i + 1, max_cut_length);

    int curr = prices[max_cut - 1];
    first_piece[i] = max_cut;

    for (int j = 0; j < max_cut - 1; j++) {
      if (curr < prices[j] + revenues[i - j - 1]) {
        curr = prices[j] + revenues[i - j - 1];
        first_piece[i] = j + 1;
      }
    }
    revenues[i] = curr;
  }

  // Find out how many members are in the solution.
  *num_cuts = 0;
  int remaining_length = length;
  while (remaining_length > 0) {
    (*num_cuts)++;
    remaining_length -= first_piece[remaining_length - 1];
  }

  // Now generate the solution to the rod cutting problem.
  *cuts = calloc(*num_cuts, sizeof(int));
  if (*cuts == NULL) {
    free(revenues);
    free(first_piece);
    return -1;
  }

  remaining_length = length;
  int n = 0;
  while (remaining_length > 0) {
    (*cuts)[n++] = first_piece[remaining_length - 1];
    remaining_length -= first_piece[remaining_length - 1];
  }
  int total_revenue = revenues[length - 1];
  free(revenues);
  free(first_piece);
  return total_revenue;
}
