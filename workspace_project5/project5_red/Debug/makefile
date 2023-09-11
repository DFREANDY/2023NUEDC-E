################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./system_msp432p401r.obj" \
"./User/Clock/clock.obj" \
"./User/InfoPrint/infoprint.obj" \
"./User/KEY/key.obj" \
"./User/Keyboard/keyboard.obj" \
"./User/LED/led.obj" \
"./User/Laser/laser.obj" \
"./User/Openmv/openmv.obj" \
"./User/PID/pid.obj" \
"./User/Tasks/task_control.obj" \
"./User/Tasks/task_decision.obj" \
"./User/delay/delay.obj" \
"./User/motor/motor.obj" \
"./User/no_use.obj" \
"./User/oled/oled.obj" \
"./User/timer/timer.obj" \
"./ccs/startup_msp432p401r_ccs.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-l"ti/display/lib/display.aem4f" \
-l"ti/grlib/lib/ccs/m4f/grlib.a" \
-l"third_party/spiffs/lib/ccs/m4f/spiffs.a" \
-l"ti/drivers/lib/drivers_msp432p401x.aem4f" \
-l"third_party/fatfs/lib/ccs/m4f/fatfs.a" \
-l"ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include User/Clock/subdir_vars.mk
-include User/InfoPrint/subdir_vars.mk
-include User/KEY/subdir_vars.mk
-include User/Keyboard/subdir_vars.mk
-include User/LED/subdir_vars.mk
-include User/Laser/subdir_vars.mk
-include User/Openmv/subdir_vars.mk
-include User/PID/subdir_vars.mk
-include User/Tasks/subdir_vars.mk
-include User/delay/subdir_vars.mk
-include User/motor/subdir_vars.mk
-include User/subdir_vars.mk
-include User/oled/subdir_vars.mk
-include User/timer/subdir_vars.mk
-include ccs/subdir_vars.mk
-include subdir_rules.mk
-include User/Clock/subdir_rules.mk
-include User/InfoPrint/subdir_rules.mk
-include User/KEY/subdir_rules.mk
-include User/Keyboard/subdir_rules.mk
-include User/LED/subdir_rules.mk
-include User/Laser/subdir_rules.mk
-include User/Openmv/subdir_rules.mk
-include User/PID/subdir_rules.mk
-include User/Tasks/subdir_rules.mk
-include User/delay/subdir_rules.mk
-include User/motor/subdir_rules.mk
-include User/subdir_rules.mk
-include User/oled/subdir_rules.mk
-include User/timer/subdir_rules.mk
-include ccs/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
project5_red.out \

EXE_OUTPUTS__QUOTED += \
"project5_red.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "project5_red.out"

# Tool invocations
project5_red.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"project5_red.map" --stack_size=512 -i"E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source" -i"E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" --diag_wrap=off --display_error_number --warn_sections --xml_link_info="project5_red_linkInfo.xml" --rom_model -o "project5_red.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "system_msp432p401r.obj" "User\Clock\clock.obj" "User\InfoPrint\infoprint.obj" "User\KEY\key.obj" "User\Keyboard\keyboard.obj" "User\LED\led.obj" "User\Laser\laser.obj" "User\Openmv\openmv.obj" "User\PID\pid.obj" "User\Tasks\task_control.obj" "User\Tasks\task_decision.obj" "User\delay\delay.obj" "User\motor\motor.obj" "User\no_use.obj" "User\oled\oled.obj" "User\timer\timer.obj" "ccs\startup_msp432p401r_ccs.obj" 
	-$(RM) "main.d" "system_msp432p401r.d" "User\Clock\clock.d" "User\InfoPrint\infoprint.d" "User\KEY\key.d" "User\Keyboard\keyboard.d" "User\LED\led.d" "User\Laser\laser.d" "User\Openmv\openmv.d" "User\PID\pid.d" "User\Tasks\task_control.d" "User\Tasks\task_decision.d" "User\delay\delay.d" "User\motor\motor.d" "User\no_use.d" "User\oled\oled.d" "User\timer\timer.d" "ccs\startup_msp432p401r_ccs.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

