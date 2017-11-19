#ifndef SHOVELLING_H
#define SHOVELLING_H

#include <State.h>

class Shovelling : public State
{
public:
	Shovelling() {};
	~Shovelling() {};
	void idle(Animation* a);
};

#endif // !IDLE_H

