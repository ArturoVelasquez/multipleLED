#define StopWrite 2
#define LightTime 200
#define NeuronCoolOff 100



void rowsOff(){
  for(int i=0;i<5;i++){
    digitalWrite(rows[i],LOW);
  }
}

int actionPotential(int row){
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
      delay(StopWrite);
      digitalWrite(row,HIGH);
      delay(LightTime);
    }
    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright);
    Tlc.set(columns[5],bright/8);
    Tlc.set(columns[4],dim);
    Tlc.set(columns[3],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);

    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);
    
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
      delay(StopWrite);
      digitalWrite(row,HIGH);
      digitalWrite(RowFour,HIGH);
      delay(LightTime);
    }
    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],bright/8);
    Tlc.set(columns[5],dim);
    Tlc.set(columns[4],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    digitalWrite(RowFour,HIGH);
    delay(NeuronCoolOff);

    Tlc.set(columns[7],bright);
    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    digitalWrite(RowFour,HIGH);
    delay(NeuronCoolOff);
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
      delay(StopWrite);
      digitalWrite(row,HIGH);
      digitalWrite(RowFive,HIGH);
      delay(LightTime);
      }
    Tlc.set(columns[6],bright/8);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    digitalWrite(RowFive,HIGH);
    delay(NeuronCoolOff);

    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    digitalWrite(RowFive,HIGH);
    delay(NeuronCoolOff);
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
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnH,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowFour,HIGH);
      digitalWrite(RowTwo,HIGH);          
      delay(StopWrite);
      digitalWrite(RowFour,LOW);
      digitalWrite(RowFive,LOW);
      digitalWrite(RowThree,LOW);
      digitalWrite(RowTwo,LOW);
      Tlc.set(ColumnH,dim);
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnA,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowFive,HIGH);
      digitalWrite(RowThree,HIGH);
      delay(StopWrite);
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
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnH,verryBright);
      Tlc.set(ColumnG,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowOne,HIGH);          
      delay(StopWrite);
      digitalWrite(RowFour,LOW);
      digitalWrite(RowOne,LOW);
      digitalWrite(RowTwo,LOW);
      digitalWrite(RowThree,LOW);
      digitalWrite(RowFive,LOW);
      Tlc.set(ColumnH,dim);
      Tlc.set(ColumnG,dim);
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnA,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowTwo,HIGH);
      digitalWrite(RowFour,HIGH);
      delay(StopWrite);
      }
    }
    if(neuronType==3){
    for(int j=0; j<40;j++){
      digitalWrite(RowFive,LOW);
      digitalWrite(RowFour,LOW);
      digitalWrite(RowThree,LOW);
      digitalWrite(RowTwo,LOW);
      Tlc.set(ColumnA,dim);
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnH,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowTwo,HIGH);          
      delay(StopWrite);
      digitalWrite(RowFour,LOW);
      digitalWrite(RowFive,LOW);
      digitalWrite(RowThree,LOW);
      digitalWrite(RowTwo,LOW);
      Tlc.set(ColumnH,dim);
      delay(StopWrite);
      Tlc.update();
      Tlc.set(ColumnA,verryBright);
      delay(StopWrite);
      Tlc.update();
      digitalWrite(RowThree,HIGH);
      delay(StopWrite);
      }
    }
  }

int badActionPotential(int row){
  bulb=0;
  if(row==RowOne){      
    bulb=0;
    Tlc.set(columns[7],dim);
    Tlc.set(columns[6],dim);
    for(int i =1; i<7; i++){
      if(bulb==0){
        randomNumber = random(0, 4095);
        Tlc.set(columns[0],randomNumber);
        }
      if(bulb==1){
        randomNumber = random(0, 4095);
        Tlc.set(columns[1],randomNumber);
        randomDivisor = random(10,50);
        Tlc.set(columns[0],randomNumber/randomDivisor);
      }
      if(bulb==6){
          randomNumber = random(0, 2000);
          Tlc.set(columns[6],randomNumber);
          randomNumber = random(0, 2000);          
          Tlc.set(columns[7],randomNumber);
          randomNumber = random(0, 4095);
          randomDivisor = random(10,50);
          Tlc.set(columns[5],randomNumber/randomDivisor);
          randomNumber = random(0, 4095);
          randomDivisor = random(10,50);
          Tlc.set(columns[4],randomNumber/randomDivisor);
          Tlc.set(columns[3],dim);
        }
      else{
        for(int i =0; i<7; i++){
          Tlc.set(columns[i],dim);
          bulbRandom =random(2,5);
          if(i == bulb){
            Tlc.set(columns[bulbRandom],randomNumber);
            randomDivisor = random(10,50);
            Tlc.set(columns[bulbRandom-1],randomNumber/randomDivisor);
            randomDivisor = random(10,50);
            Tlc.set(columns[bulbRandom-2],randomNumber/randomDivisor);
            }
          else {
            Tlc.set(columns[i],dim);
            }
          }  
       }
       bulb +=1;
      Tlc.update();
      delay(StopWrite);
      digitalWrite(row,HIGH);
      delay(LightTime);
    }
    randomNumber = random(0, 2000);
    randomDivisor = random(10,50);
    Tlc.set(columns[7],randomNumber/randomDivisor);
    randomNumber = random(0, 2000);
    randomDivisor = random(10,50);
    Tlc.set(columns[6],randomNumber/randomDivisor);
    randomNumber = random(0, 4095);
    randomDivisor = random(10,50);
    Tlc.set(columns[5],randomNumber/randomDivisor);
    Tlc.set(columns[4],dim);
    Tlc.set(columns[3],dim);
    Tlc.set(columns[2],dim);
    Tlc.set(columns[1],dim);
    Tlc.set(columns[0],dim);        
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);

    randomNumber = random(0, 4095);
    Tlc.set(columns[7],randomNumber);
    randomNumber = random(0, 4095);
    Tlc.set(columns[6],randomNumber);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);
    
  }
  else if (row==RowTwo){
    for(int i =1; i<8; i++){
      if(bulb==0){
        randomNumber = random(0, 4095);
        randomDivisor = random(10,50);
        Tlc.set(columns[0],randomNumber);
        }
      if(bulb==1){
        randomNumber = random(0, 4095);        
        Tlc.set(columns[1],randomNumber);
        randomNumber = random(0, 4095);
        randomDivisor = random(10,50);        
        Tlc.set(columns[0],randomNumber/randomDivisor);
      }
      else{
        for(int i =0; i<8; i++){
          if(i ==bulb){
            bulbRandom =random(2,5);
            randomNumber = random(0, 4095);
            Tlc.set(columns[bulbRandom],randomNumber);
            randomNumber = random(0, 4095);
            randomDivisor = random(10,50);            
            Tlc.set(columns[bulbRandom-1],randomNumber/randomDivisor);
            randomNumber = random(0, 4095);
            randomDivisor = random(10,50);            
            Tlc.set(columns[bulbRandom-2],randomNumber/randomDivisor);
            }
          else{
            Tlc.set(columns[i],dim);
            }
          }
        }
      bulb +=1;
      Tlc.update();
      delay(StopWrite);
      digitalWrite(row,HIGH);
      delay(LightTime);
    }
    randomNumber = random(0, 4095);    
    Tlc.set(columns[7],randomNumber);
    randomNumber = random(0, 4095);
    randomDivisor = random(10,50);
    Tlc.set(columns[6],randomNumber/randomDivisor);
    Tlc.set(columns[5],dim);
    Tlc.set(columns[4],dim);
    Tlc.set(columns[3],dim);
    Tlc.set(columns[2],dim);
    Tlc.set(columns[1],dim);
    Tlc.set(columns[0],dim);    
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);

    randomNumber = random(0, 4095);
    Tlc.set(columns[7],randomNumber);
    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);
  }
  else if (row==RowThree){
    for(int i =0; i<8; i++){
      if(bulb==0){
        randomNumber = random(0, 4095);
        randomDivisor = random(10,50);
        Tlc.set(columns[0],randomNumber);
        }
      if(bulb==1){
        randomNumber = random(0, 4095);
        Tlc.set(columns[1],randomNumber);
        randomNumber = random(0, 4095);
        randomDivisor = random(10,50);
        Tlc.set(columns[0],randomNumber/randomDivisor);
      }
      else{
        for(int i =0; i<8; i++){
          if(i ==bulb){
            bulbRandom =random(2,5);
            randomNumber = random(0, 4095);
            Tlc.set(columns[bulbRandom],bright);
            randomNumber = random(0, 4095);
            randomDivisor = random(10,50);
            Tlc.set(columns[bulbRandom-1],randomNumber/randomDivisor);
            randomNumber = random(0, 4095);
            randomDivisor = random(10,50);
            Tlc.set(columns[bulbRandom-2],randomNumber/randomDivisor);
          }
          else{
            Tlc.set(columns[i],dim);
          }
        }
      }
      bulb +=1;
      Tlc.update();
      delay(StopWrite);
      digitalWrite(row,HIGH);
      delay(LightTime);
      }
    randomNumber = random(0, 4095);
    randomDivisor = random(10,50);      
    Tlc.set(columns[6],randomNumber/randomDivisor);
    Tlc.set(columns[5],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);
    
    Tlc.set(columns[6],dim);
    Tlc.update();
    delay(StopWrite);
    digitalWrite(row,HIGH);
    delay(NeuronCoolOff);
    }
  }
