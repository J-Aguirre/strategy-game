#ifndef BALL_HPP
#define BALL_HPP

class Ball{

public:
	Ball();
	~Ball();
	
	void update(sf::Time& delta);
	float getSpeedX() const;

private:
	sf::Texture texture_Ball;
	sf::Vector2f speed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

Ball::Ball(){

}

#endif //BALL_HPP