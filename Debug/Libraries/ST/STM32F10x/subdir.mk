################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/ST/STM32F10x/system_stm32f10x.c 

OBJS += \
./Libraries/ST/STM32F10x/system_stm32f10x.o 

C_DEPS += \
./Libraries/ST/STM32F10x/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/ST/STM32F10x/%.o: ../Libraries/ST/STM32F10x/%.c Libraries/ST/STM32F10x/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I"/home/abdelazim/Downloads/stm/Libraries/CMSIS" -I"/home/abdelazim/Downloads/stm/Libraries/ST/STM32F10x" -I"/home/abdelazim/Downloads/stm/Drives/Inc" -I"/home/abdelazim/Downloads/stm/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

