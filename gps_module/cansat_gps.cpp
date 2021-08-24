#include "cansat_gps.hpp"

Cansat_gps::Cansat_gps() {
  ss.begin(GPSBaud);

}

/**
 * 緯度を返す
 */
double Cansat_gps::lat() {

 if (ss.available() > 0){
    char c = ss.read();    // GPSセンサからの値を読み込み
    gps.encode(c); // NMEAフォーマットの文字列をパースする
    if(gps.location.isUpdated()){ // 位置情報が更新された
      //Serial.print("Lat=\t"); // 緯度
      return gps.location.lat();
    }
  }

}

/**
 * 経度を返す
 */
double Cansat_gps::lng() {
  
 if (ss.available() > 0){
    char c = ss.read();    // GPSセンサからの値を読み込み
    gps.encode(c); // NMEAフォーマットの文字列をパースする
    if(gps.location.isUpdated()){ // 位置情報が更新された
      //Serial.print(" Lng=\t"); // 経度
      return gps.location.lng();
    }
    }
}