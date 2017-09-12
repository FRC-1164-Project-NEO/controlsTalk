// PController     Written Ian Rankin September 2017
// This command implements a simple proportional controller
// that controls the right side of the drive train
//
// The gains to set the P controller is
// PKp - is the kp constant in the preferecnes file.

#include "PController.h"
#include <Preferences.h>


PController::PController(Drive *Drive) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
    drive = Drive;
}

// Called just before this Command runs the first time
void PController::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    kp = pref->GetDouble("PKp", 0);
    
    // block runs every 20ms, 1/20ms = 50Hz
    distanceToGo = pref->GetDouble("distanceToGo", 0.0);
    drive->resetEnc();
}

// Called repeatedly when this Command is scheduled to run
void PController::Execute() {
    double error = distanceToGo - drive->getRightEnc();
    
    drive->setRight(error * kp);
}

// Make this return true when this Command no longer needs to run execute()
bool PController::IsFinished() {
    // stop once a certian amount of time has passed.
    return false; // only stop if forced to stop
}

// Called once after isFinished returns true
void PController::End() {
    // stop the motor
    drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PController::Interrupted() {
    
}
