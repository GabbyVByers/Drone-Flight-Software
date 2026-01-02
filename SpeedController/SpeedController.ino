#include <Servo.h>

Servo SPEED_CONTROL_FL;
Servo SPEED_CONTROL_FR;
Servo SPEED_CONTROL_BL;
Servo SPEED_CONTROL_BR;

void setup() {
    SPEED_CONTROL_FL.attach(2);
    SPEED_CONTROL_FR.attach(3);
    SPEED_CONTROL_BL.attach(4);
    SPEED_CONTROL_BR.attach(5);

    SPEED_CONTROL_FL.writeMicroseconds(1000);
    SPEED_CONTROL_FR.writeMicroseconds(1000);
    SPEED_CONTROL_BL.writeMicroseconds(1000);
    SPEED_CONTROL_BR.writeMicroseconds(1000);

    delay(5000); 

    for (int i = 0; i < 500; i++){
        SPEED_CONTROL_FL.writeMicroseconds(1000 + i);
        SPEED_CONTROL_FR.writeMicroseconds(1000 + i);
        SPEED_CONTROL_BL.writeMicroseconds(1000 + i);
        SPEED_CONTROL_BR.writeMicroseconds(1000 + i);
        delay(20);
    }
}

void SHUT_DOWN(){
    while (1) {
        SPEED_CONTROL_FL.writeMicroseconds(1000);
        SPEED_CONTROL_FR.writeMicroseconds(1000);
        SPEED_CONTROL_BL.writeMicroseconds(1000);
        SPEED_CONTROL_BR.writeMicroseconds(1000);
    }
}

void loop() {
    unsigned int TIME = millis();
    if (TIME >= 2500) {
        SHUT_DOWN();
    }
}










