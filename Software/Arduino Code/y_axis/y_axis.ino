#include <TM1637.h>

int CLK = 3;
int DIO = 2;
int DIO2 = 4;
int CLK2 = 5;
int DIO3 = 7;
int CLK3 = 8;
int DIO4 = 9;
int CLK4 = 10;
int DIO5 = 12;
int CLK5 = 13;

TM1637 tm(CLK,DIO);
TM1637 tm2(CLK2,DIO2);
TM1637 tm3(CLK3,DIO3);
TM1637 tm4(CLK4,DIO4);
TM1637 tm5(CLK5,DIO5);

void setup() {
  // put your setup code here, to run once:
  tm.init();
  tm2.init();
  tm3.init();
  tm4.init();
  tm5.init();
  tm.set(2);
  tm2.set(2);
  tm3.set(2);
  tm4.set(2);
  tm5.set(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  tm.display(0,4); //4500
  tm.display(1,5);
  tm.display(2,0);
  tm.display(3,0);
  
  tm2.display(0,6); //6000
  tm2.display(1,0);
  tm2.display(2,0);
  tm2.display(3,0);

  tm3.display(0,0); //0000
  tm3.display(1,0);
  tm3.display(2,0);
  tm3.display(3,0);

  tm4.display(0,1); //1500
  tm4.display(1,5);
  tm4.display(2,0);
  tm4.display(3,0);

  tm5.display(0,3); //3000
  tm5.display(1,0);
  tm5.display(2,0);
  tm5.display(3,0);
}
