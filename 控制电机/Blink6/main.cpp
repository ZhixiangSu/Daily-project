/* motor_speed_up.c
* A program to control a stepper motor(speed up) through the GPIO on Raspberry Pi.
*
* Author: Darran Zhang (http://www.codelast.com)
*/
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 2
void delayMS(int x);
void rotate(int* pins, int direction, int delay);
void stop(int* pins);
int main() {
	
	/* number of the pins which connected to the stepper motor driver board */
	int pinA = atoi("1");
	int pinB = atoi("2");
	int pinC = atoi("3");
	int pinD = atoi("4");
	int pins[4] = { pinA, pinB, pinC, pinD };
	if (-1 == wiringPiSetup()) {
		printf("Setup wiringPi failed!");
		return 1;
	}
	/* set mode to output */
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);
	delayMS(50);    // wait for a stable status 
	int delay = 3;
	while (true) {
		for (int i = 0; i < 10; i++) {
			rotate(pins, CLOCKWISE, delay);
		}
		//delay--;
	}
	return 0;
}
/* Suspend execution for x milliseconds intervals.
* @param ms Milliseconds to sleep.
*/
void delayMS(int x) {
	usleep(x * 1000);
}
/* Rotate the motor.
* @param pins     A pointer which points to the pins number array.
*  @param direction CLOCKWISE for clockwise rotation, COUNTER_CLOCKWISE for counter clockwise rotation.
* @param delay    The time intervals(in ms) to delay, and if the value is smaller, the motor rotates faster.
*/
void rotate(int* pins, int direction, int delay) {
	for (int i = 0; i < 4; i++) {
		if (CLOCKWISE == direction) {
			for (int j = 0; j < 4; j++) {
				if (j == i) {
					digitalWrite(pins[3 - j], 1); // output a high level 
				}
				else {
					digitalWrite(pins[3 - j], 0); // output a low level 
				}
			}
		}
		else if (COUNTER_CLOCKWISE == direction) {
			for (int j = 0; j < 4; j++) {
				if (j == i) {
					digitalWrite(pins[j], 1); // output a high level 
				}
				else {
					digitalWrite(pins[j], 0); // output a low level 
				}
			}
		}
		delayMS(delay);
	}
}
/* Stop the motor.
* @param pins     A pointer which points to the pins number array.
*/
void stop(int* pins) {
	for (int i = 0; i < 4; i++) {
		digitalWrite(pins[i], 0); // output a low level 
	}
}