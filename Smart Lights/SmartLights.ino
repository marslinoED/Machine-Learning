// Define pins for RGB LED
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int delayled = 7;
// Function to set RGB values
void setRGB(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setup() {
  // Set RGB pins as output
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(delayled, OUTPUT);

  digitalWrite(delayled, HIGH);
  // Delay for demonstration purposes
  delay(1000);
  digitalWrite(delayled, LOW);
}

void loop() {

  if (Serial.available() > 0) {
    // Read characters until newline is received
    String str = Serial.readStringUntil('\n');

        // Variables to store the separated integers
        int red = 0, green = 0, blue = 0;
        int currentIndex = 0;

        for (char c : str) {
            if (c == ',') {
                currentIndex++;
                continue;
            }
            int digit = c - '0';
            if (currentIndex == 0) {
                red = red * 10 + digit;
            } else if (currentIndex == 1) {
                green = green * 10 + digit;
            } else if (currentIndex == 2) {
                blue = blue * 10 + digit;
            }
        }

    Serial.println(red);
    Serial.println(green);
    Serial.println(blue);
  // Map RGB values to PWM range
  int mappedRed = red / 4;      // adjust according to your LED
  int mappedGreen = green / 4;  // adjust according to your LED
  int mappedBlue = blue / 4;    // adjust according to your LED
  
  // Set RGB values
  setRGB(mappedRed, mappedGreen, mappedBlue);
  digitalWrite(delayled, HIGH);
  // Delay for demonstration purposes
  delay(1);
  digitalWrite(delayled, LOW);


}
}

