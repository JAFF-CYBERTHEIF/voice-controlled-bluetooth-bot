//Date: 11/06/22
//Voice controlled Bluetooth car
//Author: Jawahar B
#include <SoftwareSerial.h>
String t;

#define buzzer 6
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

//RX 0
// TX 1
void setup() {
pinMode(2,OUTPUT);   //left motors forward
pinMode(3,OUTPUT);   //left motors reverse
pinMode(4,OUTPUT);   //right motors forward
pinMode(5,OUTPUT);   //right motors reverse
pinMode(6,OUTPUT);
SoftwareSerial mySerial(0, 1); // RX TX
Serial.begin(9600);
 
}
 
void loop() {

  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    t += c; //Shorthand for voice = voice + c
  }
  if (t.length() > 0){
Serial.println(t);

if(t =="forward"){            //move forward(all motors rotate in forward direction)

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
 
else if(t == "backward"){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
}
 
else if(t == "left"){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
 
else if(t == "right"){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
 
else if(t == "stop"){      //STOP (all motors stop)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 digitalWrite(buzzer, HIGH);
  delay(1000);
 digitalWrite(buzzer,LOW);
}
delay(1);
t="";
}
}
