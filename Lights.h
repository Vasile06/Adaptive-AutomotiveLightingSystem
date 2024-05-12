#pragma once
#include "Data_Types.h"
class Lights {
protected:
	LightsState lights;
public:
	LightsState GetLights() const { return lights; }
	Lights() {};
	void SetLevel(const LightsState lights_state) { lights = lights_state; }

};