#ifndef TimeBasedController_H
#define TimeBasedController_H

#include <Commands/Command.h>
#include "Drive.h"

class PositionStopController : public frc::Command {
public:
	PositionStopController(Drive *Drive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    Drive *drive;
    
    double intergral;
    double lastError;
    
    double distanceToGo;
    double kp;
    double ki;
    double kd;
};

#endif  // TimeBasedController_H
