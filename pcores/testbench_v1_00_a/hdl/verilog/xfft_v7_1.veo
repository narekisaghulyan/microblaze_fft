/*******************************************************************************
*     This file is owned and controlled by Xilinx and must be used solely      *
*     for design, simulation, implementation and creation of design files      *
*     limited to Xilinx devices or technologies. Use with non-Xilinx           *
*     devices or technologies is expressly prohibited and immediately          *
*     terminates your license.                                                 *
*                                                                              *
*     XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" SOLELY     *
*     FOR USE IN DEVELOPING PROGRAMS AND SOLUTIONS FOR XILINX DEVICES.  BY     *
*     PROVIDING THIS DESIGN, CODE, OR INFORMATION AS ONE POSSIBLE              *
*     IMPLEMENTATION OF THIS FEATURE, APPLICATION OR STANDARD, XILINX IS       *
*     MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION IS FREE FROM ANY       *
*     CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE FOR OBTAINING ANY        *
*     RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY        *
*     DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE    *
*     IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR           *
*     REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF          *
*     INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A    *
*     PARTICULAR PURPOSE.                                                      *
*                                                                              *
*     Xilinx products are not intended for use in life support appliances,     *
*     devices, or systems.  Use in such applications are expressly             *
*     prohibited.                                                              *
*                                                                              *
*     (c) Copyright 1995-2013 Xilinx, Inc.                                     *
*     All rights reserved.                                                     *
*******************************************************************************/

/*******************************************************************************
*     Generated from core with identifier: xilinx.com:ip:xfft:7.1              *
*                                                                              *
*     The Fast Fourier Transform (FFT) is a computationally efficient          *
*     algorithm for computing the Discrete Fourier Transform (DFT). The FFT    *
*     Core can compute 8 to 65536-point forward or inverse complex             *
*     transforms on up to 12 parallel channels. The input data is a vector     *
*     of complex values represented as two's-complement numbers 8 to 34        *
*     bits wide or single precision floating point numbers 32 bits wide.       *
*     The phase factors can be 8 to 34 bits wide. All memory is on-chip        *
*     using either Block RAM or Distributed RAM. Three arithmetic types are    *
*     available: full-precision unscaled, scaled fixed-point, and              *
*     block-floating point. Several parameters are run-time configurable:      *
*     the point size, the choice of forward or inverse transform, and the      *
*     scaling schedule. Four architectures are available to provide a          *
*     tradeoff between size and transform time.                                *
*******************************************************************************/

// The following must be inserted into your Verilog file for this
// core to be instantiated. Change the instance name and port connections
// (in parentheses) to your own signal names.

//----------- Begin Cut here for INSTANTIATION Template ---// INST_TAG
xfft_v7_1 your_instance_name (
  .clk(clk), // input clk
  .start(start), // input start
  .xn0_re(xn0_re), // input [15 : 0] xn0_re
  .xn0_im(xn0_im), // input [15 : 0] xn0_im
  .xn1_re(xn1_re), // input [15 : 0] xn1_re
  .xn1_im(xn1_im), // input [15 : 0] xn1_im
  .xn2_re(xn2_re), // input [15 : 0] xn2_re
  .xn2_im(xn2_im), // input [15 : 0] xn2_im
  .xn3_re(xn3_re), // input [15 : 0] xn3_re
  .xn3_im(xn3_im), // input [15 : 0] xn3_im
  .fwd_inv0(fwd_inv0), // input fwd_inv0
  .fwd_inv0_we(fwd_inv0_we), // input fwd_inv0_we
  .fwd_inv1(fwd_inv1), // input fwd_inv1
  .fwd_inv1_we(fwd_inv1_we), // input fwd_inv1_we
  .fwd_inv2(fwd_inv2), // input fwd_inv2
  .fwd_inv2_we(fwd_inv2_we), // input fwd_inv2_we
  .fwd_inv3(fwd_inv3), // input fwd_inv3
  .fwd_inv3_we(fwd_inv3_we), // input fwd_inv3_we
  .scale_sch0(scale_sch0), // input [19 : 0] scale_sch0
  .scale_sch0_we(scale_sch0_we), // input scale_sch0_we
  .scale_sch1(scale_sch1), // input [19 : 0] scale_sch1
  .scale_sch1_we(scale_sch1_we), // input scale_sch1_we
  .scale_sch2(scale_sch2), // input [19 : 0] scale_sch2
  .scale_sch2_we(scale_sch2_we), // input scale_sch2_we
  .scale_sch3(scale_sch3), // input [19 : 0] scale_sch3
  .scale_sch3_we(scale_sch3_we), // input scale_sch3_we
  .rfd(rfd), // output rfd
  .xn_index(xn_index), // output [9 : 0] xn_index
  .busy(busy), // output busy
  .edone(edone), // output edone
  .done(done), // output done
  .dv(dv), // output dv
  .xk_index(xk_index), // output [9 : 0] xk_index
  .xk0_re(xk0_re), // output [15 : 0] xk0_re
  .xk0_im(xk0_im), // output [15 : 0] xk0_im
  .xk1_re(xk1_re), // output [15 : 0] xk1_re
  .xk1_im(xk1_im), // output [15 : 0] xk1_im
  .xk2_re(xk2_re), // output [15 : 0] xk2_re
  .xk2_im(xk2_im), // output [15 : 0] xk2_im
  .xk3_re(xk3_re), // output [15 : 0] xk3_re
  .xk3_im(xk3_im) // output [15 : 0] xk3_im
);
// INST_TAG_END ------ End INSTANTIATION Template ---------

// You must compile the wrapper file xfft_v7_1.v when simulating
// the core, xfft_v7_1. When compiling the wrapper file, be sure to
// reference the XilinxCoreLib Verilog simulation library. For detailed
// instructions, please refer to the "CORE Generator Help".

