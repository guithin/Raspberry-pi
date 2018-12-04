#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>

#define MY_LED_NUM 100
#define MY_LED_WRITE _IOW ( MY_LED_NUM, 1, int )

int main(int argc, char **argv){
    int fd = open("/dev/led_dev", O_RDWR);
    if(fd < 0){
        perror("Fail to open\n");
        return errno;
    }
    printf("open drv\n");
    char buf[10] = {0,};
    printf("%d\n", argc);
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            ioctl(fd, MY_LED_WRITE, argv[i]);
        }
    }
    else{
        scanf("%s", buf);
    ioctl(fd, MY_LED_WRITE, buf);
    }
    return 0;
}
