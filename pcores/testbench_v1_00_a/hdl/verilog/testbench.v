//----------------------------------------------------------------------------
// testbench - module
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
// Filename:          testbench
// Version:           1.00.a
// Description:       Example FSL core (Verilog).
// Date:              Wed Apr  3 19:26:31 2013 (by Create and Import Peripheral Wizard)
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
module testbench 
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
output     reg[0 : 31]                    FSL_M_Data;
output                                    FSL_M_Control;
input                                     FSL_M_Full;

// ADD USER PARAMETERS BELOW THIS LINE 
// --USER parameters added here 
// ADD USER PARAMETERS ABOVE THIS LINE


//----------------------------------------
// Implementation Section
//----------------------------------------
// In this section, we povide an example implementation of MODULE testbench
// that does the following:
//
// 1. Read all inputs
// 2. Add each input to the contents of register 'sum' which
//    acts as an accumulator
// 3. After all the inputs have been read, write out the
//    content of 'sum' into the output FSL bus NUMBER_OF_OUTPUT_WORDS times
//
// You will need to modify this example for
// MODULE testbench to implement your coprocessor

   // Total number of input data.
   localparam NUMBER_OF_INPUT_WORDS  = 2048;

   // Total number of output data
   localparam NUMBER_OF_OUTPUT_WORDS = 2048;

   // Define the states of state machine
   localparam Idle  = 2'b00;
   localparam Read_Inputs = 2'b10;
   localparam Busy = 2'b10;
   localparam Write_Outputs  = 2'b11;
   

   reg [0:2] state;

   // Accumulator to hold sum of inputs read at any point in time
   reg [0:31] sum;

   // Counters to store the number inputs read & outputs written
   reg [0:NUMBER_OF_INPUT_WORDS - 1] nr_of_reads;
   reg [0:NUMBER_OF_OUTPUT_WORDS - 1] nr_of_writes;

   // CAUTION:
   // The sequence in which data are read in should be
   // consistent with the sequence they are written in the
   // driver's testbench.c file

   assign FSL_S_Read  = (state == Read_Inputs) ? FSL_S_Exists : 0;
   assign FSL_M_Write = (state == Write_Outputs) ? ~FSL_M_Full : 0;

   //assign FSL_M_Data = sum;
   
   // regs are inputs to fft;
   // wires are outputs from fft
   reg fft_clk;   
   reg fft_clk_rw; // FSL_clk / 2
   reg fft_start;
   `define fft_fwd_inv 1
   `define fft_fwd_inv_we 0
   `define fft_scale_sch_we 0
   wire  fft_rfd,    // ready for data
         fft_busy,
         fft_edone,  // early done
         fft_done,
         fft_dv;     // data valid
   wire [0:15] fft_xn_re[0:3]; // exception to above rule; these are inputs to FFT!
   `define fft_xn_im 0
   `define fft_scale_sch 0
   wire  [9:0] fft_xn_index,
               fft_xk_index;
   wire  [0:15] fft_xk_re [0:3],
                fft_xk_im [0:3];
   ///*
   xfft_v7_1 fft (
  .clk(fft_clk), // input clk
  .start(fft_start), // input start
  .xn0_re(fft_xn_re[0]), // input [15 : 0] xn0_re
  .xn0_im(fft_xn_im[0]), // input [15 : 0] xn0_im
  .xn1_re(fft_xn_re[1]), // input [15 : 0] xn1_re
  .xn1_im(fft_xn_im[1]), // input [15 : 0] xn1_im
  .xn2_re(fft_xn_re[2]), // input [15 : 0] xn2_re
  .xn2_im(fft_xn_im[2]), // input [15 : 0] xn2_im
  .xn3_re(fft_xn_re[3]), // input [15 : 0] xn3_re
  .xn3_im(fft_xn_im[3]), // input [15 : 0] xn3_im
  .fwd_inv0(fft_fwd_inv), // input fwd_inv0
  .fwd_inv0_we(fft_fwd_inv_we), // input fwd_inv0_we
  .fwd_inv1(fft_fwd_inv), // input fwd_inv1
  .fwd_inv1_we(fft_fwd_inv_we), // input fwd_inv1_we
  .fwd_inv2(fft_fwd_inv), // input fwd_inv2
  .fwd_inv2_we(fft_fwd_inv_we), // input fwd_inv2_we
  .fwd_inv3(fft_fwd_inv), // input fwd_inv3
  .fwd_inv3_we(fft_fwd_inv_we), // input fwd_inv3_we
  .scale_sch0(fft_scale_sch), // input [19 : 0] scale_sch0
  .scale_sch0_we(fft_scale_sch_we), // input scale_sch0_we
  .scale_sch1(fft_scale_sch), // input [19 : 0] scale_sch1
  .scale_sch1_we(fft_scale_sch_we), // input scale_sch1_we
  .scale_sch2(fft_scale_sch), // input [19 : 0] scale_sch2
  .scale_sch2_we(fft_scale_sch_we), // input scale_sch2_we
  .scale_sch3(fft_scale_sch), // input [19 : 0] scale_sch3
  .scale_sch3_we(fft_scale_sch_we), // input scale_sch3_we
  .rfd(fft_rfd), // output rfd
  .xn_index(fft_xn_index), // output [9 : 0] xn_index
  .busy(fft_busy), // output busy
  .edone(fft_edone), // output edone
  .done(fft_done), // output done
  .dv(fft_dv), // output dv
  .xk_index(fft_xk_index), // output [9 : 0] xk_index
  .xk0_re(fft_xk_re[0]), // output [15 : 0] xk0_re
  .xk0_im(fft_xk_im[0]), // output [15 : 0] xk0_im
  .xk1_re(fft_xk_re[1]), // output [15 : 0] xk1_re
  .xk1_im(fft_xk_im[1]), // output [15 : 0] xk1_im
  .xk2_re(fft_xk_re[2]), // output [15 : 0] xk2_re
  .xk2_im(fft_xk_im[2]), // output [15 : 0] xk2_im
  .xk3_re(fft_xk_re[3]), // output [15 : 0] xk3_re
  .xk3_im(fft_xk_im[3]) // output [15 : 0] xk3_im
);
   //*/
   /*
   xfft_v7_1 fft(
   // control
   //inputs
      .clk(fft_clk),
      .start(fft_start),
   //outputs
      .rfd(fft_rfd),       // ready for data
      .busy(fft_busy),  
      .edone(fft_edone),   // early done (one cycle before done)
      .done(fft_done),
      .dv(fft_dv),         // data valid
      
   // forward/inverse transform
      .fwd_inv0(fft_fwd_inv),
      .fwd_inv1(fft_fwd_inv),
      .fwd_inv2(fft_fwd_inv),
      .fwd_inv3(fft_fwd_inv),
      .fwd_inv0_we(fft_fwd_inv_we),
      .fwd_inv1_we(fft_fwd_inv_we),
      .fwd_inv2_we(fft_fwd_inv_we),
      .fwd_inv3_we(fft_fwd_inv_we),
    
    // scaling schedule
      .scale_sch0_we(fft_scale_sch_we),
      .scale_sch1_we(fft_scale_sch_we),
      .scale_sch2_we(fft_scale_sch_we),
      .scale_sch3_we(fft_scale_sch_we),
      .scale_sch0(fft_scale_sch),
      .scale_sch1(fft_scale_sch),
      .scale_sch2(fft_scale_sch),
      .scale_sch3(fft_scale_sch),
       
    // inputs
      .xn0_re(fft_xn_re[0]),
      .xn1_re(fft_xn_re[1]),
      .xn2_re(fft_xn_re[2]),
      .xn3_re(fft_xn_re[3]),
      .xn0_im(fft_xn_im),
      .xn1_im(fft_xn_im),
      .xn2_im(fft_xn_im),
      .xn3_im(fft_xn_im),
 
    // outputs
      .xn_index(fft_xn_index),
      .xk_index(fft_xk_index),
      
      .xk0_re(fft_xk_re[0]),
      .xk1_re(fft_xk_re[1]),
      .xk2_re(fft_xk_re[2]),
      .xk3_re(fft_xk_re[3]),
      .xk0_im(fft_xk_im[0]),
      .xk1_im(fft_xk_im[1]),
      .xk2_im(fft_xk_im[2]),
      .xk3_im(fft_xk_im[3])
   );
   //*/
   reg [0:31] channels_12; //holds channel 1 & 2
   assign fft_xn_re[0] = channels_12[0:15];
   assign fft_xn_re[1] = channels_12[16:31];
   assign fft_xn_re[2] = FSL_S_Data[0:15];
   assign fft_xn_re[3] = FSL_S_Data[16:31];
   
   always @(*)
   case(state)
      Idle:          fft_clk = FSL_Clk;
      Read_Inputs:   fft_clk = fft_clk_rw;
      Busy:          fft_clk = FSL_Clk;
      Write_Outputs: fft_clk = fft_clk_rw;
   endcase
   
   always @(posedge FSL_Clk) 
   begin  // process The_SW_accelerator
      if (FSL_Rst)               // Synchronous reset (active high)
        begin
           // CAUTION: make sure your reset polarity is consistent with the
           // system reset polarity
           state        <= Idle;
           nr_of_reads  <= 0;
           nr_of_writes <= 0;
           
        end
      else
        case (state)
          Idle: 
            if (FSL_S_Exists == 1)
            begin
              state       <= Read_Inputs;
              nr_of_reads <= NUMBER_OF_INPUT_WORDS - 1;
              fft_start   <= 1;
            end

          Read_Inputs: begin
          fft_clk_rw   <= ~nr_of_reads[0];
          fft_start <= 0;
            if (FSL_S_Exists == 1) begin
                if(nr_of_reads[0])    channels_12 <= FSL_S_Data;    
                if (nr_of_reads == 0) state       <= Busy;  
                else                  nr_of_reads <= nr_of_reads - 1;
            end
          end
          Busy:
               if(fft_dv) begin
               state        <= Write_Outputs;
               nr_of_writes <= NUMBER_OF_OUTPUT_WORDS - 1;
               end
          
          Write_Outputs: begin
          fft_clk_rw   <= ~nr_of_reads[0];
               if(nr_of_writes[0])
                  begin
                  FSL_M_Data[0:15] <= fft_xk_re[0];
                  FSL_M_Data[16:31]<= fft_xk_re[1];
                  end
               else
                  begin
                  FSL_M_Data[0:15] <= fft_xk_re[2];
                  FSL_M_Data[16:31]<= fft_xk_re[3];
                  end   
          
            if(nr_of_writes == 0) state <= Idle;
            else
              if (FSL_M_Full == 0)  nr_of_writes <= nr_of_writes - 1;
          end
        endcase
   end

endmodule
