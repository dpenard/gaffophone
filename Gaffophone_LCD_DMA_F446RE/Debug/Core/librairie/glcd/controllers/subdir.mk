################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/librairie/glcd/controllers/NT75451.c \
../Core/librairie/glcd/controllers/PCD8544.c \
../Core/librairie/glcd/controllers/ST7565R.c 

OBJS += \
./Core/librairie/glcd/controllers/NT75451.o \
./Core/librairie/glcd/controllers/PCD8544.o \
./Core/librairie/glcd/controllers/ST7565R.o 

C_DEPS += \
./Core/librairie/glcd/controllers/NT75451.d \
./Core/librairie/glcd/controllers/PCD8544.d \
./Core/librairie/glcd/controllers/ST7565R.d 


# Each subdirectory must supply rules for building sources it contributes
Core/librairie/glcd/controllers/%.o Core/librairie/glcd/controllers/%.su Core/librairie/glcd/controllers/%.cyclo: ../Core/librairie/glcd/controllers/%.c Core/librairie/glcd/controllers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-librairie-2f-glcd-2f-controllers

clean-Core-2f-librairie-2f-glcd-2f-controllers:
	-$(RM) ./Core/librairie/glcd/controllers/NT75451.cyclo ./Core/librairie/glcd/controllers/NT75451.d ./Core/librairie/glcd/controllers/NT75451.o ./Core/librairie/glcd/controllers/NT75451.su ./Core/librairie/glcd/controllers/PCD8544.cyclo ./Core/librairie/glcd/controllers/PCD8544.d ./Core/librairie/glcd/controllers/PCD8544.o ./Core/librairie/glcd/controllers/PCD8544.su ./Core/librairie/glcd/controllers/ST7565R.cyclo ./Core/librairie/glcd/controllers/ST7565R.d ./Core/librairie/glcd/controllers/ST7565R.o ./Core/librairie/glcd/controllers/ST7565R.su

.PHONY: clean-Core-2f-librairie-2f-glcd-2f-controllers

