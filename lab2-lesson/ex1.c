//Example 1 (if statements)

//move a coordinate in one direction according to the key pressed.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	char input;
	int success = 1;
	int x = 0;
	int y = 0;
	
	printf("Your current coordinate is (%d, %d).\n", x, y);
	printf("Press one of W, A, S or D to move the point.\n");
	
	//this function reads a key press in the console window.
	//warning: this code is not portable!
	input = getch();
	
	//move up
	if(input == 'w'){
		y -= 10;
	}
	//move left
	else if(input == 'a'){
		x -= 10;
	}
	//move down
	else if(input == 's'){
		y += 10;
	}
	//move right
	else if(input == 'd'){
		x += 10;
	}
	//other key was pressed
	else{
		success = 0;
	}
	
	if(success){
		printf("Your coordinate is now (%d, %d).\n", x, y);
	}
	else{
		printf("An invalid key was pressed.\n");
	}
	
	return 0;
}
