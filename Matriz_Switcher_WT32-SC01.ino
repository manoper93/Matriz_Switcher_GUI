/*
-----------------------------------------------------------------------------------------------------------------
|                                                                                                                |
|                             Manoper - Matriz Switcher edition for WT32-SC01                              |
|                                                                                                                |
-----------------------------------------------------------------------------------------------------------------
*/

#include <TFT_eSPI.h>
#include <LittleFS.h>
#include <FS.h>
#include <EEPROM.h>
#include <SPI.h>

#define ENABLE_CAP_TOUCH
#define CUSTOM_TOUCH_SDA 18
#define CUSTOM_TOUCH_SCL 19
#define touchInterruptPin GPIO_NUM_27

#ifdef ENABLE_CAP_TOUCH
#include <Wire.h>
#include <FT6236.h>
FT6236 ts = FT6236();
#endif

#define FILESYSTEM LittleFS

#define REPEAT_CAL false

#define KEY_W 95
#define KEY_H 95
#define KEY_SPACING_X 20
#define KEY_SPACING_Y 10
#define KEY_X (KEY_W / 2) + KEY_SPACING_X
#define KEY_Y (KEY_H / 2) + KEY_SPACING_Y
#define KEY_TEXTSIZE 2
#define LABEL1_FONT &FreeSansBold12pt7b

TFT_eSPI tft = TFT_eSPI();

char keyLabel[12][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
uint16_t keyColor[12] = {TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED, TFT_RED};
TFT_eSPI_Button key[12];

RTC_DATA_ATTR uint16_t valor[12];
int address = 0;
uint16_t lcd_sleep = 0, display_state = 0;


void salvarNaEEPROM() {
  for (int i = 0; i < 12; i++) {
    EEPROM.put(i * sizeof(int), valor[i]);
  }
  EEPROM.commit(); // Salvar as alterações na EEPROM
}

void lerDaEEPROM() {
  for (int i = 0; i < 12; i++) {
    EEPROM.get(i * sizeof(int), valor[i]);
  }
}

void setup() {

  Serial.begin(115200);
  EEPROM.begin(512);
  lerDaEEPROM();

  for (int i = 0; i < 12; i++) {
    
    if (valor[i] != 1) {
      valor[i] = 2;
      Serial.print(i);
      Serial.println(" = saved");
    }

    if (valor[i] == 2) {
      keyColor[i] = TFT_RED;
    } else {
      keyColor[i] = TFT_GREEN;
    }
  }
  
  salvarNaEEPROM();

#ifdef ENABLE_CAP_TOUCH
  if (ts.begin(40, CUSTOM_TOUCH_SDA, CUSTOM_TOUCH_SCL)) {
    Serial.println("Touchscreen begun.");
  } else {
    Serial.println("Touchscreen failed!");
  }
#endif

  lcd();

  tabela();
}


void loop() {

  uint16_t t_x = 0, t_y = 0;
  bool pressed = false;

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    p.x = map(p.x, 0, 320, 320, 0);
    t_y = p.x;
    t_x = p.y;
    if(display_state == 1){
      display_state = 0;
      lcd_sleep = 0;
      ledcAttachPin(TFT_BL, 0);
      Serial.println("Screen ON");
      delay(300);
    } else {
      pressed = true;
    }
  } else {
    if(lcd_sleep <= 3000){
      lcd_sleep++;
      Serial.println("LCD Sleeper count = ");
      Serial.println(lcd_sleep);
    }
    if(lcd_sleep == 3000){
      display_state = 1;
      ledcAttachPin(TFT_BL, 1);
      Serial.println("Screen OFF");
    }
  }

  for (uint8_t b = 0; b < 12; b++) {
    if (pressed && key[b].contains(t_x, t_y)) {
      buttonpress(b);
      delay(300);
      pressed = false;
    }
  }
}


void tabela() {
  for (uint8_t row = 0; row < 3; row++) {
    for (uint8_t col = 0; col < 4; col++) {

      uint8_t b = col + row * 4;

      key[b].initButton(&tft, KEY_X + col * (KEY_W + KEY_SPACING_X),
                        KEY_Y + row * (KEY_H + KEY_SPACING_Y), KEY_W, KEY_H, TFT_WHITE, keyColor[b], TFT_WHITE,
                        keyLabel[b], KEY_TEXTSIZE);
      key[b].drawButton();
    }
  }
}


void switch_color(int button) {
  if(valor[button] == 1){
    keyColor[button] = TFT_RED;
    valor[button] = 2;
  } else if(valor[button] == 2){
    keyColor[button] = TFT_GREEN;
    valor[button] = 1;
  }

  salvarNaEEPROM();

  tabela();
}


void buttonpress(int button){

  switch_color(button);

  switch(button){
    case 0:
     Serial.print("Button 1 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 1:
     Serial.print("Button 2 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }
     
     break;
    case 2:
     Serial.print("Button 3 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 3:
     Serial.print("Button 4 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 4:
     Serial.print("Button 5 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 5:
     Serial.print("Button 6 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }
     
     break;
    case 6:
     Serial.print("Button 7 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }
     
     break;
    case 7:
     Serial.print("Button 8 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 8:
     Serial.print("Button 9 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 9:
     Serial.print("Button 10 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 10:
     Serial.print("Button 11 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
    case 11:
     Serial.print("Button 12 pressed = ");
     if(valor[button] == 2){
      Serial.println("OFF");
     } else {
      Serial.println("ON");
     }

     break;
  }
}


//--------------------------------------------------------------------------------------- VOID LCD

void lcd(){
  
  ledcSetup(0, 5000, 8);
#ifdef TFT_BL
  ledcAttachPin(TFT_BL, 1);
#else
  ledcAttachPin(backlightPin, 1);
#endif
  ledcWrite(0, 20);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  ledcAttachPin(TFT_BL, 0);
}
