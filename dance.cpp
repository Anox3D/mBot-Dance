#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);		

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
				
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;



void setup(){
  // Little dance
    move(1,255);
    _delay(1);
    move(2, 255);
    _delay(1);
    move(4,100);
    _delay(2);
    move(3,100);
    _delay(4);
    move(4, 100);
    _delay(2);
  // Little music
    for(int __i__=0;__i__<2;++__i__)
    {
      buzzer.tone(247,125);  // B3
      delay(20);
      _delay(0.3);
      buzzer.tone(193,125);  // G3
      delay(20);
      _delay(0.3);
      buzzer.tone(175,125);  // F3
      delay(20);
      _delay(0.3);
      buzzer.tone(175,125);  // F3
      delay(20);
      _delay(0.3);
      buzzer.tone(193,125);  // G3
      delay(20);
      _delay(0.2);
      buzzer.tone(193,125);  // G3
      delay(20);
      buzzer.tone(220,125);  // A3
      delay(20);
      _delay(0.2);
      buzzer.tone(220,125);  // A3
      delay(20);
    }
  // 360 (or not I don't know, I'll see)
    move(4,255);
    _delay(12);
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

