#include "pch.h"
BeamsTestFixture::BeamsTestFixture()
{
	m_l = Manager_Lights();
}

void BeamsTestFixture::SetUp()
{
	m_l.SetButton(ButtonState::Automatic);
	m_l.SetFrontal(60.0); // far away
	m_l.SetIllumination(2.0); // night
}


void BeamsTestFixture::SetButtonInManager(ButtonState bs)
{
	m_l.SetButton(bs);
}

void BeamsTestFixture::SetSensorProximity(float prox)
{
	m_l.SetFrontal(prox);
}
void BeamsTestFixture::SetSensorIlumination(float ilum)
{
	m_l.SetIllumination(ilum);
}

std::tuple<DisplayState, LightsState> BeamsTestFixture::GetMLResult() const
{
	return m_l_result;
}

Manager_Lights BeamsTestFixture::GetML() const
{
	return m_l;
}

void BeamsTestFixture::CalculateLightsState()
{
	m_l_result = m_l.CalculateLightsState();
}