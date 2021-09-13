//
// Copyright © 2021 Multifunctinal Lamp.
//
//Light colour modes
//1  - danger
//2  - Warning
//------------------
//***1500K->(255, 109, 000)***-------
//3  - 1500k 100%
//4  - 1500k 75%
//5  - 1500k 50%
//6  - 1500k 25%
//7  - 1500k 10% $Optional
//------------------
//***3500K->(255, 196, 137)***-------
//8  - 3500k 100%
//9  - 3500k 75%
//10 - 3500k 50%
//11 - 3500k 25%
//12 - 3500K 10% $Optional
//------------------
//***5500K->(255, 236, 224)***-------
//13  - 5500k 100%
//14  - 5500k 75%
//15  - 5500k 50%
//16  - 5500k 25%
//17  - 5500k 10% $Optional
//------------------
//***7500K->(235, 238, 255)***-------
//18  - 7500k 100%
//19  - 7500k 75%
//20  - 7500k 50%
//21  - 7500k 25%
//22  - 7500k 10% $Optional
//------------------
//***9500K->(208, 222, 255)***-------
//23  - 9500k 100%
//24  - 9500k 75%
//25  - 9500k 50%
//26  - 9500k 25%
//27  - 9500k 10% $Optional
//------------------
//***11500K->(197, 211, 255)***------
//28  - 11500k 100%
//29  - 11500k 75%
//30  - 11500k 50%
//31  - 11500k 25%
//32  - 11500k 10% $Optional
//------------------

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "iotstreetlamp-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "jXckUdOhyOaMahD3eEqNyPHYQd8DoOaZCMBEokpG"
#define WIFI_SSID "Lucky 3241"
#define WIFI_PASSWORD "pushpa6633"

//Varibales to control the strip
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN D1
#define NUMPIXELS 60
int lCount = 60;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Pins for the operations.
int pirPin = D3;
int defectPin = D2;
int defectVal = 0;


//Main program. 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
  pinMode(defectPin,INPUT);
  //Aanlog pin of the nodemcu
  pinMode(A0, INPUT);
  //Pir pin to teh board
  pinMode(pirPin,INPUT);


  //[-]Debuging connection of the wifi
  // connect to wifi.
  //  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //  Serial.print("connecting");
  //  while (WiFi.status() != WL_CONNECTED) {
  //    //Serial.print(".");
  //    delay(500);
  //  }
  //  Serial.println();
  //  Serial.print("connected: ");
  //  Serial.println(WiFi.localIP());

  //Firebase 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  //Getting the values for the control
  boolean lightMode = Firebase.getBool("Mode");
  boolean onOff = Firebase.getBool("Global/Status");
  
  //Warning lights
  int warning = Firebase.getInt("Lights/L001/warning");

  //Serial.println(warning);
  //delay(500);

  //Mannual Override Admin will control thh light manually 
  if ((lightMode == 1) and (onOff == 1)) {


     //Do the defect monitoring via the pin---------------------
     defectVal = digitalRead(defectPin);
     switch(defectVal){
        case 0:
           Firebase.setString("Lights/L001/Status","OFF");
           break;
        case 1:
           Firebase.setString("Lights/L001/Status","ON");
           break;    
        }
     //--------------------------------------------------------


    String brightness = Firebase.getString("Global/Brightness");
    String temp =  Firebase.getString("Global/Temperature");
   

   // Serial.print(brightness);
    //Serial.println(temp);
    //delay(500);

     
    //1500K controls
    if ((temp == "1") and (brightness == "1")) {
      Serial.println("1500k light with 10%");
      pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
      pixels.setBrightness(32);
      pixels.show();
      //delay(500);
    }
    else if ((temp == "1") and (brightness == "2")) {
      //      Serial.println("1500k light with 25%");
      pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
      pixels.setBrightness(64);
      pixels.show();
      //      delay(500);
    }
    else if ((temp == "1") and (brightness == "3")) {
      //      Serial.println("1500k light with 50%");
      pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
      pixels.setBrightness(127);
      pixels.show();
      //      delay(500);
    }
    else if ((temp == "1") and (brightness == "4")) {
      //      Serial.println("1500k light with 75%");
      pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
      pixels.setBrightness(192);
      pixels.show();
      //      delay(500);
    }
    else if ((temp == "1") and (brightness == "5")) {
      //      Serial.println("1500k light with 100%");
      pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();

      //      delay(500);
    }
    //3500k Controls-----------------------------------------------
    else if ((temp == "2") and (brightness == "1")) {
      //      Serial.println("3500k light with 10%");
      pixels.fill(pixels.Color(255, 196, 137), 0, lCount);
      pixels.setBrightness(32);
      pixels.show();
    }
    //    delay(500);

    else if ((temp == "2") and (brightness == "2")) {
      //    Serial.println("3500k light with 25%");
      pixels.fill(pixels.Color(255, 196, 137), 0, lCount);
      pixels.setBrightness(64);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "2") and (brightness == "3")) {
      //    Serial.println("3500k light with 50%");
      pixels.fill(pixels.Color(255, 196, 137), 0, lCount);
      pixels.setBrightness(127);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "2") and (brightness == "4")) {
      //    Serial.println("3500k light with 75%");
      pixels.fill(pixels.Color(255, 196, 137), 0, lCount);
      pixels.setBrightness(192);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "2") and (brightness == "5")) {
      //      Serial.println("3500k light with 100%");
      pixels.fill(pixels.Color(255, 196, 137), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      //      delay(500);
    }
    //----------------------------------------------------------------
    //5500k Controls-----------------------------------------------
    else if ((temp == "3") and (brightness == "1")) {
      //    Serial.println("5500k light with 10%");
      pixels.fill(pixels.Color(255, 236, 224), 0, lCount);
      pixels.setBrightness(32);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "3") and (brightness == "2")) {
      //    Serial.println("5500k light with 25%");
      pixels.fill(pixels.Color(255, 236, 224), 0, lCount);
      pixels.setBrightness(64);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "3") and (brightness == "3")) {
      //    Serial.println("5500k light with 50%");
      pixels.fill(pixels.Color(255, 236, 224), 0, lCount);
      pixels.setBrightness(127);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "3") and (brightness == "4")) {
      //    Serial.println("5500k light with 75%");
      pixels.fill(pixels.Color(255, 236, 224), 0, lCount);
      pixels.setBrightness(192);
      pixels.show();
      //    delay(500);
    }
    else if ((temp == "3") and (brightness == "5")) {
      //    Serial.println("5500k light with 100%");
      pixels.fill(pixels.Color(255, 236, 224), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      //    delay(500);
    }
    //----------------------------------------------------------------
    //7500k Controls-----------------------------------------------
    else if ((temp == "4") and (brightness == "1")) {
      Serial.println("7500k light with 10%");
      pixels.fill(pixels.Color(235, 238, 255), 0, lCount);
      pixels.setBrightness(32);
      pixels.show();
      delay(500);
    }
    else if ((temp == "4") and (brightness == "2")) {
      Serial.println("7500k light with 25%");
      pixels.fill(pixels.Color(235, 238, 255), 0, lCount);
      pixels.setBrightness(64);
      pixels.show();
      delay(500);
    }
    else if ((temp == "4") and (brightness == "3")) {
      Serial.println("7500k light with 50%");
      pixels.fill(pixels.Color(235, 238, 255), 0, lCount);
      pixels.setBrightness(127);
      pixels.show();
      delay(500);
    }
    else if ((temp == "4") and (brightness == "4")) {
      Serial.println("7500k light with 75%");
      pixels.fill(pixels.Color(235, 238, 255), 0, lCount);
      pixels.setBrightness(192);
      pixels.show();
      delay(500);
    }
    else if ((temp == "4") and (brightness == "5")) {
      Serial.println("7500k light with 100%");
      pixels.fill(pixels.Color(235, 238, 255), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();

      delay(500);
    }
    //----------------------------------------------------------------
    //9500k Controls-----------------------------------------------
    else if ((temp == "5") and (brightness == "1")) {

      //Serial.println("9500k light with 10%");
      pixels.fill(pixels.Color(208, 222, 255), 0, lCount);
      pixels.setBrightness(32);
      pixels.show();
      //delay(500);
    }
    else if ((temp == "5") and (brightness == "2")) {
      //    Serial.println("9500k light with 25%");
      pixels.fill(pixels.Color(208, 222, 255), 0, lCount);
      pixels.setBrightness(64);
      pixels.show();

      //    delay(500);
    }
    else if ((temp == "5") and (brightness == "3")) {
      //    Serial.println("9500k light with 50%");
      pixels.fill(pixels.Color(208, 222, 255), 0, lCount);
      pixels.setBrightness(127);
      pixels.show();

      //    delay(500);
    }
    else if ((temp == "5") and (brightness == "4")) {
      //    Serial.println("9500k light with 75%");
      pixels.fill(pixels.Color(208, 222, 255), 0, lCount);
      pixels.setBrightness(192);
      pixels.show();

      //    delay(500);
    }
    else if ((temp == "5") and (brightness == "5")) {
      //    Serial.println("9500k light with 100%");
      pixels.fill(pixels.Color(208, 222, 255), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();

      //    delay(500);
    }


    //----------------------------------------------------------------

   
  }
// Automatic mode
  else if ((lightMode == 0) and (onOff == 1)) {
    
    int ldrMode = Firebase.getInt("Lights/L001/ldr");
    int pirMode = Firebase.getInt("Lights/L001/pir");
    //    Serial.println(ldrMode);
    //    Serial.println(pirMode);

    if (ldrMode == 1) {
      //Do the defect monitoring via the pin---------------------
     defectVal = digitalRead(defectPin);
     switch(defectVal){
        case 0:
           Firebase.setString("Lights/L001/Status","OFF");
           break;
        case 1:
           Firebase.setString("Lights/L001/Status","ON");
           break;    
        }
     //--------------------------------------------------------
      int value = analogRead(A0);
      //      Serial.println(value);

      if ((value > 0 ) and (value < 100))
      {
        pixels.fill(pixels.Color(255, 161, 72), 0, lCount);
        pixels.setBrightness(192);
        pixels.show();
        delay(100);
      }

      else if ( (value >= 100) and (value < 200))
      {
        digitalWrite(12, LOW); //Turns the LED OFF in Light.
        pixels.fill(pixels.Color(255, 161, 72), 0, lCount);
        pixels.setBrightness(64);
        pixels.show();
        delay(100);
      }
      else if (value >= 200) {
        pixels.fill(pixels.Color(255, 161, 72), 0, lCount);
        pixels.setBrightness(20);
        pixels.show();
        delay(100);
      }
    }
    
    else if (pirMode == 1) {
      //Do the defect monitoring via the pin---------------------
     defectVal = digitalRead(defectPin);
     switch(defectVal){
        case 0:
           Firebase.setString("Lights/L001/Status","OFF");
           break;
        case 1:
           Firebase.setString("Lights/L001/Status","ON");
           break;    
        }
     //--------------------------------------------------------

      int state = digitalRead(pirPin);
      if (state == HIGH) {
        //digitalWrite(D6, HIGH);
        pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
        pixels.setBrightness(127);
        pixels.show();
        delay(3000);
      }
      else {
       
        pixels.fill(pixels.Color(255, 109, 0), 0, lCount);
        pixels.setBrightness(32);
        pixels.show();
      }
    }
    //Red color
    else if (warning == 1){
      //Do the defect monitoring via the pin---------------------
     defectVal = digitalRead(defectPin);
     switch(defectVal){
        case 0:
           Firebase.setString("Lights/L001/Status","OFF");
           break;
        case 1:
           Firebase.setString("Lights/L001/Status","ON");
           break;    
        }
     //--------------------------------------------------------
  
      pixels.fill(pixels.Color(255, 0, 0), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      delay(200);
      pixels.fill(pixels.Color(0, 0, 0), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      delay(200);
      }
      else if((warning == 2)){
  {
    //Do the defect monitoring via the pin---------------------
     defectVal = digitalRead(defectPin);
     switch(defectVal){
        case 0:
           Firebase.setString("Lights/L001/Status","OFF");
           break;
        case 1:
           Firebase.setString("Lights/L001/Status","ON");
           break;    
        }
     //--------------------------------------------------------
      pixels.fill(pixels.Color(255, 102, 0), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      delay(500);
      pixels.fill(pixels.Color(0, 0, 0), 0, lCount);
      pixels.setBrightness(255);
      pixels.show();
      delay(500);
      }
    }
  

  else if ( (ldrMode == 0) or (pirMode == 0) or (warning == 0 )){
     pixels.clear();
    pixels.show();
    }
 
  else if ((onOff == 0)) {
    pixels.clear();
    pixels.show();
  }
}

  else if ((onOff == 0)) {
    pixels.clear();
    pixels.show();
  }      
}
