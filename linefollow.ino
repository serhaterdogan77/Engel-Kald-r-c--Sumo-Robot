#define LeftClrSens A0
#define RightClrSens A1
#define  RSens A2
#define  MSens A3
#define  LSens A4

#define LeftSpeed 3
#define LeftDir 12

#define RightSpeed 11
#define RightDir 13

int left_clr;
int right_clr;

int right_dist;
int left_dist;
int mid_dist;



void setup(){

  pinMode(LeftClrSens, INPUT);
  pinMode(RightClrSens, INPUT);

  pinMode(LeftSpeed, OUTPUT);
  pinMode(LeftDir, OUTPUT);

  pinMode(RightSpeed, OUTPUT);
  pinMode(RightDir, OUTPUT);

  pinMode(RSens,INPUT);
  pinMode(MSens,INPUT);
  pinMode(LSens ,INPUT);

  Serial.begin(9600);
  
  
}

void loop(){

    left_clr = analogRead(LeftClrSens);
    light_clr = analogRead(RightClrSens);

    right_dist = digitalRead(RSens);
    mid_dist = digitalRead(MSens);
    left_dist = digitalRead(LSens );
  
    if(analogRead(left_clr) >= 220  && analogRead(right_clr  )>= 220 ){ 
  
          analogWrite(LeftSpeed, 150);
          digitalWrite(LeftDir, HIGH);
          
          analogWrite(RightSpeed, 150);
          digitalWrite(RightDir, HIGH); 
  
      } // Eğer her iki sensörde beyaz renki zemin okuyorsa ileriye doğru
      
    else if(analogRead(left_clr)<=220  && analogRead(right_clr  )>= 220 ){
  
          analogWrite(LeftSpeed, 100);
          digitalWrite(LeftDir, HIGH);
          
          analogWrite(RightSpeed, 0);
          digitalWrite(RightDir, HIGH); 
      } // Sol sensör Siyah renkli çizgiyi okursa eğer saga döndür
      
    else if(analogRead(left_clr)>= 220&& analogRead(right_clr  )<=220 ){

          analogWrite(LeftSpeed, 0);
          digitalWrite(LeftDir, HIGH);
          
          analogWrite(RightSpeed, 100);
          digitalWrite(RightDir, HIGH);       
      } // Sag sensör Siyah renkli çizgiyi okursa eğer sola döndür
  
    
}
