

#include "MotionProfilerPID.h"
#include <Preferences.h>


MotionProfilerPID::MotionProfilerPID(Drive *Drive) {
	// Find
    drive = Drive;
}

// Called just before this Command runs the first time
void MotionProfilerPID::Initialize() {
    Preferences *pref = Preferences::GetInstance();
    
    // Get the constants for the PID Controller
    kp = pref->GetDouble("Kp", 0);
    ki = pref->GetDouble("Ki", 0);
    kd = pref->GetDouble("Kd", 0);
    
    distanceToGo = pref->GetDouble("distanceToGo", 0.0);
    // reset the distance to go for the controller
    drive->resetEnc();
    
    // delete old profiles if required
    //if (profile != NULL) {
    //	delete profile;
    //}
    // create profile and set inital V = 0 and the distance to go
    profile = new motionProfiler(pref->GetDouble("AMax", 1), pref->GetDouble("VMax", 1));
    profile->setDistance(distanceToGo, 0);

    // have to reset the intergral at the start of calling the controller
    intergral = 0;
    

    curIteration = 0;

    // set original error to the first original error
    lastError = drive->getRightEnc();
}

// block runs every 20ms
const double T = .020;

// Called repeatedly when this Command is scheduled to run
void MotionProfilerPID::Execute() {
    double error = profile->getPosition(curIteration * T) - drive->getRightEnc();
    
    // calculate the intergral using a rectangle method
    intergral += (error * T);
    
    // calculate derivative using simplistic rise of run
    // of last error method
    double derivative = (error - lastError) / T;
    
    // Calculate the PID output
    double output = (error * kp) + (intergral * ki) + (derivative * kd);
    drive->setRight(output);
    
    // reset last error as the current error for the next iteration
    lastError = error;
    curIteration++;
}

// Make this return true when this Command no longer needs to run execute()
bool MotionProfilerPID::IsFinished() {
    // stop once a certian amount of time has passed.
    return false; // only stop if forced to stop
}

// Called once after isFinished returns true
void MotionProfilerPID::End() {
    // stop the motor
    drive->set(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MotionProfilerPID::Interrupted() {
	drive->set(0,0);
}
