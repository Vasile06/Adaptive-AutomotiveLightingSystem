#pragma once
#include "Sensor.h"

class Sensor_Illumination : public Sensor
{
public:
	void Enable(bool enable) override {}
	float GetValue() const override { return value; }
	bool IsEnabled() const override { return true; }
	void SetValue(float in_value) override { value = in_value; }

};