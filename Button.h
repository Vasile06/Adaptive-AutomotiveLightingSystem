#pragma once
#include "Data_Types.h"

class Button
{
public:

	ButtonState GetState() const { return state; }
	void SetState(const ButtonState bt_state) { state = bt_state; }

protected:
	ButtonState state;
};