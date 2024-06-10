################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DcMotor.c \
../LCD.c \
../PWM.c \
../gpio.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./ADC.o \
./DcMotor.o \
./LCD.o \
./PWM.o \
./gpio.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./ADC.d \
./DcMotor.d \
./LCD.d \
./PWM.d \
./gpio.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


