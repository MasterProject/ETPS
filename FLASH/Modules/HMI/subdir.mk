################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/HMI/HMI.c" \

C_SRCS += \
../Modules/HMI/HMI.c \

OBJS += \
./Modules/HMI/HMI.o \

C_DEPS += \
./Modules/HMI/HMI.d \

OBJS_QUOTED += \
"./Modules/HMI/HMI.o" \

C_DEPS_QUOTED += \
"./Modules/HMI/HMI.d" \

OBJS_OS_FORMAT += \
./Modules/HMI/HMI.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/HMI/HMI.o: ../Modules/HMI/HMI.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/HMI/HMI.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/HMI/HMI.o"
	@echo 'Finished building: $<'
	@echo ' '


