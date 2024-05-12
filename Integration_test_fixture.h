#pragma once
#include "pch.h"


class BeamsTestFixture : public ::testing::Test
{
	Manager_Lights m_l;

	std::tuple<DisplayState, LightsState> m_l_result{};

public:
	BeamsTestFixture();
	void SetUp();
	//~IntegrationTestFixture();

	// Setters
	void SetButtonInManager(ButtonState bs);
	void SetSensorProximity(float);
	void SetSensorIlumination(float);

	// Getters
	std::tuple<DisplayState, LightsState> GetMLResult() const;
	Manager_Lights GetML() const;

	// Helpers
	void CalculateLightsState();
	void SetDisplayAndLights();
};