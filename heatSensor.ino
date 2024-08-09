const int sensorPin = A0;
const float baselineTemp = 30.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);

  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //converts ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //convert voltage to temp in degrees C. every 10 millivolts of change equals 1 degree C change
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp+2) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp + 2 && temperature < baselineTemp+4){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp + 6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
    
  delay(1);

} //back to beginning of loop
