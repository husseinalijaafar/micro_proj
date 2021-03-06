/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-19 15:46:13
 * @LastEditors: Changhua
 * @Description: SmartRobot robot tank
 * @FilePath: 
 */
#ifndef _ApplicationFunctionSet_xxx0_H_
#define _ApplicationFunctionSet_xxx0_H_

#include <Arduino.h>

class ApplicationFunctionSet
{
public:
  void ApplicationFunctionSet_Init(void);
  float ApplicationFunctionSet_Tracking(void);           //循迹
  void ApplicationFunctionSet_SensorDataUpdate(void);   //传感器数据更新
  void ApplicationFunctionSet_SerialPortDataAnalysis(void);
  float Sensor_Left(void);
  float Sensor_Right(void);
  float Sensor_Mid(void);
  bool Sensor_Mid_Tripped(void);
  bool Sensor_Right_Tripped(void);
  bool Sensor_Left_Tripped(void);
  void LinearControl(int i);
  
private:
  volatile float TrackingData_L;       //循迹数据
  volatile float TrackingData_M;       //循迹数据
  volatile float TrackingData_R;

  boolean TrackingDetectionStatus_R = false;
  boolean TrackingDetectionStatus_M = false;
  boolean TrackingDetectionStatus_L = false;

public:
  boolean Car_LeaveTheGround = true;
  boolean Car_CrossFinishLine = false;

public:
  uint16_t TrackingDetection_S = 100; //150 dat
  uint16_t TrackingDetection_E = 850;
  uint16_t TrackingDetection_V = 950; //950
  uint16_t linetrackval = 0;
};
extern ApplicationFunctionSet Application_FunctionSet;
#endif
