################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/oled/ssd1306.c \
../Drivers/oled/ssd1306_fonts.c \
../Drivers/oled/ssd1306_tests.c 

OBJS += \
./Drivers/oled/ssd1306.o \
./Drivers/oled/ssd1306_fonts.o \
./Drivers/oled/ssd1306_tests.o 

C_DEPS += \
./Drivers/oled/ssd1306.d \
./Drivers/oled/ssd1306_fonts.d \
./Drivers/oled/ssd1306_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/oled/%.o Drivers/oled/%.su Drivers/oled/%.cyclo: ../Drivers/oled/%.c Drivers/oled/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/abarnika/STM32CubeIDE/workspace_1.19.0/Graphics_01/Drivers/oled" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-oled

clean-Drivers-2f-oled:
	-$(RM) ./Drivers/oled/ssd1306.cyclo ./Drivers/oled/ssd1306.d ./Drivers/oled/ssd1306.o ./Drivers/oled/ssd1306.su ./Drivers/oled/ssd1306_fonts.cyclo ./Drivers/oled/ssd1306_fonts.d ./Drivers/oled/ssd1306_fonts.o ./Drivers/oled/ssd1306_fonts.su ./Drivers/oled/ssd1306_tests.cyclo ./Drivers/oled/ssd1306_tests.d ./Drivers/oled/ssd1306_tests.o ./Drivers/oled/ssd1306_tests.su

.PHONY: clean-Drivers-2f-oled

