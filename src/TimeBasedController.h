// TimeBasedController   Written Ian Rankin September 2017
//
// This is a niave controller that moves at a constant speed
// towards the setpoint for a certian amount of time then stops
// the controller is not robust
//
// For more info see the notes page:
//
// Constants used:
// timeBasedSpeed - the motor speed to move towards setpoint
// timeToRunSec - the time the controller runs for


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
