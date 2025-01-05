#include "main.hpp"

int main()
{

	ball.setFillColor(sf::Color::Blue);
	ball.setPosition(WIDTH / 4, HEIGHT / 2);
	ball.setOrigin(ballRadius, ballRadius);

	board.setPosition(boardPosX, boardPosY);
	//board.setFillColor(sf::Color(15,15,10));
	board.setOutlineColor(sf::Color::Green);
	//board.setOutlineThickness(outlineThickness);

	boardLineTop.setPosition(boardPosX, 0);
	boardLineTop.setFillColor(sf::Color::Green);

	leftPlayer.setPosition(boardPosX+10, HEIGHT/2);
	leftPlayer.setFillColor(sf::Color::Blue);
	leftPlayer.setOutlineColor(outlinePlayerColor);
	leftPlayer.setOutlineThickness(outlineThickness/2);

	rightPlayer.setPosition(WIDTH+boardPosX-(raquetWidth+10), HEIGHT/2);
	rightPlayer.setFillColor(sf::Color::Red);
	rightPlayer.setOutlineColor(outlinePlayerColor);
	rightPlayer.setOutlineThickness(outlineThickness/2);

	while (window.isOpen())
    {
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			//if (event.type == sf::Event::KeyPressed)
			//{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					sf::Vector2f pos = rightPlayer.getPosition();
					pos.y = std::max(0.f, pos.y - 10);
					rightPlayer.setPosition(pos);
				}
				//if (event.key.code == sf::Keyboard::Down)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					sf::Vector2f pos = rightPlayer.getPosition();
					pos.y = std::min(WIN_HEIGHT - raquetHeight , pos.y + 10);
					rightPlayer.setPosition(pos);
				}
			//}

				// left player move
			//if (event.type == sf::Event::KeyPressed)
			//{
				//if (event.key.code == sf::Keyboard::W)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					sf::Vector2f pos = leftPlayer.getPosition();
					pos.y = std::max(0.f, pos.y - 10);
					leftPlayer.setPosition(pos);
				}
				//if (event.key.code == sf::Keyboard::Z)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
					sf::Vector2f pos = leftPlayer.getPosition();
					pos.y = std::min(WIN_HEIGHT - raquetHeight , pos.y + 10);
					leftPlayer.setPosition(pos);
				}
			//}
        }

		usleep(TIME_FRESH);

		ball.move(ballDirection.x * ballVitesse, ballDirection.y *ballVitesse);
		if (ball.getPosition().y <= boardPosY || ball.getPosition().y + ballRadius >= boardPosY + HEIGHT)
    		ballDirection.y *= -1;

        window.clear(sf::Color::Black);
        window.draw(board);
        window.draw(leftPlayer);
        window.draw(rightPlayer);
        window.draw(boardLineTop);
        window.draw(ball);
        window.display();
    }

	std::cout << "Pong Game!! \n";
	return 0;
}
