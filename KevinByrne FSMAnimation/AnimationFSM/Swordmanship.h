#ifndef SWORDMANSHIP_H
#define SWORDMANSHIP_H

#include <State.h>

class Swordmanship : public State
{
public:
	Swordmanship() {};
	~Swordmanship() {};
	void idle(Animation* a);
};

#endif // !IDLE_H


