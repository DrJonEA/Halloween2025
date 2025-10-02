#include <stdio.h>
#include "pico/stdlib.h"

#include <PicoLed.hpp>

#define LED_PIN 5
#define LED_LENGTH 8

int main()
{
    stdio_init_all();
    sleep_ms(2000);

    // 0. Initialize LED strip
    printf("0. Initialize LED strip\n");
    auto ledStrip = PicoLed::addLeds<PicoLed::WS2812B>(pio0, 0, LED_PIN, LED_LENGTH, PicoLed::FORMAT_GRB);
    ledStrip.setBrightness(64);
    printf("1. Clear the strip!\n");

    // 1. Set all LEDs to red!
    printf("1. Set all LEDs to red!\n");
    ledStrip.fill( PicoLed::RGB(255, 255, 255) );
    ledStrip.show();
    sleep_ms(5000);


    PicoLed::Color  yellow = PicoLed::RGB(255, 255, 0) ;
    PicoLed::Color  green = PicoLed::RGB(0, 255, 0) ;
    PicoLed::Color  blue = PicoLed::RGB(255, 255, 255) ;

    for (int i=0; i < LED_LENGTH; i++){
    	if (i < 2){
    		ledStrip.setPixelColor( i, yellow);
    	} else if (i < 6){
    		ledStrip.setPixelColor( i,blue);
    	} else {
    		ledStrip.setPixelColor( i,green);
    	}
    }


    for (;;){
        ledStrip.show();
        sleep_ms(500);
    }


    return 0;
}
