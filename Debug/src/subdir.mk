################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/accelero.c \
../src/box.c \
../src/game.c \
../src/interrupt.c \
../src/main.c \
../src/screen.c \
../src/segments.c \
../src/switchs.c \
../src/tools.c 

OBJS += \
./src/accelero.o \
./src/box.o \
./src/game.o \
./src/interrupt.o \
./src/main.o \
./src/screen.o \
./src/segments.o \
./src/switchs.o \
./src/tools.o 

C_DEPS += \
./src/accelero.d \
./src/box.d \
./src/game.d \
./src/interrupt.d \
./src/main.d \
./src/screen.d \
./src/segments.d \
./src/switchs.d \
./src/tools.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I../../version_16_bsp/microblaze_0/include -mlittle-endian -mcpu=v10.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


