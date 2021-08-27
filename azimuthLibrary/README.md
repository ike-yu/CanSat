# 方位角計算ライブラリ

参考：https://keisan.casio.jp/exec/system/1257670779

## 利用例

現在地から目的地への方位角(tmp1)と距離(tmp2)を計算する.


```c
#include "azimuthLibrary.hpp"

double now_lat = 35.6544; // 現在地 緯度
double now_lng = 139.74477; // 現在地　経度
double goal_lat = 21.4225; // 目的地 緯度
double goal_lng = 39.8261; // 目的値 経度

double tmp1, tmp2;       

Azimuth azimuth = Azimuth();
// 方法1
tmp1 = azimuth.calculation_azimuth(now_lng, now_lat, goal_lng, goal_lat);
tmp2 = azimuth.calculation_distance(now_lng, now_lat, goal_lng, goal_lat);

// 方法2
// 目的地を設定
azimuth.set_goal(goal_lng, goal_lat);
azimuth.azimuth_to_goal(now_lng, now_lat, &tmp1);
azimuth.distance_to_goal(now_lng, now_lat, &tmp2);

// 方法3
azimuth.azimuth(now_lng, now_lat, goal_lng, goal_lat, &tmp1);
azimuth.distance(now_lng, now_lat, goal_lng, goal_lat, &tmp2);
```
