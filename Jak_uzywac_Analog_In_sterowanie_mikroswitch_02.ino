
int wynik;          // zmienna na odczyt z ADC
float napiecie;     // zmienna na przeliczone napięcie w voltach
float prog = 3.3;   // próg napięcia, który chcemy wykryć (3.3 V)

void setup() {
  pinMode(6, OUTPUT);   // pin 6 jako wyjście (dioda LED)
  Serial.begin(9600);   // komunikacja z komputerem
}

void loop() {

  wynik = analogRead(A3);  // odczyt z wejścia A3 (0–1023)

  // przeliczenie wartości ADC na napięcie:
  // napięcie = (wynik / 1023.0) * 5.0
  napiecie = (wynik / 1023.0) * 5.0;

  Serial.println(napiecie);  // podgląd napięcia w voltach

  // jeśli zmierzone napięcie jest równe lub wyższe niż 3.3 V → włącz LED
  if (napiecie >= prog) {
    digitalWrite(6, HIGH);   // włącz diodę LED
  } else {
    digitalWrite(6, LOW);    // wyłącz diodę LED
  }

  delay(10);  // krótka pauza
}

