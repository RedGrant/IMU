//libraries calling

#include "libraries.h"

//imu buffer resulting of the STIM300 default mode
int imu_buffer[38] = { 31,-61,-19,-103,-8,-92,104,55,-22,-10,0,-91,116,-79,78, 121, 43,-32,30,-109,0,115,-92,-83,57,-20,-119,-65,34,23,0,-43,101,38,28,-84,11,112};

//function prototypes
long gyroValue(int i);
long accValue(int i, int j);
long incValue(int i);

int main(void)
{
	//variables declaration
	long gyro_ang_x = 0, gyro_ang_y = 0, gyro_ang_z = 0 ;
	long acc_ang_x = 0, acc_ang_y = 0, acc_ang_z = 0;
	long inc_ang_x = 0, inc_ang_y = 0, inc_ang_z = 0;

	//gyro output computation
	gyro_ang_x = gyroValue(1);
	gyro_ang_y = gyroValue(4);
	gyro_ang_z = gyroValue(7);
	
	//by default  the acceleration results come in 2g
	acc_ang_x = accValue(11, 2);
	acc_ang_y = accValue(14, 2);
	acc_ang_z = accValue(17, 2);

	//accelometer computation
	acc_ang_x = incValue(21);
	acc_ang_y = incValue(24);
	acc_ang_z = incValue(27);

	getchar();
	return (0);
}

//computes the gyro output of the correspondent axis (given by i)
long gyroValue(int i)
{
	int output = 0;
	long num = 0, den = 0;
	num = imu_buffer[i] * pow(2, 16) + imu_buffer[i + 1] * pow(2, 8) + imu_buffer[i + 2];
	den = pow(2, 14);
	
	if (den != 0)
	{
		output = num / den;
	}
	
	return (output);
}

//computes the acceleration angle of each coordinate (given by i) and how much range it has (j)
long accValue(int i, int j)
{
	int output = 0;
	long num = 0, den = 0;
	
	num = imu_buffer[i] * pow(2, 16) + imu_buffer[i + 1] * pow(2, 8) + imu_buffer[i + 2];
	
	if (j == 2)
	{
		den = pow(2, 21);
		output = num / den;
	}

	if (j == 5)
	{
		den = pow(2, 20);
		output = num / den;
	}

	if (j == 10)
	{
		den = pow(2, 19);
		output = num / den;
	}

	if (j == 30)
	{
		den = pow(2, 18);
		output = num / den;
	}

	if (j == 100)
	{
		den = pow(2, 16);
		output = num / den;
	}

	return (output);

}

//computes the inclonometer acceleration output of the correspondent axis (given by i)
long incValue(int i)
{
	int output = 0;
	long num = 0, den = 0;
	num = imu_buffer[i] * pow(2, 16) + imu_buffer[i + 1] * pow(2, 8) + imu_buffer[i + 2];
	den = pow(2, 22);

	if (den != 0)
	{
		output = num / den;
	}

	return (output);
}