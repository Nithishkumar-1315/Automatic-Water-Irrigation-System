
const int soilMoisturePin = A0;
const int relayPin = 7;

// Soil moisture threshold
const int moistureThreshold = 600;

// Relay configuration (active LOW)
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(soilMoisturePin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Keep pump OFF initially
  digitalWrite(relayPin, RELAY_OFF);
}

void loop() {

  // Read soil moisture sensor
  int moistureValue = analogRead(soilMoisturePin);

  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  // Check soil moisture condition
  if (moistureValue > moistureThreshold) {

    // Soil is dry
    digitalWrite(relayPin, RELAY_ON);
    Serial.println("Soil is dry - Water Pump ON");

  } else {

    // Soil has sufficient moisture
    digitalWrite(relayPin, RELAY_OFF);
    Serial.println("Soil is wet - Water Pump OFF");

  }

  delay(1000);
}
