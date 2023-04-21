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

int bright=2000;
int verryBright=4095; 
int dim=0;
int bulb=0;

int columns[8] = {ColumnA,ColumnB,ColumnC,ColumnD,ColumnE,ColumnF,ColumnG,ColumnH};
int rows[5] = {RowOne,RowTwo,RowThree,RowFour,RowFive};
void setup() {

pinMode(RowOne, OUTPUT);
pinMode(RowTwo, OUTPUT);
pinMode(RowThree, OUTPUT);
pinMode(RowFour, OUTPUT);
pinMode(RowFive, OUTPUT);
Tlc.init();
}

void loop() {
  neuronSignal(RowOne);
  delay(50);
  rowsOff();
  sinapse(2);
  neuronSignal(RowTwo);
  delay(50);
  rowsOff();
  sinapse(1);
  rowsOff();
  neuronSignal(RowThree);
  delay(50);
  rowsOff();
  delay(1000);

  
  
}

void rowsOff(){
  for(int i=0;i<5;i++){
    digitalWrite(rows[i],LOW);
  }
}

int neuronSignal(int row){
  bulb=0;
  if(row==RowOne){      
    bulb=0;
    Tlc.set(columns[7],dim);
    Tlc.set(columns[6],dim);
    for(int i =1; i<7; i++){
      if(bulb==0){
        Tlc.set(columns[0],verryBright);
        }
      if(bulb==1){
        Tlc.set(columns[1],bright);
        Tlc.set(columns[0],bright/4);
      }
      if(bulb==6){
          Tlc.set(columns[6],bright);
          Tlc.set(columns[7],bright);
          Tlc.set(columns[5],bright/4);
          Tlc.set(columns[4],bright/8);
          Tlc.set(columns[3],dim);
        }
      else{
        for(int i =0; i<7; i++){
          Tlc.set(columns[i],dim);
          if(i == bulb){
            Tlc.set(columns[bulb],bright);
            Tlc.set(columns[bulb-1],bright/4);
            Tlc.set(columns[bulb-2],bright/8);
            }
          else {
            Tlc.set(columns[i],dim);
            }
          }  
       }
       bulb +=1;
      Tlc.update();
      delay(5);
      digitalWrite(row,HIGH);
      delay(200);
    }
    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright);
    Tlc.set(columns[5],bright/8);
    Tlc.set(columns[4],dim);
    Tlc.set(columns[3],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    delay(50);

    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    delay(100);
    
  }
  else if (row==RowTwo){
    for(int i =1; i<8; i++){
      if(bulb==0){
        Tlc.set(columns[0],verryBright);
        }
      if(bulb==1){
        Tlc.set(columns[1],bright);
        Tlc.set(columns[0],bright/4);
      }
      else{
        for(int i =0; i<8; i++){
          if(i ==bulb){
            Tlc.set(columns[bulb],bright);
            Tlc.set(columns[bulb-1],bright/4);
            Tlc.set(columns[bulb-2],bright/8);
          }
          else{
            Tlc.set(columns[i],dim);
          }
            }
      }
      bulb +=1;
      Tlc.update();
      delay(2);
      digitalWrite(row,HIGH);
      digitalWrite(RowFour,HIGH);
      delay(200);
    }
    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright/8);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    digitalWrite(RowFour,HIGH);
    delay(100);

    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    digitalWrite(RowFour,HIGH);
    delay(100);
  }
  else if (row==RowThree){
    for(int i =0; i<8; i++){
      if(bulb==0){
        Tlc.set(columns[0],bright);
        }
      if(bulb==1){
        Tlc.set(columns[1],bright);
        Tlc.set(columns[0],bright/4);
      }
      else{
        for(int i =0; i<8; i++){
          if(i ==bulb){
            Tlc.set(columns[bulb],bright);
            Tlc.set(columns[bulb-1],bright/4);
            Tlc.set(columns[bulb-2],bright/8);
          }
          else{
            Tlc.set(columns[i],dim);
          }
        }
      }
      bulb +=1;
      Tlc.update();
      delay(2);
      digitalWrite(row,HIGH);
      digitalWrite(RowFive,HIGH);
      delay(200);
      }
    Tlc.set(columns[6],bright/8);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    digitalWrite(RowFive,HIGH);
    delay(100);

    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(2);
    digitalWrite(row,HIGH);
    digitalWrite(RowFive,HIGH);
    delay(100);
    }
  }  

int sinapse(int neuronType){
  if(neuronType==1){
    for(int j=0; j<40;j++){
    digitalWrite(RowFive,LOW);
    digitalWrite(RowFour,LOW);
    digitalWrite(RowThree,LOW);
    digitalWrite(RowTwo,LOW);
    Tlc.set(ColumnA,dim);
    delay(2);
    Tlc.update();
    Tlc.set(ColumnH,verryBright);
    delay(2);
    Tlc.update();
    digitalWrite(RowFour,HIGH);
    digitalWrite(RowTwo,HIGH);          
    delay(2);
    digitalWrite(RowFour,LOW);
    digitalWrite(RowFive,LOW);
    digitalWrite(RowThree,LOW);
    digitalWrite(RowTwo,LOW);
    Tlc.set(ColumnH,dim);
    delay(2);
    Tlc.update();
    Tlc.set(ColumnA,verryBright);
    delay(2);
    Tlc.update();
    digitalWrite(RowFive,HIGH);
    digitalWrite(RowThree,HIGH);
    delay(2);
    }
  }
  if(neuronType==2){
    for(int j=0; j<40;j++){
    digitalWrite(RowFour,LOW);
    digitalWrite(RowOne,LOW);
    digitalWrite(RowTwo,LOW);
    digitalWrite(RowThree,LOW);
    digitalWrite(RowFive,LOW);
    Tlc.set(ColumnA,dim);
    delay(2);
    Tlc.update();
    Tlc.set(ColumnH,verryBright);
    Tlc.set(ColumnG,verryBright);
    delay(2);
    Tlc.update();
    digitalWrite(RowOne,HIGH);          
    delay(2);
    digitalWrite(RowFour,LOW);
    digitalWrite(RowOne,LOW);
    digitalWrite(RowTwo,LOW);
    digitalWrite(RowThree,LOW);
    digitalWrite(RowFive,LOW);
    Tlc.set(ColumnH,dim);
    Tlc.set(ColumnG,dim);
    delay(2);
    Tlc.update();
    Tlc.set(ColumnA,verryBright);
    delay(2);
    Tlc.update();
    digitalWrite(RowTwo,HIGH);
    digitalWrite(RowFour,HIGH);
    delay(2);
    }
  }
  }
