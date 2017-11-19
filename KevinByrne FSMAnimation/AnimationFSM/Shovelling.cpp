#include "Shovelling.h"
#include <Idle.h>

void Shovelling::idle(Animation * a)
{
	std::cout << "Shovelling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
