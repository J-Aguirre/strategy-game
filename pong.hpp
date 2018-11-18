#ifndef PONG_HPP
#define PONG_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "config.hpp"
#include "ball.hpp"

class Pong{

public:
	Pong();
	~Pong(){}

	void run();

private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time time;

	sf::Texture texture_back;
	sf::Sprite background;

	sf::Music music;

	Ball ball;

};

Pong::Pong(){

	//Creamos la ventana
	window.create(sf::VideoMode(WIDTH, HEIGHT, BPP), "Pong Example", sf::Style::Close);
	//Sincronizacion vertical 60fps
	window.setVerticalSyncEnabled(true);

	//Cargar background
	texture_back.loadFromFile("data/background.png");
	background.setTexture(texture_back);

	//Cargar musica
	music.openFromFile("data/background.ogg");
	music.setLoop(true);
	music.play();
}

void Pong::run(){
	
	while(window.isOpen()){
		time = clock.restart();

		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}

		ball.update(time);

		window.draw(background);
		window.draw(ball);

		window.display();
	}
}

#endif // PONG_HPP