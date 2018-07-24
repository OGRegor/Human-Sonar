#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X laser = Adafruit_VL53L0X();

VL53L0X_RangingMeasurementData_t dist;
// Initializes the pin connections on the board
const int button = 3;
const int headphones = 4;

int count = 0;
int freq;

float val[5];
float avg = 0;

void setup() 
{
  Serial.begin(9600);
  
  //sets up the laser sensor
  if (!laser.begin()) 
  {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  pinMode(button, INPUT);
  pinMode(headphones, OUTPUT);
}

void loop() 
{  
  while(digitalRead(button) == HIGH)
  {
    laser.rangingTest(&dist, false); 
    
    // checks for failure
    if(dist.RangeStatus != 4) 
    {  
      // phase failures have incorrect data
      Serial.print("Distance (mm): "); 
      Serial.println(dist.RangeMilliMeter);
    }
    else 
    {
      Serial.println(" out of range ");
    }
    // takes a rolling average of values so that the tone produced is smoother
    val[count%5] = float(dist.RangeMilliMeter);
    for(int i = 0; i < 5; i++)
    {
      avg += val[i];
    }
    avg = avg / 5;
    freq = 3000 - (((avg - 1)/999) * 4500); //linear transform from range 1mm to 1000mm, inverts it so freq goes from higher -> lower       

  tone(headphones, (int) freq, 200);
  // zeroes the average so it is unique between tones
  avg = 0;
  count++;
  delay(10);
  }
}
