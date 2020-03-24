/* This sketch is for reading remote controller buttons' codes
 * To read codes you need to:
 *  1. Change infrared sensor's pin to yours
 *  2. Flash this sketch to your Arduino with connected infrared reciever
 *  3. Open port monitor
 *  4. Press buttons on your remote controller and write their codes from port monitor
 */

#include <IRremote.h>

IRrecv irrecv(2); // infrared sensor's pin

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if ( irrecv.decode( &results )) {
    Serial.println( results.value);
    irrecv.resume();
  }
}
