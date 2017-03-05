################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/MidDrivers/DBNCR/Debouncer.c" \

C_SRCS += \
../Modules/MidDrivers/DBNCR/Debouncer.c \

OBJS += \
./Modules/MidDrivers/DBNCR/Debouncer.o \

C_DEPS += \
./Modules/MidDrivers/DBNCR/Debouncer.d \

OBJS_QUOTED += \
"./Modules/MidDrivers/DBNCR/Debouncer.o" \

C_DEPS_QUOTED += \
"./Modules/MidDrivers/DBNCR/Debouncer.d" \

OBJS_OS_FORMAT += \
./Modules/MidDrivers/DBNCR/Debouncer.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/MidDrivers/DBNCR/Debouncer.o: ../Modules/MidDrivers/DBNCR/Debouncer.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/MidDrivers/DBNCR/Debouncer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/MidDrivers/DBNCR/Debouncer.o"
	@echo 'Finished building: $<'
	@echo ' '


