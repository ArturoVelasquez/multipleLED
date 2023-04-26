#include "Tlc5940.h"

#define ColumnA 0
#define ColumnB 1
#define ColumnC 2
#define ColumnD 3
#define ColumnE 4
#define ColumnF 5
#define ColumnG 6
#define ColumnH 7

#define RowOne 4
#define RowTwo 7
#define RowThree 8
#define RowFour 6
#define RowFive 5
#define buttonNeuron 12

int bright=2000;
int verryBright=4095; 
int dim=0;
int bulb=0;
int randomNumber=0;
int randomDivisor=0;
int bulbRandom=0;
int buttonState;

int columns[8] = {ColumnA,ColumnB,ColumnC,ColumnD,ColumnE,ColumnF,ColumnG,ColumnH};
int rows[5] = {RowOne,RowTwo,RowThree,RowFour,RowFive};
void setup() {
  pinMode(RowOne, OUTPUT);
  pinMode(RowTwo, OUTPUT);
  pinMode(RowThree, OUTPUT);
  pinMode(RowFour, OUTPUT);
  pinMode(RowFive, OUTPUT);
  pinMode(buttonNeuron,INPUT);
  Tlc.init();
  randomSeed(42);
}

void loop() {
  buttonState = digitalRead(buttonNeuron);
  for(int i ; i<3; i++){
    actionPotential(RowOne);
    delay(50);
    rowsOff();
    sinapse(2);
    actionPotential(RowTwo);
    delay(50);
    rowsOff();
    sinapse(1);
    rowsOff();
    actionPotential(RowThree);
    delay(50);
    rowsOff();
    delay(1000);
  }
  for(int j; j<3; j++){
    badActionPotential(RowOne);
    delay(50);
    rowsOff();
    sinapse(2);
    rowsOff();
    badActionPotential(RowTwo);
    delay(50);
    rowsOff();
    sinapse(3);
    rowsOff();
    badActionPotential(RowThree);
    delay(50);
    rowsOff();
    delay(1000);
  }

}
