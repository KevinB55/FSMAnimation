#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Walking.h>
#include <Swordmanship.h>
#include <Shovelling.h>
#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}
void Idle::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Idle::swordmanship(Animation * a)
{
	std::cout << "Idle -> Swordmanship" << std::endl;
	a->setCurrent(new Swordmanship());
	delete this;
}

void Idle::shovelling(Animation * a)
{
	std::cout << "Idle -> Shovelling" << std::endl;
	a->setCurrent(new Shovelling());
	delete this;
}
