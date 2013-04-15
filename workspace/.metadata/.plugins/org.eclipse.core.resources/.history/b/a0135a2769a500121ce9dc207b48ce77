################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fft_test0.c \
../src/platform.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/fft_test0.o \
./src/platform.o 

C_DEPS += \
./src/fft_test0.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O3 -c -fmessage-length=0 -I../../fft_test_bsp_0/microblaze_0/include -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


