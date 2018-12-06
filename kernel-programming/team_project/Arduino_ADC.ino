//auther: guithin(Jinwon Jung)
//rasoberry pi project code for ADC
//raspberry pi does not have ADC
//use arduino's ADC and send ADC value as Serial(UART)

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() && Serial.read() == 'R'){
    Serial.print(analogRead(A0));
  }
}
