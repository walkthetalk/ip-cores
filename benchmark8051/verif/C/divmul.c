/*
 * Copyright (c) 1999-2001 Tony Givargis.  Permission to copy is granted
 * provided that this header remains intact.  This software is provided
 * with no warranties.
 *
 * Version : 2.9
 */

/*---------------------------------------------------------------------------*/

#include <8051.h>

/*---------------------------------------------------------------------------*/

void main() {
    
    unsigned x = 134;
    unsigned y = 1;
    unsigned q, r, p, i;
    
    for(i=0; i<12; i++) {
        
        y++;
    }
    
    q = x / y;
    r = x % y;
    p = q * y + r;
    
    P0 = q;
    P0 = r;
    P0 = p;
    if(p == 134 && r == 4 && q == 10) {
        P2 = 0xAA; // Pass Signature
        P3 = 0xAA;
    } else {
        P2 = 0x55; // Fail Signature
        P3 = 0x1;
   }
    
    while(1);
}
