/*
 * tools.h
 *
 *  Created on: 4 dec. 2019
 *      Authors: Wistaro & tyan
 */

#ifndef SRC_TOOLS_H_
#define SRC_TOOLS_H_

#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))

void Dly_ms(int ms);

int rnd(int lower, int upper);

#endif /* SRC_TOOLS_H_ */
