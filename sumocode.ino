#define LeftLine A0
#define RightLine A1
#define RightSens A2
#define FrontSens A3
#define LeftSens A4


#define Right_motor 11
#define Right_dir 13
#define Left_motor 3
#define Left_dir 12

void setup() {
  pinMode(FrontSens, INPUT);
  pinMode(LeftSens, INPUT);
  pinMode(RightLine, INPUT);
  pinMode(LeftLine, INPUT);

  pinMode(Right_motor, OUTPUT);
  pinMode(Right_dir, OUTPUT);
  pinMode(Left_motor, OUTPUT);
  pinMode(Left_dir, OUTPUT);

}


void loop() {
 

   if(digitalRead(RightLine)==0 && digitalRead(LeftLine)==0) {
  
    if(digitalRead(LeftSens)==1 && digitalRead(FrontSens)==1 && digitalRead(RightSens)==1){
      move();
    }
    
    if(digitalRead(LeftSens)==1 && digitalRead(FrontSens)==0 && digitalRead(RightSens)==1){
      left();
    }
    
    if(digitalRead(LeftSens)==1 && digitalRead(FrontSens)==1 && digitalRead(RightSens)==0){
      move();
    }
    
    if(digitalRead(LeftSens)==1 && digitalRead(FrontSens)==0 && digitalRead(RightSens)==0){
      left();
    }
    
   }
   
}

void move() {

  analogWrite(Right_motor,100);
  digitalWrite(Right_dir,HIGH);
  
  analogWrite(Left_motor,100);
  digitalWrite(Left_dir,HIGH);
}

void right() {
  analogWrite(Right_motor,100);
  digitalWrite(Right_dir,HIGH);
  
  analogWrite(Left_motor,100);
  digitalWrite(Left_dir,LOW);
}
void left() {
  analogWrite(Right_motor,100);
  digitalWrite(Right_dir,LOW);
  
  analogWrite(Left_motor,100);
  digitalWrite(Left_dir,HIGH);
}
