################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1501840289:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1501840289-inproc

build-1501840289-inproc: ../app.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_51_01_18_core/xs" --xdcpath="C:/ti/sdk-k2h/bios_6_73_01_01/packages;C:/ti/sdk-k2h/pdk_k2hk_4_0_12/packages;C:/ti/sdk-k2h/ndk_3_40_01_01/packages;C:/ti/sdk-k2h/ipc_3_50_03_04/packages;F:/myPlatform;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p cyhc.dsp.core0 -r release -b "D:/pxqwork/project/app-n/basic-platform/Debug/configPkg/config.bld" -c "C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c6000_8.3.3" --compileOptions "-g" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: D:/pxqwork/project/app-n/basic-platform/Debug/configPkg/config.bld
configPkg/linker.cmd: build-1501840289 ../app.cfg D:/pxqwork/project/app-n/basic-platform/Debug/configPkg/config.bld
configPkg/compiler.opt: build-1501840289 D:/pxqwork/project/app-n/basic-platform/Debug/configPkg/config.bld
configPkg/: build-1501840289 D:/pxqwork/project/app-n/basic-platform/Debug/configPkg/config.bld

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" --include_path="D:/pxqwork/project/app-n/basic-platform" --include_path="C:/ti/sdk-k2h/bios_6_73_01_01/packages/ti/posix/ccs" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/pxqwork/project/app-n/basic-platform/init" --include_path="D:/pxqwork/project/app-n/basic-platform/driver-interface" --include_path="D:/pxqwork/project/app-n/basic-platform/common" --define=SOC_K2H --define=DEVICE_K2H --define=evm_K2H -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


