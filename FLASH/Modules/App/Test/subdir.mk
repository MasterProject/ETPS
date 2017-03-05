################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/App/Test/Test.c" \

C_SRCS += \
../Modules/App/Test/Test.c \

OBJS += \
./Modules/App/Test/Test.o \

C_DEPS += \
./Modules/App/Test/Test.d \

OBJS_QUOTED += \
"./Modules/App/Test/Test.o" \

C_DEPS_QUOTED += \
"./Modules/App/Test/Test.d" \

OBJS_OS_FORMAT += \
./Modules/App/Test/Test.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/App/Test/Test.o: ../Modules/App/Test/Test.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/App/Test/Test.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/App/Test/Test.o"
	@echo 'Finished building: $<'
	@echo ' '


