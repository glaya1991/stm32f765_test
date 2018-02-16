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
CND_PLATFORM=GNU_ARM-Windows
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
	${OBJECTDIR}/startup_stm32f429xx.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.o \
	${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.o \
	${OBJECTDIR}/stm32f4/Src/ExtFunctionsMC.o \
	${OBJECTDIR}/stm32f4/Src/ad7190.o \
	${OBJECTDIR}/stm32f4/Src/dma.o \
	${OBJECTDIR}/stm32f4/Src/fmc.o \
	${OBJECTDIR}/stm32f4/Src/gpio.o \
	${OBJECTDIR}/stm32f4/Src/i2c.o \
	${OBJECTDIR}/stm32f4/Src/main.o \
	${OBJECTDIR}/stm32f4/Src/spi.o \
	${OBJECTDIR}/stm32f4/Src/stm32f4xx_hal_msp.o \
	${OBJECTDIR}/stm32f4/Src/stm32f4xx_it.o \
	${OBJECTDIR}/stm32f4/Src/system_stm32f4xx.o \
	${OBJECTDIR}/stm32f4/Src/tim.o \
	${OBJECTDIR}/stm32f4/Src/usart.o


# C Compiler Flags
CFLAGS=-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lgcc -lc -lm ../../XitLibWorking/libxitlib_cortexm4.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/stm32f429_firmware.elf.exe

${CND_DISTDIR}/${CND_CONF}/stm32f429_firmware.elf.exe: ../../XitLibWorking/libxitlib_cortexm4.a

${CND_DISTDIR}/${CND_CONF}/stm32f429_firmware.elf.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/stm32f429_firmware.elf ${OBJECTFILES} ${LDLIBSOPTIONS} -TSTM32F429BITx_FLASH.ld

${OBJECTDIR}/startup_stm32f429xx.o: startup_stm32f429xx.s
	${MKDIR} -p ${OBJECTDIR}
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/startup_stm32f429xx.o startup_stm32f429xx.s

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c

${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.o: stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.o stm32f4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c

${OBJECTDIR}/stm32f4/Src/ExtFunctionsMC.o: stm32f4/Src/ExtFunctionsMC.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/ExtFunctionsMC.o stm32f4/Src/ExtFunctionsMC.c

${OBJECTDIR}/stm32f4/Src/ad7190.o: stm32f4/Src/ad7190.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/ad7190.o stm32f4/Src/ad7190.c

${OBJECTDIR}/stm32f4/Src/dma.o: stm32f4/Src/dma.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/dma.o stm32f4/Src/dma.c

${OBJECTDIR}/stm32f4/Src/fmc.o: stm32f4/Src/fmc.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/fmc.o stm32f4/Src/fmc.c

${OBJECTDIR}/stm32f4/Src/gpio.o: stm32f4/Src/gpio.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/gpio.o stm32f4/Src/gpio.c

${OBJECTDIR}/stm32f4/Src/i2c.o: stm32f4/Src/i2c.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/i2c.o stm32f4/Src/i2c.c

${OBJECTDIR}/stm32f4/Src/main.o: stm32f4/Src/main.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/main.o stm32f4/Src/main.c

${OBJECTDIR}/stm32f4/Src/spi.o: stm32f4/Src/spi.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/spi.o stm32f4/Src/spi.c

${OBJECTDIR}/stm32f4/Src/stm32f4xx_hal_msp.o: stm32f4/Src/stm32f4xx_hal_msp.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/stm32f4xx_hal_msp.o stm32f4/Src/stm32f4xx_hal_msp.c

${OBJECTDIR}/stm32f4/Src/stm32f4xx_it.o: stm32f4/Src/stm32f4xx_it.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/stm32f4xx_it.o stm32f4/Src/stm32f4xx_it.c

${OBJECTDIR}/stm32f4/Src/system_stm32f4xx.o: stm32f4/Src/system_stm32f4xx.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/system_stm32f4xx.o stm32f4/Src/system_stm32f4xx.c

${OBJECTDIR}/stm32f4/Src/tim.o: stm32f4/Src/tim.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/tim.o stm32f4/Src/tim.c

${OBJECTDIR}/stm32f4/Src/usart.o: stm32f4/Src/usart.c
	${MKDIR} -p ${OBJECTDIR}/stm32f4/Src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCCDefines -DEVOKER -DMC -DP300 -DSL_FULL -DSTM32 -DSTM32F429xx -DUSE_HAL_DRIVER -DUSE_STDPERIPH_DRIVER -D__MIKROC_PRO_FOR_ARM__ -I. -Istm32f4 -Istm32f4/Inc -Istm32f4/Drivers/CMSIS/Include -Istm32f4/Drivers/CMSIS/Device/ST/STM32F4xx/Include -Istm32f4/Drivers/STM32F4xx_HAL_Driver/Inc -ILibrary/Inc -I../../XitLibWorking/External -I../../XitLibWorking/inc -I../../XitLibWorking/inc/coap -I../../XitLibWorking/inc/json -I../../XitLibWorking/inc/malloc -I../../XitLibWorking/inc/models -Istm32f4/WiFi/Inc -Istm32f4/SimpleLink/include -Istm32f4/SimpleLink/source -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stm32f4/Src/usart.o stm32f4/Src/usart.c

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
