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

	void set(double left, double right);

	void setLeft(double value);
	void setRight(double value);

	void resetEnc();
	double getLeftEnc();
	double getRightEnc();

	void InitDefaultCommand();
};

#endif  // Drive_H
