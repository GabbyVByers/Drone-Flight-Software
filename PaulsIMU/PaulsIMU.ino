#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 myIMU = Adafruit_BNO055();

#include <Servo.h>
Servo SPEED_CONTROLLER = Servo();

void setup() {
    Serial.begin(115200);
    myIMU.begin();
    myIMU.setExtCrystalUse(true);

    SPEED_CONTROLLER.attach(9,1000,2000);
    SPEED_CONTROLLER.write(180);
}

void loop() {
    uint8_t SYS_CALI, GYR_CALI, ACC_CALI, MAG_CALI;
    myIMU.getCalibration(&SYS_CALI, &GYR_CALI, &ACC_CALI, &MAG_CALI);
    
    imu::Vector<3> ACC_VECT = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
    Serial.print(ACC_VECT.x());
    Serial.print(",");
    Serial.print(ACC_VECT.y());
    Serial.print(",");
    Serial.println(ACC_VECT.z());

    SPEED_CONTROLLER.write(100);
}





