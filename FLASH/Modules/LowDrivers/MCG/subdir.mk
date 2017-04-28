################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/MCG/MGCDvr.c" \

C_SRCS += \
../Modules/LowDrivers/MCG/MGCDvr.c \

OBJS += \
./Modules/LowDrivers/MCG/MGCDvr.o \

C_DEPS += \
./Modules/LowDrivers/MCG/MGCDvr.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/MCG/MGCDvr.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/MCG/MGCDvr.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/MCG/MGCDvr.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/MCG/MGCDvr.o: ../Modules/LowDrivers/MCG/MGCDvr.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/MCG/MGCDvr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/MCG/MGCDvr.o"
	@echo 'Finished building: $<'
	@echo ' '


