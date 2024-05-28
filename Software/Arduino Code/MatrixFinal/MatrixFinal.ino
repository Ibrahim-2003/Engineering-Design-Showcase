#include <FastLED.h>

#define LED_PIN     13
#define NUM_LEDS    100
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

int male_ratio[3] = {0, 0, 255};
int female_ratio[3] = {105, 255, 180};

int rice[100][3] = {};

CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 12, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 11, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 10, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 7, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void Rice(void){
  leds[0]=CRGB::White;
  leds[1]=CRGB::White;
  leds[2]=CRGB::Black;
  leds[3]=CRGB::Blue;
  leds[4]=CRGB::Blue;
  leds[5]=CRGB::Black;
  leds[6]=CRGB::Black;
  leds[7]=CRGB::Blue;
  leds[8]=CRGB::Blue;
  leds[9]=CRGB::Blue;
  leds[10]=CRGB::White;
  leds[11]=CRGB::White;
  leds[12]=CRGB::Black;
  leds[13]=CRGB::Blue;
  leds[14]=CRGB::Blue;
  leds[15]=CRGB::Black;
  leds[16]=CRGB::White;
  leds[17]=CRGB::Blue;
  leds[18]=CRGB::Blue;
  leds[19]=CRGB::Blue;
  leds[20]=CRGB::Black;
  leds[21]=CRGB::White;
  leds[22]=CRGB::Black;
  leds[23]=CRGB::Black;
  leds[24]=CRGB::Blue;
  leds[25]=CRGB::Black;
  leds[26]=CRGB::White;
  leds[27]=CRGB::Blue;
  leds[28]=CRGB::Black;
  leds[29]=CRGB::Blue;
  leds[30]=CRGB::Black;
  leds[31]=CRGB::White;
  leds[32]=CRGB::Black;
  leds[33]=CRGB::Black;
  leds[34]=CRGB::Blue;
  leds[35]=CRGB::Black;
  leds[36]=CRGB::White;
  leds[37]=CRGB::Blue;
  leds[38]=CRGB::Black;
  leds[39]=CRGB::Blue;
  leds[40]=CRGB::White;
  leds[41]=CRGB::White;
  leds[42]=CRGB::Black;
  leds[43]=CRGB::Black;
  leds[44]=CRGB::Blue;
  leds[45]=CRGB::Black;
  leds[46]=CRGB::Black;
  leds[47]=CRGB::Blue;
  leds[48]=CRGB::Blue;
  leds[49]=CRGB::Blue;
  leds[50]=CRGB::White;
  leds[51]=CRGB::White;
  leds[52]=CRGB::Black;
  leds[53]=CRGB::Black;
  leds[54]=CRGB::Blue;
  leds[55]=CRGB::Black;
  leds[56]=CRGB::White;
  leds[57]=CRGB::Black;
  leds[58]=CRGB::Blue;
  leds[59]=CRGB::Blue;
  leds[60]=CRGB::Black;
  leds[61]=CRGB::White;
  leds[62]=CRGB::Black;
  leds[63]=CRGB::Black;
  leds[64]=CRGB::Blue;
  leds[65]=CRGB::Black;
  leds[66]=CRGB::White;
  leds[67]=CRGB::Blue;
  leds[68]=CRGB::Blue;
  leds[69]=CRGB::Blue;
  leds[70]=CRGB::Black;
  leds[71]=CRGB::White;
  leds[72]=CRGB::Black;
  leds[73]=CRGB::Black;
  leds[74]=CRGB::Blue;
  leds[75]=CRGB::Black;
  leds[76]=CRGB::White;
  leds[77]=CRGB::Blue;
  leds[78]=CRGB::Black;
  leds[79]=CRGB::Blue;
  leds[80]=CRGB::White;
  leds[81]=CRGB::White;
  leds[82]=CRGB::Black;
  leds[83]=CRGB::Blue;
  leds[84]=CRGB::Blue;
  leds[85]=CRGB::Black;
  leds[86]=CRGB::White;
  leds[87]=CRGB::Blue;
  leds[88]=CRGB::Black;
  leds[89]=CRGB::Blue;
  leds[90]=CRGB::White;
  leds[91]=CRGB::White;
  leds[92]=CRGB::Black;
  leds[93]=CRGB::Blue;
  leds[94]=CRGB::Blue;
  leds[95]=CRGB::Black;
  leds[96]=CRGB::White;
  leds[97]=CRGB::Blue;
  leds[98]=CRGB::Black;
  leds[99]=CRGB::Blue;
  FastLED.show();

  }

void texas(void){
  leds[0] = CRGB::White;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White;
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Blue;
  leds[8] = CRGB::Blue;
  leds[9] = CRGB::Blue;
  leds[10] = CRGB::White;
  leds[11] = CRGB::White;
  leds[12] = CRGB::White;
  leds[13] = CRGB::White;
  leds[14] = CRGB::White;
  leds[15] = CRGB::White;
  leds[16] = CRGB::Blue;
  leds[17] = CRGB::Blue;
  leds[18] = CRGB::Blue;
  leds[19] = CRGB::Blue;
  leds[20] = CRGB::White;
  leds[21] = CRGB::White;
  leds[22] = CRGB::White;
  leds[23] = CRGB::White;
  leds[24] = CRGB::White;
  leds[25] = CRGB::White;
  leds[26] = CRGB::Blue;
  leds[27] = CRGB::Blue;
  leds[28] = CRGB::Blue;
  leds[29] = CRGB::Blue;
  leds[30] = CRGB::White;
  leds[31] = CRGB::White;
  leds[32] = CRGB::White;
  leds[33] = CRGB::White;
  leds[34] = CRGB::White;
  leds[35] = CRGB::White;
  leds[36] = CRGB::Blue;
  leds[37] = CRGB::Blue;
  leds[38] = CRGB::Blue;
  leds[39] = CRGB::Blue;
  leds[40] = CRGB::White;
  leds[41] = CRGB::White;
  leds[42] = CRGB::White;
  leds[43] = CRGB::White;
  leds[44] = CRGB::White;
  leds[45] = CRGB::White;
  leds[46] = CRGB::Blue;
  leds[47] = CRGB::White;
  leds[48] = CRGB::White;
  leds[49] = CRGB::Blue;
  leds[50] = CRGB::Red;
  leds[51] = CRGB::Red;
  leds[52] = CRGB::Red;
  leds[53] = CRGB::Red;
  leds[54] = CRGB::Red;
  leds[55] = CRGB::Red;
  leds[56] = CRGB::Blue;
  leds[57] = CRGB::White;
  leds[58] = CRGB::White;
  leds[59] = CRGB::Blue;
  leds[60] = CRGB::Red;
  leds[61] = CRGB::Red;
  leds[62] = CRGB::Red;
  leds[63] = CRGB::Red;
  leds[64] = CRGB::Red;
  leds[65] = CRGB::Red;
  leds[66] = CRGB::Blue;
  leds[67] = CRGB::Blue;
  leds[68] = CRGB::Blue;
  leds[69] = CRGB::Blue;
  leds[70] = CRGB::Red;
  leds[71] = CRGB::Red;
  leds[72] = CRGB::Red;
  leds[73] = CRGB::Red;
  leds[74] = CRGB::Red;
  leds[75] = CRGB::Red;
  leds[76] = CRGB::Blue;
  leds[77] = CRGB::Blue;
  leds[78] = CRGB::Blue;
  leds[79] = CRGB::Blue;
  leds[80] = CRGB::Red;
  leds[81] = CRGB::Red;
  leds[82] = CRGB::Red;
  leds[83] = CRGB::Red;
  leds[84] = CRGB::Red;
  leds[85] = CRGB::Red;
  leds[86] = CRGB::Blue;
  leds[87] = CRGB::Blue;
  leds[88] = CRGB::Blue;
  leds[89] = CRGB::Blue;
  leds[90] = CRGB::Red;
  leds[91] = CRGB::Red;
  leds[92] = CRGB::Red;
  leds[93] = CRGB::Red;
  leds[94] = CRGB::Red;
  leds[95] = CRGB::Red;
  leds[96] = CRGB::Blue;
  leds[97] = CRGB::Blue;
  leds[98] = CRGB::Blue;
  leds[99] = CRGB::Blue;
  FastLED.show();
  }


void loop()
{
    Rice();
    delay(1000*5);
    ChangePalettePeriodically();
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    delay(5000);
    maleToFem(40);
    delay(1000 * 20);
    texas();
    delay(1000*5);
    
}

void maleToFem(int percentage){
  for(int i = 0; i < NUM_LEDS; i++){
    if(i%10 < int(percentage/10)){
      leds[i] = CRGB(female_ratio[1],female_ratio[0], female_ratio[2]);
      }else if(i%10 < 10){
        leds[i] = CRGB(male_ratio[1],male_ratio[0], male_ratio[2]);
        }
    }
    FastLED.show();
  }

//void maleToFem(void){
//  for(int i = 0; i < NUM_LEDS; i++){
//    if(i < 4){
//      leds[i] = CRGB(female_ratio[1],female_ratio[0], female_ratio[2]);
//      }else if(i < 10){
//        leds[i] = CRGB(male_ratio[1],male_ratio[0], male_ratio[2]);
//        }else if(i >= 10){
//          if(i - 10 < 4){
//            leds[i] = CRGB(female_ratio[1],female_ratio[0], female_ratio[2]);
//            }else if(i - 10 < 10){
//              leds[i] = CRGB(male_ratio[1],male_ratio[0], male_ratio[2]);
//              }else if(i >= 20){
//                if(i - 20 < 4){
//                  leds[i] = CRGB(female_ratio[1],female_ratio[0], female_ratio[2]);
//                  }else if(i - 20 < 10){
//                    leds[i] = CRGB(male_ratio[1],male_ratio[0], male_ratio[2]);
//                    }else if(i >= 30){
//                      leds[i] = CRGB(male_ratio[1],male_ratio[0], male_ratio[2]);
//                      }
//                }
//          }
//    }
//    FastLED.show();
//  }

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}


// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.

void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 99;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND;
//        if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
//        if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
//        if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
//        if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
//        if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
//        if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
//        if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
//        if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
//        if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
//        if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
    }
}

// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette()
{
    for( int i = 0; i < 16; ++i) {
        currentPalette[i] = CHSV( random8(), 255, random8());
    }
}

// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.
void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[8] = CRGB::White;
    currentPalette[12] = CRGB::White;
    
}

// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}


// This example shows how to set up a static color palette
// which is stored in PROGMEM (flash), which is almost always more
// plentiful than RAM.  A static PROGMEM palette like this
// takes up 64 bytes of flash.
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,
    CRGB::Gray, // 'white' is too bright compared to red and blue
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Red,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Black
};



// Additional notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.
