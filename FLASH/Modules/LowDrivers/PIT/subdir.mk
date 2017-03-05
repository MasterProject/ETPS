################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/PIT/PIT.c" \

C_SRCS += \
../Modules/LowDrivers/PIT/PIT.c \

OBJS += \
./Modules/LowDrivers/PIT/PIT.o \

C_DEPS += \
./Modules/LowDrivers/PIT/PIT.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/PIT/PIT.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/PIT/PIT.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/PIT/PIT.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/PIT/PIT.o: ../Modules/LowDrivers/PIT/PIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/PIT/PIT.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/PIT/PIT.o"
	@echo 'Finished building: $<'
	@echo ' '


