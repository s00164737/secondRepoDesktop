//Custom variables
 int LED=3;      //initialize variable for LED to correspond with Digital Port 1
 int brightness = 0;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}//end setup

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  //Max 1023
  int knobValue = analogRead(A0);

   // print out the value you read:
  Serial.println(knobValue);


Control_Led(knobValue);

}//end loop

//Method that controls the LED brightness depending on Potentiometer
//Brightness Min 0 Max 255
//Turn on at Potentiometer value of 400
void Control_Led(int val)
{
  brightness = ((val-400)/3);
  if(val >= 400)
  {
    turnOn_led(brightness);
    delay(30);
  }
  else
  {
    turnOff_led();
  }
}

//Method that turns on LED
void turnOn_led(int brightness)
{
  analogWrite(LED, brightness);  // turn the LED on (HIGH is the voltage level)                    // wait for a second
}//end turnOn_led

//Method that turns off LED
void turnOff_led()
{
    analogWrite(LED, 0);   // turn the LED off by making the voltage LOW
}//end turnOff_led
