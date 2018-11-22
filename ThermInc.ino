int thermistor1Pin = A4;
int thermistor2Pin = A5;
int temprefPin = A3;

float difference = 0;
float average = 0;
float twenty_thermistorValue = 0;


float thermistor1Value = 0;
float thermistor2Value = 0;    
float temprefValue = 0;    

int alarm_ledPin = 2;
int heater_ledPin = 3;


void setup() {
  pinMode(thermistor1Pin, INPUT);
  pinMode(thermistor2Pin, INPUT);
  pinMode(alarm_ledPin, OUTPUT);
  pinMode(heater_ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  thermistor1Value = analogRead(thermistor1Pin);
  thermistor2Value = analogRead(thermistor2Pin);
  temprefValue = analogRead(temprefPin);


  twenty_thermistorValue = (0.2 * thermistor2Value);

  average = (thermistor1Value + thermistor2Value)/2;

  difference = abs(thermistor1Value - thermistor2Value);


  
  if (difference <= twenty_thermistorValue) {
    if (average < temprefValue) {
      digitalWrite(heater_ledPin, LOW);
      digitalWrite(alarm_ledPin, LOW); }
   
       else { (average >= temprefValue); 
       digitalWrite(heater_ledPin, HIGH);
       digitalWrite(alarm_ledPin, LOW);
    }
  } 

  if((difference > twenty_thermistorValue) && (average > temprefValue) && (average < temprefValue)){
      digitalWrite(heater_ledPin, LOW);
      digitalWrite(alarm_ledPin, HIGH); 
       }

  



}
  
  
