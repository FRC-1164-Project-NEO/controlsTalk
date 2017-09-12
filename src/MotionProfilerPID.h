


#ifndef MotionProfilerPID_H
#define MotionProfilerPID_H

#include <Commands/Command.h>
#include "Drive.h"
#include "motionProfiler.h"

class MotionProfilerPID : public frc::Command {
public:
	MotionProfilerPID(Drive *Drive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
    
private:
    Drive *drive;
    motionProfiler *profile;
    
    double intergral;
    double lastError;
    
    int curIteration;

    double distanceToGo;
    double kp;
    double ki;
    double kd;
};

#endif  // MotionProfilerPID_H
