################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src_device/driverlib/%.obj: ../src_device/driverlib/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1100/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu1 -O3 --opt_for_speed=3 --fp_mode=relaxed --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/control/pi" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/control/fwc" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/control/mtpa" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/control/vs_freq" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/control/dclink_ss" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/filter/filter_fo" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/est_lib" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/esmo" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/speedfr" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/speedcalc" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/ssipd" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/isbldc" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/encoder" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/observers/hall" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/transforms/clarke" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/transforms/ipark" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/transforms/park" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/transforms/svgen" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/transforms/volts" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/angle_gen" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/cpu_time" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/datalog" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/step_response" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/traj/" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/rimpulse" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/mod6cnt" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/utilities/types/include" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/sfra" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/libraries/dacs/dac128s085" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_control" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_control/common/include" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_control/drivers/include" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_board" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_device" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_device/device_support/headers/include" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/src_device/driverlib" --include_path="D:/ti/ccs1100/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --advice:performance=all --define=_INLINE --define=_FLASH --define=_F28002x --define=_FULL_FAST_LIB --define=BSXL8323RH_REVB --define=USER_MY_DRV8323RH --define=MOTOR1_FAST --define=MOTOR1_ESMO_N --define=MOTOR1_ENC_N --define=MOTOR1_HALL_N --define=HALL_CAL_N --define=MOTOR1_OVM_N --define=MOTOR1_FWC_N --define=MOTOR1_MTPA_N --define=MOTOR1_SSIPD_N --define=MOTOR1_VOLRECT_N --define=DATALOGF2_EN_N --define=DAC128S_ENABLE --define=DAC128S_SPIB_N --define=DAC128S_SPIA --define=CPUTIME_ENABLE_N --define=TEST_ENABLE_N --define=SFRA_ENABLE_N --define=STEP_RP_EN_N --define=CMD_POT_EN_N --define=CMD_CAP_EN_N --define=CMD_SWITCH_EN_N --define=CMD_CAN_EN_N --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="src_device/driverlib/$(basename $(<F)).d_raw" --include_path="E:/WorkSpace/CCSWorkSpace/universal_motorcontrol_lab_f28002x/Flash_lib_DRV8323RH_2SC_1SC/syscfg" --obj_directory="src_device/driverlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


