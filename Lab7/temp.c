#include<wiringPi.h>
#include<lcd.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

#define LCD_RS 11
#define LCD_E 10
#define LCD_D4 6
#define LCD_D5 5
#define LCD_D6 4
#define LCD_D7 1

int main(){
    int lcd;
    wiringPiSetup();
    if(lcd=lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)){
        printf("lcd init fail\n");
        return -1;
    }
    
    while(1){
        lcdPosition(lcd, 0, 0);
        time_t t=time(NULL);
        struct tm tm = *localtime(&t);
        char buf[100]={};
	if(tm.tm_sec == 0){
		lcdClear(lcd);
	}
        sprintf(buf, "%d-%d %d:%d:%d", tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        lcdPuts(lcd, buf);
        usleep(100000);
    }
    return 0;
}
