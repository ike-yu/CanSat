#ifndef __AZIMUTH_H__
#define __AZIMUTH_H__

#include "Arduino.h"
#include <stdio.h>
#include <math.h>

#define R 6378.137 // 赤道半径

class Azimuth {
  public:
    Azimuth();

    /*
    (経度, 緯度) = A(lng_1, lat_1), B(lng_2, lat_2)
    AからBの方位角(°)を求める -> calculation_azimuth, azimuth
    AとBの距離(km)を求める -> calculation_distance, distance
    B にセットしたゴール地点の値を代入する -> azimuth_to_goal, distance_to_goal
    */
    // 方位角は左手系北基準 (北 0°, 東 90°, 南 180°, 西 270°)
    double calculation_azimuth(double lng_1, double lat_1,  double lng_2, double lat_2);
    double calculation_distance(double lng_1, double lat_1,  double lng_2, double lat_2);
    
    void azimuth(double lng_1, double lat_1, double lng_2, double lat_2, double* ret); 
    void distance(double lng_1, double lat_1, double lng_2, double lat_2, double* ret);

    void azimuth_to_goal(double lng_1, double lat_1, double* ret); 
    void distance_to_goal(double lng_1, double lat_1, double* ret); 

    // ゴール位置の設定
    void set_goal(double lng, double lat); 

    
  private:
    double goal_lat; // ゴール地点の緯度
    double goal_lng; // ゴール地点の経度

};

#endif // __AZIMUTH_H__
