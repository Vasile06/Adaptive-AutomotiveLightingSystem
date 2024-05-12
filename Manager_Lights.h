#pragma once
#include "Button.h"
#include "Sensor_Frontal.h"
#include "Sensor_Ilumination.h"
#include <tuple>

class Manager_Lights
{
	Button button;
	Sensor_Illumination illumination;
	Sensor_Frontal frontal;

public:

	void SetButton(const ButtonState buttonState) {
		button.SetState(buttonState);
	}

	void SetIllumination(const float value) {
		illumination.SetValue(value);
	}

	void SetFrontal(const float value) {
		frontal.SetValue(value);
	}

	std::tuple<DisplayState, LightsState> CalculateLightsState() {

		auto lightsState = std::make_tuple(DisplayState::None, LightsState::LEDOff);

		switch (button.GetState())
		{
		case ButtonState::LowBeam:
		{
			lightsState = std::make_tuple(DisplayState::Green, LightsState::LowBeamLED);
			break;
		}
		case ButtonState::HighBeam:
		{
			lightsState = std::make_tuple(DisplayState::Blue, LightsState::HighBeamLED);
			break;
		}
		case ButtonState::Automatic:
		{
			if (illumination.GetValue() < NighttimeThreshold) {
				lightsState = std::make_tuple(DisplayState::None, LightsState::LEDOff);
			}
			// it is night
			else {
				if (frontal.GetValue() > ApprochingVehicleDistance) {
					lightsState = std::make_tuple(DisplayState::Blue, LightsState::HighBeamLED);
				}
				// vehicle is approching
				else {
					lightsState = std::make_tuple(DisplayState::Green, LightsState::LowBeamLED);
				}
			}
			break;
		}
		case ButtonState::Off:
		default:
		{
			lightsState = std::make_tuple(DisplayState::None, LightsState::LEDOff);
			break;
		}
		}
		return lightsState;
	}

};