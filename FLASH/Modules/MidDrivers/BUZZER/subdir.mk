################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/MidDrivers/BUZZER/BZR.c" \

C_SRCS += \
../Modules/MidDrivers/BUZZER/BZR.c \

OBJS += \
./Modules/MidDrivers/BUZZER/BZR.o \

C_DEPS += \
./Modules/MidDrivers/BUZZER/BZR.d \

OBJS_QUOTED += \
"./Modules/MidDrivers/BUZZER/BZR.o" \

C_DEPS_QUOTED += \
"./Modules/MidDrivers/BUZZER/BZR.d" \

OBJS_OS_FORMAT += \
./Modules/MidDrivers/BUZZER/BZR.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/MidDrivers/BUZZER/BZR.o: ../Modules/MidDrivers/BUZZER/BZR.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/MidDrivers/BUZZER/BZR.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/MidDrivers/BUZZER/BZR.o"
	@echo 'Finished building: $<'
	@echo ' '


