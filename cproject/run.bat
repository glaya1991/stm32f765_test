del "dist\Release\stm32f429_firmware.hex"
arm-none-eabi-objcopy -O ihex dist\Release\stm32f429_firmware.elf dist\Release\stm32f429_firmware.hex
"C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe" -c SWD -p "dist\Release\stm32f429_firmware.hex" -Rst -Run
del "dist\Release\stm32f429_firmware.hex"