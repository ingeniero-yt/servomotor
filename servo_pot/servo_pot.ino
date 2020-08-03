/*
 *      -----CONTROL DE SERVOMOTOR CON POTENCIÓMETRO-----
 * 
 * Por "Ingeniero en Casa"
 * https://www.youtube.com/channel/UCurfoG9YbFyQmxCLlxZVArg
 * 
 * La distribución y/o modificación del código es totalmente libre.
 */
 
#include <ESP32Servo.h>

Servo miServo;

#define servoPin 26     //Pin al que conectamos el cable naranja del servo.

#define potPin 4        //Pin al que conectamos la patilla central del potenciómetro.

void setup() 
{   
  miServo.attach(servoPin);
  miServo.write(0);     //Ángulo de giro en grados.
  
  pinMode(potPin,INPUT);
} 

void loop() {

  int valorPot = analogRead(potPin);                  //Lectura del conversor A/D en bits.
  int valorServo = map(valorPot, 0, 4095, 0, 180);    //Mapeado de valores:  [0..4095 ]  ->  [0..180]
  
  miServo.write(valorServo);

  delay(25);
  
  } 
