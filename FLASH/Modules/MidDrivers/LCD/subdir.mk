################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/MidDrivers/LCD/LCD.c" \

C_SRCS += \
../Modules/MidDrivers/LCD/LCD.c \

OBJS += \
./Modules/MidDrivers/LCD/LCD.o \

C_DEPS += \
./Modules/MidDrivers/LCD/LCD.d \

OBJS_QUOTED += \
"./Modules/MidDrivers/LCD/LCD.o" \

C_DEPS_QUOTED += \
"./Modules/MidDrivers/LCD/LCD.d" \

OBJS_OS_FORMAT += \
./Modules/MidDrivers/LCD/LCD.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/MidDrivers/LCD/LCD.o: ../Modules/MidDrivers/LCD/LCD.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/MidDrivers/LCD/LCD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/MidDrivers/LCD/LCD.o"
	@echo 'Finished building: $<'
	@echo ' '


