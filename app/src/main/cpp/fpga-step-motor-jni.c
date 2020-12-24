#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <fcntl.h>
#include <unistd.h>
#include <asm/fcntl.h>

#define STEP_DEVICE "/dev/fpga_step_motor"

int fpga_step_motor(int action, int direction, int speed)
{
    int i;
    int dev;
    int str_siz;

    unsigned char motor_state[3];

    if (speed>250)
        speed = 250;
    else if (speed<5)
        speed = 5;

    memset(motor_state, 0, sizeof (motor_state));
    motor_state[0] = (unsigned char)action;
    motor_state[1] = (unsigned char)direction;
    motor_state[2] = (unsigned char)speed;

    dev = open(STEP_DEVICE, O_RDWR);
    if (dev<0) {
        __android_log_print(ANDROID_LOG_INFO, "Device Open Error", "Driver = %d", dev);
    } else {
        __android_log_print(ANDROID_LOG_INFO, "Device Open Success", "Driver = %d", dev);
        write (dev, motor_state, sizeof (motor_state));

        __android_log_print (ANDROID_LOG_INFO, "debug 1", "Driver = %d", dev);
        close(dev);
    }

    return 0;
}

jstring Java_com_example_puushswitch_MainActivity_SetMotorState(
        JNIEnv* env, jobject thiz, jint act, jint dir, jint spd )
{
    __android_log_print(ANDROID_LOG_INFO, "FpgaStepMotorExample", "SetMotor");
    fpga_step_motor(act, dir, spd);
    return 0;
}

