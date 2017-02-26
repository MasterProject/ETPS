################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/App/HeartBit/HeartBit.c" \

C_SRCS += \
../Modules/App/HeartBit/HeartBit.c \

OBJS += \
./Modules/App/HeartBit/HeartBit.o \

C_DEPS += \
./Modules/App/HeartBit/HeartBit.d \

OBJS_QUOTED += \
"./Modules/App/HeartBit/HeartBit.o" \

C_DEPS_QUOTED += \
"./Modules/App/HeartBit/HeartBit.d" \

OBJS_OS_FORMAT += \
./Modules/App/HeartBit/HeartBit.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/App/HeartBit/HeartBit.o: ../Modules/App/HeartBit/HeartBit.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/App/HeartBit/HeartBit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/App/HeartBit/HeartBit.o"
	@echo 'Finished building: $<'
	@echo ' '


