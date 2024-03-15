// Define the pin for the LED
int ledPin [10] = {2,3,4,5,6,7,8,9,10,11};
int Pins   [10] = {0,0,0,0,0,0,0,0, 0, 0};
void setup() {
  // Initialize serial communication
  Serial.begin(2000000);
  
  // Set the LED pin as an output
  for(int i = 0; i < 10; i++)
    pinMode(ledPin[i], OUTPUT);

}

void loop() {


  // Check if data is available to read from serial port
  if (Serial.available() > 0) {
    // Read the value from serial port
   String value = Serial.readString();
   
   int num = value.toInt();
   if (num >= 1)
   {
      Pins[0] = Pins [9] = 255;
      Pins[1] = Pins[2] = Pins[3]= Pins[4]= Pins[5]= Pins[6]= Pins[7]= Pins[8] = 0;
       
   }
 
   if (num >= 3)
   {
      Pins[1] = Pins [8] = 255;
      Pins[2] = Pins[3]= Pins[4]= Pins[5]= Pins[6] = Pins[7] = 0;
       
   
   }
   if (num >= 5)
   {
      Pins[2] = Pins [7] = 255;
      Pins[3]= Pins[4]= Pins[5] = Pins[6] = 0;
       
   }
   if (num >= 7)
   {
      Pins[3] = Pins [6] = 255;
       Pins[4]= Pins[5]  = 0;
        
   }
   if (num >= 8)
   {
      Pins[4] = Pins [5] = 255;
   }


    for(int i = 0; i < 10; i++)
    {
      analogWrite(ledPin[i], Pins[i]);
    }



  }
   
}
