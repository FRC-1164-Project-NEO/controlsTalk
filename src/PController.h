// PController     Written Ian Rankin September 2017
// This command implements a simple proportional controller
// that controls the right side of the drive train
//
// The gains to set the P controller is
//
// Constants used:
// PKp - is the kp constant in the preferecnes file.
// distanceToGo - the distance for this controller to use as it's input


#ifndef PController_H
#define PController_H

#include <Commands/Command.h>
#include "Drive.h"

class PController : public frc::Command {
public:
	PController(Drive *Drive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    Drive *drive;
    
    double distanceToGo;
    double kp;
};

#endif  // PController_H
