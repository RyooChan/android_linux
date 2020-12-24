#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <fcntl.h>
#include <unistd.h>

#define FND_DEVICE "/dev/fpga_fnd"
#define MAX_DIGIT 4

int fpga_fnd(const char* str)
{
    int dev;
    unsigned char data[4];
    unsigned char retval;
    int i;
    int str_size;

    memset(data, 0, sizeof(data));

    str_size = (strlen(str));

    str_size = (strlen(str));
    if(str_size > MAX_DIGIT)
    {
        str_size = MAX_DIGIT;
    }

    for(i=0; i<str_size; i++)
    {
        if((str[i]<0x30)||(str[i])>0x39){
            return 1;
        }
        data[i] = str[i] - 0x30;
    }
    dev = open(FND_DEVICE, O_RDWR);
    if(dev<0){
        __android_log_print(ANDROID_LOG_INFO, "Device Open Error", "Driver = %s", str);
        return -1;
    }else {
        __android_log_print(ANDROID_LOG_INFO, "Device Open Success", "Driver = %d", str);
        write(dev, &data, 4);
        close(dev);
        return 0;
    }
}

JNIEXPORT jint JNICALL Java_com_example_puushswitch_MainActivity_ReceiveFndValue(JNIEnv *env, jobject thiz, jstring val)
{
    jint result;
    const  char * str = (*env)-> GetStringUTFChars(env, val, NULL);
    __android_log_print(ANDROID_LOG_INFO, "FpgaFndExample", " Value = %s", str);
    result = fpga_fnd(str);
    (*env) -> ReleaseStringUTFChars(env, val, str);

    return result;
}