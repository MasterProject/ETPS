################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/NVIC/NVIC.c" \

C_SRCS += \
../Modules/LowDrivers/NVIC/NVIC.c \

OBJS += \
./Modules/LowDrivers/NVIC/NVIC.o \

C_DEPS += \
./Modules/LowDrivers/NVIC/NVIC.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/NVIC/NVIC.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/NVIC/NVIC.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/NVIC/NVIC.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/NVIC/NVIC.o: ../Modules/LowDrivers/NVIC/NVIC.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/NVIC/NVIC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/NVIC/NVIC.o"
	@echo 'Finished building: $<'
	@echo ' '


