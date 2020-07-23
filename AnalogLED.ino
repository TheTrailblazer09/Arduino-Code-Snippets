long timeperiod, SampleRate = 100; // in Hz
int resolution=12;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  // Configure ADC
  analogReadResolution(resolution);//set the sample bits and resolution. 
  //It can be a value between 9 (0 – 511) and 12 bits (0 – 4095). Default is 12-bit resolution.
                                        //  9-bit gives an ADC range of 0-511
                                        // 10-bit gives an ADC range of 0-1023
                                        // 11-bit gives an ADC range of 0-2047
                                        // 12-bit gives an ADC range of 0-4095
  SampleRate = 10; // in Hz
  timeperiod = 1000/SampleRate; // in milliSeconds
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int val = analogRead(25);
  // Convert the analog reading (which goes from 0 - 4196) to a voltage (0 - 3.3V):
  float voltage = val * (3.3 / 4196.0); // why include .0 ??
  // print out the value you read:
  Serial.print(val);
  Serial.print(" ");
  Serial.println(voltage);
//  analogWrite(2,voltage);
  delay(timeperiod);
}
