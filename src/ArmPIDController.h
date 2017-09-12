// PIDController     Written Ian Rankin September 2017
//
// PID Controller this is probably the most popular controller
// in the world.
// There are some issues with this controller and things that make
// it work better. One of these is by adding a feed-forward component
// to the setpoint of the controller. One such feed-forward component
// if the motion profiler also in this code.
//
// The constants of the PID controller are:
// kp - the proportional gain
// ki - the intergral gain
// kd - the derivative gain
//
// distanceToGo - the distance for this controller to use as it's input
//
// block diagram
//
//                         +------+
//                         |      |
//                    +--->| kp   |------------------|
//                    |    |      |                  |
//                    |    +------+                  |
//                    |                              v
//          +------+  |    +------+   +------+    +------+   +-------+
//          |      |  |    |      |   |      |    |      |   |       |
//r(t)----->|+     ---|--> |  ki  |-->|  ∫   |--> |  ∑   |-->| Plant |-----------> y(t)
//          |  -   |  |    |      |   |      |    |      |   |       |     |
//          +--|---+  |    +------+   +------+    +------+   +-------+     |
//             |      |                              ^                     |
//             |      |    +------+   +------+       |                     |
//             |      |    |      |   |  d   |       |                     |
//             |      +--->| kd   |-->| ---  |-------+                     |
//             |           |      |   |  dt  |                             |
//             |           +------+   +------+                             |
//             |                                                           |
//             +-----------------------------------------------------------+
//
// For more info see notes page:
// Also see:
// https://en.wikipedia.org/wiki/PID_controller
// http://www.ni.com/white-paper/3782/en/
//
// Also note in literature we have the PID controller in Ideal form, and not in standard form.






#ifndef ArmPIDController_H
#define ArmPIDController_H

#include <Commands/Command.h>
#include "RollerArm.h"

class ArmPIDController : public frc::Command {
public:
	ArmPIDController(RollerArm *Drive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    RollerArm *arm;
    
    double intergral;
    double lastError;
    
    double distanceToGo;
    double kp;
    double ki;
    double kd;
};

#endif  // ArmPIDController_H
