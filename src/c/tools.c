/*
 * tools.c
 *
 *  Created on: 4 dec. 2019
 *     Authors: Wistaro & tyan
 */

#include "tools.h"
#include <stdio.h>
#include <stdlib.h>

void Dly_ms(int ms)
{
   int ii,jj;
   if (ms<1) ms=1;
   for(ii=0;ii<ms;ii++)
   for(jj=0;jj<13352;jj++);    //busclk:80MHz--1ms
}


int rnd(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;

}
