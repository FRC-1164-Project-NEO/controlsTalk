// PositionStopController    Written Ian Rankin September 2017
//
// This controller is a niave feedback controller
// It simply moves towards the setpoint at a static speed
// until it reaches the setpoint then it stops.
//
// For more info see the notes page:
//
// Constants used:
// posBasedSpeed - the motor speed to move towards controller
// distanceToGo - distanceToGo

#ifndef PositionStopController_H
#define PositionStopController_H

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
    
    double distanceToGo;
    double motorPower;
};

#endif  // PositionStopController_H
