//----------------------------------------------------------------------------
// fft_coprocessor - module
//----------------------------------------------------------------------------
// IMPORTANT:
// DO NOT MODIFY THIS FILE EXCEPT IN THE DESIGNATED SECTIONS.
//
// SEARCH FOR --USER TO DETERMINE WHERE CHANGES ARE ALLOWED.
//
// TYPICALLY, THE ONLY ACCEPTABLE CHANGES INVOLVE ADDING NEW
// PORTS AND GENERICS THAT GET PASSED THROUGH TO THE INSTANTIATION
// OF THE USER_LOGIC ENTITY.
//----------------------------------------------------------------------------
//
// ***************************************************************************
// ** Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.            **
// **                                                                       **
// ** Xilinx, Inc.                                                          **
// ** XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"         **
// ** AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND       **
// ** SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,        **
// ** OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,        **
// ** APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION           **
// ** THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,     **
// ** AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE      **
// ** FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY              **
// ** WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE               **
// ** IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR        **
// ** REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF       **
// ** INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS       **
// ** FOR A PARTICULAR PURPOSE.                                             **
// **                                                                       **
// ***************************************************************************
//
//----------------------------------------------------------------------------
// Filename:          fft_coprocessor
// Version:           1.00.a
// Description:       Example FSL core (Verilog).
// Date:              Tue Apr  9 19:58:11 2013 (by Create and Import Peripheral Wizard)
// Verilog Standard:  Verilog-2001
//----------------------------------------------------------------------------
// Naming Conventions:
//   active low signals:                    "*_n"
//   clock signals:                         "clk", "clk_div#", "clk_#x"
//   reset signals:                         "rst", "rst_n"
//   generics:                              "C_*"
//   user defined types:                    "*_TYPE"
//   state machine next state:              "*_ns"
//   state machine current state:           "*_cs"
//   combinatorial signals:                 "*_com"
//   pipelined or register delay signals:   "*_d#"
//   counter signals:                       "*cnt*"
//   clock enable signals:                  "*_ce"
//   internal version of output port:       "*_i"
//   device pins:                           "*_pin"
//   ports:                                 "- Names begin with Uppercase"
//   processes:                             "*_PROCESS"
//   component instantiations:              "<ENTITY_>I_<#|FUNC>"
//----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
//
// Definition of Ports
// FSL_Clk             : Synchronous clock
// FSL_Rst           : System reset, should always come from FSL bus
// FSL_S_Clk       : Slave asynchronous clock
// FSL_S_Read      : Read signal, requiring next available input to be read
// FSL_S_Data      : Input data
// FSL_S_Control   : Control Bit, indicating the input data are control word
// FSL_S_Exists    : Data Exist Bit, indicating data exist in the input FSL bus
// FSL_M_Clk       : Master asynchronous clock
// FSL_M_Write     : Write signal, enabling writing to output FSL bus
// FSL_M_Data      : Output data
// FSL_M_Control   : Control Bit, indicating the output data are contol word
// FSL_M_Full      : Full Bit, indicating output FSL bus is full
//
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------
// Module Section
//----------------------------------------
//`include "../../../../xfft_v7_1.v"

module fft_coprocessor 
	(
		// ADD USER PORTS BELOW THIS LINE 
		// -- USER ports added here 
		// ADD USER PORTS ABOVE THIS LINE 

		// DO NOT EDIT BELOW THIS LINE ////////////////////
		// Bus protocol ports, do not add or delete. 
		FSL_Clk,
		FSL_Rst,
		FSL_S_Clk,
		FSL_S_Read,
		FSL_S_Data,
		FSL_S_Control,
		FSL_S_Exists,
		FSL_M_Clk,
		FSL_M_Write,
		FSL_M_Data,
		FSL_M_Control,
		FSL_M_Full
		// DO NOT EDIT ABOVE THIS LINE ////////////////////
	);

// ADD USER PORTS BELOW THIS LINE 
// -- USER ports added here 
// ADD USER PORTS ABOVE THIS LINE 

input                                     FSL_Clk;
input                                     FSL_Rst;
input                                     FSL_S_Clk;
output                                    FSL_S_Read;
input      [0 : 31]                       FSL_S_Data;
input                                     FSL_S_Control;
input                                     FSL_S_Exists;
input                                     FSL_M_Clk;
output                                    FSL_M_Write;
output reg [0 : 31]                       FSL_M_Data;
output                                    FSL_M_Control;
input                                     FSL_M_Full;

// ADD USER PARAMETERS BELOW THIS LINE 
// --USER parameters added here 
// ADD USER PARAMETERS ABOVE THIS LINE


//----------------------------------------
// Implementation Section
//----------------------------------------
// In this section, we povide an example implementation of MODULE fft_coprocessor
// that does the following:
//
// 1. Read all inputs
// 2. Add each input to the contents of register 'sum' which
//    acts as an accumulator
// 3. After all the inputs have been read, write out the
//    content of 'sum' into the output FSL bus NUMBER_OF_OUTPUT_WORDS times
//
// You will need to modify this example for
// MODULE fft_coprocessor to implement your coprocessor

   // Total number of input data.
   localparam NUMBER_OF_INPUT_WORDS  = 1024;

   // Total number of output data
   localparam NUMBER_OF_OUTPUT_WORDS = 1024;

   // Define the states of state machine
   localparam Idle  = 0;
   localparam Read_Inputs = 1;
   localparam Busy = 2;
   localparam Write_Outputs  = 3;

   reg [0:2] state;

   // Accumulator to hold sum of inputs read at any point in time
   reg [0:31] sum;

   // Counters to store the number inputs read & outputs written
   reg [0:NUMBER_OF_INPUT_WORDS - 1] nr_of_reads;
   reg [0:NUMBER_OF_OUTPUT_WORDS - 1] nr_of_writes;

   // regs are inputs to fft;
   // wires are outputs from fft
   wire fft_clk;
   reg fft_start;
   `define fft_fwd_inv 1
   `define fft_fwd_inv_we 0
   `define fft_scale_sch_we 0
   wire  fft_rfd,    // ready for data
         fft_busy,
         fft_edone,  // early done
         fft_done,
         fft_dv;     // data valid
   reg [0:15] fft_xn_re;
   `define fft_xn_im 0
   `define fft_scale_sch 0
   wire  [9:0] fft_xn_index,
               fft_xk_index;
   wire  [0:15] fft_xk_re,
                fft_xk_im;

    xfft_v7_1 my_fft (
      .clk(fft_clk), // input clk
      .start(fft_start), // input start
      .xn_re(fft_xn_re), // input [15 : 0] xn_re
      .xn_im(fft_xn_im), // input [15 : 0] xn_im
      .fwd_inv(fft_fwd_inv), // input fwd_inv
      .fwd_inv_we(fft_fwd_inv_we), // input fwd_inv_we
      .scale_sch(fft_scale_sch), // input [9 : 0] scale_sch
      .scale_sch_we(fft_scale_sch_we), // input scale_sch_we
      .rfd(fft_rfd), // output rfd
      .xn_index(fft_xn_index), // output [9 : 0] xn_index
      .busy(fft_busy), // output busy
      .edone(fft_edone), // output edone
      .done(fft_done), // output done
      .dv(fft_dv), // output dv
      .xk_index(fft_xk_index), // output [9 : 0] xk_index
      .xk_re(fft_xk_re), // output [15 : 0] xk_re
      .xk_im(fft_xk_im) // output [15 : 0] xk_im
    );

   // CAUTION:
   // The sequence in which data are read in should be
   // consistent with the sequence they are written in the
   // driver's fft_coprocessor.c file

   assign FSL_S_Read  = (state == Read_Inputs) ? FSL_S_Exists : 0;
   assign FSL_M_Write = (state == Write_Outputs) ? ~FSL_M_Full : 0;

   //assign FSL_M_Data = sum;
   
   
   // fft continuous assignments
   reg fft_ce;
   assign fft_clk = FSL_Clk && fft_ce;


   // fft module timing is on page 29, figure 10, "LogiCORE IP Fast Fourier Transform v7.1"
   
   always @(posedge FSL_Clk) 
   begin  // process The_SW_accelerator
      if (FSL_Rst)               // Synchronous reset (active high)
        begin
           // CAUTION: make sure your reset polarity is consistent with the
           // system reset polarity
           state        <= Idle;
           nr_of_reads  <= 0;
           nr_of_writes <= 0;
           sum          <= 0;
        end
      else
        case (state)
          Idle: begin
            fft_ce <= 1;
            
            if (FSL_S_Exists)
            begin
              state       <= Read_Inputs;
              nr_of_reads <= NUMBER_OF_INPUT_WORDS - 1;
              
              fft_start   <= 1; // asserted for one clock cycle
              FSL_M_Data  <= 0;
              
              sum         <= 0;
            end
          end

          Read_Inputs: begin
            fft_ce <= FSL_S_Exists; // only clock in data if we have data to clock in
            fft_start <= 0;
          
            if (FSL_S_Exists) 
            begin
              fft_xn_re <= FSL_S_Data[0:15];
              // fft_xn_im <= 0;    // inside a `define
              
              sum         <= sum + FSL_S_Data; // test
              
              if (nr_of_reads == 0)
                begin
                  state        <= Busy;
                  nr_of_writes <= NUMBER_OF_OUTPUT_WORDS - 1;
                end
              else
                nr_of_reads <= nr_of_reads - 1;
            end
          end

          Busy: if (!fft_busy)  state <= Write_Outputs;

          Write_Outputs: begin
          
            FSL_M_Data[0:15] <= fft_xk_re;
            
            if (nr_of_writes == 0) 
              state <= Idle;
            else
              if (FSL_M_Full == 0)  nr_of_writes <= nr_of_writes - 1;
          end
        endcase
   end

endmodule

/*
module   xfft_v7_1 (
  input clk,
  input start,
  input [15 : 0] xn_re,
  input [15 : 0] xn_im,
  input fwd_inv,
  input fwd_inv_we,
  input [19 : 0] scale_sch,
  input scale_sch_we,
  output rfd,
  output [9 : 0] xn_index,
  output busy,
  output edone,
  output done,
  output dv,
  output [9 : 0] xk_index,
  output [15 : 0] xk_re,
  output [15 : 0] xk_im
);
endmodule
//*/