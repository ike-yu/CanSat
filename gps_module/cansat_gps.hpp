#ifndef __CANSAT_GPS_H__
#define __CANSAT_GPS_H__

#include "Arduino.h"
#include <TinyGPS++.h>

class Cansat_gps {
  public:
    Cansat_gps();

    double lat(); // 緯度
    double lng(); // 経度

  private:
    static const uint32_t GPSBaud = 9600;
    TinyGPSPlus gps;
    HardwareSerial ss(2);
};

#endif // __CANSAT_GPS_H__
