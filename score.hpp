#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>

#include <sstream>

class Score
{
public:
	Score();
	~Score(){}

	void show(sf::RenderWindow& window);
	void addPointPlayer();
	void addPointIA();

private:
	sf::Font font;
	sf::Text text_player;
	sf::Text text_ia;
	unsigned int points_player;
	unsigned int points_ia;
	
};

Score::Score(){
	points_ia = 0;
	points_player = 0;

	font.loadFromFile("data/OpenSans.ttf");

	text_ia.setFont(font);
	text_player.setFont(font);
	text_player.setCharacterSize(30);
	text_ia.setCharacterSize(30);
	text_player.setColor(sf::Color::White);
	text_ia.setColor(sf::Color::White);

	text_player.setPosition(20, 20);
	text_ia.setPosition(WIDTH - 20 - text_ia.getLocalBounds().width, 20);
}

void Score::addPointIA(){
	points_ia++;
}

void Score::addPointPlayer(){
	points_player++;
}

void Score::show(sf::RenderWindow& window){
	// Creamos 2 streams para pasar de int a string
	std::stringstream ia;
	std::stringstream ju;
	// Obtenemos las cadenas desde los puntos
	ia << points_ia;
	ju << points_player;
	// Establecemos las cadenas en los textos
	text_ia.setString(ia.str());
	text_player.setString(ju.str());

	// Recalculamos la posición del texto derecho para que se mantenga alineado
	text_ia.setPosition(WIDTH - 20 - text_ia.getLocalBounds().width, 20);

	// dibujamos los textos en la ventana
	window.draw(text_player);
	window.draw(text_ia);
}

#endif // SCORE_HPP