#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>

#define MY_T_SENSOR 100
#define MY_T_SENSOR_READ _IOR( MY_T_SENSOR, 0, int )
#define MY_T_SENSOR_WRITE _IOW( MY_T_SENSOR, 1, int )

int main(int argc, char **argv){
    int fd = open("/dev/tsensor_dev", O_RDWR);
    if(fd < 0){
        perror("Fail to open\n");
        return errno;
    }
    printf("open drv\n");
    char buf[100] = {0,};
    ioctl(fd, MY_T_SENSOR_READ, buf);
    printf("%s\n", buf);
    return 0;
}
