/*****************************************************************************
* Filename:          /home/cc/cs150/sp13/class/cs150-ac/microblaze_fft/drivers/fft_coprocessor_v1_00_a/src/fft_coprocessor.h
* Version:           1.00.a
* Description:       fft_coprocessor (invoke the FFT coprocessor) Driver Header File
* Date:              Tue Apr  9 19:58:20 2013 (by Create and Import Peripheral Wizard)
*****************************************************************************/

#ifndef FFT_COPROCESSOR_H
#define FFT_COPROCESSOR_H

#include "xstatus.h"

#include "fsl.h" 
#define write_into_fsl(val, id)  putfsl(val, id)
#define read_from_fsl(val, id)  getfsl(val, id)

/* Definitions for peripheral FFT_COPROCESSOR_0 */
#define XPAR_FSL_FFT_COPROCESSOR_0_INPUT_SLOT_ID 0
#define XPAR_FSL_FFT_COPROCESSOR_0_OUTPUT_SLOT_ID 0
#define XPAR_FSL_FFT_COPROCESSOR_0_INPUT_SIZE 1024
#define XPAR_FSL_FFT_COPROCESSOR_0_OUTPUT_SIZE 1024

/*
* A macro for accessing FSL peripheral.
*
* This example driver writes all the data in the input arguments
* into the input FSL bus through blocking writes. FSL peripheral will
* automatically read from the FSL bus. Once all the inputs
* have been written, the output from the FSL peripheral is read
* into output arguments through blocking reads.
*
* Arguments:
*	 input_slot_id
*		 Compile time constant indicating FSL slot from
*		 which coprocessor read the input data. Defined in
*		 xparameters.h .
*	 output_slot_id
*		 Compile time constant indicating FSL slot into
*		 which the coprocessor write output data. Defined in
*		 xparameters.h .
*	 input_0    An array of unsigned integers. Array size is 1024
*	 output_0   An array of unsigned integers. Array size is 1024
*
* Caveats:
*    The output_slot_id and input_slot_id arguments must be
*    constants available at compile time. Do not pass
*    variables for these arguments.
*
*    Since this is a macro, using it too many times will
*    increase the size of your application. In such cases,
*    or when this macro is too simplistic for your
*    application you may want to create your own instance
*    specific driver function (not a macro) using the 
*    macros defined in this file and the slot
*    identifiers defined in xparameters.h .  Please see the
*    example code (fft_coprocessor_app.c) for details.
*/

#define  fft_coprocessor(input_0, output_0)\
{\
   int i,d;\
   for (i=0; i<1024; i++)\
      write_into_fsl((u32)input_0[i], 0);\
   for (i=0; i<1024; i++) {\
      read_from_fsl(d, 0);\
      output_0[i] = (u16)d;\
   }\
}
#endif 