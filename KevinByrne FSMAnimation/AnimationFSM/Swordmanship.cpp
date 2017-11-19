#include "Swordmanship.h"
#include <Idle.h>

void Swordmanship::idle(Animation * a)
{
	std::cout << "Swordmanship -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
