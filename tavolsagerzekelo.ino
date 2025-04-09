// Pin deklarálása
const int trigPin = 9;  // Trig pin (kimenet)
const int echoPin = 10; // Echo pin (bemenet)
long duration;
int distance;

void setup() {
  // Inicializáljuk a soros kommunikációt
  Serial.begin(9600);
  
  // Beállítjuk a trig pin-t kimenetként, az echo pin-t bemenetként
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Először kikapcsoljuk a trig pin-t
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  
  // Indítjuk a pulzust (10 mikrosec)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Megmérjük az echo pin-en visszaverődött jelet
  duration = pulseIn(echoPin, HIGH);
  
  // Kiszámítjuk a távolságot centiméterben
  distance = duration * 0.0344 / 2; // Az ultrahang sebessége 343 m/s, de cm-ben számolunk
  
  // Kiírjuk a távolságot a soros monitorra
  Serial.print("Távolság: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Kis késleltetés a következő mérés előtt
  delay(500);
}
