/*
 * Robot.h
 *
 *  Created on: Aug 31, 2017
 *      Author: neoadmin
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <iostream>
#include <memory>
#include <string>

#include "Drive.h"
#include <Joystick.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot: public frc::IterativeRobot {
public:

	static std::shared_ptr<Drive> drive;
	static std::shared_ptr<Joystick> joystick;


	void RobotInit();
	void AutonomousInit() override;
	void AutonomousPeriodic();
	void TeleopInit();

	void TeleopPeriodic();
	void TestPeriodic();

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
};



#endif /* SRC_ROBOT_H_ */
