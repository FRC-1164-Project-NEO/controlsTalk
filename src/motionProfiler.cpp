//
//  motionProfiler.cpp
//  
//
//  Created by Ian Rankin on 1/14/16.
//
//

#include "motionProfiler.h"
#include <cmath>

motionProfiler::motionProfiler(double AMax, double VMax) {
    aMax = AMax;
    vMax = VMax;
    
    t1 = 0;
    t2 = 0;
    t3 = 0;
    vInital = 0;
    
    distance = 0;
    negate = false;
}


void motionProfiler::setDistance(double Distance, double VInital) {
    if (Distance >= 0) {
        vInital = VInital;
        distance = Distance;
        negate = false;
    } else {
        vInital = -VInital;
        distance = -Distance;
        negate = true;
    }
    
    t2 = 0;
    
    double right = sqrt((vInital + (2 * distance)) / 2);
    double t1P = (-(vInital / aMax)) + right;
    double t1N = (-(vInital / aMax)) - right;
    
    if (t1P > 0 || t1N > 0) {
        if (t1P > 0) {
            if (t1N > 0) {
                cout << "Both are positive don't know what to choose" << endl;
                return;
            } // end if for both
            t1 = t1P;
        } else {
            t1 = t1N;
        } // end if else for if t1P is positive.
    } else {
        cout << "No positive solution for time" << endl;
        return;
    }
    
    t3 = t1 + (vInital / aMax);
    v2 = (aMax * t1) + vInital;
    
    // check if the fastest speed is quicker then vMax
    if (v2 > vMax) {
        // 3 segments with middle at vMax
        t1 = (vMax - vInital) / aMax;
        t3 = vMax / aMax;
        
        t2 = (distance - (0.5 * aMax * t1 * t1) - (vInital * t1) -
              (vMax * t3) + (0.5 * aMax * t3 * t3)) / vMax;
        v2 = vMax;
    }
}


double motionProfiler::getPosition(double time) {
    if (negate) {
        return -getPositionP(time);
    }
    
    return getPositionP(time);
}

double motionProfiler::getPositionP(double time) {
    double position = 0;
    if (time > (t1 + t2 + t3))
        return distance;
    
    if (time <= t1) {
        return (0.5 * aMax * time * time) + (vInital * time);
    }
    position = (0.5 * aMax * t1 * t1) + (vInital * t1);
    
    if (time <= (t1 + t2)) {
        return (vMax * (time - t1)) + position;
    }
    
    position += (vMax * (t2));
    time = time - (t1 + t2);
    return position - (0.5 * aMax * time * time) + (v2 * time);
}

double motionProfiler::totalTime() { return t1 + t2 + t3; }







