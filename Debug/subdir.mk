################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_config.c \
../PID.c \
../PollingDataClient.c \
../TC72.c \
../TimerCompareMode.c \
../device.c \
../gpio.c \
../lcd.c \
../main.c \
../poller.c \
../pwm.c \
../spi.c 

OBJS += \
./DIO_config.o \
./PID.o \
./PollingDataClient.o \
./TC72.o \
./TimerCompareMode.o \
./device.o \
./gpio.o \
./lcd.o \
./main.o \
./poller.o \
./pwm.o \
./spi.o 

C_DEPS += \
./DIO_config.d \
./PID.d \
./PollingDataClient.d \
./TC72.d \
./TimerCompareMode.d \
./device.d \
./gpio.d \
./lcd.d \
./main.d \
./poller.d \
./pwm.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


