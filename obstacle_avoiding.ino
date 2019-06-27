
        //Servo motor library. This is standard library
      //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

//sensor pins
#define trig 13 //analog input 1
#define echo 12 //analog input 2

#define maximum_distance 200
//boolean goesForward = true;
int distance = 100;



void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
Serial.begin(9600);
pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
  
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
}

void loop(){

  distance = readPing();
delay(100);
  if (distance < 25){
    moveStop();
    delay(300);
    turnRight();
      delay(400);
      
    moveBackward();
    delay(400);
   
      
    }
   
   else{
    moveForward();
  
  }
   
}



int readPing(){
  unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
    return distance;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  //if(!goesForward){

  //  goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    //digitalWrite(LeftMotorBackward, LOW);
  //  digitalWrite(RightMotorBackward, LOW); 
 // }
}

void moveBackward(){

 // goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
 // digitalWrite(LeftMotorForward, HIGH);
  //digitalWrite(RightMotorForward, HIGH);
  
 // digitalWrite(LeftMotorBackward, LOW);
 // digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
 // digitalWrite(LeftMotorForward, HIGH);
 // digitalWrite(RightMotorForward, HIGH);
  
 // digitalWrite(LeftMotorBackward, LOW);
//  digitalWrite(RightMotorBackward, LOW);
}

 
