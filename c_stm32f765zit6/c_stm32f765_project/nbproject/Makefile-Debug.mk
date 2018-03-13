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
CCC=g++
CXX=g++
FC=gfortran
AS=arm-none-eabi-ld

# Macros
CND_PLATFORM=GNU-ARM-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/48f06713/core.o \
	${OBJECTDIR}/_ext/48f06713/delay.o \
	${OBJECTDIR}/_ext/48f06713/dma.o \
	${OBJECTDIR}/_ext/48f06713/graph.o \
	${OBJECTDIR}/_ext/48f06713/text.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_cortex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_gpio.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_spi.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim_ex.o \
	${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_uart.o \
	${OBJECTDIR}/_ext/d6f1651e/dma.o \
	${OBJECTDIR}/_ext/d6f1651e/gpio.o \
	${OBJECTDIR}/_ext/d6f1651e/i2c.o \
	${OBJECTDIR}/_ext/d6f1651e/main.o \
	${OBJECTDIR}/_ext/d6f1651e/spi.o \
	${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o \
	${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o \
	${OBJECTDIR}/_ext/d6f1651e/system_stm32f7xx.o \
	${OBJECTDIR}/_ext/d6f1651e/tim.o \
	${OBJECTDIR}/_ext/d6f1651e/usart.o \
	${OBJECTDIR}/_ext/27a824d7/startup_stm32f765xx.o


# C Compiler Flags
CFLAGS=-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/../XitLib/dist/Debug_MC/GNU-ARM-Windows/libxitlib.a /../EEG_Evoker/dist/Debug_MC/GNU-ARM-Windows/libeeg_evoker.a /../CoAP/dist/Debug_MC/GNU-ARM-Windows/libcoap.a -lgcc -lm -lc

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf.exe: /../XitLib/dist/Debug_MC/GNU-ARM-Windows/libxitlib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf.exe: /../EEG_Evoker/dist/Debug_MC/GNU-ARM-Windows/libeeg_evoker.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf.exe: /../CoAP/dist/Debug_MC/GNU-ARM-Windows/libcoap.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/controllernew.elf ${OBJECTFILES} ${LDLIBSOPTIONS} -Tstm32f4_flash.ld

${OBJECTDIR}/_ext/48f06713/core.o: ../sources/Drivers/ILI9341/core.c
	${MKDIR} -p ${OBJECTDIR}/_ext/48f06713
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/48f06713/core.o ../sources/Drivers/ILI9341/core.c

${OBJECTDIR}/_ext/48f06713/delay.o: ../sources/Drivers/ILI9341/delay.c
	${MKDIR} -p ${OBJECTDIR}/_ext/48f06713
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/48f06713/delay.o ../sources/Drivers/ILI9341/delay.c

${OBJECTDIR}/_ext/48f06713/dma.o: ../sources/Drivers/ILI9341/dma.c
	${MKDIR} -p ${OBJECTDIR}/_ext/48f06713
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/48f06713/dma.o ../sources/Drivers/ILI9341/dma.c

${OBJECTDIR}/_ext/48f06713/graph.o: ../sources/Drivers/ILI9341/graph.c
	${MKDIR} -p ${OBJECTDIR}/_ext/48f06713
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/48f06713/graph.o ../sources/Drivers/ILI9341/graph.c

${OBJECTDIR}/_ext/48f06713/text.o: ../sources/Drivers/ILI9341/text.c
	${MKDIR} -p ${OBJECTDIR}/_ext/48f06713
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/48f06713/text.o ../sources/Drivers/ILI9341/text.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_cortex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_cortex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_dma_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_flash_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_gpio.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_gpio.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_i2c_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_pwr_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_rcc_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_spi.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_spi.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim_ex.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_tim_ex.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c

${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_uart.o: ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3d9a2b56
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3d9a2b56/stm32f7xx_hal_uart.o ../sources/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c

${OBJECTDIR}/_ext/d6f1651e/dma.o: ../sources/Src/dma.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/dma.o ../sources/Src/dma.c

${OBJECTDIR}/_ext/d6f1651e/gpio.o: ../sources/Src/gpio.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/gpio.o ../sources/Src/gpio.c

${OBJECTDIR}/_ext/d6f1651e/i2c.o: ../sources/Src/i2c.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/i2c.o ../sources/Src/i2c.c

${OBJECTDIR}/_ext/d6f1651e/main.o: ../sources/Src/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/main.o ../sources/Src/main.c

${OBJECTDIR}/_ext/d6f1651e/spi.o: ../sources/Src/spi.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/spi.o ../sources/Src/spi.c

${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o: ../sources/Src/stm32f7xx_hal_msp.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_hal_msp.o ../sources/Src/stm32f7xx_hal_msp.c

${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o: ../sources/Src/stm32f7xx_it.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/stm32f7xx_it.o ../sources/Src/stm32f7xx_it.c

${OBJECTDIR}/_ext/d6f1651e/system_stm32f7xx.o: ../sources/Src/system_stm32f7xx.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/system_stm32f7xx.o ../sources/Src/system_stm32f7xx.c

${OBJECTDIR}/_ext/d6f1651e/tim.o: ../sources/Src/tim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/tim.o ../sources/Src/tim.c

${OBJECTDIR}/_ext/d6f1651e/usart.o: ../sources/Src/usart.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d6f1651e
	${RM} "$@.d"
	$(COMPILE.c) -g -DSTM32F429xx -DUSE_HAL_DRIVER -I/../XitLib -IPeriph -Ilibraries/Imp/Inc -I. -Ilibraries/CMSIS/Include -Ilibraries/CMSIS/Device/ST/STM32F4xx/Include -Ilibraries/STM32F4xx_HAL_Driver/Inc -I../sources/Drivers/ILI9341 -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d6f1651e/usart.o ../sources/Src/usart.c

${OBJECTDIR}/_ext/27a824d7/startup_stm32f765xx.o: ../sources/startup/startup_stm32f765xx.s
	${MKDIR} -p ${OBJECTDIR}/_ext/27a824d7
	$(AS) $(ASFLAGS) -g -o ${OBJECTDIR}/_ext/27a824d7/startup_stm32f765xx.o ../sources/startup/startup_stm32f765xx.s

# Subprojects
.build-subprojects:
	cd /../XitLib && ${MAKE}  -f Makefile CONF=Debug_MC
	cd /../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug_MC
	cd /../CoAP && ${MAKE}  -f Makefile CONF=Debug_MC
	cd /../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug_MC
	cd /../XitLib && ${MAKE}  -f Makefile CONF=Debug_MC
	cd /../CoAP && ${MAKE}  -f Makefile CONF=Debug_MC

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd /../XitLib && ${MAKE}  -f Makefile CONF=Debug_MC clean
	cd /../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug_MC clean
	cd /../CoAP && ${MAKE}  -f Makefile CONF=Debug_MC clean
	cd /../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug_MC clean
	cd /../XitLib && ${MAKE}  -f Makefile CONF=Debug_MC clean
	cd /../CoAP && ${MAKE}  -f Makefile CONF=Debug_MC clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
