#include "cansat_gps.hpp"

Cansat_gps cansat_gps = Cansat_gps();

void setup() {

}

void loop() {
  Serial.begin(115200);
  Serial.println("GPS start!");

  double lat_value;
  lat_value = cansat_gps.lat();
  double lng_value;
  lng_value = cansat_gps.lng();

  Serial.println(lat_value,6);
  Serial.print(",");
  Serial.println(lng_value,6);
  
  delay(1000);
}
