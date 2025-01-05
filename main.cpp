#include "main.hpp"

int main()
{

	ball.setFillColor(sf::Color::Blue);
	ball.setPosition(WIDTH / 2, HEIGHT / 2);
	ball.setOrigin(ballRadius, ballRadius);

	board.setPosition(boardPosX, boardPosY);
	board.setFillColor(sf::Color(15,15,10));
	board.setOutlineColor(sf::Color::Green);
	board.setOutlineThickness(outlineThickness);

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
        }

		usleep(TIME_FRESH);

        window.clear();
        window.draw(board);
        window.draw(ball);
        window.draw(rightPlayer);
        window.draw(leftPlayer);
        window.display();
    }

	std::cout << "Pong Game!! \n";
	return 0;
}
