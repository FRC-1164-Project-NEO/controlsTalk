#include "Drive.h"

const int r1PWM = 0;
const int r2PWM = 0;
const int r3PWM = 0;

Drive::Drive() : Subsystem("BasicDrive") {
	r1 = new VictorSP(r1PWM);
	r2 = new VictorSP(r2PWM);
	r3 = new VictorSP(r3PWM);
}

// setRight
// This function sets the right side of the motors
// @param value - the value to control the left side to in range [-1,1]
void Drive::setRight(double value) {
	r1->Set(value);
	r2->Set(value);
	r3->Set(value);
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
