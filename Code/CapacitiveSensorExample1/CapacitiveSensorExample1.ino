#include <CapacitiveSensor.h>

/*
  CapacitiveSensorExample 1
  (C) 2015 Richel Bilderbeek
  
  aangepast van onderstaand:
*/
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


/*
  2              4 
  |  +--------+  |
  +--+ R      +--+
  |  +--------+
  |
  X
  
  2: Arduino pin 2, de sensor pin
  4: Arduino pin 4, de hulp pin
  R: weerstand van minstens 1 Mega-Ohm (bruin-zwart-groen-goud)
  Draad aanraken bij 'X', je kunt hier ook met folie werken
  
  Je kunt ook een LED aansluiten (maar er is ook een LEDje op de Arduino zelf):
  
 13              4 GND
  |    +--------+  |
  + +--+ R      +--+
  | |  +--------+
  | |
  +-+
  |L|
  +-+

  13: Arduino pin 13, de LED pin
  GND: Arduino pin GND, de Aarde (zit 3x op de Arduino Uno, elke is goed)
  L: LEDje, lange pin aan de kant van 13 (dit is de plus kant)
  R: weerstand van minsten 220 Ohm (rood-rood-bruin-goud), veiliger is 1 kilo-Ohm (bruin-zwart-rood-goud)
  
*/

const int pin_sensor = 2;
const int pin_hulp   = 4;
const int pin_led    = 13;

CapacitiveSensor mijn_cap_sensor = CapacitiveSensor(pin_hulp,pin_sensor);        

void setup()                    
{
  pinMode(pin_led,OUTPUT);
  Serial.begin(9600);
}

void loop()                    
{
  //Hoe hoger 'samples', hoe nauwkeuriger de sensor meet
  const int samples = 30;

  //Meet de waarde van de sensor
  const int waarde = mijn_cap_sensor.capacitiveSensor(samples);

  //Laat de waarde zien in de Serial Monitor
  Serial.println(waarde);

  //De drempelwaarde bepaalt wanneer het programma denkt dat je de sensor aanraakt
  // - te laag: dan zal het programma vaker denken dat je de sensor aanraakt, terwijl je dat niet doet
  // - te hoog: dan zal het programma minder vaak denken dat je de sensor aanraakt, terwijl je dat wel doet
  const int drempelwaarde = 100;
  
  //Als je de sensor aanraakt, gaat het LEDje op pin 'pin_led' branden
  digitalWrite(pin_led,waarde >= drempelwaarde ? HIGH : LOW);

  delay(100);
}


