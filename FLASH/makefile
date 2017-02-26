################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 14
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include System/SysInit/subdir.mk
-include System/Scheduler/subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Modules/LowDrivers/TPM/subdir.mk
-include Modules/LowDrivers/PIT/subdir.mk
-include Modules/LowDrivers/GPIO/subdir.mk
-include Modules/LowDrivers/ADC/subdir.mk
-include Modules/App/Test/subdir.mk
-include Modules/App/HeartBit/subdir.mk
-include Modules/App/ElectroTherapy/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ProyectoTerapiaPresion.elf \

EXECUTABLES_QUOTED += \
"ProyectoTerapiaPresion.elf" \

EXECUTABLES_OS_FORMAT += \
ProyectoTerapiaPresion.elf \


# All Target
all: warning-messages explicit-dependencies ProyectoTerapiaPresion.elf secondary-outputs

# Tool invocations
ProyectoTerapiaPresion.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/MKL25Z128_flash.ld
	@echo 'Building target: $@'
	@echo 'Executing target #15 $@'
	@echo 'Invoking: ARM Ltd Windows GCC C Linker'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED) @"ProyectoTerapiaPresion.args" -o"ProyectoTerapiaPresion.elf"
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) "./*/*/*/*.o" "./*/*/*.o" "./*/*.o"  $(S_UPPER_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(SX_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*/*.d" "./*/*/*.d" "./*/*.d"  $(ProjDirPath)/FLASH/ProyectoTerapiaPresion.elf
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: ../Project_Settings/Linker_Files/MKL25Z128_flash.ld 

warning-messages: 

