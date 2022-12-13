﻿#include "settings.h"
#include "functions.h"
#include <ctime>
using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
    initBat(leftBat, leftBatColor, batPosition);
	initBat(rightBat, rightBatColor, batPosition1);

	float leftBatSpeedy = 0.f;
	float rightBatSpeedy = 0.f;
	


	//шарик
	CircleShape ball;
	initBall(ball, ballColor, ballPosition);

	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	srand(time(nullptr));
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//счёт
	int leftPlayer = 0, rightPlayer = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");

	Text leftPText;
	PText(leftPText, font, textPosition);
	leftPText.setString(std::to_string(leftPlayer));
	
	/*leftPText.setFont(font);
	leftPText.setCharacterSize(40);
	leftPText.setPosition(WINDOW_WIDTH * 0.5 - 30 - 40,0);*/

    Text rightPText;
	PText(rightPText, font, textPosition1);
	rightPText.setString(std::to_string(rightPlayer));
	
	/*rightPText.setFont(font);
	rightPText.setCharacterSize(40);
	rightPText.setPosition(WINDOW_WIDTH * 0.5 + 30 + 40, 0);*/


	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов
		//шарик: поведение
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0 /*|| ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius)*/)
		{
			ball_speedx = -ball_speedx;
			rightPlayer++;
			rightPText.setString(std::to_string(rightPlayer));
		}
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			ball_speedx = -ball_speedx;
			leftPlayer++;
			leftPText.setString(std::to_string(leftPlayer));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >= (WINDOW_HEIGHT - 2 * ballRadius))
		{
			ball_speedy = -ball_speedy;
		}
		float midleftx = ball.getPosition().x;
		float midlefty = ball.getPosition().y + ballRadius;
		float midrightx = ball.getPosition().x + ballRadius * 2;
		float midrighty = ball.getPosition().y + ballRadius;
		float midupx = ball.getPosition().x + ballRadius;
		float midupy = ball.getPosition().y;
		float middownx = ball.getPosition().x + ballRadius;
		float middowny = ball.getPosition().y + ballRadius * 2;
		if ((leftBat.getPosition().x <= midleftx && midleftx <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= midlefty && midlefty <= leftBat.getPosition().y + batHeight))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftBat.getPosition().x <= middownx && middownx <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= middowny && middowny <= leftBat.getPosition().y + batHeight))
		{
			ball_speedy = -ball_speedy;
		}
		if ((leftBat.getPosition().x <= midupx && midupx <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= midupy && midupy <= leftBat.getPosition().y + batHeight))
		{
			ball_speedy = -ball_speedy;
		}
		if ((rightBat.getPosition().x <= midrightx && midrightx <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= midlefty && midlefty <= rightBat.getPosition().y + batHeight))
		{
			ball_speedx = -ball_speedx;
		}
		if ((rightBat.getPosition().x <= middownx && middownx <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= middowny && middowny <= rightBat.getPosition().y + batHeight))
		{
			ball_speedy = -ball_speedy;
		}
		if ((rightBat.getPosition().x <= midupx && midupx <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= midupy && midupy <= rightBat.getPosition().y + batHeight))
		{
			ball_speedy = -ball_speedy;
		}
		
		
		//ball.move(ball_dx, ball_dy);

		//ракетки: поведение
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			leftBatSpeedy = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			leftBatSpeedy = batSpeed;
		}
		leftBat.move(0, leftBatSpeedy);
		leftBatSpeedy = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rightBatSpeedy = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rightBatSpeedy = batSpeed;
		}
		rightBat.move(0, rightBatSpeedy);
		rightBatSpeedy = 0.f;
		//1 ракетка
		if (leftBat.getPosition().y <= 0 || leftBat.getPosition().y >= WINDOW_HEIGHT)
		{
			leftBat.setPosition(batOffset,0);
		}
		if (leftBat.getPosition().y + 80 >= WINDOW_HEIGHT || leftBat.getPosition().y >= WINDOW_WIDTH)
		{
			leftBat.setPosition(batOffset, WINDOW_HEIGHT - 80);
		}
		//2 ракетка
		if (rightBat.getPosition().y <= 0 || rightBat.getPosition().y >= WINDOW_HEIGHT)
		{
			rightBat.setPosition(WINDOW_WIDTH - batOffset, 0);
		}
		if (rightBat.getPosition().y + 80 >= WINDOW_HEIGHT || rightBat.getPosition().y >= WINDOW_WIDTH)
		{
			rightBat.setPosition(WINDOW_WIDTH - batOffset, WINDOW_HEIGHT - 80);
		}


		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPText);
		window.draw(rightPText);
		//3.3 вывод на экран
		window.display();
	}

	return 0;
}
