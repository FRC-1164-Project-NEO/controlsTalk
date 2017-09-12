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


#include "PositionStopController.h"
#include <Preferences.h>


PositionStopController::PositionStopController(Drive *Drive) {
	drive = Drive;
}

// Called just before this Command runs the first time
void PositionStopController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    motorPower = pref->GetDouble("posBasedSpeed", 0);
    
    // block runs every 20ms, 1/20ms = 50Hz
    distanceToGo = pref->GetDouble("distanceToGo", 0.0);
    drive->resetEnc();
}

// Called repeatedly when this Command is scheduled to run
void PositionStopController::Execute() {
    drive->setRight(motorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool PositionStopController::IsFinished() {
    // stop once a certian distance has been moved
    return drive->getRightEnc() >= distanceToGo;
}

// Called once after isFinished returns true
void PositionStopController::End() {
    // stop the motor once done.
    drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PositionStopController::Interrupted() {
    
}
