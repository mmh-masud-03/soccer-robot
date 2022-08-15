#define flmf 2
#define flmb 3
#define frmf 4
#define frmb 7
#define flms 5  // pwm
#define frms 6   //pwm
#define blmf 8
#define blmb 11
#define brmf 12
#define brmb 13
#define blms 9  //pwm
#define brms 10   //pwm
#define head_light A0
char x;
int spd = 250;
void setup() {
  pinMode(flmf, OUTPUT);
  pinMode(flmb, OUTPUT);
  pinMode(flms, OUTPUT);
  pinMode(frmf, OUTPUT);
  pinMode(frmb, OUTPUT);
  pinMode(frms, OUTPUT);
  pinMode(blmf, OUTPUT);
  pinMode(blmb, OUTPUT);
  pinMode(blms, OUTPUT);
  pinMode(brmf, OUTPUT);
  pinMode(brmb, OUTPUT);
  pinMode(brms, OUTPUT);
  pinMode(head_light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read();
    Serial.println(x);
    if ( x == 'R') motor(spd, spd);
    else if ( x == 'B') motor(-spd, spd);
    else if ( x == 'F') motor(spd, -spd);
    else if ( x == 'H') motor(0, spd);
    else if ( x == 'I') motor(spd, 0);
    else if ( x == 'G') motor(0, -spd);
    else if ( x == 'J') motor(-spd, 0);
    else if ( x == 'L') motor(-spd,-spd);
    else if ( x == 'S') motor(0,0);
    else if ( x == 'U') analogWrite(head_light, HIGH);
    else if ( x == 'u') analogWrite(head_light, LOW);
    else if ( x == '0') spd = 0;
    else if ( x == '1') spd = 25;
    else if ( x == '2') spd = 50;
    else if ( x == '3') spd = 75;
    else if ( x == '4') spd = 100;
    else if ( x == '5') spd = 125;
    else if ( x == '6') spd = 150;
    else if ( x == '7') spd = 175;
    else if ( x == '8') spd = 200;
    else if ( x == '9') spd = 225;
    else if ( x == 'q') spd = 253;  
    
  }
}

void motor(int a, int b){
  if(a>=0){
    digitalWrite(flmf, 1);
    digitalWrite(flmb, 0);
    digitalWrite(blmf, 1);
    digitalWrite(blmb, 0);
  }
  else{
    a=-a;
    digitalWrite(flmf, 0);
    digitalWrite(flmb, 1);
    digitalWrite(blmf, 0);
    digitalWrite(blmb, 1);
  }
  if(b>=0){
    digitalWrite(frmf, 1);
    digitalWrite(frmb, 0);
    digitalWrite(brmf, 1);
    digitalWrite(brmb, 0);
  }
  else{
    b=-b;
    digitalWrite(frmf, 0);
    digitalWrite(frmb, 1);
    digitalWrite(brmf, 0);
    digitalWrite(brmb, 1);
  }
  analogWrite(flms,a);
  analogWrite(frms,b);
  analogWrite(blms,a);
  analogWrite(brms,b);
}
