/*
 * Widgets.cpp
 *
 *  Created on: 4 Aug 2025
 *      Author: jondurrant
 */

#include "Widgets.h"
#include <cstdio>



Widgets::Widgets() {

}

Widgets::~Widgets() {
	// TODO Auto-generated destructor stub
}



void Widgets::init() {

	 /*Create tileview*/
	xTV = lv_tileview_create(lv_scr_act());
	lv_obj_set_scrollbar_mode(xTV,  LV_SCROLLBAR_MODE_OFF);

	initTile1();

}



void Widgets::initTile1() {

	/*Tile1: */
	xTile1 = lv_tileview_add_tile(xTV, 0, 0,  LV_DIR_ALL);

	lv_style_init(&xStyleTile);
	lv_style_set_bg_color(&xStyleTile, lv_color_hex(0x000000));
	lv_style_set_bg_opa(&xStyleTile, LV_OPA_COVER);
	lv_obj_add_style(xTile1, &xStyleTile, 0);



	pKing1 = lv_img_create(xTile1);
	LV_IMG_DECLARE(king1);
	lv_img_set_src(pKing1, &king1);
	lv_obj_align(pKing1, LV_ALIGN_TOP_LEFT, 0, 20);
	lv_obj_add_flag(pKing1, LV_OBJ_FLAG_HIDDEN);

	pKing2 = lv_img_create(xTile1);
	LV_IMG_DECLARE(king2);
	lv_img_set_src(pKing2, &king2);
	lv_obj_align(pKing2, LV_ALIGN_CENTER, 0, -20);
	lv_obj_add_flag(pKing2, LV_OBJ_FLAG_HIDDEN);


	pTimer = lv_timer_create(timerCB, 100,  this);
}


void Widgets::setLeds(PicoLed::PicoLedController *p){
	pLeds = p;
}


void Widgets::timerCB(lv_timer_t * timer){
	Widgets *self = (Widgets *)timer->user_data;
	self->timerHandler(timer);
}

void Widgets::timerHandler(lv_timer_t * timer){

	if (pLeds != NULL){
		pLeds->show();
	}
	if (seq == 0){
		r=g=b=150;
		ar=ag=ab=-1;
		king0();
	}
	if (seq == 100){
		r = 0;
		b = 80;
		g = 0;
		ar=0;
		ab=-1;
		ag=1;
		king2();
	}
	if (seq == 200){
		r = 0;
		b = 70;
		g = 70;
		ar=2;
		ab=1;
		ag=1;
		king1();
	}
	seq++;
	if (seq > 300){
		seq = 0;
	}
	if (pLeds != NULL){
		r = r + ar;
		if (r < 0)
			r=0;
		g = g +ag;
		if (g < 0)
			g=0;
		b = b + ab;
		if (b < 0)
			b=0;
		pLeds->fill( PicoLed::RGB(r,g,b) );
	}
}

void Widgets::king0(){
	lv_obj_add_flag(pKing2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(pKing1, LV_OBJ_FLAG_HIDDEN);
}


void Widgets::king1(){
	lv_obj_clear_flag(pKing1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(pKing2, LV_OBJ_FLAG_HIDDEN);
}

void Widgets::king2(){
	lv_obj_clear_flag(pKing2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(pKing1, LV_OBJ_FLAG_HIDDEN);
}



