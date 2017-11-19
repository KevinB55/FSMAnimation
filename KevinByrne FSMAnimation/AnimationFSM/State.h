#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Input.h>
#include <Animation.h>
#include <Debug.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void walking(Animation* a)
	{
		DEBUG_MSG("State::Walking");
	}
	virtual void swordmanship(Animation* a)
	{
		DEBUG_MSG("State::Swordmanship");
	}
	virtual void shovelling(Animation* a)
	{
		DEBUG_MSG("State::Shovelling");
	}
};

#endif // ! ANIMATION_H

