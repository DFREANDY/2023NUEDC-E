################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
User/LED/%.obj: ../User/LED/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/Keyboard" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/Laser" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/InfoPrint" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/Openmv" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/Clock" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/delay" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/KEY" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/LED" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/motor" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/oled" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/PID" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/Tasks" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green/User/timer" --include_path="E:/MyDigitalDesign/Project5/workspace_project5/project5_green" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="E:/MyStudyApp/MyTI/ccs1230/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="E:/MyStudyApp/MyTI/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="User/LED/$(basename $(<F)).d_raw" --obj_directory="User/LED" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


