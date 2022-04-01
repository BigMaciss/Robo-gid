int t=7;
#define PIN_TRIG1 12
#define PIN_ECHO1 11
#define PIN_TRIG2 10
#define PIN_ECHO2 9
#define PIN_TRIG3 12
#define PIN_ECHO3 11
long duration, cm, cm1, cm2,cm3;
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
  pinMode(t, OUTPUT);
}

void loop() {

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

  //  Время задержки акустического сигнала на эхолокаторе.
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


    if (cm1&&cm2&&cm3<=53){
Serial.println("stop");}
}
