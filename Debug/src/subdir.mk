################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AnalogOutput.cpp \
../src/DigitalInput.cpp \
../src/DigitalOutput.cpp \
../src/SPI.cpp \
../src/iopin.cpp \
../src/test.cpp 

OBJS += \
./src/AnalogOutput.o \
./src/DigitalInput.o \
./src/DigitalOutput.o \
./src/SPI.o \
./src/iopin.o \
./src/test.o 

CPP_DEPS += \
./src/AnalogOutput.d \
./src/DigitalInput.d \
./src/DigitalOutput.d \
./src/SPI.d \
./src/iopin.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/arm-linux-gnueabihf/include/c++/4.6.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


