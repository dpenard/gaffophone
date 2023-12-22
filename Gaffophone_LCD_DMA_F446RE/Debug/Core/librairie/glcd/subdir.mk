################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/librairie/glcd/glcd.c \
../Core/librairie/glcd/graphics.c \
../Core/librairie/glcd/graphs.c \
../Core/librairie/glcd/text.c \
../Core/librairie/glcd/text_tiny.c \
../Core/librairie/glcd/unit_tests.c 

OBJS += \
./Core/librairie/glcd/glcd.o \
./Core/librairie/glcd/graphics.o \
./Core/librairie/glcd/graphs.o \
./Core/librairie/glcd/text.o \
./Core/librairie/glcd/text_tiny.o \
./Core/librairie/glcd/unit_tests.o 

C_DEPS += \
./Core/librairie/glcd/glcd.d \
./Core/librairie/glcd/graphics.d \
./Core/librairie/glcd/graphs.d \
./Core/librairie/glcd/text.d \
./Core/librairie/glcd/text_tiny.d \
./Core/librairie/glcd/unit_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Core/librairie/glcd/%.o Core/librairie/glcd/%.su Core/librairie/glcd/%.cyclo: ../Core/librairie/glcd/%.c Core/librairie/glcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-librairie-2f-glcd

clean-Core-2f-librairie-2f-glcd:
	-$(RM) ./Core/librairie/glcd/glcd.cyclo ./Core/librairie/glcd/glcd.d ./Core/librairie/glcd/glcd.o ./Core/librairie/glcd/glcd.su ./Core/librairie/glcd/graphics.cyclo ./Core/librairie/glcd/graphics.d ./Core/librairie/glcd/graphics.o ./Core/librairie/glcd/graphics.su ./Core/librairie/glcd/graphs.cyclo ./Core/librairie/glcd/graphs.d ./Core/librairie/glcd/graphs.o ./Core/librairie/glcd/graphs.su ./Core/librairie/glcd/text.cyclo ./Core/librairie/glcd/text.d ./Core/librairie/glcd/text.o ./Core/librairie/glcd/text.su ./Core/librairie/glcd/text_tiny.cyclo ./Core/librairie/glcd/text_tiny.d ./Core/librairie/glcd/text_tiny.o ./Core/librairie/glcd/text_tiny.su ./Core/librairie/glcd/unit_tests.cyclo ./Core/librairie/glcd/unit_tests.d ./Core/librairie/glcd/unit_tests.o ./Core/librairie/glcd/unit_tests.su

.PHONY: clean-Core-2f-librairie-2f-glcd

