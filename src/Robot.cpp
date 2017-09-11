#include "Robot.h"
#include "TimeBasedController.h"
#include <cstdlib>
#include <Preferences.h>



void Robot::RobotInit() {
	chooser.AddDefault(autoNameDefault, autoNameDefault);
	chooser.AddObject(autoNameCustom, autoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	// init sub-systems
	drive = new Drive();
	joystick = new Joystick(0);


	// init commands
	frc::SmartDashboard::PutData("timeBasedController", new TimeBasedController(drive));
    frc::SmartDashboard::PutData("PositionStopController", new PositionStopController(drive));
    frc::SmartDashboard::PutData("PController", new PController(drive));
    frc::SmartDashboard::PutData("PIDController", new PIDController(drive));
}

void Robot::RobotPeriodic() {
	if (joystick->GetRawButton(Preferences::GetInstance()->GetInt("EncResetButton",1))) {
		drive->resetEnc();
	}
}

/*
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString line to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the
 * SendableChooser make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
	autoSelected = chooser.GetSelected();
	// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
	std::cout << "Auto selected: " << autoSelected << std::endl;

	if (autoSelected == autoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::AutonomousPeriodic() {
	if (autoSelected == autoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	drive->set(-joystick->GetY(), -joystick->GetThrottle());

	// This is done because the smart dashboard only updates when a new value is given to it.
	// Giving small varying number added to actual number.
	double smallRandomNumber = (rand() % 500) / 4000.0;
	double encoderValue = drive->getRightEnc() + smallRandomNumber;
	frc::SmartDashboard::PutNumber("EncoderPosition", encoderValue);
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)


