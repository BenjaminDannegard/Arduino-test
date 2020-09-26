int ledPin = 13; // Use Pin 13 as the pin where the LED is connected 
int shockPin = 10; // Use Pin 10 as Input from the sensor
int shockVal = HIGH; // This variables value will be high until the sensor is triggered
boolean bAlarm = false; // Set the checking variable as false initialy

unsigned long lastShockTime; // Variable for holding the recorded time that we measured a trigger

int shockAlarmTime = 250; // Number of milli seconds to keep the triggered sensor active

void setup () //This part will run once when the code is first activated on the Arduino board.
{
  Serial.begin(9600);  // Initiates the serial monitor
  pinMode (shockPin, INPUT) ; // Input from the vibration sensor
}

void loop () //This is the part of the code that runs continusly when the Arduino board is on
{
  shockVal = digitalRead (shockPin) ; // Read the value from the sensor and put it into our previously defined variable

  if (shockVal == LOW) // If the sensor detects vibration the variable will be set to LOW and the code inside this part will run
  { 
    // This for loop makes the LED light fade in. Having a variable increasing in value for each time the loop is repeated until the light turns on.                              
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue); //Gives the value to the LED light. Telling it to light up
    delay(30); //Adding a short delay so that the change is noticable
    } 
    
    // This for loop makes the LED light fade out. Having a variable decreasing in value for each time the loop is repeated until the light turns off.
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(ledPin, fadeValue); //Gives the value to the LED light. Telling it to turn off
      delay(30); //Adding a short delay so that the change is noticable
      lastShockTime = millis(); // Records the time when the sensor was activated. Millis() is a function that measures the time an Arduino board has been active.
      
      // The following if statement inhibits the serial monitor from printing values continiously when the sensor is activated. Reducing clutter in the serial monitor.
      if (!bAlarm){
        Serial.println("Sensor triggered"); //Writes Sensor triggered to the serial monitor when the sensor detects vibration
        bAlarm = true; //Set the control variable to true so that it will only write the time once
      }
    }
  }
  else
  {
    // This if statement checks if enough time has passed since the sensor was triggered compared to our previously defined variable, and that it has been triggered. This makes it so that the bAlarm variable is not imidatly reset.
    // Giving us some time between when triggers are printed in the serial monitor.
    if( (millis()-lastShockTime) > shockAlarmTime  &&  bAlarm){
      Serial.println("no alarm");
      bAlarm = false;
    }
  }
}
