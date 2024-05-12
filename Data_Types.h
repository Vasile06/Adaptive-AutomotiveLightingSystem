#pragma once
typedef enum ButtonState
{
	Off = 0,
	LowBeam,	// 1
	HighBeam,	// 2
	Automatic	// 3
};
typedef enum LightsState {
	LEDOff = 0,
	LowBeamLED,
	HighBeamLED,
	AutomaticLED
};

typedef enum DisplayState {
	None = 0,
	Green,
	Blue
};

constexpr float NighttimeThreshold{ 1.0 }; // less than 1.0 means day
constexpr float ApprochingVehicleDistance{ 50.0 }; // less than 50 m means a vehicle is approching