/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Francisco Barillas
 * Carnet: 2019376
*/
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C


//Directivas de preprocesador
#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define TRIG 11
#define ECHO 12
int DISTANCIA;
long T;
LiquidCrystal_I2C LCD_FRANCISCO_BARILLAS(Direccion_LCD, COLUMNAS, FILAS);
//BLOQUE
byte BLOQUE[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
  };
void setup()
{
  LCD_FRANCISCO_BARILLAS.begin(16, 2);
  LCD_FRANCISCO_BARILLAS.createChar(1, BLOQUE);
  LCD_FRANCISCO_BARILLAS.write(1);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  LCD_FRANCISCO_BARILLAS.init();
  LCD_FRANCISCO_BARILLAS.backlight();
}


void loop()
{
  MEDIDA();
  SENSOR();
}
int MEDIDA(){ 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  T = pulseIn(ECHO, HIGH);
  DISTANCIA = T/59;
  delay(50);
  return DISTANCIA;
}
int SENSOR(){
   if( DISTANCIA > 50){
    LCD_FRANCISCO_BARILLAS.setCursor(7,0);
    LCD_FRANCISCO_BARILLAS.print("50");
    LCD_FRANCISCO_BARILLAS.setCursor(0,1);
    LCD_FRANCISCO_BARILLAS.print("     LIBRE      ");
    LCD_FRANCISCO_BARILLAS.setCursor(3,0);
    LCD_FRANCISCO_BARILLAS.print("    ");
    LCD_FRANCISCO_BARILLAS.setCursor(9,0);
    LCD_FRANCISCO_BARILLAS.print("    ");
    //Bloques asignados
    LCD_FRANCISCO_BARILLAS.setCursor(0,0);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.setCursor(13,0);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
  }
  if( DISTANCIA == 30 ){
    LCD_FRANCISCO_BARILLAS.setCursor(7,0);
    LCD_FRANCISCO_BARILLAS.print("30");
    LCD_FRANCISCO_BARILLAS.setCursor(0,1);
    LCD_FRANCISCO_BARILLAS.print("     CUIDADO      ");
    LCD_FRANCISCO_BARILLAS.setCursor(5,0);
    LCD_FRANCISCO_BARILLAS.print("  ");
    LCD_FRANCISCO_BARILLAS.setCursor(9,0);
    LCD_FRANCISCO_BARILLAS.print("  ");
    LCD_FRANCISCO_BARILLAS.setCursor(0,0);
    //Bloques asignados
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.setCursor(11,0);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
  }
  if( DISTANCIA == 10){
    LCD_FRANCISCO_BARILLAS.setCursor(7,0);
    LCD_FRANCISCO_BARILLAS.print("10");
    LCD_FRANCISCO_BARILLAS.setCursor(0,1);
    LCD_FRANCISCO_BARILLAS.print("      ALTO      ");
    LCD_FRANCISCO_BARILLAS.setCursor(0,0);
    //Bloques asignados
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.setCursor(9,0);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    LCD_FRANCISCO_BARILLAS.write(1);
    
  }
  return 0;
 }
 
