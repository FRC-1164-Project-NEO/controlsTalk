#ifndef TimeBasedController_H
#define TimeBasedController_H

#include <Commands/Command.h>

class PositionStopController : public frc::Command {
public:
	PositionStopController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    double distanceToGo;
    double motorPower;
};

#endif  // TimeBasedController_H
