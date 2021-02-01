//Example 2

//A program that prompts the user for number of the month
//and prints the name of the month

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int month_number;
	
	printf("Enter a number between 1-12: ");
	scanf("%d", &month_number);
	
	//print the name of the month
	if(month_number > 0 && month_number < 13){
		printf("The name of the month is ");
	}
	
	if(month_number == 1){
		printf("January");
	}
	else if(month_number == 2){
		printf("February");
	}
	else if(month_number == 3){
		printf("March");
	}
	else if(month_number == 4){
		printf("April");
	}
	else if(month_number == 5){
		printf("May");
	}
	else if(month_number == 6){
		printf("June");
	}
	else if(month_number == 7){
		printf("July");
	}
	else if(month_number == 8){
		printf("August");
	}
	else if(month_number == 9){
		printf("September");
	}
	else if(month_number == 10){
		printf("October");
	}
	else if(month_number == 11){
		printf("November");
	}
	else if(month_number == 12){
		printf("December");
	}
	else{
		printf("This month %d does not exist.", month_number);
	}
	printf("\n");
	
	return 0;
}
	