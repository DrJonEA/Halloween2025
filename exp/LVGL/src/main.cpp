#include <stdio.h>
#include "pico/stdlib.h"

#include <PicoLed.hpp>
#include "Widgets.h"

#include "hardware/clocks.h"
extern "C"{
#include "AMOLED_1in64.h"
#include "qspi_pio.h"
#include "QMI8658.h"
#include "FT3168.h"
#include "lv_port_disp.h"
}





#define LED_PIN 29
#define LED_LENGTH 8


int main()
{

	auto ledStrip = PicoLed::addLeds<PicoLed::WS2812B>(
			pio1,
			0,
			LED_PIN,
			LED_LENGTH, PicoLed::FORMAT_GRB);
	ledStrip.setBrightness(64);
	ledStrip.fill( PicoLed::RGB(255, 255, 255) );
	ledStrip.show();


    if (DEV_Module_Init() != 0)
    {
        return -1;
    }

    printf("AMOLED_1IN64_LCGL_test Demo\r\n");
    /*QSPI PIO Init*/
    QSPI_GPIO_Init(qspi);
    QSPI_PIO_Init(qspi);
    QSPI_4Wrie_Mode(&qspi);
    /*Init AMOLED*/
    AMOLED_1IN64_Init();
    AMOLED_1IN64_SetBrightness(60);
    AMOLED_1IN64_Clear(WHITE);
    /*Init touch screen*/
    FT3168_Init(FT3168_Point_Mode);
    /*Init IMU*/
    QMI8658_init();
    /*Init LVGL*/
    LVGL_Init();

    Widgets widgets;
    widgets.setLeds(&ledStrip);

    printf("Pre Widgets\n");
    widgets.init();
    for(;;){
        //lv_timer_handler();
        //printf("Loop\n");
        //sleep_ms(1);
    	 lv_task_handler();
    }
}
