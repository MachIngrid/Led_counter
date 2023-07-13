#include "LiquidCrystal_I2C.h"
#include "Wire.h" 
#include "Ultrasonic.h"

#define col 16
#define lin  2
#define ende  0x27

LiquidCrystal_I2C lcd(ende,col,lin);  //Configura o display
HC_SR04 sensor1(12,13);             //Configura os pinos sensor ultrassonico (Trigger,Echo)
int x = 0;
void setup() {
  lcd.init();                       // Inicializa o LCD
  lcd.backlight();                  // Liga o backlight do LCD
}

void loop() {

  lcd.setCursor(1, 0);
  lcd.print("Contagem :"+String(x));  
  
  while (sensor1.distance() > 3){
    lcd.setCursor(1, 0);
   lcd.print("Contagem :"+String(x));  
  }
  x = x+1;
  delay(2000);
  
  lcd.clear(); 
                      
}