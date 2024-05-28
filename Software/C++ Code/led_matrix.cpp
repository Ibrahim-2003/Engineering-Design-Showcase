#include <iostream>
#include <stdio.h>
#include <string>

const int register_count = 19;
const int led_count = 7*7; // 7x7 matrix

// Matrix for RGB LED pins, ordered as leds[led#][r,g,b]
int leds[led_count][3] = {0};

bool registers[8*register_count];

void makeRed(int led){
    leds[led][0] = 255;
    leds[led][1] = 0;
    leds[led][2] = 0;
}

void makeGreen(int led){
    leds[led][0] = 0;
    leds[led][1] = 255;
    leds[led][2] = 0;
}

void makeBlue(int led){
    leds[led][0] = 0;
    leds[led][1] = 0;
    leds[led][2] = 255;
}

void makeYellow(int led){
    leds[led][0] = 0;
    leds[led][1] = 255;
    leds[led][2] = 255;
}

void turnOffLed(int led){
    leds[led][0] = 0;
    leds[led][1] = 0;
    leds[led][2] = 0;
}

int main(){
    // Set LED #4 to red
    leds[4][0] = 255;

    printf("LED #\tRed\tGreen\tBlue\n\n");
    for(int i=0; i<led_count; i++){
        if(i<=15 && i>=0){
            makeRed(i);
        }else if(i<=30 && i>15){
            makeGreen(i);
        }else if(i<=45 && i>30){
            makeBlue(i);
        }else{
            makeYellow(i);
        }
        printf("LED %d\t%d\t%d\t%d\n",i+1,leds[i][0],leds[i][1],leds[i][2]);
    }

    std::string x;

    std::cin >> x;

    return 0;
}