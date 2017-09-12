#include "Robot.h"

#include "TimeBasedController.h"
#include "PositionStopController.h"
#include "PController.h"
#include "PIDController.h"
#include "MotionProfilerPID.h"
#include "ArmPIDController.h"
#include "ArmLinearize.h"

#include <cstdlib>
#include <Preferences.h>



void Robot::RobotInit() {
	chooser.AddDefault(autoNameDefault, autoNameDefault);
	chooser.AddObject(autoNameCustom, autoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	// init sub-systems
	drive = new Drive();
	arm = new RollerArm();
	joystick = new Joystick(0);


	// init commands
	frc::SmartDashboard::PutData("timeBasedController", new TimeBasedController(drive));
    frc::SmartDashboard::PutData("PositionStopController", new PositionStopController(drive));
    frc::SmartDashboard::PutData("PController", new PController(drive));
    frc::SmartDashboard::PutData("PIDController", new PIDController(drive));
    frc::SmartDashboard::PutData("MotionProfilePID", new MotionProfilerPID(drive));
    frc::SmartDashboard::PutData("ArmPIDController", new ArmPIDController(arm));
    frc::SmartDashboard::PutData("ArmLinearize", new ArmLinearize(arm));
}

// runs periodicly in every state
void Robot::RobotPeriodic() {
	if (joystick->GetRawButton(Preferences::GetInstance()->GetInt("EncResetButton",1))) {
		drive->resetEnc();
	}

	frc::SmartDashboard::PutNumber("EncoderPositionActual", drive->getRightEnc());
	frc::SmartDashboard::PutNumber("ArmPositionActual", arm->getEnc());
	frc::SmartDashboard::PutNumber("ArmLimit", arm->getLimit());

	if (arm->getLimit() == 0) {
		arm->resetEnc();
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
	//frc::Command *command = new TimeBasedController(drive);
	//command->Start();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	Preferences *pref = Preferences::GetInstance();
	//drive->set(-joystick->GetY(), -joystick->GetThrottle());
	//arm->set(-joystick->GetY());
	//arm->set(pref->GetDouble("armPower", 0.0));

	// This is done because the smart dashboard only updates when a new value is given to it.
	// Giving small varying number added to actual number.
	double smallRandomNumber = (rand() % 500) / 4000.0;
	double encoderValue = drive->getRightEnc() + smallRandomNumber;
	frc::SmartDashboard::PutNumber("EncoderPosition", encoderValue);

	frc::SmartDashboard::PutNumber("ArmPosition", arm->getEnc() + smallRandomNumber);
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)


