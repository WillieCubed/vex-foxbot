#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in4,    gyro,           sensorGyro)
#pragma config(Sensor, in6,    armPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, I2C_1,  rightIME,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftIME,        sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  armIME,         sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, I2C_2)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void forwards()
{

int normalSpeed;					// Create the Varible Here
	int slowSpeed;
	normalSpeed = 63;					// Initailize te Varible
	slowSpeed = 55;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

while(SensorValue[rightEncoder] )

	if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
	{
		motor[rightMotor] = normalSpeed;
		motor[leftMotor] = slowSpeed;
	}
	if( SensorValue [rightEncoder] > SensorValue[leftEncoder])
	{
		motor[rightMotor] = slowSpeed;
		motor[leftMotor] = normalSpeed;
	}
	if( SensorValue[leftEncoder] == SensorValue[rightEncoder])
	{
		motor [rightMotor] = normalSpeed;
		motor [leftMotor] = normalSpeed;
	}
}


void backwards()
{

int normalSpeed;					// Create the Varible Here
	int slowSpeed;
	normalSpeed = -63;					// Initailize te Varible
	slowSpeed = -55;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

while(SensorValue[rightEncoder] )

	if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
	{
		motor[rightMotor] = normalSpeed;
		motor[leftMotor] = slowSpeed;
	}
	if( SensorValue [rightEncoder] > SensorValue[leftEncoder])
	{
		motor[rightMotor] = slowSpeed;
		motor[leftMotor] = normalSpeed;
	}
	if( SensorValue[leftEncoder] == SensorValue[rightEncoder])
	{
		motor [rightMotor] = normalSpeed;
		motor [leftMotor] = normalSpeed;
	}
}




	void turnpointleft () // Parameters control the Number value or what have you of what you want to run in your robot task main with your fuction
{																				// Fuctions start with void then what ever you want to name it then ()
	int normalSpeed;					// Create the Varible Here   Varibles run within a fuction or task Main that act like a mini fuction
	int slowSpeed;																			// Varibles give a item a value or phase that can be used in programs as a substitue
	normalSpeed = 63;					// Initailize te Varible
	slowSpeed = 55;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder])      // Turn Left jbflot@nrec.ri.cmu.edu
	{
		motor [rightMotor] = 63;
		motor [leftMotor] = -63;}

	if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
	{
		motor[rightMotor] = normalSpeed;
		motor[leftMotor] = slowSpeed;
	}
	if( SensorValue [rightEncoder] > SensorValue[leftEncoder])
	{
		motor[rightMotor] = slowSpeed;
		motor[leftMotor] = normalSpeed;
	}
	if( SensorValue[leftEncoder] == SensorValue[rightEncoder])
	{
		motor [rightMotor] = normalSpeed;
		motor [leftMotor] = normalSpeed;
	}

}



task main()
{

	wait1Msec(2000);

	forwards();


	while(SensorValue[sonarSensor] > 20)

	backwards();
	turnpointleft ();
	}