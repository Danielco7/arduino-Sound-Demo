int sensor = 2;  // Connected to the digital output of KY-038 sound sensor module
int led = 13;     // Connected to the positive side of the LED
boolean is_on = false;  // To determine/track if the LED is on or off

void setup() {
  pinMode(sensor, INPUT);  // Setting the pin to input for reading data
  pinMode(led, OUTPUT);    // Setting the pin to output for turning the LED on/off
  Serial.begin(9600);      // Start serial communication for printing
}

void loop() {
  int data = digitalRead(sensor);  // Reading data from the sensor and storing it in a variable

  Serial.print("Sensor Value: ");  // Print the sensor's value to the Serial Monitor
  Serial.println(data);            // Print either 1 (sound detected) or 0 (no sound)

  if (data == 1) {  // If 1 is sent from the sensor when loud noise is detected
    if (is_on == true) {  // If the LED is on, turn it off
      digitalWrite(led, LOW);
      is_on = false;
    }
    else {  // Else, if the LED is off, turn it on
      digitalWrite(led, HIGH);
      is_on = true;
    }
  }

  delay(50);  // Small delay to prevent bouncing and too frequent updates
}
