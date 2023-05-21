#define MPU6050_DEFAULT_ADDRESS     0x68 // address pin low (GND), default for InvenSense evaluation board
#define OFFSETS  4294960742,   4294960814,   10352,   106,   97,   1
#define CalibrationLoops 8

String Json;

String GetJSONString(String sensorName, float Pitch, float Roll, float Yaw, int Thumb, int Index, int Middle, int Ring, int Pinky){

  StaticJsonDocument<1024> staticJsonDoc;
  //staticJsonDoc["name"] = sensorName;
  staticJsonDoc["pitch"] = Pitch;
  staticJsonDoc["roll"] = Roll;
  staticJsonDoc["yaw"] = Yaw;
  staticJsonDoc["thumb"] = Thumb;
  staticJsonDoc["index"] = Index;
  staticJsonDoc["middle"] = Middle;
  staticJsonDoc["ring"] = Ring;
  staticJsonDoc["pinky"] = Pinky;


  char SerializedJson[150]; 
  serializeJson(staticJsonDoc, SerializedJson);
  Serial.println(SerializedJson);
  return SerializedJson;
}


void SendValues (int16_t *gyro, int16_t *accel, int32_t *quat) {
  Quaternion q;
  VectorFloat gravity;

  float ypr[3] = { 0, 0, 0 };
  float xyz[3] = { 0, 0, 0 };
  float euler[3]; 
  mpu.GetQuaternion(&q, quat);
  mpu.GetGravity(&gravity, &q);
  mpu.GetYawPitchRoll(ypr, &q, &gravity);
  mpu.GetEuler(euler, &q);
  mpu.ConvertToDegrees(ypr, xyz);


  float P = euler[0] * 180 / M_PI;
  float R = euler[1] * 180 / M_PI;
  float Y = euler[2] * 180 / M_PI;


    String Json;
    Json = GetJSONString("hand", P, R, Y, Thumb, Index, Middle, Ring, Pinky);
    UDPSendData(Json);
}


void mpu_setup()
{
  
  // Setup the MPU
  int sdaPin = 21, 
  sclPin = 22;
  mpu.begin(sdaPin, sclPin);
  mpu.Set_DMP_Output_Rate_Hz(10);          // Set the DMP output rate from 200Hz to 5 Minutes.
  mpu.SetAddress(MPU6050_DEFAULT_ADDRESS); //Sets the address of the MPU.
  mpu.CalibrateMPU(CalibrationLoops);                      // Calibrates the MPU.
  mpu.load_DMP_Image(OFFSETS);                    // Loads the DMP image into the MPU and finish configuration.
  mpu.on_FIFO(SendValues);               // Set callback function that is triggered when FIFO Data is retrieved


}