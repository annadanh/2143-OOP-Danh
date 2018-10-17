///**
//	 *  Anna Danh
//	 *  Course: CMPS 2143 - OOP
//	 *	Program: P04
//	 *  Purpose: Simulate John Conway's Game of Life for specified
//	 *	number of generations
//	 *
//	 *  @version 1.1 10/18/2018
//	 *  @github repo: https://github.com/annadanh/2143-oop-danh
//	 */
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	/**
	*  Constructs GoL cell
	*
	*  @param: n/a
	*  @return: {GoLCell} default cell constructed
	*/
	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Yellow);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
		neighborCount = 0;
	}

	/**
	*  @Function: setCellPos
	*	Set the position of GoL cell
	*
	*  @param: {int} x and {int} y coordinates
	*  @return: n/a
	*/
	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	int frameRate;
	int frameCount;
	RenderWindow Window;
	golCell** World;
	golCell** tempWorld;
	/**
	*  Constructs GoL board
	*
	*  @param: {int} height and {int} width of board
	*  
	*/
	gameOfLife(int height, int width) {
		Width = width;
		Height = height;
		// multiply width and height by 10 to display entire board
		Window.create(VideoMode(Width*10, Height*10), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i < height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j < width; j++) {
				World[i][j].setCellPos(i, j);
				World[i][j].isAlive = false;
			}
		}
	}

	/**
	*  @Function: initBoard
	*	Initializes Game of Life board
	*
	*  @param: {ifstream} input file of GoL cell values
	*  @return: n/a
	*/
	void initBoard(std::ifstream &infile) {
		int Cols;
		int Rows;
		std::string line;
		// Reads in first two numbers from first line
		infile >> Cols >> Rows;

		// dynamically allocate number of rows
		tempWorld = new golCell*[Rows];

		// dynamically allocate number of columns
		for (int i = 0; i < Rows; i++) {
			tempWorld[i] = new golCell[Cols];
		}

		for (int i = 0; i < Rows; i++) {
			// read line from file
			infile >> line;

			for (int j = 0; j < Cols; j++) {
				tempWorld[i][j].isAlive = line[j] - 48;
				World[j][i].isAlive = tempWorld[i][j].isAlive;
			}
		}
	}

	/**
	*  @Function: onWorld
	*	Checks to see if a position is on the board
	*
	*  @param: {int} height and {int} width 
	*  @return: {bool} true if position is on the board 
	*	otherwise returns false
	*/
	bool onWorld(int height, int width) {
		// checks if height is less then 0 or greater 
		// than or equal to board's Height
		if (height < 0 || height >= Height) {
			return false;
		}
		
		// checks if width is less then 0 or greater 
		// than or equal to board's Width
		if (width < 0 || width >= Width) {
			return false;
		}
		return true;
	}

	/**
	*	Function: drawWorld
	*		draw GoL board 
	*
	*  @param n/a
	*  @return n/a
	*/
	void drawWorld() {
		Window.clear();
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (World[i][j].isAlive) {
					Window.draw(World[i][j].Rect);
				}
			}
		}
		Window.display();
	}

	/**
	*  @Function: updateNeighbors
	*	Updates neighborCount for cells on board
	*
	*  @param: n/a
	*  @return: n/a
	*/
	void updateNeighbors() {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				// initialize neighborCount to 0
				World[i][j].neighborCount = 0;

				//check if each adjacent position is on board 
				//and if the cell is alive, if both true 
				// neighborCount is incrimented
				if (onWorld(i - 1, j - 1)) {
					if (World[i - 1][j - 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i - 1, j)) {
					if (World[i - 1][j].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i - 1, j + 1)) {
					if (World[i - 1][j + 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i, j - 1)) {
					if (World[i][j - 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i, j + 1)) {
					if (World[i][j + 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i + 1, j - 1)) {
					if (World[i + 1][j - 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i + 1, j)) {
					if (World[i + 1][j].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i + 1, j + 1)) {
					if (World[i + 1][j + 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
			}
		}
	}

	/**
	*  @FunctionName: printBoard
	*		prints board to output file
	*  @param: {ofstream} outfile to print to
	*  @return: n/a
	*/
	void printBoard(std::ofstream& outfile) {
		outfile << "Anna Danh\nCourse: CMPS 2143 - OOP\n"
			<< "Program: P04\n"
			<< "github repo: https://githb.com/annadanh/2143-oop-danh \n\n";
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				// print 1 if cell is alive
				if (World[i][j].isAlive) {
					outfile << "1";
				}
				// else print 0
				else {
					outfile << "0";
				}
			}
			outfile << "\n";
		}
	}

	/**
	*  @Function: play
	*		runs GoL for a number of generations
	*
	*  @param: {int} generations: number of generations
	*  @return: n/a
	*/
	void play(int generation) {
		for (int i = 0; i < generation; i++) {
			//update neighbor count
			updateNeighbors();
			for (int j = 0; j < Height; j++) {
				for (int k = 0; k < Width; k++) {
					// cell dies if it has less than 2 neighbors
					if (World[j][k].neighborCount < 2) {
						World[j][k].isAlive = false;
					}
					// cell is alive if it has 3 neighbors
					else if (World[j][k].neighborCount == 3) {
						World[j][k].isAlive = true;
					}
					// cell dies if it has more than 3 neighbors
					else if (World[j][k].neighborCount > 3) {
						World[j][k].isAlive = false;
					}
				}
			}
		}

	}
	
};



int main() {
	gameOfLife GoL(40, 50);
	GoL.frameRate = 5;
	GoL.frameCount = 5;

	// create and open input/output files
	std::ifstream infile;
	std::ofstream outfile;
	
	infile.open("gen_zero.txt");
	outfile.open("outfile.txt");

	// initialize GoL board
	GoL.initBoard(infile);

	//run for 338 generations
	GoL.play(338);

	while (GoL.Window.isOpen())
	{
		
		Event event;
		while (GoL.Window.pollEvent(event))
		{
			
			if ((GoL.frameCount % GoL.frameRate) == 0) {
				GoL.drawWorld();
				GoL.frameCount = 0;
			}

			//GoL.drawWorld();
			if (event.type == Event::Closed)
				GoL.Window.close();
		}
		GoL.frameCount++;
	}

	//print result to output file
	GoL.printBoard(outfile);

	//close input/output files
	infile.close();
	outfile.close();
	return 0;
}
