/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final - Segundo Bimestre
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 26 de mayo
   
*/

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define led1 6
#define led2 7
#define led3 8
#define f1_teclado A0
#define f2_teclado A1
#define f3_teclado A2
#define f4_teclado A3
#define c1_teclado 2
#define c2_teclado 3
#define c3_teclado 4
#define c4_teclado 5
#define tiempo1 delay(1000);
#define tiempo2 delay(250);
#define tiempoJ delay(3000);
#define tiempoServo delay(2000);
#define B 10
#define C 11
#define D 12

Servo servoSteven;



const byte filas_teclado = 4;
const byte columnas_teclado = 4;

char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};


Keypad instructions = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);

void setup()
{
  Serial.begin(9600);
  servoSteven.attach(9);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("Steven");
  lcd.setCursor(0,1);
  lcd.print("Proyecto final");
  
}



void loop()
{
  char numero = instructions.getKey();
  
  if(numero)
  {
    Serial.print("La instruccion pedida es: "); 
    Serial.println(numero);    


    switch(numero)
    {
      case('1'):
      {
        for(int subida = 1; subida < 100; subida++){
        Serial.println(subida);
        tiempo2
          if(subida == 99){
          Serial.println("0");
         }
        }
      break;
      }
      case('2'):
      {
        for(int bajada = 98; bajada > -1; bajada--){
        Serial.println(bajada);
        tiempo2
          if(bajada == 0){
          Serial.println("99");
         }
        }
      break;
      }
      case('3'):
      {
        digitalWrite(led1, HIGH);
        tiempo2
        digitalWrite(led2, HIGH);
        tiempo2
        digitalWrite(led1, LOW);
        tiempo2
        digitalWrite(led3, HIGH);
        tiempo2
        digitalWrite(led2, LOW);
        tiempo2
        digitalWrite(led3, LOW);
        tiempo2
        digitalWrite(led3, HIGH);
        tiempo2
        digitalWrite(led2, HIGH);
        tiempo2
        digitalWrite(led3, LOW);
        tiempo2
        digitalWrite(led1, HIGH);
        tiempo2
        digitalWrite(led2, LOW);
        tiempo2
        digitalWrite(led1, LOW);
        tiempo2
      break;
      }
      case('4'):
      {
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        tiempoJ
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
      break;
      }
      case('5'):
      {
        servoSteven.write(180);
        tiempoServo
        servoSteven.write(0);
      break;
      }
    }
  }
}