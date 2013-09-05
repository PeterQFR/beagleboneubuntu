################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AnalogOutput.cpp \
../src/DigitalInput.cpp \
../src/DigitalOutput.cpp \
../src/iopin.cpp \
../src/test.cpp 

OBJS += \
./src/AnalogOutput.o \
./src/DigitalInput.o \
./src/DigitalOutput.o \
./src/iopin.o \
./src/test.o 

CPP_DEPS += \
./src/AnalogOutput.d \
./src/DigitalInput.d \
./src/DigitalOutput.d \
./src/iopin.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


