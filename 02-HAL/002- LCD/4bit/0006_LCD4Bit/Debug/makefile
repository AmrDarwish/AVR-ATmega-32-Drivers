################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
0006_LCD4Bit.lss \

FLASH_IMAGE += \
0006_LCD4Bit.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 0006_LCD4Bit.elf secondary-outputs

# Tool invocations
0006_LCD4Bit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,0006_LCD4Bit.map -mmcu=atmega32 -o "0006_LCD4Bit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

0006_LCD4Bit.lss: 0006_LCD4Bit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 0006_LCD4Bit.elf  >"0006_LCD4Bit.lss"
	@echo 'Finished building: $@'
	@echo ' '

0006_LCD4Bit.hex: 0006_LCD4Bit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 0006_LCD4Bit.elf  "0006_LCD4Bit.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 0006_LCD4Bit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 0006_LCD4Bit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 0006_LCD4Bit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
