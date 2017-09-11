// Drive    Written Ian Rankin September 2017
//
// This class encompases the drive

#ifndef Drive_H
#define Drive_H

#include <VictorSP.h>
#include <Encoder.h>
#include <Commands/Subsystem.h>

class Drive : public Subsystem {
private:
	// Drive motors
	VictorSP *r1;
	VictorSP *r2;
	VictorSP *r3;

	VictorSP *l1;
	VictorSP *l2;
	VictorSP *l3;

	// Encoder inputs
	Encoder *lEnc;
	Encoder *rEnc;
    
    double countsPerDegree;

public:
	Drive();

    // set
    // This function sets the speed for the drive.
    // @param left - the speed of the left side in range [-1, 1]
    // @param right - the speed of the right side in range [-1, 1]
	void set(double left, double right);

    // setRight
    // This function sets the right side of the motors
    // @param value - the value to control the left side to in range [-1,1]
	void setLeft(double value);
    // setRight
    // This function sets the right side of the motors
    // @param value - the value to control the left side to in range [-1,1]
	void setRight(double value);

    
    // resets the encoder
	void resetEnc();
    
    // Read drive encoders
	double getLeftEnc();
	double getRightEnc();

	void InitDefaultCommand();
};

#endif  // Drive_H
