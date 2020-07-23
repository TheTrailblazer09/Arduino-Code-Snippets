#include "BluetoothSerial.h" // include Bluetooth Serial library

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif // check if Bluetooth hardware is enabled or not

BluetoothSerial SerialBT;

void setup() {
  
 //// Serial.begin(115200); // initiate Serial via USB
  
  SerialBT.begin("YTS2020"); // initiate Serial via Bluetooth and set device name
  pinMode(2,OUTPUT);
  //Serial.println("The device started, now you can pair it with bluetooth!");
}
int i =0;
void loop() {
  
if(SerialBT.available()){
  int c=SerialBT.parseInt();
  SerialBT.println(c);
 if(c==1){
  digitalWrite(2,HIGH);
  SerialBT.println("the led is on");
   }
   if(c==0){
    digitalWrite(2,LOW);
    SerialBT.println("the led is off");
   }
   else{
    SerialBT.println("please enter 0 or 1");
   }
 
}


}
