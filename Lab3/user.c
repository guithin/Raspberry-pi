#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_LENGHT 256
static char receive[BUFFER_LENGHT];

int main(){
	int ret, fd;
	char stringToSend[BUFFER_LENGHT];

	fd = open("/dev/simple_char_dev", O_RDWR, 0777);
	if(fd < 0){
		perror("Failed to open the device...");
		return errno;
	}
	printf("Type in a short string to send to the kernel module:\n");
	scanf("%[^\n]%*c", stringToSend);
	printf("Writing message to the device [%s].\n", stringToSend);

	ret = write(fd, stringToSend, 9);
	if(ret < 0){
		perror("Failed to write the message to the device.");
		return errno;
	}

	printf("Reading from the device...\n");

	ret = read(fd, receive, 9);//fill
	
	if(ret < 0){
		perror("Failed to read the message from the device.");
		return errno;
	}
	printf("The received message is: [%s]\n", receive);
	printf("End of the program\n");
	close(fd);
	return 0;
}
