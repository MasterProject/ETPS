################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/IIC/IIC.c" \

C_SRCS += \
../Modules/LowDrivers/IIC/IIC.c \

OBJS += \
./Modules/LowDrivers/IIC/IIC.o \

C_DEPS += \
./Modules/LowDrivers/IIC/IIC.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/IIC/IIC.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/IIC/IIC.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/IIC/IIC.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/IIC/IIC.o: ../Modules/LowDrivers/IIC/IIC.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/IIC/IIC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/IIC/IIC.o"
	@echo 'Finished building: $<'
	@echo ' '


