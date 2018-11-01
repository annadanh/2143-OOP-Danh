/**
	 *  Anna Danh
	 *  Course: CMPS 2143 - OOP
	 *
	 *  Purpose: Create a counter class
	 *
	 *  @version 1.1 11/1/18
	 *  @github repo: https://github.com/annadanh/2143-oop-danh
	 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Counter {
private:
	Font font;		// clock's font
	Text time;		// var to hold digits
	Time start;		// var for clock start time
	Time end;		// var for clock end time
	Time elapsed;	// var to hold elapsed time
	Clock clock;


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
		start = seconds(s);
		end = seconds(e);

		clock.restart();
		elapsed = clock.getElapsedTime();
		// looks for font and returns error message if not found
		if (!font.loadFromFile("Segment7Standard.otf"))
		{
			cout << "ERROR! Font could not be loaded";
		}
		time.setFont(font);
		time.setCharacterSize(60);
		time.setFillColor(Color::Red);
		time.setPosition(80, 50);

	}

	/**
	*  @Function: getTime
	*	decides whether to use an incrementing or 
	*	decrementing timer
	*  @param: {int, int} start and end times
	*  @return: {cTime} current time
	*/
	int getTime(int s, int e) {
		if (s > e) {
			elapsed = clock.getElapsedTime();
			cTime = start.asSeconds() - elapsed.asSeconds();
			time.setString(to_string(cTime));
		}
		else {
			elapsed = clock.getElapsedTime();
			cTime = elapsed.asSeconds();
			time.setString(to_string(cTime));
		}
		return cTime;
	}
	/**
	*  @Function: drawCounter
	*	draws the clock to sfml window
	*  @param: {&window} Refernce to sfml window
	*  @return: n/a
	*/
	void drawCounter(RenderWindow &window) {
		window.draw(time);
	}
};

int main() {
	RenderWindow window(VideoMode(200, 200), "SFML works!");
	// start and end time for timer
	int start = 0;
	int end = 5;

	// create an instance of counter class 
	Counter C(start, end);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// gets time and draws to the window while it 
		// is open
		window.clear();
		C.getTime(start, end);
		C.drawCounter(window);
		window.display();

		// closes the window when timer reaches 0
		if (start > end && C.cTime < 1)
			window.close();
		// closes window when timer is over end time
		if (start < end && C.cTime > end-1)
			window.close();
	}

	return 0;
}
