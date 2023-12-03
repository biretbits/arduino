#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h> 

const int rs = 0, en = 1, d0 = 2, d1 = 3, d2 = 4, d3 = 5; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d0, d1, d2, d3);

Adafruit_NeoPixel tira = Adafruit_NeoPixel(64,6,NEO_GRB + NEO_KHZ800);
void setup() {
  tira.begin();
  tira.show();
  
  //Serial.begin(9600);
  lcd.begin(20, 4); //16*2 LCD display a usar
  lcd.clear();
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print("IMAGINA Y"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("Rojo: 255"); //Display a intro message
  lcd.setCursor(0, 2);   // set the cursor to column 0, line 1
  lcd.print("Azul: 255"); //Display a intro message

  lcd.setCursor(0, 3);   // set the cursor to column 0, line 1
  lcd.print("Verde: 255"); //Display a intro message
  
  lcd.setCursor(15, 1);   // set the cursor to column 0, line 1
  lcd.print("*"); //Display a intro message
  
  pinMode(7,1);
  pinMode(7,0x0);//bajar
  pinMode(8,1);
  pinMode(8,0x0);//subir
  pinMode(9,1);
  pinMode(9,0x0);//aumentar
  pinMode(10,1);
  pinMode(10,0x0);//disminuir

}
int posicion = 1;
int fin = 0;
int precioAbajo = 0;
int act = 0;int rojo = 255;int verde = 255;int azul =255;
void loop() {
  
  int bajar = digitalRead(7);
  int subir = digitalRead(8);
  
  int dis = digitalRead(10);
  int aum = digitalRead(9);
  
  if(bajar == 0){
    if(posicion==1){
      posicion=2;
    }else
    if(posicion==2){
      posicion=3;
    }
  }
  if(subir == 0){
    if(posicion==1){
      posicion=1;
    }else
    if(posicion==2){
      posicion=1;
    }else if(posicion == 3){
      posicion = 2;
    }
  }
  if(aum == 0){
    aument();
  }
  if(dis == 0){
    dismi();
  }
  cursorr(posicion);
  encenderRGB();
  delay(150);
}

void cursorr(int pos){
  for(int i = 0;i<4;i++){
    lcd.setCursor(15, i);   // set the cursor to column 0, line 1
    lcd.print(" "); //Display a intro message
  }
  lcd.setCursor(15, pos);   // set the cursor to column 0, line 1
  lcd.print("*"); //Display a intro message
}

void aument(){
  if(posicion == 1){
    for(int i = 0;i<12;i++){
      lcd.setCursor(i, 1);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(rojo < 255){
      rojo++;
    }
    if(rojo == 255){
      rojo = 255;
    }
    lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
    lcd.print("Rojo: "); //Display a intro message
    lcd.print(rojo);

  }
  if(posicion == 2){
   for(int i = 0;i<12;i++){
      lcd.setCursor(i, 2);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(verde < 255){
      verde++;
    }
    if(verde == 255){
      verde = 255;
    }
    lcd.setCursor(0, 2);
    lcd.print("Verde: "); //Display a intro message
    lcd.print(verde);

  }
  if(posicion == 3){
   for(int i = 0;i<12;i++){
      lcd.setCursor(i, 3);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(azul < 255){
      azul++;
    }
    if(azul == 255){
      azul = 255;
    }
    lcd.setCursor(0, 3);
    lcd.print("Azul: "); //Display a intro message
    lcd.print(azul);
  }
}

void dismi(){
  if(posicion == 1){
    for(int i = 0;i<12;i++){
      lcd.setCursor(i, 1);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(rojo <= 0){
      rojo = 0;
    }else{
      rojo--;
    }
    lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
    lcd.print("Rojo: "); //Display a intro message
    lcd.print(rojo);

  }
  if(posicion == 2){
   for(int i = 0;i<12;i++){
      lcd.setCursor(i, 2);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(verde <= 0){
      verde = 0;
    }else
    {  verde--;
    }
    lcd.setCursor(0, 2);   // set the cursor to column 0, line 1
    lcd.print("Verde: "); //Display a intro message
    lcd.print(verde);
    
  }
  if(posicion == 3){
   for(int i = 0;i<12;i++){
      lcd.setCursor(i, 3);   // set the cursor to column 0, line 1
      lcd.print(" "); //Display a intro message
    }
    if(azul <= 0){
      azul = 0;
    }else{
      azul--;
    }
    lcd.setCursor(0, 3);   // set the cursor to column 0, line 1
    lcd.print("Azul: "); //Display a intro message
    lcd.print(azul);
  }

}

void encenderRGB(){
  for(int i = 0;i<65;i++){
    tira.setPixelColor(i,rojo,verde,azul);
  }
  tira.show();
}
