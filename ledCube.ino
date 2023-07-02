int latchPin = 9;
int clockPin = 10;
int dataPin = 8;

int latchPin0 = 6;
int clockPin0 = 7;
int dataPin0 = 5;

void setup() {
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  initCube();
  fillCubeAnimate(400, 600);
  initCube();
}

void loop() {
  /*for(int i = 0; i < 5; i++)
    sweepVolumeHorizontal(120, 2);
  initCube();
  delay(200);
  //scatter(100);
  for(int i = 0; i < 5; i++)
    sweepVolumeVertical(150, 2);
  initCube();
  delay(200);*/

  fillCube();
  delay(5000);
  /*initCube();
  delay(200);

  for(int i = 0; i < 20000; i++)
    scatter(70);
  initCube();
  delay(200);*/
}

void initCube() {
  confRow1(LOW);
  confRow2(LOW);
  confRow3(LOW);
  confRow4(LOW);
  confRegister1(0);
  confRegister2(0);
}

void scatter(int speed) {
  confRow1((int)random(0, 2));
  confRow2((int)random(0, 2));
  confRow3((int)random(0, 2));
  confRow4((int)random(0, 2));

  confRegister1((int)random(1, 256));
  confRegister2((int)random(1, 256));

  delay(speed);
}

void fillCubeAnimate(int speed, int dimensionTransition) {
  /* 0-Dimension */
  confRow1(HIGH);
  confRow2(LOW);
  confRow3(LOW);
  confRow4(LOW);
  confRegister1(16);
  delay(dimensionTransition);

  /* 1-Dimension */
  confRegister1(16);
  delay(speed);
  confRegister1(48);
  delay(speed);
  confRegister1(112);
  delay(speed);
  confRegister1(240);
  delay(dimensionTransition);

  /* 2-Dimension */
  confRow2(HIGH);
  delay(speed);
  confRow3(HIGH);
  delay(speed);
  confRow4(HIGH);
  delay(dimensionTransition);

  /* 3-Dimension */
  confRegister1(255);
  delay(speed);
  confRegister2(30);
  delay(speed);
  confRegister2(255);
  delay(dimensionTransition * 2);
}

void fillCube() {
  confRow1(HIGH);
  confRow2(HIGH);
  confRow3(HIGH);
  confRow4(HIGH);
  confRegister1(255);
  confRegister2(255);
}
void sweepVolumeVertical(int speed, int transitionConst) {
  confRegister1(255);
  confRegister2(255);

  confRow1(LOW);
  confRow4(HIGH);
  delay(speed);
  confRow4(HIGH);
  confRow3(HIGH);
  delay(speed / transitionConst);
  confRow4(LOW);
  confRow3(HIGH);
  delay(speed);
  confRow3(HIGH);
  confRow2(HIGH);
  delay(speed / transitionConst);
  confRow3(LOW);
  confRow2(HIGH);
  delay(speed);
  confRow2(HIGH);
  confRow1(HIGH);
  delay(speed / transitionConst);
  confRow2(LOW);
  confRow1(HIGH);
  delay(speed);
  
  //confRow1(HIGH);
  //confRow4(HIGH);
  //delay(speed / transitionConst);

}

void sweepVolumeHorizontal(int speed, int transitionConst) {
  confRow1(HIGH);
  confRow2(HIGH);
  confRow3(HIGH);
  confRow4(HIGH);

  confRegister1(240);
  confRegister2(0);
  delay(speed);
  confRegister1(255);
  confRegister2(0);
  delay(speed / transitionConst);
  confRegister1(15);
  confRegister2(0);
  delay(speed);
  confRegister1(15);
  confRegister2(30);
  delay(speed / transitionConst);
  confRegister1(0);
  confRegister2(30);
  delay(speed);
  confRegister1(0);
  confRegister2(255);
  delay(speed / transitionConst);
  confRegister1(0);
  confRegister2(225);
  delay(speed);
  confRegister1(0);
  confRegister2(225);
  delay(speed);

  //confRegister1(240);
  //confRegister2(225);
  //delay(speed / transitionConst);
}

void confRow1(int state) {
  if(state == 1)
    analogWrite(A2, 255);
  else
    analogWrite(A2, 0);
}

void confRow2(int state) {
  if(state == 1)
    analogWrite(A3, 255);
  else
    analogWrite(A3, 0);
}

void confRow3(int state) {
  if(state == 1)
    analogWrite(A4, 255);
  else
    analogWrite(A4, 0);
}

void confRow4(int state) {
  if(state == 1)
    analogWrite(A5, 255);
  else
    analogWrite(A5, 0);
}

void confRegister1(int val) {
  digitalWrite(latchPin0, LOW);
  shiftOut(dataPin0, clockPin0, MSBFIRST, val);
  digitalWrite(latchPin0, HIGH);
}

void confRegister2(int val) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}
