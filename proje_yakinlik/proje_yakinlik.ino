const int trigPin = 5, echoPin = 6;
long uzaklik;
long sure;
const int ledPin = 10;

int maximumRange = 50;
int minimumRange = 0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int olcum = mesafe(maximumRange, minimumRange);
  Serial.println(olcum);
}

  int mesafe(int maxrange, int minrange)
{
  long sure, mesafe;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH); //pulsın fonksiyonu ile pinin ne kadar süre ile high kaldığını ölçüyoruz.
  mesafe = sure / 2 / 29.1;
  if(mesafe <=7 && mesafe >= 1){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  delay(50);

  if (mesafe >= maxrange || mesafe <= minrange)
    return 0;
  return mesafe;
}
