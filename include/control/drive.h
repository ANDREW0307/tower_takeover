#pragma once

/*--------------------------------
    DRIVE FUNCTIONS
--------------------------------*/

/* This section is only for driving functions. Movement functions such as operating the lift should not exist here. */
//calibraes the gyro for precise turns
void calibrategyro();
// drives using gyro slop
void drivegyro(double target, int speed, double rate, double angle, double gyroamp, double tol);
// drives using gyro slop and has two points
void drivegyro(double target, int speed, double rate, double angle, double gyroamp,double target2, int speed2, double rate2, double angle2, double gyroamp2, double tolerance);
// Drives the robot in a straight line to the target in rotations, in a given speed(rpm). Uses PD loop. Rate controls the slew constant.
void drive(double target, int speed, double rate);

// Drives the robot in a straight line to the target in rotations, in a given speed(rpm). Offset controls slop. Uses PD loop. Rate controls the slew constant.
void drive(double target, int speed, double rate, double amp, double offset);

// Turns the robot to the target in rotations, in a given speed(rpm). Uses PD looop. Rate controls the slew constant.
void turn(double target, int speed, double rate);

// Turns the robot to the target in rotations, in a given speed(rpm). Uses PD looop. Rate controls the slew constant. Uses Gyro.
void turnG(double target, int speed, double rate);

// Strafes the robot to the target in ticks, in a given speed(rpm).
void strafe(double target, int speed, double rate);

// Strafes the robot to the target in ticks, in a given speed(rpm). Sturn yeet
void strafe(double target, int speed, double rate, double sturn);

// Lines upto the wall using the two ultrasonic sensors, to a given distance(cm).
void align(double target, double tolerance);

// Sets braketype to hold on all motors.
void lockChassis();

// Sets braketype to coast on all motors.
void unlockChassis();

// Ignore the below functions. They accomodate the functions above.

void left(int speed);
void right(int speed);