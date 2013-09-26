/******************************************************************************
 * File: ackerman.s
 * Author: Patrick Payne
 * Date Created: Sep 26, 2013
 * Purpose: Implements the Ackerman function, which has the following C
 *    pseudocode:
 *
 * int ackerman(int x, int y) {
 *    if (x == 0) return y + 1;
 *    else if (y = 0) return ackerman(x - 1, y);
 *    else return ackerman(x - 1, ackerman(x, y - 1));
 * }
 *****************************************************************************/ 
.text
.global ackerman

/******************************************************************************
 * The body of the ackerman function starts here.
 *****************************************************************************/ 
ackerman:
  # Save the return address and x input registers.
  subi sp, sp, 8
  stw ra, 4(sp)
  stw r4, 0(sp)

  # Check for each case, branching appropriately.
  beq r4, zero, X_IS_ZERO
  beq r5, zero, Y_IS_ZERO
  br NEITHER_IS_ZERO
  
X_IS_ZERO:
  addi r2, r5, 1
  br EPILOGUE

Y_IS_ZERO:
  # We need (x - 1) as the argument to this recursive ackerman call.
  subi r4, r4, 1
  call ackerman
  br EPILOGUE

NEITHER_IS_ZERO:
  # First get ackerman(x, y - 1)
  subi r5, r5, 1
  call ackerman

  # Now get ackerman(x-1, ackerman(x, y - 1))
  subi r4, r4, 1
  mov r2, r5
  call ackerman
  br EPILOGUE

EPILOGUE:
  ldw r4, 0(sp)
  ldw ra, 4(sp)
  addi sp, sp, 8
  ret
