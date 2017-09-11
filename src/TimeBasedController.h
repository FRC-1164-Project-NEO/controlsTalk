#ifndef TimeBasedController_H
#define TimeBasedController_H

#include "Drive.h"
#include <Commands/Command.h>

class TimeBasedController : public frc::Command {
public:
	TimeBasedController(Drive *Drive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    int iterationsToRun;
    int curIteration;
    double motorPower;
	Drive *drive;
};

#endif  // TimeBasedController_H
