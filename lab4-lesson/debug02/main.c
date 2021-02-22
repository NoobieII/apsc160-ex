//Lithio (the developer's pseudonym)
//February 21, 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 50

#define MAP_WIDTH 16
#define MAP_HEIGHT 15

//constants returned by getch()
#define ESC 27
#define ENTER 13
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

//file names used
#define MAP_FILENAME "maps/map0000.txt"
#define SAVE_FILENAME "save.txt"

void run_menu();

void create_new_game();
void load_game();

void print_menu(int cursor);
void print_error_screen();
void print_game(int map_data[], int x_position, int y_position);
void load_map(int map_data[]);
void save_game(int x_position, int y_position);

int main(void){
	
	//start the game by running the menu
	run_menu();
	
	return 0;
}


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
		print_menu(cursor);
		
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
			create_new_game();
			load_game();
		}
	}
	while(option_selected != 2);
}

void draw_str(const char *str, char screen[], int x, int y);
void draw_tile(const char *sprite, char screen[], int x, int y);

void print_menu(int cursor){
	int i = 0;
	
	//the text that will be printed to the screen
	char screen[SCREEN_WIDTH * SCREEN_HEIGHT] = {0};
	
	//fill the text with spaces
	while(i < SCREEN_WIDTH * SCREEN_HEIGHT){
		screen[i] = ' ';
		i++;
	}
	
	//draw a border of #'s
	i = 0;
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
	printf("\n");
	fwrite(screen, 1, SCREEN_WIDTH * SCREEN_HEIGHT - 1, stdout);
	fflush(stdout);
}

void print_error_screen(){
	int i = 0;
	
	//the text that will be printed to the screen
	char screen[SCREEN_WIDTH * SCREEN_HEIGHT] = {0};
	
	//fill the text with spaces
	while(i < SCREEN_WIDTH * SCREEN_HEIGHT){
		screen[i] = ' ';
		i++;
	}
	
	//draw a border of #'s
	i = 0;
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
	draw_str("Error loading save file.", screen, 28, 20);
	
	//set the last character in each row to newline characters
	i = 1;
	while(i < SCREEN_HEIGHT - 1){
		screen[SCREEN_WIDTH * i - 1] = '\n';
		i++;
	}
	
	//set last character to null
	screen[SCREEN_WIDTH * SCREEN_HEIGHT - 1] = '\0';
	
	//print to screen
	printf("\n");
	fwrite(screen, 1, SCREEN_WIDTH * SCREEN_HEIGHT - 1, stdout);
	fflush(stdout);
}

void print_game(int map_data[], int x_position, int y_position){
	//draw the map tiles
	int x = 0;
	int y = 0;
	int i;
	
	//array of characters that will be printed to the screen
	char screen[SCREEN_WIDTH * SCREEN_HEIGHT] = {0};
	
	//
	while(y < MAP_HEIGHT){
		while(x < MAP_WIDTH){
			//if the tile value is 01
			if(map_data[y * MAP_WIDTH + x] == 1){
				//draw the obstruction
				draw_tile(" + +++ + ", screen, x, y);
			}
		}
	}
	
	//draw the player
	draw_tile("iO lHl M ", screen, x_position, y_position);
	
	//set the last character in each row to newline characters
	i = 1;
	while(i < SCREEN_HEIGHT - 1){
		screen[SCREEN_WIDTH * i - 1] = '\n';
		i++;
	}
	
	//set last character to null
	screen[SCREEN_WIDTH * SCREEN_HEIGHT - 1] = '\0';
	
	//print to screen
	printf("\n");
	fwrite(screen, 1, SCREEN_WIDTH * SCREEN_HEIGHT - 1, stdout);
	fflush(stdout);
}

void draw_str(const char *str, char screen[], int x, int y){
	int i = 0;
	
	//copy the contents of the string to screen[]
	while(str[i] && (x + i) < SCREEN_WIDTH){
		screen[SCREEN_WIDTH * y + (x + i)] = str[i];
		i++;
	}
}

void draw_tile(const char *sprite, char screen[], int x, int y){
	int i = 0;
	int j = 0;
	
	//tiles are 3x3 characters wide
	x = x*3;
	y = y*3;
	
	while(i < 3){
		//check if the surface is within bounds
		j = 0;
		while(j < 3){
			if(x+j >= 0 && x+j < SCREEN_WIDTH && y+i >= 0 && y+i < SCREEN_HEIGHT){
				screen[SCREEN_WIDTH * (y + i) + x + j] = sprite[i * 3 + j];
			}
			j++;
		}
		i++;
	}
}

//create a file with player coordinates (5, 5)
void create_new_game(){
	FILE *out_file;
	int x_position = 5;
	int y_position = 5;
	
	//write to a new file in text mode
	fopen(SAVE_FILENAME, "wt");
	
	//print the position files
	fprintf(out_file, "%d %d\n", x_position, y_position);
	
	//close the file
	fclose(out_file);
}

void load_game(){
	FILE *save_file;
	
	int dest_x_position;
	int dest_y_position;
	
	int x_position;
	int y_position;
	
	int map_data[MAP_WIDTH * MAP_HEIGHT];
	
	int input;
	
	//load game file
	save_file = fopen(SAVE_FILENAME, "rt");
	
	//if the file doesn't exist
	if(!save_file){
		print_error_screen();
		
		//prompt the user to press any key to continue
		input = getch();
		if(input == 0 || input == 224){
			input = getch();
		}
		
		//go back to menu
		return;
	}
	
	fscanf(save_file, "%d%d", &x_position, &y_position);
	fclose(save_file);
	
	//load map
	load_map(map_data);
	
	do{
		//draw map and player
		print_game(map_data, x_position, y_position);
		
		//get user input from keyboard
		input = getch();
		//getch() returns a second value if the first value is 0 or 224
		if(input == 0 || input == 224){
			input = getch();
		}
		
		//handle input
		if(input == UP){
			//move player up
			dest_y_position--;
		}
		else if(input == LEFT){
			//move player left
			dest_x_position--;
		}
		else if(input == RIGHT){
			dest_x_position++;
		}
		else if(input == DOWN){
			dest_y_position++;
		}
		
		//check if the destination tile is not an obstruction
		if(map_data[dest_y_position * MAP_WIDTH + dest_x_position] == 0){
			x_position = dest_x_position;
			y_position = dest_y_position;
		}
	}
	while(input != ESC);
	
	//save the game
	save_file = fopen(SAVE_FILENAME, "wt");
	
	fprintf(save_file, "%d %d\n", x_position, y_position);
	fclose(save_file);
}

void load_map(int map_data[]){
	FILE *map_file;
	int tile_value;
	int i = 0;
	
	map_file = fopen(MAP_FILENAME, "rt");
	
	//read the values of each tile
	while(i < MAP_WIDTH * MAP_HEIGHT){
		fscanf(map_file, "%d", &tile_value);
		
		map_data[i] = tile_value;
		
		i++;
	}
	
	fclose(map_file);
}
