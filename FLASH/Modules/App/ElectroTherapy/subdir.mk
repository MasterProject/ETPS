################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/App/ElectroTherapy/ET.c" \

C_SRCS += \
../Modules/App/ElectroTherapy/ET.c \

OBJS += \
./Modules/App/ElectroTherapy/ET.o \

C_DEPS += \
./Modules/App/ElectroTherapy/ET.d \

OBJS_QUOTED += \
"./Modules/App/ElectroTherapy/ET.o" \

C_DEPS_QUOTED += \
"./Modules/App/ElectroTherapy/ET.d" \

OBJS_OS_FORMAT += \
./Modules/App/ElectroTherapy/ET.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/App/ElectroTherapy/ET.o: ../Modules/App/ElectroTherapy/ET.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/App/ElectroTherapy/ET.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/App/ElectroTherapy/ET.o"
	@echo 'Finished building: $<'
	@echo ' '


