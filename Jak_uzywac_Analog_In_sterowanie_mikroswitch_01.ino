
int wynik;  // zmienna do przechowywania odczytu z wejścia analogowego A3

void setup() {
  pinMode(6, OUTPUT);  // ustawiamy pin 6 jako wyjście (będzie sterował diodą LED)
  Serial.begin(9600);  // włączamy komunikację z komputerem, aby podglądać wartości
}

void loop() {

  wynik = analogRead(A3);  // odczyt napięcia z pinu A3 (0–1023)
  Serial.println(wynik);   // wyświetlenie odczytanej wartości w monitorze portu

  // 3.3 V odpowiada mniej więcej wartości 675 w skali ADC (3.3/5.0 * 1023 ≈ 675)
  // jeśli wynik jest równy lub większy, to znaczy, że na A3 jest około 3.3 V
  if (wynik >= 675) {
    digitalWrite(6, HIGH);  // włącz diodę LED na pinie 6
  } else {
    digitalWrite(6, LOW);   // wyłącz diodę LED, jeśli napięcie jest niższe
  }

  delay(500);  // krótka pauza, aby odczyty nie były wykonywane zbyt szybko
}  
