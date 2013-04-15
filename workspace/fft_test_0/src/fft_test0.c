/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "platform.h"

void print(char *str);
void xil_printf(char *str, ...);

void fftREPL();
//void parseREPL();
//void echoREPL();
int parseNum();
int parseInputs(u16 *);
#define REPL_SUCCESS -1
void printOutputs();

#define ECHO_ONLY
//#define REPL_ONLY

#define BUF_SIZE 1024
#define NL "\n\r"

int main()
{
    init_platform();

    print(NL "FFT Test 0" NL);

//    echoREPL();
    fftREPL();
//    parseREPL();

    cleanup_platform();

    return 0;
}

/*
 * Gets and prints the inputted character.
 */
#define gpchar(c) { \
	while( !(c=getchar()) ); \
	if (c=='\r') print("\n"); \
	xil_printf("%c",c); \
	}

/*
 * Passes stdin to stdout.
 */
/*
void echoREPL()
{
	char c;
	while(1) gpchar(c);
}
//*/
/*
 * Read-eval-print loop. This reads the inputs, pushes it to the FFT, and
 * prints the output.
 */
void fftREPL()
{
    u16 buffer[BUF_SIZE];
    int success,k;
    k=0;

    while(1) {
    	xil_printf("%d: Please input " stringify(BUF_SIZE) " samples:" NL, k++);

		success = parseInputs(buffer);
		if (success != REPL_SUCCESS) {
			xil_printf(NL "#### Parse failed at line %d. ####" NL, success);
			continue;
		}

		fft_coprocessor(buffer, buffer); // overwrite inputs with outputs

		print("#### Processing... ####" NL);
		printOutputs(buffer);
		print("#### DONE ####" NL);

    }
}
/*
void parseREPL()
{
	int i;
	u16 buffer[BUF_SIZE];

	while(1) {
		print("Please input " stringify(BUF_SIZE) " numbers: \r\n");
		for (i=0; i<BUF_SIZE; i++) {
			print(">> ");
			buffer[i] = parseNum();
		}
		printOutputs(buffer);
	}
}
//*/
/*
 * Gobbles a string with a number and returns an int. returns -1 on fail.
 */
int parseNum()
{
	int d = 0;
	char c;
	gpchar(c);
	if (!isdigit(c)) return -1;
	while (isdigit(c)) {
		if (isdigit(c)) d = d*10 + (c-'0');
		do {
			gpchar(c);
		} while(!c) ;
	}
	return d;
}

/*
 * Eats one CR. Echoes its input.
 * Returns whether it saw a CR.
 */
/*
char gobbleCR()
{
	char c;
	gpchar(c);
	return c=='\r';
}
//*/
/*
 * Reads decimal numbers from stdin and puts them into an array.
 * One number per line, separated by any number of \n or \r.
 * @param(inputs) is a pointer to an array of u32's where we will dump the parsed numbers.
 * @returns whether 1024 numbers were parsed correctly.
 */
int parseInputs(u16 *inputs)
{
	int i;
	for (i = 0; i < BUF_SIZE; i++)
	{
		inputs[i] = parseNum();
		if (inputs[i] == -1) return i;
	}

	return REPL_SUCCESS;
}

/*
 * Prints the decimal numbers in input to stdout, one number per line.
 */
void printOutputs(u16 *outputs)
{
	int i;
	for (i=0; i < BUF_SIZE; i++)
	{
		xil_printf("%d" NL, outputs[i]);
	}
}
