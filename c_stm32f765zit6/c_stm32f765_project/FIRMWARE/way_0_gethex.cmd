set NAME_FILE=stm32f429_firmware
set PATH_ARM_EABI=C:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q2-update\bin\
cd ..\dist\Release\GNU-ARM-Windows\
"%PATH_ARM_EABI%arm-none-eabi-readelf.exe" -S %NAME_FILE%.elf
"%PATH_ARM_EABI%arm-none-eabi-objcopy.exe" -Oihex %NAME_FILE%.elf ../../../FIRMWARE/%NAME_FILE%.hex