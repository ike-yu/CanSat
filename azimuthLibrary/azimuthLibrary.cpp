#include "azimuthLibrary.hpp"

Azimuth::Azimuth() {

}

// 1->2の方位角を返す
double Azimuth::calculation_azimuth(double lng_1, double lat_1,  double lng_2, double lat_2){
  double azimuth;
  lng_1 = lng_1/180*M_PI;
  lat_1 = lat_1/180*M_PI;
  lng_2 = lng_2/180*M_PI;
  lat_2 = lat_2/180*M_PI;
  double delta_x = lng_2 - lng_1;

  azimuth = atan2(cos(lat_1)*tan(lat_2) - sin(lat_1)*cos(delta_x), sin(delta_x))/M_PI*180;
  // 北 0°, 東 90°, 南 180°, 西 270°に変換
  azimuth = 90 - azimuth;
  if( azimuth < 0){
      azimuth = 360 + azimuth;
  }
  
  return azimuth;
}

// 1-2の距離を返す
double Azimuth::calculation_distance(double lng_1, double lat_1,  double lng_2, double lat_2){
  lng_1 = lng_1/180*M_PI;
  lat_1 = lat_1/180*M_PI;
  lng_2 = lng_2/180*M_PI;
  lat_2 = lat_2/180*M_PI;
  double delta_x = lng_2 - lng_1;

  return R*acos(sin(lat_1)*sin(lat_2) + cos(lat_1)*cos(lat_2)*cos(delta_x));

}


// ゴール位置までの方位角を返す
void Azimuth::azimuth_to_goal(double lng_1, double lat_1, double* ret){

  *ret = calculation_azimuth(lng_1, lat_1, goal_lng, goal_lat);
}

// 2点(1->2)の方位角を返す 
void Azimuth::azimuth(double lng_1, double lat_1, double lng_2, double lat_2, double* ret){
  *ret = calculation_azimuth(lng_1, lat_1, lng_2, lat_2);
}


// ゴール位置までの距離を返す
void Azimuth::distance_to_goal(double lng_1, double lat_1, double* ret){
  *ret = calculation_distance(lng_1, lat_1, goal_lng, goal_lat);
 }

 // 2点間の距離を返す
void Azimuth::distance(double lng_1, double lat_1, double lng_2, double lat_2, double* ret){
  *ret = calculation_distance(lng_1, lat_1, lng_2, lat_2);
 }


// ゴール位置の設定
void Azimuth::set_goal(double lng, double lat){
  goal_lat = lat;
  goal_lng = lng;
  
}
