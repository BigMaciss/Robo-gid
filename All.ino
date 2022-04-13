int u=7; 
#define PIN_TRIG1 12 
#define PIN_ECHO1 11 
#define PIN_TRIG2 10 
#define PIN_ECHO2 9 
#define PIN_TRIG3 13 
#define PIN_ECHO3 14 
long duration, cm, cm1, cm2,cm3; 
int command;  
  
int a = 10;    //  развернуть левый  
int d = 13;    //  развернуть правый  
  
int w = 11; //  (не)ехать  
int t = 12;  
  
bool go = 0;     //      едем ли (+ поправки)?  
int q = 1;      //      направление левого  
int e = 1;     //      направление правого  
  
int t_i_m_e = 0;  
  
void Timer(int t) { //      типа delay(), только не  
  int timer = millis();  
  while (millis() - timer < t)  
    ;  
}  
  
void signal(int x) {  //  сигнал на драйвера  
  digitalWrite(x, HIGH);  
  Timer(10);  
  digitalWrite(x, LOW);  
  Timer(10);  
}  
void setup() { 
 
  // Инициализируем взаимодействие по последовательному порту 
 
  Serial.begin (9600); 
  //Определяем вводы и выводы 
  pinMode(PIN_TRIG1, OUTPUT); 
  pinMode(PIN_ECHO1, INPUT); 
  pinMode(PIN_TRIG2, OUTPUT); 
  pinMode(PIN_ECHO2, INPUT); 
  pinMode(PIN_TRIG3, OUTPUT); 
  pinMode(PIN_ECHO3, INPUT); 
  pinMode(u, OUTPUT); 
  pinMode(a, OUTPUT);  //       повернуть левый  
  pinMode(d, OUTPUT);  //       повернуть правый  
  
  pinMode(w, OUTPUT); //      ехать  
  pinMode(t, OUTPUT);  
} 
 
void loop() { 
 if (Serial.available()) {  
    command = Serial.parseInt();  
  }  
  /*int comand[] = {8, 5, 4, 5, 6, 5, 2, 5};  
    command = comand[t_i_m_e % 8];*/  
  if (command != 0) {  
    Serial.print("C");  
    Serial.println(command);  
  }  
  
  switch (command) {  
    case 8:            // команда 8 - вперёд  
        if (go == 0) {  
          signal(w);  
          signal(t);  
          go = 1 ; 
        }  
         
        if (q == -1) {  
          signal(a);  
          q = 1;  
        }  
        if (e == -1) {  
          signal(d);  
          e = 1;  
        }  
      break;  
    case 2:              // команда 2 - назад  
        if (go == 0) {  
          signal(w);  
          signal(t);  
          go = 1;  
        }  
        if (q == 1) {  
          signal(a);  
          q = -1;  
        }  
        if (e == 1) {  
          signal(d);  
          e = -1;  
        }  
      break;  
    case 6:              // команда 6 - поворачивать вправо  
        if (go == 0) {  
          signal(w);  
          signal(t);  
          go = 1;  
        }  
        if (q == -1) {  
          signal(a);  
          q = 1;  
        }  
        if (e == 1) {  
          signal(d);  
          e = -1;  
        }  
      break;  
    case 4:              // команда 4 - поворачивать влево  
        if (go == 0) {  
          signal(w);  
          signal(t);  
          go = 1;  
        }  
        if (q == 1) {  
          signal(a);  
          q = -1;  
        }  
        if (e == -1) {  
          signal(d);  
          e = 1;  
        }  
      break;  
    case 5: {             // команда 5 - ехать или остановиться  
        signal(w);  
        signal(t);  
        go = 1 - go;      // статус ()  
      }  
  }  
  command = 0;  
  
  t_i_m_e++;  
 
  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд. 
 
  digitalWrite(PIN_TRIG1, LOW); 
  delayMicroseconds(5); 
  digitalWrite(PIN_TRIG1, HIGH); 
 
  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц. 
  delayMicroseconds(10); 
  digitalWrite(PIN_TRIG1, LOW); 
 
  //  Время задержки акустического сигнала на эхолокаторе. 
  duration = pulseIn(PIN_ECHO1, HIGH); 
 
  // Теперь осталось преобразовать время в расстояние 
  cm1 = (duration / 2) / 29.1; 
 
  Serial.print("Ram1: "); 
  Serial.print(cm1); 
  Serial.println(" см."); 
 
  // Задержка между измерениями для корректной работы скеча 
  delay(250); 
// 
  digitalWrite(PIN_TRIG2, LOW); 
  delayMicroseconds(5); 
  digitalWrite(PIN_TRIG2, HIGH); 
 
  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц. 
  delayMicroseconds(10); 
  digitalWrite(PIN_TRIG2, LOW); 
 
  //  Время задержки
акустического сигнала на эхолокаторе. 
  duration = pulseIn(PIN_ECHO2, HIGH); 
 
  // Теперь осталось преобразовать время в расстояние 
  cm2 = (duration / 2) / 29.1; 
 
  Serial.print("Ram2: "); 
  Serial.print(cm2); 
  Serial.println(" см."); 
 
  // Задержка между измерениями для корректной работы скеча 
  delay(250); 
// 
 
  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд. 
 
  digitalWrite(PIN_TRIG3, LOW); 
  delayMicroseconds(5); 
  digitalWrite(PIN_TRIG3, HIGH); 
 
  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц. 
  delayMicroseconds(10); 
  digitalWrite(PIN_TRIG3, LOW); 
 
  //  Время задержки акустического сигнала на эхолокаторе. 
  duration = pulseIn(PIN_ECHO3, HIGH); 
 
  // Теперь осталось преобразовать время в расстояние 
  cm = (duration / 2) / 29.1; 
 
  Serial.print("Ram3: "); 
  Serial.print(cm3); 
  Serial.println(" cm."); 
 
  // Задержка между измерениями для корректной работы скеча 
  delay(250); 
 
 
    if (cm1 ||cm2||cm3<=53){ 
Serial.println("stop"); 
 
        signal(w);  
        signal(t);  
        go = 1 - go;      // статус ()  
    } 
}
