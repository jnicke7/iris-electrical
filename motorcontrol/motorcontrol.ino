
#include <Sabertooth.h>

Sabertooth ST[2] = { Sabertooth(128), Sabertooth(129) }; //128 ->Left and right Drive, 129->Bucket Ladder

#define dir_1 7
#define pwm_1 6
#define dir_2 4
#define pwm_2 3

#define dir_3 117
#define pwm_3 116
#define dir_4 114
#define pwm_4 113




void setup()
{
  SabertoothTXPinSerial.begin(9600);
  Sabertooth::autobaud(SabertoothTXPinSerial);

pinMode(pwm_1,OUTPUT);
pinMode(dir_1,OUTPUT);
pinMode(pwm_2,OUTPUT);
pinMode(dir_2,OUTPUT);

pinMode(pwm_3,OUTPUT);
pinMode(dir_3,OUTPUT);
pinMode(pwm_4,OUTPUT);
pinMode(dir_4,OUTPUT);


}

void loop()
{
   boolean Input[11];




   
  // insert code to put right things into input
  /*
   * Input[0],[1],[2] correspond to motor
  KEY:
  Motor ID: 
0: Left Drive
1: Right Drive
2: Bucket Ladder M
3: dump conveyor LA
4: bucket ladder LA
5: agitator
6: dump conveyor M
  */
  int motorVal = (int)(Input[0])*4+(int)(Input[1])*2+(int)(Input[2]); 
  int power = 0;
  int increment = 1;
  for(int i = 0; i<7; i++){
    power+=increment*Input[10-i];
    increment*=2;
    }
    if(Input[3] == 1 && motorVal<3){
      power*=-1;
      }
  if(motorVal<3){ //call a sabertooth for the action
    ST[Input[1]].motor((byte)(Input[2])+1,power); //THIS FUCKING LINE!!!!
    }
  else{//call a linAC
    linAC(power,motorVal);
    }
 
}

 void linAC(int power, int motor){
    switch(motor) {

   case 3 :
      digitalWrite(dir_1, (int)(Input[3])); //controls the direction the motor;
      analogWrite(pwm_1, power*2); 
      break; 
   case 4 :
      digitalWrite(dir_2, (int)(Input[3])); //controls the direction the motor;
      analogWrite(pwm_2, power*2);
      break; 
  case 5 :
      digitalWrite(dir_3, (int)(Input[3])); //controls the direction the motor;
      analogWrite(pwm_3, power*2);
      break; /
  
   case 6 :
      digitalWrite(dir_4, (int)(Input[3])); //controls the direction the motor;
      analogWrite(pwm_4, power*2);
      break; 
  
  default : 
   return;
}
  
  }
