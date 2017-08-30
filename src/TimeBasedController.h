#ifndef TimeBasedController_H
#define TimeBasedController_H

#include <Commands/Command.h>

class TimeBasedController : public frc::Command {
public:
	TimeBasedController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TimeBasedController_H
