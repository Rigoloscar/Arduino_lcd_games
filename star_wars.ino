    #include<Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 6, 5, 4, 3); 


byte TIEfighter [8]        
{ 0b00000,
  0b10001,
  0b10001,
  0b10101,
  0b11011,
  0b10101,
  0b10001,
  0b10001,
};

byte XWing [8]      
{
  0b00000,
  0b00000,
  0b00100,
  0b00100,
  0b10101,
  0b11111,
  0b11111,
  0b10101,
};

byte Xwingfuego [8]
{
  0b00100,
  0b00000,
  0b00100,
  0b00100,
  0b10101,
  0b11111,
  0b11111,
  0b10101,
};

byte TIEfire [8]
{
  0b11111,
  0b01110,
  0b01110,
  0b01010,
  0b00100,
  0b01010,
  0b01110,
  0b01110,
};

byte s [8]      
{
  0b00000,
  0b00111,
  0b01111,
  0b01100,
  0b01100,
  0b11100,
  0b11000,
  0b00000,
};

byte t [8]      
{
  0b00000,
  0b11111,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};

byte a [8]      
{
  0b00000,
  0b00100,
  0b01110,
  0b11011,
  0b10001,
  0b11111,
  0b10001,
  0b00000,
};

byte r [8]      
{
 0b00000,
 0b11110,
  0b11001,
  0b11001,
  0b11110,
  0b11100,
  0b10111,
  0b00000,
};

 
int boton1 = 2;
int boton2 = 7 ;
int Xnave = 8;
int state1 = 0;
int state2 = 0;
const int Time= 150;
int Xcaza = 8;
int randomcaza1 = 0;
int juego = false;
int caza = true;
int buzzerPin = 9;
int contador = 20;



void setup() {
  
 lcd.begin(16,2);
 pinMode(boton1, INPUT);
 pinMode(boton2, INPUT);
 pinMode(buzzerPin, OUTPUT);
 lcd.createChar(1, TIEfighter);
 lcd.createChar(2,XWing);
 lcd.createChar(3, Xwingfuego);
 lcd.createChar(4, TIEfire);
 lcd.createChar(5, s);
 lcd.createChar(6, t);
 lcd.createChar(7, a);
 lcd.createChar(8, r);
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.write(5);
 lcd.write(6);
 lcd.write(7);
 lcd.write(8);
 lcd.setCursor(8, 0);
 lcd.write("w");
 lcd.write(7);
 lcd.write(8);
 lcd.write(5);
 lcd.setCursor(0, 1);
 lcd.write("IMPERIAL INVADER");
 delay(3000);
 lcd.clear();
 lcd.setCursor(8, 0);
 caza = true;
 juego = true;
 
}



void loop() {
 state1=digitalRead(boton1);
 state2=digitalRead(boton2);

if(caza==true&&juego==true){
  Xcaza = random(1, 13);
  lcd.setCursor(Xcaza, 0);
  lcd.write(1);
  caza = false;
}
else if(contador==0){
 juego==false;
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.write("*CONGRATULATION*");
 lcd.setCursor(0, 1);
 lcd.write("rebel flote wins");
 exit(0); 
} 
else if(state1==HIGH&&Xnave<15&&state2==LOW&&juego==true){
  Xnave++;
  lcd.setCursor(Xnave,1);
  lcd.write(byte(2));
  lcd.setCursor(Xnave-1,1);
  lcd.print(" ");
  delay(Time);
}
else if(state1==LOW&&Xnave>0&&state2==HIGH&&juego==true){
  Xnave--;
  lcd.setCursor(Xnave, 1);
  lcd.write(byte(2));
  lcd.setCursor(Xnave+1,1);
  lcd.print(" ");
  delay(Time);  
}
else if(state1==HIGH&&Xnave>0&&Xnave<15&&state2==HIGH&&juego==true){
  tone(buzzerPin,700,100);
  lcd.setCursor(Xnave, 1);
  lcd.write(byte(3));
  lcd.print(" ");
  delay(Time);
  lcd.print(" ");
  lcd.setCursor(Xnave, 1);
  lcd.write(byte(2));
  
   if(Xnave == Xcaza) {
    tone(buzzerPin,800,200);
    lcd.setCursor (Xcaza, 0);
    lcd.write(byte(4));
    delay(Time);
    lcd.setCursor (Xcaza, 0);
    lcd.print(" ");
    contador--;
    caza = true;
    
    
   }
}
}

 
 
