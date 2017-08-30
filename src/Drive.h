#ifndef Drive_H
#define Drive_H

#include <VictorSP.h>
#include <Commands/Subsystem.h>

class Drive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP *r1;
	VictorSP *r2;
	VictorSP *r3;

public:
	Drive();
	void setRight(double value);
	void InitDefaultCommand();
};

#endif  // Drive_H
