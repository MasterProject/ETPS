################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/ADC/ADC.c" \

C_SRCS += \
../Modules/LowDrivers/ADC/ADC.c \

OBJS += \
./Modules/LowDrivers/ADC/ADC.o \

C_DEPS += \
./Modules/LowDrivers/ADC/ADC.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/ADC/ADC.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/ADC/ADC.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/ADC/ADC.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/ADC/ADC.o: ../Modules/LowDrivers/ADC/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/ADC/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/ADC/ADC.o"
	@echo 'Finished building: $<'
	@echo ' '


