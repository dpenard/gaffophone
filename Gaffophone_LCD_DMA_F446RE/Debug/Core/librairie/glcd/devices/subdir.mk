################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/librairie/glcd/devices/AVR8.c \
../Core/librairie/glcd/devices/LPC111x.c \
../Core/librairie/glcd/devices/LPC11Uxx.c \
../Core/librairie/glcd/devices/PIC24H.c \
../Core/librairie/glcd/devices/PIC32.c \
../Core/librairie/glcd/devices/STM32F0xx.c \
../Core/librairie/glcd/devices/STM32F10x.c \
../Core/librairie/glcd/devices/STM32F4.c \
../Core/librairie/glcd/devices/STM32F4xx.c \
../Core/librairie/glcd/devices/STM32L0xx.c 

OBJS += \
./Core/librairie/glcd/devices/AVR8.o \
./Core/librairie/glcd/devices/LPC111x.o \
./Core/librairie/glcd/devices/LPC11Uxx.o \
./Core/librairie/glcd/devices/PIC24H.o \
./Core/librairie/glcd/devices/PIC32.o \
./Core/librairie/glcd/devices/STM32F0xx.o \
./Core/librairie/glcd/devices/STM32F10x.o \
./Core/librairie/glcd/devices/STM32F4.o \
./Core/librairie/glcd/devices/STM32F4xx.o \
./Core/librairie/glcd/devices/STM32L0xx.o 

C_DEPS += \
./Core/librairie/glcd/devices/AVR8.d \
./Core/librairie/glcd/devices/LPC111x.d \
./Core/librairie/glcd/devices/LPC11Uxx.d \
./Core/librairie/glcd/devices/PIC24H.d \
./Core/librairie/glcd/devices/PIC32.d \
./Core/librairie/glcd/devices/STM32F0xx.d \
./Core/librairie/glcd/devices/STM32F10x.d \
./Core/librairie/glcd/devices/STM32F4.d \
./Core/librairie/glcd/devices/STM32F4xx.d \
./Core/librairie/glcd/devices/STM32L0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/librairie/glcd/devices/%.o Core/librairie/glcd/devices/%.su Core/librairie/glcd/devices/%.cyclo: ../Core/librairie/glcd/devices/%.c Core/librairie/glcd/devices/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-librairie-2f-glcd-2f-devices

clean-Core-2f-librairie-2f-glcd-2f-devices:
	-$(RM) ./Core/librairie/glcd/devices/AVR8.cyclo ./Core/librairie/glcd/devices/AVR8.d ./Core/librairie/glcd/devices/AVR8.o ./Core/librairie/glcd/devices/AVR8.su ./Core/librairie/glcd/devices/LPC111x.cyclo ./Core/librairie/glcd/devices/LPC111x.d ./Core/librairie/glcd/devices/LPC111x.o ./Core/librairie/glcd/devices/LPC111x.su ./Core/librairie/glcd/devices/LPC11Uxx.cyclo ./Core/librairie/glcd/devices/LPC11Uxx.d ./Core/librairie/glcd/devices/LPC11Uxx.o ./Core/librairie/glcd/devices/LPC11Uxx.su ./Core/librairie/glcd/devices/PIC24H.cyclo ./Core/librairie/glcd/devices/PIC24H.d ./Core/librairie/glcd/devices/PIC24H.o ./Core/librairie/glcd/devices/PIC24H.su ./Core/librairie/glcd/devices/PIC32.cyclo ./Core/librairie/glcd/devices/PIC32.d ./Core/librairie/glcd/devices/PIC32.o ./Core/librairie/glcd/devices/PIC32.su ./Core/librairie/glcd/devices/STM32F0xx.cyclo ./Core/librairie/glcd/devices/STM32F0xx.d ./Core/librairie/glcd/devices/STM32F0xx.o ./Core/librairie/glcd/devices/STM32F0xx.su ./Core/librairie/glcd/devices/STM32F10x.cyclo ./Core/librairie/glcd/devices/STM32F10x.d ./Core/librairie/glcd/devices/STM32F10x.o ./Core/librairie/glcd/devices/STM32F10x.su ./Core/librairie/glcd/devices/STM32F4.cyclo ./Core/librairie/glcd/devices/STM32F4.d ./Core/librairie/glcd/devices/STM32F4.o ./Core/librairie/glcd/devices/STM32F4.su ./Core/librairie/glcd/devices/STM32F4xx.cyclo ./Core/librairie/glcd/devices/STM32F4xx.d ./Core/librairie/glcd/devices/STM32F4xx.o ./Core/librairie/glcd/devices/STM32F4xx.su ./Core/librairie/glcd/devices/STM32L0xx.cyclo ./Core/librairie/glcd/devices/STM32L0xx.d ./Core/librairie/glcd/devices/STM32L0xx.o ./Core/librairie/glcd/devices/STM32L0xx.su

.PHONY: clean-Core-2f-librairie-2f-glcd-2f-devices

