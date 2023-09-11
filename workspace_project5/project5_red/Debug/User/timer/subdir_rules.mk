################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
User/timer/%.obj: ../User/timer/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/Keyboard" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/Laser" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/InfoPrint" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/Openmv" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/Clock" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/delay" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/KEY" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/LED" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/motor" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/oled" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/PID" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/Tasks" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red/User/timer" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_red" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="User/timer/$(basename $(<F)).d_raw" --obj_directory="User/timer" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


