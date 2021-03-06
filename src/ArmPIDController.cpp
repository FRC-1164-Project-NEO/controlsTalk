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

#include "ArmPIDController.h"
#include <Preferences.h>


ArmPIDController::ArmPIDController(RollerArm *Arm) {
	// Find
    arm = Arm;
}

// Called just before this Command runs the first time
void ArmPIDController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    
    // Get the constants for the PID Controller
    kp = pref->GetDouble("ArmKp", 0);
    ki = pref->GetDouble("ArmKi", 0);
    kd = pref->GetDouble("ArmKd", 0);
    
    distanceToGo = pref->GetDouble("ArmControlLocation", 0.0);
    
    // have to reset the intergral at the start of calling the controller
    intergral = 0;
    
    // set original error to the first original error
    lastError = arm->getEnc();
}

// block runs every 20ms
const double T = .020;

// Called repeatedly when this Command is scheduled to run
void ArmPIDController::Execute() {
    double error = distanceToGo - arm->getEnc();
    
    // calculate the intergral using a rectangle method
    intergral += (error * T);
    
    // calculate derivative using simplistic rise of run
    // of last error method
    double derivative = (error - lastError) / T;
    
    // Calculate the PID output
    double output = (error * kp) + (intergral * ki) + (derivative * kd);
    arm->set(output);
    
    // reset last error as the current error for the next iteration
    lastError = error;
}

// Make this return true when this Command no longer needs to run execute()
bool ArmPIDController::IsFinished() {
    // stop once a certian amount of time has passed.
    return false; // only stop if forced to stop
}

// Called once after isFinished returns true
void ArmPIDController::End() {
    // stop the motor
    arm->set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmPIDController::Interrupted() {
	arm->set(0);
}
