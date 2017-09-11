#include "TimeBasedController.h"
#include "Robot.h"


PositionStopController::PositionStopController() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drive.get());
}

// Called just before this Command runs the first time
void PositionStopController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    motorPower = pref->GetDouble("posBasedSpeed", 0)
    
    // block runs every 20ms, 1/20ms = 50Hz
    distanceToGo = pref->GetDouble("distanceToGo", 0.0);
    Robot::drive->resetEnc();
}

// Called repeatedly when this Command is scheduled to run
void PositionStopController::Execute() {
    Robot::drive->setLeft(motorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool PositionStopController::IsFinished() {
    // stop once a certian amount of time has passed.
    return curIteration >= iterationsToRun;
}

// Called once after isFinished returns true
void PositionStopController::End() {
    // stop the motor
    Robot::drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PositionStopController::Interrupted() {
    
}
