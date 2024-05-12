#pragma once
#include "Data_Types.h"
class Display {
protected:
	DisplayState led_color;
public:
	Display() {};
	DisplayState GetLedColor() const { return  led_color; }
	void SetLedColor(const DisplayState led_state) { led_color = led_state; }

};
