################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/CMSIS/core_cm3.c 

OBJS += \
./Libraries/CMSIS/core_cm3.o 

C_DEPS += \
./Libraries/CMSIS/core_cm3.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/CMSIS/%.o: ../Libraries/CMSIS/%.c Libraries/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I"/home/abdelazim/Downloads/stm/Libraries/CMSIS" -I"/home/abdelazim/Downloads/stm/Libraries/ST/STM32F10x" -I"/home/abdelazim/Downloads/stm/Drives/Inc" -I"/home/abdelazim/Downloads/stm/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

