int t = 9;   
int w = 11;   
int d = 12;   
int a = 8;   
   
void setup() {   
   
  Serial.begin(9600);   
  pinMode(12, OUTPUT); //вперед ПРАВЫЙ   
  pinMode(11, OUTPUT); //вперед ПРАВЫЙ   
  pinMode(8, OUTPUT); //правый повернуть   
  pinMode(9, OUTPUT); //левый повернуть   
   
}   
   
   
   
   
void loop() {   
  // int inRead = Serial.read() - '0';   
  int inRead = Serial.parseInt();   
   
  if (inRead == 8) {   
    digitalWrite(w, HIGH);   
    digitalWrite(t, HIGH);   
    delay(100);   
    digitalWrite(w, LOW);   
    digitalWrite(t, LOW);   
    delay(1000);   
  }   
  if (inRead == 5) {   
    digitalWrite(w, HIGH);   
    delay(100);   
    digitalWrite(w, LOW);   
    delay(1000);   
  }   
  if (inRead == 2) {   
    digitalWrite(d, HIGH);   
    digitalWrite(a, HIGH);   
    delay(100);   
    digitalWrite(d, LOW);   
    digitalWrite(a, LOW);   
    delay(1000);   
  }   
  if (inRead == 6) {   
    digitalWrite(d, HIGH);   
    delay(100);   
    digitalWrite(d, LOW);   
    delay(100);   
   
  }   
  if (inRead == 4) {   
    digitalWrite(a, HIGH);   
    delay(100);   
    digitalWrite(a, LOW);   
    delay(100);   
   
  }   
  if (inRead == 102) {   
    digitalWrite(w, HIGH); //8   
    digitalWrite(t, HIGH);   
    delay(100);   
    digitalWrite(w, LOW);   
    digitalWrite(t, LOW);   
    delay(16000);   
    digitalWrite(d, HIGH);//6   
    delay(100);   
    digitalWrite(d, LOW);   
    delay(6800);   
    digitalWrite(d, HIGH);//6   
    delay(100);   
    digitalWrite(d, LOW);   
    delay(30000);  
    digitalWrite(d, HIGH);//6   
    delay(100);   
    digitalWrite(d, LOW);  
    delay(6800);   
    digitalWrite(d, HIGH);//6   
    delay(100);   
    digitalWrite(d, LOW);   
    delay(20000);  
    digitalWrite(d, HIGH);//6   
    delay(100);   
    digitalWrite(d, LOW);  
    delay(6800);  
    digitalWrite(w, HIGH); //8   
    digitalWrite(t, HIGH);   
    delay(100);   
    digitalWrite(w, LOW);   
    digitalWrite(t, LOW);   
      
    /*digitalWrite(w, HIGH); //8   
    digitalWrite(t, HIGH);   
    delay(100);   
    digitalWrite(w, LOW);   
    digitalWrite(t, LOW);   
    delay(3000); */ 
    }}
