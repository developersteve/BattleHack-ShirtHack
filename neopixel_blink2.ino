#include <Adafruit_NeoPixel.h>

#define PIN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN, NEO_GRB + NEO_KHZ800);

uint8_t myColors[][3] = {{232, 100, 255},
                         {200, 200, 20}, 
                         {30, 200, 200}, 
                          };
                               
#define FAVCOLORS sizeof(myColors) / 3

void setup() {
  strip.begin();
  strip.show(); 
}

void loop() {
flashRandom(5, 2, 20, 2);   
flashRandom(50, 2, 10, 1);
}

void flashRandom(int wait, uint8_t howmany, uint8_t howlong, uint8_t ftype) {
  for(uint16_t Ti=0; Ti<howlong; Ti++){   
    for(uint16_t i=0; i<howmany; i++) {
   
      int c = random(FAVCOLORS);
      int red = myColors[c][0];
      int green = myColors[c][1];
      int blue = myColors[c][2]; 
      
      int j = random(strip.numPixels());
  
      for (int x=0; x < 5; x++) {
        int r = red * (x+1); r /= 5;
        int g = green * (x+1); g /= 5;
        int b = blue * (x+1); b /= 5;
        
        if(ftype==1){
          strip.setPixelColor(0, strip.Color(r, g, b));
          strip.setPixelColor(1, strip.Color(r, g, b));        
        }
        else
        {
          strip.setPixelColor(j, strip.Color(r, g, b));          
        }
                
        strip.show();
        delay(wait);
      }
  
      for (int x=5; x >= 0; x--) {
        int r = red * x; r /= 5;
        int g = green * x; g /= 5;
        int b = blue * x; b /= 5;

        if(ftype==1){
          strip.setPixelColor(0, strip.Color(r, g, b));
          strip.setPixelColor(1, strip.Color(r, g, b));        
        }
        else
        {
          strip.setPixelColor(j, strip.Color(r, g, b));          
        }        

        strip.show();
        delay(wait);
      }
    }
  }
}
