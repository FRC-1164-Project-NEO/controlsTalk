#include "TimeBasedController.h"
#include "Robot.h"


TimeBasedController::TimeBasedController() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(Robot::drive.get());
}

// Called just before this Command runs the first time
void TimeBasedController::Initialize() {
	//Robot::drive->resetEnc();
}

// Called repeatedly when this Command is scheduled to run
void TimeBasedController::Execute() {
	//double value = Robot::drive->getLeft();


}

// Make this return true when this Command no longer needs to run execute()
bool TimeBasedController::IsFinished() {
	return false; // TODO: FIX JERK!
}

// Called once after isFinished returns true
void TimeBasedController::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimeBasedController::Interrupted() {

}
