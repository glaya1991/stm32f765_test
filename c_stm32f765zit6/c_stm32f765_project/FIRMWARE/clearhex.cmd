set NAME_FILE=stm32f429_firmware

DEL /F /S /Q /A %NAME_FILE%.hex

RD /S /Q ..\build\Release
RD /S /Q ..\build\Debug
RD /S /Q ..\dist\Release
RD /S /Q ..\dist\Debug