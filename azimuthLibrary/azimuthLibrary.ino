#include "Arduino.h"
#include "azimuthLibrary.hpp"

#define R 6378.137 // 赤道半径

double now_lat = 35.6544; // 現在地 緯度
double now_lng = 139.74477; // 現在地　経度
double goal_lat = 21.4225; // 目的地 緯度
double goal_lng = 39.8261; // 目的値 経度

void setup() {
  Serial.begin(115200); 
  Serial.println("start");
   Azimuth azimuth = Azimuth();
    Serial.print("calculation_azimuth: ");
    Serial.print(azimuth.calculation_azimuth(now_lng, now_lat, goal_lng, goal_lat),6);
    Serial.print("calculation_distance: ");
    Serial.print(azimuth.calculation_distance(now_lng, now_lat, goal_lng, goal_lat),6);
    Serial.print("\n");

    azimuth.set_goal(goal_lng, goal_lat);

    double tmp1, tmp2;          
    azimuth.azimuth_to_goal(now_lng, now_lat, &tmp1);
    azimuth.distance_to_goal(now_lng, now_lat, &tmp2);
    Serial.print("azimuth_goal: ");
    Serial.print(tmp1,6);
    Serial.print("distance_goal: ");
    Serial.print(tmp2,6);
    Serial.print("\n");

    azimuth.azimuth(now_lng, now_lat, goal_lng, goal_lat, &tmp1);
    azimuth.distance(now_lng, now_lat, goal_lng, goal_lat, &tmp2);
    Serial.print("azimuth_goal: ");
    Serial.print(tmp1,6);
    Serial.print("distance_goal: ");
    Serial.print(tmp2,6);
    Serial.print("\n");
}

void loop() {
   
}
