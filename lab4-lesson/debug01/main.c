//Lithio (the developer's pseudonym)
//February 21, 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 50

//constants returned by getch()
#define ENTER 13
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


void run_menu();

int main(void){
	
	//start the game by running the menu
	run_menu();
	
	return 0;
}

int load_game();
void draw_menu(int cursor);

//The menu looks like this:
//
//  >Load Game
//   New Game
//   Quit

void run_menu(){
	int cursor = 0;
	int option_selected;
	int input;
	
	do{
		option_selected = -1;
		
		//draw the interface
		draw_menu(cursor);
		
		//get user input from keyboard
		input = getch();
		//getch() returns a second value if the first value is 0 or 224
		if(input == 0 || input == 224){
			input = getch();
		}
		
		//handle input
		if(input == UP){
			//move cursor up
			if(cursor > 0){
				cursor--;
			}
		}
		else if(input == DOWN){
			//move cursor down
			if(cursor < 2){
				cursor++;
			}
		}
		else if(input == ENTER){
			option_selected = cursor;
		}
		
		if(option_selected == 0){
			load_game();
		}
		else if(option_selected == 1){
			//create a new game then load
		}
	}
	while(option_selected != 2);
}

void draw_str(const char *str, char screen[], int x, int y);

void draw_menu(int cursor){
	int i = 0;
	
	//the text that will be printed to the screen
	char screen[SCREEN_WIDTH * SCREEN_HEIGHT] = {0};
	
	//fill the text with spaces
	while(i < SCREEN_WIDTH * SCREEN_HEIGHT){
		screen[i] = ' ';
	}
	
	//draw a border of #'s
	while(i < SCREEN_WIDTH){
		screen[i] = '#';
		screen[SCREEN_WIDTH * (SCREEN_HEIGHT - 1) + i] = '#';
		i++;
	}
	
	i = 1;
	while(i < SCREEN_HEIGHT - 1){
		screen[SCREEN_WIDTH * i] = '#';
		screen[SCREEN_WIDTH * (i + 1) - 2] = '#';
		i++;
	}
	
	//draw the option strings
	draw_str("Load Game", screen, 35, 20);
	draw_str("New Game",  screen, 35, 21);
	draw_str("Quit",      screen, 35, 22);
	
	//draw the cursor
	screen[SCREEN_WIDTH * (20 + cursor) + 34] = '>';
	
	//set the last character in each row to newline characters
	i = 1;
	while(i < SCREEN_HEIGHT - 1){
		screen[SCREEN_WIDTH * i - 1] = '\n';
		i++;
	}
	
	//set last character to null
	screen[SCREEN_WIDTH * SCREEN_HEIGHT - 1] = '\0';
	
	//print to screen
	printf("%s", screen);
}

void draw_str(const char *str, char screen[], int x, int y){
	int i = 0;
	
	//copy the contents of the string to screen[]
	while(str[i] && (x + i) < SCREEN_WIDTH){
		screen[SCREEN_WIDTH * y + (x + i)] = str[i];
		i++;
	}
}

int load_game(){
}

