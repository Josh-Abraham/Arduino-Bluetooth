#include <SoftwareSerial.h> // special function in Arduino to connect devices
// Channel A on Motor shield  = Motor A 
// Channel b on Motor Sield = Motor B
// We don't connect the bluetoothe device in the pin 0 and 1 as they also work as TXD (transmitter) and RXD (Receiver) then our bluettoh will not be able to connect to the mobile
int brake_A = 9;  // Brake Pin for Motor A
int brake_B = 8 ; // Beake Pin for Motor B
int direction_A = 12;  // Direction Pin for Motor A
int direction_B = 13;  // Direction Pin for Motor B
int speed_A = 3; // Speed pin for Motor A
int speed_B = 11; // Speed pin for Motor B

SoftwareSerial mySerial(4, 7); // RX, TX  
// Connect HC 01      Arduino Uno
//     Pin 2/RXD          Pin 7 
//     Pin 3/TXD          Pin 8
//     Pin 4/Gnd          Gnd
//     Pin 5/VCC          5V

void setup() {  
  // Setup for Motor A
  pinMode(direction_A, OUTPUT); //Initiates motor pin for Motor A
  pinMode(brake_A, OUTPUT); //Initiates break pin for Motor B

  //Setup for Motor B
  pinMode(direction_B, OUTPUT); //Initiates motor pin for channel B
  pinMode(brake_B, OUTPUT);  //Initiates break pin for channel B

  //Diengages the motors breaks first
  digitalWrite(brake_A, LOW);   //Disengage the Brake for Channel A
  digitalWrite(brake_B, LOW);   //Disengage the Brake for Channel B
  
  
  mySerial.begin(9600); // to start the bluetooth device
}

void loop() {  
  
  String voice; // to get the string input from MIT app inventor saying the desired command
 while (mySerial.available())
  { 
  delay(10); 
  char c = mySerial.read();
  
 
  voice += c; 
  }  
  if (voice.length() > 0)
  {
   
   
    if (voice == "Forward")
    {
      // Non-zero input means "turn on LED".

    
    digitalWrite(direction_A, HIGH); //Establishes direction of Channel A
    analogWrite(speed_A, 100);   //Spins the motor on Channel A at max speed
    digitalWrite(direction_B, HIGH);  //Establishes backward direction of Channel B
    analogWrite(speed_B, 100);    //Spins the motor on Channel B at max speed
   
    }
    else if (voice == "Backward")
    {
      // Input value zero means "turn off LED".
   
    digitalWrite(direction_A, LOW); //Establishes direction of Channel A
    analogWrite(speed_A, 100);   //Spins the motor on Channel A at max speed
    digitalWrite(direction_B, LOW);  //Establishes backward direction of Channel B
    analogWrite(speed_B, 100);    //Spins the motor on Channel B at max speed
   
    }  

     else if (voice == "FR")
    {
      // Input value zero means "turn off LED".
    digitalWrite(direction_A, HIGH); //Establishes direction of Channel A
    analogWrite(speed_A, 120);   //Spins the motor on Channel A at max speed
    digitalWrite(direction_B, HIGH);  //Establishes backward direction of Channel B
    analogWrite(speed_B, 100);    //Spins the motor on Channel B at max speed
   
    }  

     else if (voice == "FL")
    {
      // Input value zero means "turn off LED".
    digitalWrite(direction_A, HIGH); //Establishes direction of Channel A
    analogWrite(speed_A, 100);   //Spins the motor on Channel A at max speed
    digitalWrite(direction_B, HIGH);  //Establishes backward direction of Channel B
    analogWrite(speed_B, 120);    //Spins the motor on Channel B at max speed
   
    }  
    
  }
  
}

