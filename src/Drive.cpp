#include "Drive.h"
#include <Preferences.h>

const int r1PWM = 0;
const int r2PWM = 0;
const int r3PWM = 0;

Drive::Drive() : Subsystem("Drive") {
	Preferences *pref = Preferences::GetInstance();

	r1 = new VictorSP(pref->GetInt("driveR1", 0));
	r2 = new VictorSP(pref->GetInt("driveR2", 1));
	r3 = new VictorSP(pref->GetInt("driveR3", 2));

	l1 = new VictorSP(pref->GetInt("driveL1", 3));
	l2 = new VictorSP(pref->GetInt("driveL2", 4));
	l3 = new VictorSP(pref->GetInt("driveL3", 5));
}


//
void Drive::set(double left, double right) {
	setLeft(left);
	setRight(right);
}

// setRight
// This function sets the right side of the motors
// @param value - the value to control the left side to in range [-1,1]
void Drive::setLeft(double value) {
	l1->Set(value);
	l2->Set(value);
	l3->Set(value);
}

// setRight
// This function sets the right side of the motors
// @param value - the value to control the left side to in range [-1,1]
void Drive::setRight(double value) {
	r1->Set(value);
	r2->Set(value);
	r3->Set(value);
}



void Drive::resetEnc() {
	lEnc->Reset();
	rEnc->Reset();
}
double Drive::getLeft() {
	return lEnc->Get();
}
double Drive::getRight() {
	return rEnc->Get();
}



void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
