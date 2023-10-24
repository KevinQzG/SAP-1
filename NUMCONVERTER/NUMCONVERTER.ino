#define NUMCONVERT 47


void setup() {
  DDRA = 0XFF;
  DDRB = 0xFF;
  DDRC = 0xFF;
  DDRF = 0x00;
  
  pinMode(HEX,INPUT);

  // put your setup code here, to run once:

}

void loop() {

  byte num = PINF;


  if(digitalRead(NUMCONVERT)){

    PORTA = getNdigit(1,num);
    PORTB = getNdigit(2,num);
    PORTC = getNdigit(3,num);
  }
  else{
    PORTA = 0x00;
    PORTB = num >> 4;
    PORTC = highByte((num << 12)) >> 4;
  }



  
  // put your main code here, to run repeatedly:

}

//Asumess The number has 3 digits max, FF = 255
int getNdigit(int digitPos, int num){

  int neededPos = 3 - digitPos;


  return (num / int(pow(10,neededPos))) % 10;

}
