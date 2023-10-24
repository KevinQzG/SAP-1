const int LDA = 0;
const int OUT = 3;
const int HLT = 4;
const int ADD = 1;
const int SUB = 2;
const int MUL = 5;
const int RTN = 17;
const int DIV = 36;
const int CALL = 16;
const int DE = 38;
const int INS3 = 6;

const int ED = 52;
const int IRC =51;
const int ERC = 50;
const int IRLE1 = 10;
const int LTR = 11;



const int ADDALU = 21;
const int SUBALU = 20;
const int MULALU = 19;
const int DIVALU = 18;



const int LA = 22;
const int EA = 23;
const int LB = 24;
const int EI = 28;
const int EU = 29;
const int LI = 27;
const int CP = 32;
const int EP = 33;
const int CLR = 30;
const int ER = 31;
const int LO = 25;
const int LM = 26;
const int CALLA = 34;
const int RT = 35;
const int ODE = 53;

const double retraso = 100;

bool finish = false;
bool first = true;

void setup() {

  pinMode(LDA, INPUT);
  pinMode(ADD, INPUT);
  pinMode(DIV, INPUT);
  pinMode(SUB, INPUT);
  pinMode(OUT, INPUT);
  pinMode(HLT, INPUT);
  pinMode(MUL, INPUT);
  pinMode(RTN, INPUT);
  pinMode(CALL, INPUT);
  pinMode(DE, INPUT);
  pinMode(INS3,INPUT);

  pinMode(ADDALU, OUTPUT);
  pinMode(SUBALU,OUTPUT);
  pinMode(MULALU,OUTPUT);
  pinMode(DIVALU,OUTPUT);


  pinMode(ED, OUTPUT);
  pinMode(IRC, OUTPUT);
  pinMode(ERC, OUTPUT);
  pinMode(IRLE1, INPUT);
  pinMode(LTR, OUTPUT);
  

  pinMode(LA, OUTPUT);
  pinMode(EA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LO, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(EI, OUTPUT);
  pinMode(EU, OUTPUT);
  pinMode(CLR, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(CP, OUTPUT);
  pinMode(EP, OUTPUT);
  pinMode(CALLA, OUTPUT);
  pinMode(RT, OUTPUT);
  pinMode(ODE,OUT);

  digitalWrite(LA, LOW);
  digitalWrite(EA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LO, LOW);
  digitalWrite(LM, LOW);
  digitalWrite(LI, LOW);
  digitalWrite(EI, LOW);
  digitalWrite(EU, LOW);
  digitalWrite(CLR, LOW);
  digitalWrite(ER, LOW);
  digitalWrite(CP, LOW);
  digitalWrite(EP, LOW);
  digitalWrite(CALLA, LOW);
  digitalWrite(RT, LOW);
}

void loop() {

  if (!finish) {

    digitalWrite(EP, HIGH);
    digitalWrite(LM, HIGH);
    delay(retraso);
    digitalWrite(LM, LOW);
    digitalWrite(EP, LOW);

    digitalWrite(ER, HIGH);
    digitalWrite(LI, HIGH);
    delay(retraso);
    digitalWrite(LI, LOW);
    digitalWrite(ER, LOW);


    if (digitalRead(LDA) == HIGH) {

      digitalWrite(EI, HIGH);
      digitalWrite(LM, HIGH);
      delay(retraso);
      digitalWrite(LM, LOW);
      digitalWrite(EI, LOW);

      digitalWrite(ER, HIGH);
      digitalWrite(LA, HIGH);
      delay(retraso);
      digitalWrite(LA, LOW);
      digitalWrite(ER, LOW);

      digitalWrite(CP, HIGH);
      delay(retraso);
      digitalWrite(CP, LOW);

    } else if (digitalRead(MUL) == 1 || digitalRead(ADD) == 1 || digitalRead(SUB) == 1 || digitalRead(DIV) == 1) {


      digitalWrite(EI, HIGH);
      digitalWrite(LM, HIGH);
      delay(retraso);
      digitalWrite(LM, LOW);
      digitalWrite(EI, LOW);

      digitalWrite(ER, HIGH);
      digitalWrite(LB, HIGH);
      delay(retraso);
      digitalWrite(LB, LOW);

      digitalWrite(ER, LOW);
      delay(retraso);


      int activatedOp = 0;

      if(digitalRead(MUL)){

        digitalWrite(MULALU,HIGH);
        activatedOp = MULALU;

      }  if(digitalRead(ADD)){

        digitalWrite(ADDALU,HIGH);
        activatedOp = ADDALU;
        
      } if(digitalRead(SUB)){
        digitalWrite(SUBALU,HIGH);
        activatedOp = SUBALU;

      } if (digitalRead(DIV)){

        if(digitalRead(DE)){
          digitalWrite(ODE,HIGH);
          digitalWrite(LO,HIGH);
          delay(retraso);
          finish = true;
          return;
        }

        digitalWrite(DIVALU,HIGH);
        activatedOp = DIVALU;
      }

      



      digitalWrite(EU, HIGH);
      digitalWrite(LA, HIGH);
      delay(retraso);
      digitalWrite(LA, LOW);
      digitalWrite(activatedOp, LOW);
      digitalWrite(EU, LOW);

      digitalWrite(CP, HIGH);
      delay(retraso);
      digitalWrite(CP, LOW);
      

    } else if (digitalRead(OUT) == 1) {

      digitalWrite(EA, HIGH);
      digitalWrite(LO, HIGH);
      delay(retraso);
      digitalWrite(LO, LOW);
      digitalWrite(EA, LOW);

      digitalWrite(CP, HIGH);
      delay(retraso);
      digitalWrite(CP, LOW);

    } else if (digitalRead(HLT) == HIGH) {
      finish = true;

    } else if (digitalRead(CALL) == 1) {

      digitalWrite(EI, HIGH);
      digitalWrite(CALLA, HIGH);
      delay(retraso);
      digitalWrite(CALLA, LOW);
      digitalWrite(EI, LOW);

    } else if (digitalRead(RTN) == 1) {

      digitalWrite(RT, HIGH);
      delay(retraso);
      digitalWrite(RT, LOW);
    }
    else if(digitalRead(INS3)){

      while (1) {


        digitalWrite(ED, HIGH);
        digitalWrite(LB, HIGH);
        delay(retraso);
        digitalWrite(LB, LOW);
        digitalWrite(ED, LOW);
        digitalWrite(DIVALU, HIGH);
        digitalWrite(EU, HIGH);
        delay(retraso);
        digitalWrite(LA, HIGH);
        delay(retraso);
        digitalWrite(LA, LOW);
        digitalWrite(DIVALU, LOW);
        digitalWrite(EU, LOW);
        digitalWrite(IRC, HIGH);
        delay(retraso);
        digitalWrite(IRC, LOW);
        digitalWrite(EA, HIGH);
        digitalWrite(LTR, HIGH);
        delay(retraso);
        digitalWrite(LTR,LOW);
        digitalWrite(EA, LOW);

        if(digitalRead(IRLE1)){
          digitalWrite(ERC,HIGH);
          digitalWrite(LA, HIGH);
          delay(retraso);
          digitalWrite(LA, LOW);
          digitalWrite(ERC, LOW);
          break;
        }

      
      }

     digitalWrite(CP, HIGH);
      delay(retraso);
      digitalWrite(CP, LOW);

    }
  }
}
