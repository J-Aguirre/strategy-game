#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "config.hpp"
#include "score.hpp"

class Ball : public sf::Sprite
{
public:
	Ball();
	~Ball(){};
	
	void update(sf::Time&, sf::FloatRect, sf::FloatRect, Score&);
	float getSpeedX() const;

private:
	sf::Texture texture_ball;
	sf::Vector2f speed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

Ball::Ball()
	: sf::Sprite()
{
	//Carga textura
	texture_ball.loadFromFile("data/ball.png");
	this->setTexture(texture_ball);

	//Carga sonido
	this->buffer.loadFromFile("data/hitball.wav");
	this->sound.setBuffer(buffer);

	this->setOrigin(this->getLocalBounds().width/2.0f, this->getLocalBounds().height/2.0f);
	this->setPosition(WIDTH/2.0f, HEIGHT/2.0f);

	//Velocidad
	this->speed.x = 300.0f;
	this->speed.y = 300.0f;
}

void Ball::update(sf::Time& delta, sf::FloatRect p1, sf::FloatRect p2, Score& score)
{
	// Obtenemos los cuatro laterales de la bola
	float left = this->getPosition().x - this->getOrigin().x;
	float right = this->getPosition().x + this->getOrigin().x;
	float top = this->getPosition().y - this->getOrigin().y;
	float bottom = this->getPosition().y + this->getOrigin().y;

	// Comprobamos si choca contra las paredes
	if (left <= 0 && speed.x < 0)
	{
		this->speed.x *= -1;
		this->sound.play();
		score.addPointIA();
		this->setPosition(WIDTH/2.0f,HEIGHT/2.0f);
	}
	if (right >= WIDTH && speed.x > 0)
	{
		this->speed.x *= -1;
		this->sound.play();
		score.addPointPlayer();
		this->setPosition(this->getLocalBounds().width/2.0f, this->getLocalBounds().height/2.0f);
	}
	if ((top <= 0 && speed.y < 0) || (bottom >= HEIGHT && speed.y > 0))
	{
		this->speed.y *= -1;
		this->sound.play();
	}

	// Por último comprobamos si ha chocado contra las palas
	if (this->getGlobalBounds().intersects(p1) || this->getGlobalBounds().intersects(p2))
	{
		this->speed.x *= -1;
		this->sound.play();
	}
	// Movemos la bola multiplicando la velocidad por el tiempo pasado
	this->move(delta.asSeconds() * this->speed.x, delta.asSeconds() * this->speed.y);
}

float Ball::getSpeedX() const
{
	return speed.x;
}

#endif //BALL_HPP