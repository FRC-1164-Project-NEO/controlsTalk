// TimeBasedController   Written Ian Rankin September 2017
//
// This is a niave controller that moves at a constant speed
// towards the setpoint for a certian amount of time then stops
// the controller is not robust
//
// For more info see the notes page:

#include "TimeBasedController.h"


TimeBasedController::TimeBasedController(Drive *Drive) {
	// set drive for the controller
	drive = Drive;
}

// Called just before this Command runs the first time
void TimeBasedController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    
    // set speed to run the controller at.
    motorPower = pref->GetDouble("timeBasedSpeed", 0)
    
    // block runs every 20ms, 1/20ms = 50Hz
    iterationsToRun = pref->GetDouble("timeToRunSec", 0.0) * 50;
    curIteration = 0;
}

// Called repeatedly when this Command is scheduled to run
void TimeBasedController::Execute() {
    Robot::drive->setLeft(motorPower);
    
    // increment the number of iterations
    curIteration++;
}

// Make this return true when this Command no longer needs to run execute()
bool TimeBasedController::IsFinished() {
    // stop once a certian amount of time has passed.
    return curIteration >= iterationsToRun;
}

// Called once after isFinished returns true
void TimeBasedController::End() {
    // stop the motor once done.
    drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimeBasedController::Interrupted() {
    
}
