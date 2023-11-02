// biblioteca "LiquidCrystal.h", que é usada para controlar um display LCD.
#include <LiquidCrystal.h>

/* criada uma instância de LiquidCrystal chamada lcd
com a configuração dos pinos do Arduino para o display LCD */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Constante para o pino do sensor ultrassonico
#define PINO 8

/* Função que recebe um pino como argumento,
   configura o pino como saída, envia um pulso ultrassônico,
   lê a duração do retorno do pulso e retorna essa duração em microssegundos.*/

long lerSensor(int pino)
{
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
    delayMicroseconds(2);
    digitalWrite(pino, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino, LOW);
    pinMode(pino, INPUT);
    return pulseIn(pino, HIGH);
}

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
    // Pega o valor de retorno da funçao e multiplica para ter o valor em centimetros.
    int cm = 0.01723 * lerSensor(PINO);
    Serial.print(cm);
    Serial.println("cm");

    // Pequeno IF para corrigir um bug no display lCD
    if (cm < 100)
    {
        lcd.setCursor(5, 0);
        lcd.print(" ");

        if (cm < 10)
        {
            lcd.setCursor(4, 0);
            lcd.print(" ");
        }
    }

    // Configurando exibiçao no display LCD
    lcd.setCursor(0, 0);
    lcd.print("cm:");
    lcd.setCursor(3, 0);
    lcd.print(cm);

    delay(100);
}