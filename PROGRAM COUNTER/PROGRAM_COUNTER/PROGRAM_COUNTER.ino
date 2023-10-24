// Constantes para los pines del Arduino
const int CP = 24;   // Contador positivo
const int CLR = 25;  // Reiniciar
const int CALLA = 26;
const int RTN = 17;  // Retornar

// Retraso en milisegundosF
const double retraso = 110;

// Contadores
int contador = 0;
int contador_return = 0;

void setup() {
  // Configurar los pines del Arduino como entradas o salidas
  // DDRF: Dirección del puerto F
  // DDRC: Dirección del puerto C
  DDRF = 0X00;  // Todos los pines del puerto F como entradas
  DDRC = 0xFF;  // Todos los pines del puerto C como salidas

  // Configurar los pines CP, CLR y RTN como entradas
  pinMode(CP, INPUT);
  pinMode(CLR, INPUT);
  pinMode(RTN, INPUT);
}

void loop() {
  // Incrementar el contador si el botón CP está presionado
  if (digitalRead(CP) == 1) {
    contador++;
    delay(retraso);
  }

  // Reiniciar el contador si el botón CLR está presionado
  if (digitalRead(CLR) == 1) {
    contador = 0;
    delay(retraso);
  }

  // Restaurar el contador al valor negativo si el botón RTN está presionado
  // y el contador negativo no es igual a -1
  if (digitalRead(RTN)) {
    contador = contador_return;
    contador_return = 0;
    delay(retraso);
  }

  if (digitalRead(CALLA)){
    contador_return = contador + 1;
    contador = PINF;
    delay(retraso);
  }

  // Mostrar el contador en el puerto C
  PORTC = contador;
}
