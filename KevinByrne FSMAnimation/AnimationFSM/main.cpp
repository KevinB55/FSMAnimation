#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite idle_animated_sprite(texture);
	idle_animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	idle_animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	idle_animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	idle_animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	idle_animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	idle_animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	//Setup Climbing animated sprite
	AnimatedSprite climbing_animated_sprite(texture);
	climbing_animated_sprite.addFrame(sf::IntRect(3, 88, 84, 84));
	climbing_animated_sprite.addFrame(sf::IntRect(88, 88, 84, 84));
	climbing_animated_sprite.addFrame(sf::IntRect(173, 88, 84, 84));
	climbing_animated_sprite.addFrame(sf::IntRect(258, 88, 84, 84));
	climbing_animated_sprite.addFrame(sf::IntRect(343, 88, 84, 84));
	climbing_animated_sprite.addFrame(sf::IntRect(428, 88, 84, 84));

	//Setup walking sprite
	AnimatedSprite walking_animated_sprite(texture);
	walking_animated_sprite.addFrame(sf::IntRect(3, 173, 84, 84));
	walking_animated_sprite.addFrame(sf::IntRect(88, 173, 84, 84));
	walking_animated_sprite.addFrame(sf::IntRect(173, 173, 84, 84));
	walking_animated_sprite.addFrame(sf::IntRect(258, 173, 84, 84));
	walking_animated_sprite.addFrame(sf::IntRect(343, 173, 84, 84));
	walking_animated_sprite.addFrame(sf::IntRect(428, 173, 84, 84));

	//Setup Jumping animated Sprite
	AnimatedSprite jumping_animated_sprite(texture);
	jumping_animated_sprite.addFrame(sf::IntRect(3, 258, 84, 84));
	jumping_animated_sprite.addFrame(sf::IntRect(88, 258, 84, 84));
	jumping_animated_sprite.addFrame(sf::IntRect(173, 258, 84, 84));
	jumping_animated_sprite.addFrame(sf::IntRect(258, 258, 84, 84));
	jumping_animated_sprite.addFrame(sf::IntRect(343, 258, 84, 84));
	jumping_animated_sprite.addFrame(sf::IntRect(428, 258, 84, 84));

	//Setup Swordmanship animated Sprite
	AnimatedSprite swordmanship_animated_sprite(texture);
	swordmanship_animated_sprite.addFrame(sf::IntRect(3, 343, 84, 84));
	swordmanship_animated_sprite.addFrame(sf::IntRect(88, 343, 84, 84));
	swordmanship_animated_sprite.addFrame(sf::IntRect(173, 343, 84, 84));
	swordmanship_animated_sprite.addFrame(sf::IntRect(258, 343, 84, 84));
	swordmanship_animated_sprite.addFrame(sf::IntRect(343, 343, 84, 84));
	swordmanship_animated_sprite.addFrame(sf::IntRect(428, 343, 84, 84));

	//Setup Shovelling animated Sprite
	AnimatedSprite shovelling_animated_sprite(texture);
	shovelling_animated_sprite.addFrame(sf::IntRect(3, 428, 84, 84));
	shovelling_animated_sprite.addFrame(sf::IntRect(88, 428, 84, 84));
	shovelling_animated_sprite.addFrame(sf::IntRect(173, 428, 84, 84));
	shovelling_animated_sprite.addFrame(sf::IntRect(258, 428, 84, 84));
	shovelling_animated_sprite.addFrame(sf::IntRect(343, 428, 84, 84));
	shovelling_animated_sprite.addFrame(sf::IntRect(428, 428, 84, 84));

	// Setup the Player
	Player player(idle_animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (input.getCurrent() != (Input::Action::LEFT))
					{
						input.setCurrent(Input::Action::LEFT);
						player.m_animated_sprite = walking_animated_sprite;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (input.getCurrent() != (Input::Action::RIGHT))
					{
						input.setCurrent(Input::Action::RIGHT);
						player.m_animated_sprite = swordmanship_animated_sprite;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (input.getCurrent() != (Input::Action::UP))
					{
						input.setCurrent(Input::Action::UP);
						player.m_animated_sprite = climbing_animated_sprite;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (input.getCurrent() != (Input::Action::DOWN))
					{
						input.setCurrent(Input::Action::DOWN);
						player.m_animated_sprite = shovelling_animated_sprite;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
				{
					if (input.getCurrent() != (Input::Action::RCONTROL))
					{
						input.setCurrent(Input::Action::RCONTROL);
						player.m_animated_sprite = jumping_animated_sprite;
					}
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				player.m_animated_sprite = idle_animated_sprite;
				break;
			}
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};