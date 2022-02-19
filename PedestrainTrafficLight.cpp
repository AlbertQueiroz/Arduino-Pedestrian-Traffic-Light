// C++ code
//

int conta;

byte displaySeteSeg[10][7] = { 
  
 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,1,0,1,1 }   //DIGITO 9
 
};

void setup() {
  // Sinal Pedestre
  pinMode(1, INPUT); // Botão
  pinMode(9, OUTPUT); // Sinal verde pedestre
  pinMode(10, OUTPUT); // Sinal vermelho pedestre
  
  // Sinal Carros
  pinMode(11, OUTPUT); // Sinal verde carros
  pinMode(12, OUTPUT); // Sinal amarelo carros
  pinMode(13, OUTPUT); // Sinal vermelho carros
  
  // Display de 7 Segmentos
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
 
  // inicializa display com número 0
  conta = 0;
  incrementDisplay(conta);
    
}

void loop() {
  // Se o botão estiver apertado executa a passagem de pedestres
  if (digitalRead(1) == LOW) {
	countToNine();
    pedestrianTrafficLightGreen();
  } else {
  	carTrafficLight();
  }
}

void carTrafficLight() {
  pedestrianTrafficLightRed();
  carTrafficLightGreen();
  delay(3000); // Espera 3 segundos
  carTrafficLightYellow();
  delay(1000); // Espera 1 segundo
  carTrafficLightRed();
  delay(2000); // Espera 2 segundos
}

void pedestrianTrafficLightGreen() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void pedestrianTrafficLightRed() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void carTrafficLightGreen() {
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void carTrafficLightYellow() {
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
}

void carTrafficLightRed() {
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}

void countToNine() {
	delay(1000);
    conta++; //incremento

    if(conta == 10){ //Se passar de 9 reseta o display para 0
      conta = 0; 
    }
    incrementDisplay(conta);
}

void incrementDisplay(byte digito){ //função para acionar o display com o digito correspondente
  byte pino = 2;
   
  //Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos){ 
    digitalWrite(pino, !displaySeteSeg[digito][contadorSegmentos]);
    ++pino; 
  }
}