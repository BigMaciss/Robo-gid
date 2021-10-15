#include <Ultrasonic.h>    // подключаем библиотеку Ultrasonic
Ultrasonic ultrasonic(8,9); // назначаем выходы для Trig и Echo 
 int l=5;
 int r=6;
void setup() {
  Serial.begin(9600);        // подключаем монитор порта
  pinMode (11, OUTPUT); // левый вперед
  pinMode (12, OUTPUT); //правый вперед
   pinMode (5, OUTPUT); //левый назад
  pinMode (6, OUTPUT);  //правый назад
}

void loop () {
  int dist = ultrasonic.Ranging(CM);
  Serial.print(dist);     // выводим расстояние в сантиметрах
  Serial.println(" cm");

  // переключаем цвета светодиода
  if (dist > 50) {digitalWrite(12,HIGH); digitalWrite(11,HIGH);}
  if (dist < 50) {
    digitalWrite(12,LOW); digitalWrite(11,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(2000); // смотря сколько времени нужно, чтобы он развернулся на 90 градусов
    digitalWrite(12,HIGH);
    digitalWrite(5,LOW);
    delay(4000);
    }
    
  

  delay(100);
}
