// RollerArm   Written Ian Rankin September 2017
//
// The class encompases the roller arm
//
// Constants used:
// rollerCANID
// rollerCountsPerDegree
// rollerDegreeOffset

#ifndef RollerArm_H
#define RollerArm_H

#include <CANTalon.h>
#include <Commands/Subsystem.h>

class RollerArm : public Subsystem {
private:
	// Talon speed controller
    CANTalon *motor;
    
    double countsPerDegree;
    double degreeOffset;

public:
	RollerArm();

    // set - set the speed of the motor between [-1,1]
    // @param value - the motor speed to set between [-1,1]
	void set(double value);

    // resetEnc - resets the current encoder value
	void resetEnc();
    
    // getEnc this function returns the encoder value from the talon
    // @ return the encoder value in degrees.
    double getEnc();

    int getLimit();

	void InitDefaultCommand();
};

#endif  // RollerArm_H
