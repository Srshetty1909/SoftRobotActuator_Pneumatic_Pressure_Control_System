#include "HX710Array.h"
int ci = 0, cd = 0;
int mode = 0;
int pressurevalve = 2;
int exhaustvalve = 3;
int cellvalve[4] = {4, 5, 6, 7};
long target[4] = {0, 0, 0, 0};
long error[4] = {0, 0, 0, 0};
long ptarget[4] = {0, 0, 0, 0};
int inputs[5] = {0, 0, 0, 0, 0};
int input, i = 0, j = 0, count = 0, clk = 8;
int valvestate[] = {1, 0, 0, 0, 0};
int douts[] = {9, 10, 11, 12};
long pressure[] = {0, 0, 0, 0};
long pascal[] = {0, 0, 0, 0};
HX710Array ps;
void setup() {
  // put your setup code here, to run once:
  pinMode(pressurevalve, OUTPUT);
  pinMode(exhaustvalve, OUTPUT);
  for(i = 0; i < 4; i++)
  {
    pinMode(cellvalve[i], OUTPUT);
  }
  
  Serial.begin(115200);
  ps.initialize(clk, 4, douts);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    input = Serial.read();
    inputs[count] = input;
    count = count + 1;
    if(count == 5)
    {
      count = 0;
    }  
  }
  for(i = 0; i < 4; i++)
  {
    ptarget[i] = map(inputs[i], 0, 100, 200, 1200);
  }  
  while( !ps.isReady() );
  ps.readAndSelectNextData( HX710_DIFFERENTIAL_INPUT_40HZ );
  for(i = 0; i < 4; i++)
  {
    pressure[i] = ps.getLastDifferentialInput( i );
    switch(i)
      {
        case 0:  pascal[i] = (pressure[i] - 4720000)/692.19;
                 break;
        case 1:  pascal[i] = (pressure[i] - 4650000)/830.8;
                 break;
        case 3:  pascal[i] = (pressure[i] - 5120000)/690.96;
                 break;
        case 2:  pascal[i] = (pressure[i] - 4810000)/715.72;
                 break;
  }
  }
  
  target[0] = 4720000 + (ptarget[0]*692.19); //map(ptarget[0], 0, 5300, 4720000, 8388607);
  target[1] = 4650000 + (ptarget[1]*830.8); //map(ptarget[1], 0, 4500, 4650000, 8388607);
  target[3] = 5120000 + (ptarget[2]*680.96); //map(ptarget[2], 0, 4800, 5120000, 8388607);
  target[2] = 4810000 + (ptarget[3]*715.72); //map(ptarget[3], 0, 5000, 4810000, 8388607);
  error[0] = 25 * 692.19;
  error[1] = 25 * 830.8;
  error[3] = 25 * 680.96;
  error[2] = 25 * 715.72;  
  
  
  if(inputs[4] == 1)
  {
    digitalWrite(pressurevalve, LOW);
    digitalWrite(exhaustvalve, HIGH);
    for(i = 0; i < 4; i++)
    {
      digitalWrite(cellvalve[i], HIGH);
    }
  }
  else
  {
    for(i = 0; i < 4; i++)
    {
        if(pascal[i] < (ptarget[i] - 20))
      {
        ci = ci + 1;
      }
      else if(pascal[i] > (ptarget[i] + 20))
      {
        cd = cd + 1;
      }
    }
    if(ci > 0)
    {
      digitalWrite(pressurevalve, HIGH);
      digitalWrite(exhaustvalve, LOW);
      for(i = 0; i < 4; i++)
      {
          if(pascal[i] < (ptarget[i] - 20))
        {
          digitalWrite(cellvalve[i], HIGH);
        }
        else
        {
          digitalWrite(cellvalve[i], LOW);
        }
      }
    }
    if((ci == 0) && (cd > 0))
    {
      digitalWrite(pressurevalve, LOW);
      digitalWrite(exhaustvalve, HIGH);
      for(i = 0; i < 4; i++)
      {
          if(pascal[i] > (ptarget[i] + 20))
        {
          digitalWrite(cellvalve[i], HIGH);
        }
        else
        {
          digitalWrite(cellvalve[i], LOW);
        }
      }
    }
    if((cd == 0) && (ci == 0))
    {
      digitalWrite(pressurevalve, LOW);
      digitalWrite(exhaustvalve, LOW);
      for(i = 0; i < 4; i++)
      {
        digitalWrite(cellvalve[i], LOW);
      }
    }
    cd = 0;
    ci = 0;
  }
  for(i = 0; i < 4; i++)
  {
    Serial.print(pascal[i]);
    Serial.print(ptarget[i]);

  }
  

}
