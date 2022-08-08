#include <Arduino.h>
#include <SoftwareSerial.h>


//define all the pins 
#define enr 9    //ena
#define enl 10  //enb
#define in1 3  
#define in2 4 
#define in3 5 
#define in4 6 

//define bluetooth pins SoftwareSerial
const byte rxPin = 0; //0
const byte txPin = 1; //1

SoftwareSerial mySerial (rxPin, txPin);

//speed
int speed = 250 ; 

void setup() {

  //pinmode for l298 motor driver

   pinMode(enr , OUTPUT); 
   pinMode(enl , OUTPUT);
   pinMode(in1 , OUTPUT);
   pinMode(in2 , OUTPUT);
   pinMode(in3 , OUTPUT);
   pinMode(in4 , OUTPUT);
   mySerial.begin(9600);
   

   //
}

// declare function 
void forward() ;
void backward() ;
void right ();
void left (); 
void stand ();


void loop() {
  char c = mySerial.read();
  if (c== 'F')
  {
    forward() ; /* code */
  }
  else if (c== 'B')
  {
    backward() ; 
  }
  else if (c== 'R')
  {
    right ();/* code */
  }
  else if ( c== 'L')
  {
    left ();/* code */
  }
  else {
    stand ();
  }
    
  
  
}

void forward(){
  analogWrite (enr , speed) ; 
  analogWrite(enl , speed) ;
  // for MotorR
  digitalWrite (in1 , HIGH) ; 
  digitalWrite (in2 , LOW) ;

  // for MotorL
  digitalWrite (in3 , HIGH) ; 
  digitalWrite (in4 , LOW) ;

}

void backward() {
  analogWrite (enr , speed) ; 
  analogWrite(enl , speed) ;
  // for MotorR
  digitalWrite (in1 , LOW) ; 
  digitalWrite (in2 , HIGH) ;

  // for MotorL
  digitalWrite (in3 , LOW) ; 
  digitalWrite (in4 , HIGH) ;
}

void right () {
  analogWrite (enr , speed) ; 
  analogWrite(enl , speed) ;
  // for MotorR
  digitalWrite (in1 , LOW) ; 
  digitalWrite (in2 , HIGH) ;

  // for MotorL
  digitalWrite (in3 , HIGH) ; 
  digitalWrite (in4 , LOW) ;
}

void left (){
  analogWrite (enr , speed) ; 
  analogWrite(enl , speed) ;
  // for MotorL
  digitalWrite (in3 , LOW) ; 
  digitalWrite (in4 , HIGH) ;

  // for MotorR
  digitalWrite (in1 , HIGH) ; 
  digitalWrite (in2 , LOW) ;

}

void stand () {
  analogWrite (enr , 0) ; 
  analogWrite(enl ,  0) ;
}