################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application.c \
../dll.c \
../dll_util.c 

O_SRCS += \
../application.o \
../dll.o \
../dll_util.o 

OBJS += \
./application.o \
./dll.o \
./dll_util.o 

C_DEPS += \
./application.d \
./dll.d \
./dll_util.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


