#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    rightFollower,  sensorLineFollower)
#pragma config(Sensor, dgtl1,  leftBumper,     sensorTouch)
#pragma config(Sensor, dgtl2,  rightBumper,    sensorTouch)
#pragma config(Sensor, dgtl3,  armBaseEncoder1, sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269_HBridge, openLoop, reversed, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port2,           armBaseLeft,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           armBaseRight,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           armElbow,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           armWrist,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           armRiser,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269_HBridge, openLoop, reversed, driveRight, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define abs(X) ((X < 0) ? -1 * X : X)

#define MAX_SPEED 127
#define MID_SPEED 63
#define ZERO_SPEED 0

/**
* driveStraight(int, int) should be preferred to moving individual motors.
* Note: distance is in tenths of an inch.
*/
void driveMotor(int distance, int speed, short motorName, short encoderName)
{
	SensorValue[encoderName] = 0;

	int tickGoal = 29 * distance / 10;

	int totalTicks = 0;

	while (abs(totalTicks) < tickGoal)
	{
		totalTicks += SensorValue(encoderName);
		motor[motorName] = speed;
		wait1Msec(100);
	}
	motor[motorName] = 0;
}

void driveStraight(int distance, int speed)
{
	int masterPower = speed;
	int slavePower = masterPower - 5;

	int tickGoal = 29 * distance;

	int totalTicks = 0;

	// The difference in speed between the master and slave encoders.
	int error = 0;

	//'Constant of proportionality' which the error is divided by. Usually this is a number between 1 and 0 the
	//error is multiplied by, but we cannot use floating point numbers. Basically, it lets us choose how much
	//the difference in encoder values effects the final power change to the motor.
	int kp = 5;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	while (abs(totalTicks) < tickGoal) {
		motor[leftMotor] = masterPower;
		motor[rightMotor] = slavePower;

		error = SensorValue[I2C_1] - SensorValue[I2C_2];

		slavePower += error / kp;

		SensorValue[I2C_1] = 0;
		SensorValue[I2C_2] = 0;

		wait1Msec(100);

		totalTicks += SensorValue[I2C_1];
	}
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void driveStraight(int distance)
{
	driveStraight(distance, MAX_SPEED);
}

void turnLeft(int distance, int speed)
{
	driveMotor(distance, speed, rightMotor, I2C_2);
}

void turnLeft(int distance)
{
	turnLeft(distance, MID_SPEED);
}

void turnRight(int distance, int speed)
{
	driveMotor(distance, speed, leftMotor, I2C_1);
}

void turnRight(int distance)
{
	turnRight(distance, MID_SPEED);
}

void reset()
{

}

void expandArm()
{

}

void moveArmBase(int distance)
{

}

void moveElbow(int distance)
{

}

task main()
{
	wait1Msec(2000);
	driveStraight(60);
	turnRight(2);
	driveStraight(150);
	turnRight(2);
	driveStraight(150);
	turnRight(2);
	driveStraight(25);
	turnRight(2);
	driveStraight(25);
	turnLeft(2);
	driveStraight(25);
	turnLeft(2);
	driveStraight(10);

	// motor[armBaseLeft] = -127;
	// motor[armBaseRight] = -127;
	// wait1Msec(10000);
}
