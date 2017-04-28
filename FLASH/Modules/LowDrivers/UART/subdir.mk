################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/UART/UART.c" \

C_SRCS += \
../Modules/LowDrivers/UART/UART.c \

OBJS += \
./Modules/LowDrivers/UART/UART.o \

C_DEPS += \
./Modules/LowDrivers/UART/UART.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/UART/UART.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/UART/UART.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/UART/UART.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/UART/UART.o: ../Modules/LowDrivers/UART/UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/UART/UART.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/UART/UART.o"
	@echo 'Finished building: $<'
	@echo ' '


