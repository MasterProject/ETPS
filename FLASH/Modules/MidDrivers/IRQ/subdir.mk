################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/MidDrivers/IRQ/IRQ.c" \

C_SRCS += \
../Modules/MidDrivers/IRQ/IRQ.c \

OBJS += \
./Modules/MidDrivers/IRQ/IRQ.o \

C_DEPS += \
./Modules/MidDrivers/IRQ/IRQ.d \

OBJS_QUOTED += \
"./Modules/MidDrivers/IRQ/IRQ.o" \

C_DEPS_QUOTED += \
"./Modules/MidDrivers/IRQ/IRQ.d" \

OBJS_OS_FORMAT += \
./Modules/MidDrivers/IRQ/IRQ.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/MidDrivers/IRQ/IRQ.o: ../Modules/MidDrivers/IRQ/IRQ.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/MidDrivers/IRQ/IRQ.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/MidDrivers/IRQ/IRQ.o"
	@echo 'Finished building: $<'
	@echo ' '


