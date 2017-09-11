//
//  motionProfiler.h
//  
//
//  Created by Ian Rankin on 1/14/16.
//
// a trapizodial motion planner
// the velocity graph is a trapizod and the acceleration is step functions.
// allows you to enter a inital V.

#ifndef ____motionProfiler__
#define ____motionProfiler__

#include <iostream>

using namespace std;

class motionProfiler {
public:
    motionProfiler(double AMax, double VMax);
    
    void setDistance(double Distance, double VInital);
    
    double getPosition(double time);
    double totalTime();
    
    
private:
    double t1;
    double t2;
    double t3;
    double vInital;
    bool negate;
    double v2;
    
    double aMax;
    double vMax;
    
    double distance;
    
    double getPositionP(double time);
};

#endif /* defined(____motionProfiler__) */
