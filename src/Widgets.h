/*
 * Widgets.h
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */

#ifndef EXP_LVGLDASHBOARD_SRC_WIDGETS_H_
#define EXP_LVGLDASHBOARD_SRC_WIDGETS_H_

#include <PicoLed.hpp>

#include "lvgl.h"
#include "src/core/lv_obj.h"
#include "src/misc/lv_area.h"
#include "pico/stdlib.h"


class Widgets {
public:
	Widgets();
	virtual ~Widgets();

	void init();

	void setLeds(PicoLed::PicoLedController *p);


private:
	int seq=0;

	void king1();
	void king2();
	void king0();

	static void timerCB(lv_timer_t * timer);
	void timerHandler(lv_timer_t * timer);



	void initTile1();

	lv_obj_t *xTV;
	lv_obj_t *xTile1;
	lv_style_t xStyleTile;
	lv_style_t xLabelSt;

	lv_obj_t *pKing1;
	lv_obj_t *pKing2;
	lv_timer_t * pTimer;

	int r,g,b;
	int ar, ag, ab;


	PicoLed::PicoLedController *pLeds = NULL;

};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
