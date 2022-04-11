//VALVES _______________________________________________________________________________________________________________________________________________________________
#define valve1_pin 10 //when set high it tells relay module to open valve 1 (WATER)
#define valve2_pin 11 //when set high it tells relay module to open valve 2 (FERTILIZER)

//LED _______________________________________________________________________________________________________________________________________________________________
#define led_pin 12 //when set high it goes to the gate of MOSFET transistor and turns LED on

//SOIL SENSOR_______________________________________________________________________________________________________________________________________________________________
//from tutorial: https://how2electronics.com/measure-soil-nutrient-using-arduino-soil-npk-sensor/
#include <SoftwareSerial.h>
#include <Wire.h> //also used by SHT30 and light sensor

#define RE 8 //enable pin for Rx
#define DE 7 //enable pin for Tx

//DATA TRANSFER_______________________________________________________________________________________________________________________________________________________________
#define serialPi Serial

//The arrays of data we are sending to the sensor
const uint8_t humid_send [] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0a}; //Relative humid (%RH) TX:01 03 00 00 00 01 84 0a RX:01 03 02 01 2B F9 CB 
const uint8_t temp_send [] = {0x01, 0x03, 0x00, 0x01, 0x00, 0x01, 0xd5, 0xca}; // in (degrees Celcius) TX:01 03 00 01 00 01 d5 ca RX:01 03 02 00 ED 78 09 
const uint8_t conduct_send [] = {0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0x25, 0xca}; //Conductivity (Us/cm) TX:01 03 00 02 00 01 25 ca RX:01 03 02 03 A2 39 0D
const uint8_t ph_send [] = {0x01, 0x03, 0x00, 0x03, 0x00, 0x01, 0x74, 0x0a}; //pH TX:01 03 00 03 00 01 74 0a RX:01 03 02 00 3E 39 94 
const uint8_t n_send [] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xc5, 0xcb}; //Nitrogen (mg/kg) TX:01 03 00 04 00 01 c5 cb RX:01 03 02 00 41 78 74
const uint8_t p_send [] = {0x01, 0x03, 0x00, 0x05, 0x00, 0x01, 0x94, 0x0b}; //Phosphorous (mg/kg) TX:01 03 00 05 00 01 94 0b RX:01 03 02 00 5B F9 BF
const uint8_t k_send [] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0b}; //Potassium (mg/kg) TX:01 03 00 06 00 01 64 0b RX:01 03 02 00 DC B9 DD 


//The arrays that store the data received from sensor
uint8_t humid_return[7]; //we expect a returning array of 7 uint8_ts
uint8_t temp_return[7];
uint8_t conduct_return[7];
uint8_t ph_return[7];
uint8_t n_return[7];
uint8_t p_return[7];
uint8_t k_return[7];

SoftwareSerial mod(2,3); //mySerial RX,TX note that we are connecting RX of sensor (adapter module) to RX of arduino and TX of sensor to TX of arduino


//SHT30 SENSOR_______________________________________________________________________________________________________________________________________________________________
#include <Arduino.h>
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();

//LIGHT SENSOR_______________________________________________________________________________________________________________________________________________________________
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)


void configureSensor(void)
{
 
  tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  delay(100);
}


void setup()
{
  Serial.begin(4800);
  serialPi.begin(4800);

//VALVES_______________________________________________________________________________________________________________________________________________________________
  pinMode(valve1_pin, OUTPUT);
  pinMode(valve2_pin, OUTPUT);
  
//LED_______________________________________________________________________________________________________________________________________________________________
  pinMode(led_pin, OUTPUT);

//SOIL SENSOR_______________________________________________________________________________________________________________________________________________________________
  mod.begin(4800); //mySerial.begin change to 4800 later?????
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  delay(3000);

//SHT30 SENSOR_______________________________________________________________________________________________________________________________________________________________
  if (! sht31.begin(0x44)) {   // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }

//LIGHT SENSOR_______________________________________________________________________________________________________________________________________________________________
  configureSensor();

}


//SOIL SENSOR_______________________________________________________________________________________________________________________________________________________________
uint8_t humid()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(humid_send, sizeof(humid_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          humid_return[i]= mod.read(); 
        }
    }
uint8_t humid_uint8_t1 = humid_return[3]; //same as uint8_t
uint8_t humid_uint8_t2 = humid_return[4];


uint16_t humid_both_uint8_ts = 0; 

humid_both_uint8_ts = humid_uint8_t1;
humid_both_uint8_ts <<=8; //left shift
humid_both_uint8_ts = humid_both_uint8_ts | humid_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float humid_float =0;
humid_float = humid_both_uint8_ts;

float humid_final = 0;
humid_final = humid_float / 10;

return humid_final;
}


uint8_t temperature()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(temp_send, sizeof(temp_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          temp_return[i]= mod.read(); 
        }
    }
uint8_t temp_uint8_t1 = temp_return[3]; //same as uint8_t
uint8_t temp_uint8_t2 = temp_return[4];


uint16_t temp_both_uint8_ts = 0; 

temp_both_uint8_ts = temp_uint8_t1;
temp_both_uint8_ts <<=8; //left shift
temp_both_uint8_ts = temp_both_uint8_ts | temp_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float temp_float =0;
temp_float = temp_both_uint8_ts;

float temp_final = 0;
temp_final = temp_float / 10;

//Serial.println(temp_final, 1);
//delay(100);
return temp_final;
}


uint8_t conductivity()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(conduct_send, sizeof(conduct_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          conduct_return[i]= mod.read(); 
        }
    }
uint8_t conduct_uint8_t1 = conduct_return[3]; //same as uint8_t
uint8_t conduct_uint8_t2 = conduct_return[4];


uint16_t conduct_both_uint8_ts = 0; 

conduct_both_uint8_ts = conduct_uint8_t1;
conduct_both_uint8_ts <<=8; //left shift
conduct_both_uint8_ts = conduct_both_uint8_ts | conduct_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float conduct_float =0;
conduct_float = conduct_both_uint8_ts;

float conduct_final = conduct_both_uint8_ts;

//Serial.println(conduct_final,0);
//delay(100);
return conduct_final;
}


uint8_t ph()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(ph_send, sizeof(ph_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          ph_return[i]= mod.read(); 
        }
    }
uint8_t ph_uint8_t1 = ph_return[3]; //same as uint8_t
uint8_t ph_uint8_t2 = ph_return[4];


uint16_t ph_both_uint8_ts = 0; 

ph_both_uint8_ts = ph_uint8_t1;
ph_both_uint8_ts <<=8; //left shift
ph_both_uint8_ts = ph_both_uint8_ts | ph_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float ph_float =0;
ph_float = ph_both_uint8_ts;

float ph_final = 0;
ph_final = ph_float / 10;

//Serial.println(ph_final, 1);
//delay(100);
return ph_final;
}


uint8_t nitrogen()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(n_send, sizeof(n_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          n_return[i]= mod.read(); 
        }
    }
uint8_t n_uint8_t1 = n_return[3]; //same as uint8_t
uint8_t n_uint8_t2 = n_return[4];


uint16_t n_both_uint8_ts = 0; 

n_both_uint8_ts = n_uint8_t1;
n_both_uint8_ts <<=8; //left shift
n_both_uint8_ts = n_both_uint8_ts | n_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float n_float =0;
n_float = n_both_uint8_ts;

float n_final = n_both_uint8_ts;

//Serial.println(n_final, 0);
//delay(100);

return n_final;
}



uint8_t phosphorous()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(p_send, sizeof(p_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          p_return[i]= mod.read(); 
        }
    }
uint8_t p_uint8_t1 = p_return[3]; //same as uint8_t
uint8_t p_uint8_t2 = p_return[4];


uint16_t p_both_uint8_ts = 0; 

p_both_uint8_ts = p_uint8_t1;
p_both_uint8_ts <<=8; //left shift
p_both_uint8_ts = p_both_uint8_ts | p_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float p_float =0;
p_float = p_both_uint8_ts;

float p_final = p_both_uint8_ts;

//Serial.println(p_final, 0);
//delay(100);

return p_final;
}




uint8_t potassium()
{
  digitalWrite(DE,HIGH); //transmit mode
  digitalWrite(RE,HIGH);
  delay(100);

  if (mod.write(k_send, sizeof(k_send)) == 8) //checking if message is correct length
    {
      digitalWrite(DE, LOW); //receive mode
      digitalWrite(RE, LOW);
      delay(100);
      
      for(uint8_t i=0; i<7; i++)
        {
          k_return[i]= mod.read(); 
        }
    }
uint8_t k_uint8_t1 = k_return[3]; //same as uint8_t
uint8_t k_uint8_t2 = k_return[4];


uint16_t k_both_uint8_ts = 0; 

k_both_uint8_ts = k_uint8_t1;
k_both_uint8_ts <<=8; //left shift
k_both_uint8_ts = k_both_uint8_ts | k_uint8_t2; //OR operation to merge uint8_t1 and uint8_t2 (01 23 -> 0123)

float k_float =0;
k_float = k_both_uint8_ts;

float k_final = k_both_uint8_ts;

//Serial.println(k_final, 0);
//delay(100);

return k_final;
}



//SHT30 SENSOR_______________________________________________________________________________________________________________________________________________________________
int sht30temp ()
{
  float t = sht31.readTemperature();
  if (! isnan(t)) {  // check if 'is not a number'
    //Serial.println(t);
    return t;
  } else { 
    Serial.println("Failed to read temperature");
  }
  //delay(100);
}

int sht30humid ()
{
  float h = sht31.readHumidity();
  
  if (! isnan(h)) {  // check if 'is not a number'
    return h;
  } else { 
    Serial.println("Failed to read humid");
  }

  //delay(100);
}


//LIGHT SENSOR_______________________________________________________________________________________________________________________________________________________________
int advancedRead()
{
  // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
  // That way you can do whatever math and comparisons you want!
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;

  //Serial.println(tsl.calculateLux(full, ir), 0);
  //delay(100);

  return tsl.calculateLux(full, ir);
}



void loop()
{

//SENSORS____________________________________________________________________________________________________________________________________________________________________
  //humid();
  int humid_global = humid();
  //Serial.println(humid_global);
  delay(100);
  //temperature();
  int temp_global = temperature();
  //Serial.println(temp_global);
  delay(100);
  //conductivity();
  int conduct_global = conductivity();
  //Serial.println(conduct_global);
  delay(100);
  //ph();
  int ph_global = ph();
  //Serial.println(ph_global);
  delay(100);
  //nitrogen();
  int n_global = nitrogen();
  //Serial.println(n_global);
  delay(100);
  //phosphorous();
  int p_global = phosphorous();
  //Serial.println(p_global);
  delay(100);
  //potassium();
  int k_global = potassium ();
  //Serial.println(k_global);
  delay(100);


  int ambtemp_global = sht30temp();
  //Serial.println (ambtemp_global);
  delay(100);

  int ambhumid_global = sht30humid();
  //Serial.println (ambhumid_global);
  delay(100);

  int light_global = advancedRead();
  //Serial.println (light_global);
  delay(100);


//DATA TRANSFER____________________________________________________________________________________________________________________________________________________________________
//Send the data to the rpi
serialPi.print("<");
serialPi.print("humidity ");
serialPi.print(humid_global);
serialPi.print(",");
serialPi.print("temperature ");
serialPi.print(temp_global);
serialPi.print(",");
serialPi.print("conductivity ");
serialPi.print(conduct_global);
serialPi.print(",");
serialPi.print("pH ");
serialPi.print(ph_global);
serialPi.print(",");
serialPi.print("nitrogen ");
serialPi.print(n_global);
serialPi.print(",");
serialPi.print("phosphorous ");
serialPi.print(p_global);
serialPi.print(",");
serialPi.print("potassium ");
serialPi.print(k_global);
serialPi.print(",");
serialPi.print("ambient_temperature ");
serialPi.print(ambtemp_global);
serialPi.print(",");
serialPi.print("ambient_humidity ");
serialPi.print(ambhumid_global);
serialPi.print(",");
serialPi.print("light ");
serialPi.print(light_global);
serialPi.print(">");
delay(5000);

//VALVES____________________________________________________________________________________________________________________________________________________________________

//Valve1 (water) 
 //int humid_global = humid();
  //Serial.println("humid_global is ");
  //Serial.println(humid_global);
  
  if (humid_global < 5)
    {
      digitalWrite(valve1_pin, HIGH); //open valve 1
      //delay(30000); //30 seconds
      digitalWrite(valve1_pin, LOW);
    }

//Valve 2
 //int n_global = nitrogen();
 //int p_global = phosphorous();
 //int k_global = potassium ();

 if (n_global < 10 && p_global < 10 && k_global < 10)
 {
      digitalWrite(valve2_pin, HIGH); //open valve 1
      //delay(30000); //30 seconds
      digitalWrite(valve2_pin, LOW);
 }

//LED____________________________________________________________________________________________________________________________________________________________________
 //int light_global = advancedRead();
 //Serial.print("light level is ");
 //Serial.println(light_global);
 
  if (light_global < 100) //anything under 100 Lux is pretty dark so we turn LED on
    {
      digitalWrite(led_pin, HIGH); //turn light on
    }
  else {
    digitalWrite(led_pin, LOW); //turn light off
  }

  Serial.println("\n");
  delay(1000);


}
