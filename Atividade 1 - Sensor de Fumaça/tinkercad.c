// Importando a biblioteca para o uso do display LCD
#include <LiquidCrystal_I2C.h>

// Pino analógico onde o sensor de gás está conectado
#define GAS A3

// Pino digital onde o alarme está conectado
#define SOM 8

/* Declarando um objeto chamado "lcd" da classe "LiquidCrystal_I2C".
O construtor da classe "LiquidCrystal_I2C" está sendo usado para inicializar o objeto. */
LiquidCrystal_I2C lcd(32, 16, 2);

void setup()
{
  // Inicializa a comunicação serial
  Serial.begin(9600);

  pinMode(GAS, INPUT);
  pinMode(SOM, OUTPUT);

  // Inicia e liga a luz de fundo do display
  lcd.init();
  lcd.backlight();
}

void loop()
{
  // Leitura do valor do sensor de gás
  int gas = analogRead(GAS);

  /* Tomada de decisão caso o
  valor do sensor do gás estaja muito algo*/
  if (gas > 500)
  {
    /* Configura para o ponto inicial do LCD
       e escreve "PERIGO"*/
    lcd.setCursor(0, 0);
    lcd.print("PERIGO!");

    // Liga e desliga o alarme
    tone(SOM, 1500);
    delay(500);
    noTone(SOM);
  }
  else
  {
    // Limpar tela display
    lcd.clear();
  }

  Serial.print("Valor do Sensor de Gas: ");
  Serial.println(gas);

  delay(1000);
}