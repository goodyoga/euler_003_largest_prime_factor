/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;

//
// @startuml
// participant defaults
// participant divider
// participant cur
// 
// note over defaults,cur:  [Problem 3] Largest prime factor
// 
// break h option
// defaults->defaults: PRINT(usage)
// defaults->defaults: exit(EXIT_SUCCESS)
// end
// defaults->defaults: a number = 600851475143UL;
// opt n option
// defaults->defaults: a number = value by cmdline
// end
// 
// cur->cur: cur = a number
// divider->divider:divider = 2 
// note right of divider: 2 is the smallest prime number as a factor.
// 
// loop divider
// note over divider,cur
// this loop finds a number's factors begining from small factor.
// so, if we got all factors, the last one is the largest prime factor.
// 
// example: a number: 90
// 
// cur = 90, divider = 2 : is a factor
// cur = 45, divider = 2 : is not a factor
//     divider++
// cur = 45, divider = 3 : is a factor
// cur = 15, divider = 3 : is a factor again
// cur = 5, divider = 3 : is not a factor
//     divider++
// cur = 5, divider = 4 : is not a factor
//     /*****
//      * 4 is not a prime number.
//      * but we already divided a number by smaller prime numbers as a factor(i.e. 2 or 3, here).
//      * so we can safely ignore the "divider" that is not a prime number.
//      * if we can divide "cur", it is a prime factor.
//      *****/
//    divider++
// cur = 5, divider = 5 : is a factor
// now cur == divider, so 5 is the largest prime factor
// end note
// break divider==cur
// note over divider,cur: end
// end
// 
// alt divider is a factor(cur % divider == 0)
// cur->cur: cur = cur/divider
// else not a factor
// divider->divider: divider++
// note over divider: try next factor
// end 
// 
// end loop
// 
// cur->cur: PRINT(cur)
// @enduml
//

int main(int argc, char **argv)
{
    unsigned long long int number = 600851475143UL;
    unsigned long long int cur, divider;
    int opt;
    char *p;
    prog = argv[0];

    while ( -1 != (opt = getopt(argc, argv, "hn:")) )
    {
        if('h' == opt)
        {
            usage();
            exit(EXIT_SUCCESS);
        }
        else if ('n' == opt)
        {
            number = strtoull(optarg, &p, 0);
        }
    }
    
    printf("getting largest prime factor of %llu...\n", number);

    cur = number;
    divider = 2;
loop2:
    if (divider == cur) goto solved;
    if (0 == (cur % divider))
    {
         printf("cur / divider: %llu / %llu = %llu\n", cur, divider, cur / divider);
         cur = cur / divider;
         goto loop2;
    }
    else
    {
        divider++;
    }
    goto loop2;

solved:
    printf("largest cur: %llu\n", cur);

    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=3\n");
    printf("    [Problem 3] Largest prime factor\n");
    printf("    The prime factors of 13195 are 5, 7, 13 and 29.\n"
           "    What is the largest prime factor of the number 600851475143 ?\n\n");
    printf("    -h: show this help\n"
           "    -n <number>: solve this with <number>\n");
    return;
}


