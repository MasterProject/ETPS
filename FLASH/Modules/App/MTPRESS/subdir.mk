################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Modules/App/MTPRESS/MTPRESS.c" \

C_SRCS += \
../Modules/App/MTPRESS/MTPRESS.c \

OBJS += \
./Modules/App/MTPRESS/MTPRESS.o \

C_DEPS += \
./Modules/App/MTPRESS/MTPRESS.d \

OBJS_QUOTED += \
"./Modules/App/MTPRESS/MTPRESS.o" \

C_DEPS_QUOTED += \
"./Modules/App/MTPRESS/MTPRESS.d" \

OBJS_OS_FORMAT += \
./Modules/App/MTPRESS/MTPRESS.o \


# Each subdirectory must supply rules for building sources it contributes
Modules/App/MTPRESS/MTPRESS.o: ../Modules/App/MTPRESS/MTPRESS.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Modules/App/MTPRESS/MTPRESS.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Modules/App/MTPRESS/MTPRESS.o"
	@echo 'Finished building: $<'
	@echo ' '


