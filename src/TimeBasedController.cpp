#include "TimeBasedController.h"
//#include "Robot.h"


TimeBasedController::TimeBasedController(Drive *Drive) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	drive = Drive;
}

// Called just before this Command runs the first time
void TimeBasedController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
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
    // stop the motor
    drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimeBasedController::Interrupted() {
    
}
