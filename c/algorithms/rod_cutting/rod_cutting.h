/******************************************************************************
 * File: rod_cutting.c
 * Author: Patrick Payne
 * Date Created: May 18, 2014
 * Purpose: Implements the rod cutting algorithm, as presented in CLRS.
 * Copyright 2014 by Patrick Payne.
 *****************************************************************************/

#ifndef SNIPPET_C_ROD_CUTTING_H_
#define SNIPPET_C_ROD_CUTTING_H_

/*! @brief Given the array of length costs, prints out the optimal rod cutting.
 *  @param prices The prices of each integer length of rod.
 *  @param max_cut_length The largest length customers will pay for.
 *  @param length The length of the full rod to be cut.
 *  @param cuts A pointer to the resulting list of cut lengths for the optimal
 *      case.
 *  @return The profit from this optimal cutting.
 */
int RodCutting(int *prices, int max_cut_length, int length, int **cuts,
               int *num_cuts);

#endif /* SNIPPET_C_ROD_CUTTING_H_ */
