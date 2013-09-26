/******************************************************************************
 * File: test_ackerman.s
 * Author: Patrick Payne
 * Date Created: Sep 26, 2013
 * Purpose: Tests the assembly implementation of the ackerman function in
 *    ackerman.s.
 *****************************************************************************/ 
.equ ADDR_GREENLEDS, 	0x10000010
.equ ADDR_REDLEDS, 	0x10000000

.text
.global _start
.global ackerman

_start:
  # ackerman(0, 0) == 1
  movi r4, 0
  movi r5, 0
  call ackerman
  movi r8, 1
  bne r2, r8, BAD

  # ackerman(10, 0) == 1
  movi r4, 10
  movi r5, 0
  call ackerman
  movi r8, 1
  bne r2, r8, BAD
 
  # ackerman(10, 1) == 1
  movi r4, 10
  movi r5, 1
  call ackerman
  movi r8, 1
  bne r2, r8, BAD

GOOD:
	# turn on green LEDS
  movia	r2, ADDR_GREENLEDS
  movi	r3, -1
  stwio	r3,0(r2)
  br	DONE

BAD:
	# turn on red LEDS
  movia	r2, ADDR_REDLEDS
  movi	r3, -1
  stwio	r3,0(r2)

DONE:
  br DONE
