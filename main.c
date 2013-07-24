/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;

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


