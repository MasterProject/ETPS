################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/LowDrivers/TPM/TPM.c" \

C_SRCS += \
../Modules/LowDrivers/TPM/TPM.c \

OBJS += \
./Modules/LowDrivers/TPM/TPM.o \

C_DEPS += \
./Modules/LowDrivers/TPM/TPM.d \

OBJS_QUOTED += \
"./Modules/LowDrivers/TPM/TPM.o" \

C_DEPS_QUOTED += \
"./Modules/LowDrivers/TPM/TPM.d" \

OBJS_OS_FORMAT += \
./Modules/LowDrivers/TPM/TPM.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/LowDrivers/TPM/TPM.o: ../Modules/LowDrivers/TPM/TPM.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/LowDrivers/TPM/TPM.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/LowDrivers/TPM/TPM.o"
	@echo 'Finished building: $<'
	@echo ' '


