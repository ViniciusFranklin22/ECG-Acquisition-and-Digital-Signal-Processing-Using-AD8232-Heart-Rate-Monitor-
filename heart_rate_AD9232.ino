/******************************************************************************
ECG Display with AD8232 (usando millis e lastSample)
Envia: tempo_em_ms, valor_ADC
Se houver problema, repete a última leitura válida.
******************************************************************************/

int lastValue = 0;               // última leitura válida
unsigned long lastSample = 0;    // tempo da última amostra
const unsigned int sampleInterval = 2; // ms → 500 Hz

void setup() {
  Serial.begin(115200);
  /*pinMode(10, INPUT); // LO+
  pinMode(11, INPUT); // LO-*/
}

void loop() {
  unsigned long now = millis();

  if (now - lastSample >= sampleInterval) {
    lastSample = now;
    int read;

    // Se algum eletrodo solto, repete a última leitura válida
    /*if ((digitalRead(10) == 1) || (digitalRead(11) == 1)) {
      read = lastValue;
    } else {*/
    read = analogRead(A0);
    //lastValue = read; // atualiza última leitura válida
    

    // envia CSV: tempo_ms, valor_ADC
    Serial.print(now);
    Serial.print(",");
    Serial.println(read);
  }
}
