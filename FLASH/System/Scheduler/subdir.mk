################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../System/Scheduler/Sch.c" \

C_SRCS += \
../System/Scheduler/Sch.c \

OBJS += \
./System/Scheduler/Sch.o \

C_DEPS += \
./System/Scheduler/Sch.d \

OBJS_QUOTED += \
"./System/Scheduler/Sch.o" \

C_DEPS_QUOTED += \
"./System/Scheduler/Sch.d" \

OBJS_OS_FORMAT += \
./System/Scheduler/Sch.o \


# Each subdirectory must supply rules for building sources it contributes
System/Scheduler/Sch.o: ../System/Scheduler/Sch.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"System/Scheduler/Sch.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"System/Scheduler/Sch.o"
	@echo 'Finished building: $<'
	@echo ' '


