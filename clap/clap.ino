int Green_Led = 10;
int Red_Led = 11;
int Mic_Pin = 12;

int micVal = HIGH;



void setup() {
  Serial.begin(9600);
  pinMode(Green_Led, OUTPUT);
  pinMode(Red_Led, OUTPUT);

  pinMode(Mic_Pin, INPUT);

  digitalWrite(Green_Led, HIGH);

  delay(1000);

  digitalWrite(Green_Led, LOW);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  micVal = digitalRead(Mic_Pin);
  

  if (micVal == HIGH) {
    Serial.println("Heard Something!!!");
    digitalWrite(Green_Led, HIGH);
    delay(500);
    digitalWrite(Green_Led, LOW);

  }

}
