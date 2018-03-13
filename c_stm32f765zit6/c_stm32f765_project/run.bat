set PATH_ST_LINK=C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\
set PATH_ARM_EABI=C:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q2-update\bin\
set NAME_FILE=stm32f429_firmware
set NAME_TOOL=GNU-ARM
set NAME_SETTING=Debug

cd %CD%\dist\%NAME_SETTING%\%NAME_TOOL%-Windows\

set ERROR_SCRIPT=%ERRORLEVEL%

if %ERROR_SCRIPT% neq 0 set NAME_SETTING=Release
if %ERROR_SCRIPT% neq 0 cd %CD%\dist\%NAME_SETTING%\%NAME_TOOL%-Windows\

"%PATH_ARM_EABI%arm-none-eabi-readelf.exe" -S %NAME_FILE%.elf
"%PATH_ARM_EABI%arm-none-eabi-objcopy.exe" -Oihex %NAME_FILE%.elf ../../../FIRMWARE/%NAME_FILE%.hex
"%PATH_ARM_EABI%arm-none-eabi-objcopy.exe" -Obinary %NAME_FILE%.elf ../../../FIRMWARE/%NAME_FILE%.bin

"%PATH_ST_LINK%ST-LINK_CLI.exe" -c SWD UR freq=1000 -P ../../../FIRMWARE/%NAME_FILE%.hex -V -Rst