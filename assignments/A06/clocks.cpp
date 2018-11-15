/**
	 *  Anna Danh
	 *  Course: CMPS 2143 - OOP
	 *
	 *  Purpose: Create a counter class using sfml that can 
	 *	be incremented or decremented. extends from group 
	 *
	 *  @version 1.1 11/14/18
	 *  @github repo: https://github.com/annadanh/2143-oop-danh
	 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Group.h"

using namespace std;
using namespace sf;

class Counter : public Group {
private:
	Font font;		// clock's font
	Text time;		// var to hold digits
	Time start;		// var for clock start time
	Time end;		// var for clock end time
	Time elapsed;	// var to hold elapsed time
	Clock clock;

	float posX;
	float posY;
	float bounceX = 1;
	float bounceY = 1;
	
	int frameRate;
	int endTime;
	int startTime;
	RectangleShape rec;

	
public:
	// intialize clock to 0
	int cTime = 0;

	/**
	*  @Function: Counter
	*	contructor that creates clock; sets the font, size,
	*	position, and color of clock
	*  @param: {int,int} start and end time
	*  @return: n/a
	*/
	Counter(int s, int e) {
		posX = 60.0;
		posY = 60.0;
		start = seconds(s);
		startTime = s;
		end = seconds(e);
		endTime = e;
		clock.restart();
		elapsed = clock.getElapsedTime();
		// looks for font and returns error message if not found
		if (!font.loadFromFile("Segment7Standard.otf"))
		{
			cout << "ERROR! Font could not be loaded";
		}

		// set clock's size, font color, & position
		time.setFont(font);
		time.setCharacterSize(60);
		time.setFillColor(Color::Red);
		time.setPosition(Vector2f(posX, posY));

		// set rectangle's size, color, position,
		// border thickness, & border color
		rec.setSize(Vector2f(100, 100));
		rec.setFillColor(Color::White);
		rec.setOutlineThickness(2);
		rec.setOutlineColor(Color::Red);
		rec.setPosition(Vector2f(posX, posY));

		this->push_back(rec);
		this->push_back(time);
	}

	/**
	*  @Function: Counter
	*	contructor that creates clock; sets the font, size,
	*	position, and color of clock
	*  @param: {int,int} start and end time
	*  @return: n/a
	*/
	Counter(int s, int e, float x, float y) {
		posX = x;
		posY = y;
		frameRate = 0;
		start = seconds(s);
		startTime = s;
		end = seconds(e);
		endTime = e;
		clock.restart();
		elapsed = clock.getElapsedTime();

		// looks for font and returns error message if not found
		if (!font.loadFromFile("Segment7Standard.otf"))
		{
			cout << "ERROR! Font could not be loaded";
		}
		
		// set clock's size, font color, & position
		time.setFont(font);
		time.setCharacterSize(60);
		time.setFillColor(Color::Red);
		time.setPosition(Vector2f(posX, posY));
		
		// set rectangle's size, color, position,
		// border thickness, & border color
		rec.setSize(Vector2f(100, 100));
		rec.setFillColor(Color::White);
		rec.setOutlineThickness(3);
		rec.setOutlineColor(Color::Red);
		rec.setPosition(Vector2f(posX, posY));

		this->push_back(rec);
		this->push_back(time);
		
	}

	/**
	*  @Function: getTime
	*	decides whether to use an incrementing or 
	*	decrementing timer
	*  @param: {int, int} start and end times
	*  @return: {cTime} current time
	*/
	
	int getTime(float width, float height) {
		if (startTime > endTime) {
			elapsed = clock.getElapsedTime();
			cTime = start.asSeconds() - elapsed.asSeconds();
			time.setString(to_string(cTime));
		}
		else {
			elapsed = clock.getElapsedTime();
			cTime = elapsed.asSeconds();
			time.setString(to_string(cTime));
		}
		if (frameRate == 10) {
			bounce(width, height);
			frameRate = 0;
		}
		else {
			frameRate++;
		}
		return cTime;
	}
	
	/**
	*  @Function: bounce
	*	bounces clock if it hits an edge
	*  @param: {float, float} width and height of window
	*  @return: n/a
	*/
	void bounce(float width, float height) {
		// flips x or y movement direction if it hits an edge
		if (posX < 0 || posX > (width)) {
			bounceX *= -1;
		}
		if (posY < 0 || posY > height) {
			bounceY *= -1;
		}

		// changes x & y locations
		posX -= bounceX;
		posY -= bounceY;

		// set location
		rec.setPosition(posX, posY);
		time.setPosition(posX, posY);
	}
	
	/**
	*  @Function: drawCounter
	*	draws the clock to sfml window
	*  @param: {&window} Refernce to sfml window
	*  @return: n/a
	*/
	void drawCounter(RenderWindow &window) {
		window.draw(rec);
		window.draw(time);
	}
	
	/**
	*  @Function: changeFontColor
	*	changes font color of clock
	*  @param: {color} color of font
	*  @return: n/a
	*/
	void changeFontColor(Color color) {
		time.setFillColor(color);
	}
	
	/**
	*  @Function: changeFontSize
	*	changes clock's font size
	*  @param: {int} size of font
	*  @return: n/a
	*/
	void changeFontSize(int size) {
		time.setCharacterSize(size);
	}
	
	/**
	*  @Function: changeBorderColor
	*	changes rectangle border color
	*  @param: {color} color of border
	*  @return: n/a
	*/
	void changeBorderColor(Color color) {
		rec.setOutlineColor(color);
	}
	
	/**
	*  @Function: changeBackgroundColor
	*	changes rectangle's color
	*  @param: {color} color of rectangle
	*  @return: n/a
	*/
	void changeBackgroundColor(Color color) {
		rec.setFillColor(color);
	}
	
	/**
	*  @Function: changeClockPos
	*	changes position of clock & rectangle
	*  @param: {float, float} x and y positions
	*  @return: n/a
	*/
	void changeClockPos(float x, float y) {
		time.setPosition(Vector2f(x, y));
		rec.setPosition(Vector2f(x, y));
	}
	
	/**
	*  @Function: End()
	*	checks if clock has hit the end 
	*  @param: n/a
	*  @return: true or false
	*/
	bool End() {
		if (endTime == cTime)
			return true;
		else
			return false;
	}
};

int main() {
	float width = 600.0;
	float height = 500.0;
	RenderWindow window(VideoMode(width, height), "SFML works!");

	// create an instance of counter class 
	Counter C1(0, 20, 50, 100);
	Counter C2(20, 0, 400, 100);

	// change background, border, and font color of 2nd clock
	C2.changeBackgroundColor(Color::Red);
	C2.changeBorderColor(Color::White);
	C2.changeFontColor(Color::White);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (window.isOpen() && C1.End() && C2.End())
			window.close();

		// gets time and draws to the window while it 
		// is open
		window.clear();
		C1.drawCounter(window);
		C2.drawCounter(window);
		C1.getTime(width, height);
		C2.getTime(width, height);
		
		
		window.display();

	}

	return 0;
}
