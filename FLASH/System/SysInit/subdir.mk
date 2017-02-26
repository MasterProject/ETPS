################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../System/SysInit/SysInit.c" \

C_SRCS += \
../System/SysInit/SysInit.c \

OBJS += \
./System/SysInit/SysInit.o \

C_DEPS += \
./System/SysInit/SysInit.d \

OBJS_QUOTED += \
"./System/SysInit/SysInit.o" \

C_DEPS_QUOTED += \
"./System/SysInit/SysInit.d" \

OBJS_OS_FORMAT += \
./System/SysInit/SysInit.o \


# Each subdirectory must supply rules for building sources it contributes
System/SysInit/SysInit.o: ../System/SysInit/SysInit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"System/SysInit/SysInit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"System/SysInit/SysInit.o"
	@echo 'Finished building: $<'
	@echo ' '


