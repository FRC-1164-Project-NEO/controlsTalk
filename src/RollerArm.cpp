// RollerArm   Written Ian Rankin September 2017
//
// The class encompases the roller arm
//
// Constants used:
// rollerCANID
// rollerCountsPerDegree
// rollerDegreeOffset

#include "RollerArm.h"
#include <Preferences.h>


RollerArm::RollerArm() : Subsystem("RollerArm") {
    Preferences *pref = Preferences::GetInstance();
    
    motor = new CANTalon(pref->GetInt("rollerCANID", 2));
    
    // set the talon to be controlled in throttle mode
    // Not PID or other control methods
    //motor->SetControlMode(CANTalon::kThrottleMode);
    
    countsPerDegree = pref->GetDouble("rollerCountsPerDegree", 1.0);
    degreeOffset = pref->GetDouble("rollerDegreeOffset", 0.0);
}

// set - set the speed of the motor between [-1,1]
// @param value - the motor speed to set between [-1,1]
void RollerArm::set(double value) {
	Preferences *pref = Preferences::GetInstance();
	value = -value;

	if (value > pref->GetDouble("armMaxUp", 0.01)) {
		value = pref->GetDouble("armMaxUp", 0.01);
	} else if (value > pref->GetDouble("armMaxDown", -0.01)) {
		value = pref->GetDouble("armMaxDown", -0.01);
	}

    motor->Set(value);
}

// resetEnc - resets the current encoder value
void RollerArm::resetEnc() {
    motor->SetEncPosition(0);
}

// getEnc this function returns the encoder value from the talon
// @ return the encoder value in degrees.
double RollerArm::getEnc() {
    return (motor->GetEncPosition() / countsPerDegree) + degreeOffset;
}

int RollerArm::getLimit() {
	return motor->GetPinStateQuadIdx();
	//return motor->GetReverseLimitOK();
}


void RollerArm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
