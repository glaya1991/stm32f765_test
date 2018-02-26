#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-none-eabi-gcc
CCC=arm-none-eabi-g++
CXX=arm-none-eabi-g++
FC=gfortran
AS=arm-none-eabi-as

# Macros
CND_PLATFORM=GNU-ARM-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/d6f1651e/dma.o \
	${OBJECTDIR}/_ext/d6f1651e/gpio.o \
	${OBJECTDIR}/_ext/d6f1651e/i2c.o \
	${OBJECTDIR}/_ext/d6f1651e/main.o \
	${OBJECTDIR}/_ext/d6f1651e/spi.o \
	${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o \
	${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o \
	${OBJECTDIR}/_ext/d6f1651e/tim.o \
	${OBJECTDIR}/_ext/d6f1651e/usart.o \
	${OBJECTDIR}/_ext/e9f01746/startup_stm32f429xx.o


# C Compiler Flags
CFLAGS=-mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall --specs=nosys.specs

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lgcc -lc -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stm32f429_firmware.elf.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stm32f429_firmware.elf.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stm32f429_firmware.elf ${OBJECTFILES} ${LDLIBSOPTIONS} -T../sources/STM32F765ZITx_FLASH.ld

${OBJECTDIR}/_ext/d6f1651e/dma.o: ../sources/Src/dma.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/dma.o ../sources/Src/dma.c

${OBJECTDIR}/_ext/d6f1651e/gpio.o: ../sources/Src/gpio.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/gpio.o ../sources/Src/gpio.c

${OBJECTDIR}/_ext/d6f1651e/i2c.o: ../sources/Src/i2c.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/i2c.o ../sources/Src/i2c.c

${OBJECTDIR}/_ext/d6f1651e/main.o: ../sources/Src/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/main.o ../sources/Src/main.c

${OBJECTDIR}/_ext/d6f1651e/spi.o: ../sources/Src/spi.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/spi.o ../sources/Src/spi.c

${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o: ../sources/Src/stm32f7xx_hal_msp.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o ../sources/Src/stm32f7xx_hal_msp.c

${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o: ../sources/Src/stm32f7xx_it.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o ../sources/Src/stm32f7xx_it.c

${OBJECTDIR}/_ext/d6f1651e/tim.o: ../sources/Src/tim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/tim.o ../sources/Src/tim.c

${OBJECTDIR}/_ext/d6f1651e/usart.o: ../sources/Src/usart.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -O3 -DSTM32F765xx -DSTM32F7XX -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -DXITLIB -I. -I/../sources/Inc -I/../sources/Drivers/CMSIS/Include -I/../sources/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/../sources/Drivers/STM32F4xx_HAL_Driver/Inc -I/../../../XitLibWorking/External -I/../../../XitLibWorking/inc -I/../../../XitLibWorking/inc/coap -I/../../../XitLibWorking/inc/json -I/../../../XitLibWorking/inc/malloc -I/../../../XitLibWorking/inc/models -I/../sources/Drivers/CC3000 -I/../sources/Drivers/STM32_USB_Device_Library/Core/Inc -I/../sources/Drivers/STM32_USB_Device_Library/Class/CDC/Inc -I/../sources/Drivers/FreeRTOS/Source/CMSIS_RTOS -I/../sources/Drivers/FreeRTOS/Source/include -I/../sources/Drivers/FreeRTOS/Source/portable/MemMang -I/../sources/Drivers/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/../sources/Drivers/SimpleLink/include -I/../sources/Drivers/SimpleLink/platform -I/../../STM32-Bootloader-I2C -I/../../STM32-Bootloader-I2C/parsers -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/usart.o ../sources/Src/usart.c

${OBJECTDIR}/_ext/e9f01746/startup_stm32f429xx.o: /../sources/startup/startup_stm32f429xx.s
	${MKDIR} -p ${OBJECTDIR}/_ext/e9f01746
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/_ext/e9f01746/startup_stm32f429xx.o /../sources/startup/startup_stm32f429xx.s

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
