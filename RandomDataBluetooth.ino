#include "BluetoothSerial.h" // include Bluetooth Serial library

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif // check if Bluetooth hardware is enabled or not

BluetoothSerial SerialBT;

void setup() {
  
  //Serial.begin(115200); // initiate Serial via USB
  
  SerialBT.begin("YTS2020"); // initiate Serial via Bluetooth and set device name
  
  //Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  
//  SerialBT.println("Hello World!!"); // Send string via Bluetooth Serial
  SerialBT.println(millis()/1000);//time from starting
  SerialBT.println(random(0,10));
  // Send int via Bluetooth Serial
//for(int i=1;i<=10;i++){
  //SerialBT.println(i); // Send float via Bluetooth Serial
  delay(100);
//}
  //for(int j=10;j<=1;j--){
    //SerialBT.println(j);
    //delay(100);
    
  //}
  
}
