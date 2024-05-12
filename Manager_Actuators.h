#pragma once
#include "Display.h"
#include "Lights.h"
#include "Manager_Lights.h"

class Manager_Actuators
{
public:
	Manager_Actuators(Manager_Lights lightsResult) : lights_result(lightsResult) {}
	Manager_Actuators(Manager_Lights* lightsResult) : lightsResult(lightsResult) {}
	void ReadManagerLights(Manager_Lights lightsResult)
	{
		lights_result = lightsResult;
	}

	void SetDisplay() {
		display.SetLedColor(std::get<0>(lights_result.CalculateLightsState()));
	}
	void SetLights() {
		lights.SetLevel(std::get<1>(lights_result.CalculateLightsState()));
	}

	Display GetDisplay() const {
		return display;
	}

	Lights GetLights() const {
		return lights;
	}

private:
	Display display;
	Lights lights;
	Manager_Lights lights_result;
	Manager_Lights* lightsResult;

};