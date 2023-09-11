################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/PID/%.obj: ../Hardware/PID/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/Clock" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/delay" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/EXTI" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/KEY" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/LED" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/motor" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/MPU6050" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/oled" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/timer" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware/USART" --include_path="E:/MyDigitalDesign/Project2/workspace_project2/Project2/Hardware" --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Hardware/PID/$(basename $(<F)).d_raw" --obj_directory="Hardware/PID" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


