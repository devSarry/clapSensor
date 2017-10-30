

int Green_Led = 10;

int Mic_Pin = 12;

int micVal = HIGH;
int clapCounter = 0;



void setup() {
  Serial.begin(9600);
  pinMode(Green_Led, OUTPUT);

  pinMode(Mic_Pin, INPUT);

  digitalWrite(Green_Led, HIGH);

  delay(1000);

  digitalWrite(Green_Led, LOW);

  
}

void loop() {

  micVal = digitalRead(Mic_Pin);
  
  if (micVal == HIGH) {

    double startTime = millis();

    while( millis() - startTime <= 3000) {
        micVal = digitalRead(Mic_Pin);
        digitalWrite(Green_Led, HIGH);

        if (micVal == HIGH) {
          clapCounter++;
          delay(100);
        }

        
    }
    digitalWrite(Green_Led, LOW);

    int clapSQR = clapCounter * clapCounter;

    Serial.print("The number of claps^2: ");
    Serial.println(clapSQR );
    Serial.print("In Binary: ");
    Serial.println(clapSQR, BIN);
    Serial.print("In HEX: ");
    Serial.println(clapSQR, HEX);
    Serial.print("In OCT: ");
    Serial.println(clapSQR, OCT);
    

    for ( int init = 0; init <= clapSQR; init++) {
      digitalWrite(Green_Led, HIGH);
      delay(100);
      digitalWrite(Green_Led, LOW);
      delay(100); 
      
    }

    

  }

}
