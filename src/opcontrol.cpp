#include "main.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor driveLeftBack(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftFront(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(19, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Tray(8, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor arm(9, pros::E_MOTOR_GEARSET_36,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Lintake(1,pros::E_MOTOR_GEARSET_36,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Rintake(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
 int constant=1;
	void opcontrol()
	{
	  while (true)
	    { //ARCADE DRIVE
	           int power = master.get_analog(ANALOG_RIGHT_Y);
	           int turn = master.get_analog(ANALOG_RIGHT_X);

	           int left = power + turn;
	           int right = power - turn;
	           int left1 = power +turn;
	           int right1 = power -turn;
	           driveLeftFront  = left;
	           driveLeftBack  = left1;
	           driveRightFront  = right;
	           driveRightBack  = right1;

		if (master.get_digital(DIGITAL_UP)) {
		 Tray.move_velocity(50); // This is 100 because it's a 100rpm motor
	 }
	 else if (master.get_digital(DIGITAL_DOWN)) {
		 Tray.move_velocity(-50);
	 }
	 else {
		 Tray.move_velocity(0);
	 }
	 //arm///////////////////////////////////////////////////////////////////////
				if (master.get_digital(DIGITAL_R1)){
				 arm.move_velocity(50); // This is 100 because it's a 100rpm motor
				}
				else if (master.get_digital(DIGITAL_R2)){
				 arm.move_velocity(-50);
				}
				else{
				 arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
				 arm.move_velocity(0);//bug: motor is too powerful
			 }

			 //intake//////////////////////////////////////////////////////////////////////
			 	if (master.get_digital(DIGITAL_L1)){
				Lintake.move_velocity(100); // This is 100 because it's a 100rpm motor
				Rintake.move_velocity(100);
			 	}
			 else if (master.get_digital(DIGITAL_L2)){
				Rintake.move_velocity(-100);
				Lintake.move_velocity(-100);
			 }
			 else{
				Rintake.move_velocity(0);
				Lintake.move_velocity(0);//bug: motor is too powerful
			}

			 pros::delay(20);
		}//while
			return;
}//void

/*
	void traycontrol()
	{
		while(true)
		{
		}
	}
	void armcontrol()
	{



	}
	*/
