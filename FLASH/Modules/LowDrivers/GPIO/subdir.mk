################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/GPIO/GPIO.c" \

C_SRCS += \
../Modules/LowDrivers/GPIO/GPIO.c \

OBJS += \
./Modules/LowDrivers/GPIO/GPIO.o \

C_DEPS += \
./Modules/LowDrivers/GPIO/GPIO.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/GPIO/GPIO.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/GPIO/GPIO.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/GPIO/GPIO.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/GPIO/GPIO.o: ../Modules/LowDrivers/GPIO/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/GPIO/GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/GPIO/GPIO.o"
	@echo 'Finished building: $<'
	@echo ' '


