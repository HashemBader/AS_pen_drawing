#include<stdio.h>
#define MAX 50
// the two major problems are: 
//problem 1: any attempt to go beyond the floor it will not make the turtle reach the boundary of the floor.
//problem 2: The whole turtle program does not execute when command 9 is entered. When the the user insert the command the program excute it instantly.
int position_row, position_column, direction, penDown, walk;

int is_valid_command(int command){
	if(command > 0 && command <= 9) 
		return 1;
	return 0;
}

void printFloor(int floor[][MAX]){
	for(int i =0; i<MAX; i++){
		for(int j= 0; j<MAX; j++){
		if(floor[i][j] == 1) printf("*");
		else printf(" ");
		}
		printf("\n");
	}
}

void execute_command(int command, int floor[][MAX]){
	
	if(!walk){
		
		if(command == 1){
				penDown = 1;
			}
		else if(command == 2){
				penDown = 0;
			}
		else if(command == 3){
			if(direction > 1) direction--;
				else direction = 4;
			}
		else if(command == 4){
			if(direction < 4) direction++;
			else direction = 1;
				
			}
		else if(command == 6){
				printFloor(floor);
			}
	}
	// problem 1 fixed here.
	else {
		if(direction == 1){
			
			if(position_column + command < MAX){
				for(int i = 0; i<= command; i++){
					if(penDown) floor[position_row][position_column + i] = 1;
				}
				position_column += command;
			}
			else if(position_column + command >= MAX){
			    for(int i = position_column; i< MAX; i++){
			        if(penDown) floor[position_row][i] = 1;
			    }
			    position_column = MAX-1;
			}
		}
		else if(direction == 2){
			if(position_row + command < MAX){
				for(int i = 0; i<= command; i++){
					if(penDown) floor[position_row + i][position_column] = 1;
				}
				position_row += command;
			}
			else if(position_row + command >= MAX){
			    for(int i = position_row; i< MAX; i++){
			        if(penDown) floor[i][position_column] = 1;
			    }
			    position_row = MAX-1;
			}
			
		}
		else if(direction == 3){
			if(position_column - command >= 0){
				for(int i = 0; i<= command; i++){
					if(penDown) floor[position_row][position_column - i] = 1;
				}
				position_column -= command;
			}
			else if(position_column - command < 0){
			    for(int i = 0; i<= position_column; i++){
			        if(penDown) floor[position_row][position_column - i] = 1;
			    }
			    position_column = 0;
			}
			
		}
		else{
			if(position_row - command >= 0){
				for(int i = 0; i<= command; i++){
					if(penDown) floor[position_row-i][position_column] = 1;
				}
				position_row -= command;
			}
			else if(position_row - command < 0){
			    for(int i = 0; i<= position_row; i++){
			        if(penDown) floor[position_row-i][position_column] = 1;
			    }
			    position_row = 0;
			}
		}
		
	}

}

int main()
{
	int rows, columns;
	int floor[MAX][MAX];
	//direction: 1-> right, 2-> down, 3-> left, 4->up
	int command, command1;
	position_row = 0;
	position_column = 0;
	direction = 1;
	penDown = 0;
	walk = 0;
	//Initialize floor with zeros   
	for (rows = 0; rows < MAX; rows++)
		 for (columns = 0; columns < MAX; columns++)
			 floor[rows][columns] = 0;
	 
	 //Keeps on running until command 9 is entered
	  int count = 0 ;
	 int arr[1000];
	 int arr1[1000];
	 do{
		 scanf("%d", &command);
		  if (command == 5){
			  scanf(",%d", &command1);
			  arr[count] = command;
			  arr1[count] = command1;
			  count++;
			  }
		  else{
			  arr[count] =  command;
			  count++;
		  }
	 }
	 while(command != 9);
	 // problem 2 fixed here.
	 // starts excuting when the command 9 is entered  
	 for (int i = 0; i < 1000; i++){
	     if (arr[i] == 5){
	         command1 = arr1[i];
	         command = arr[i];
	         walk = 1;
	         if(is_valid_command(command) && walk){
			execute_command(command1,floor);}
		else if(is_valid_command(command)&& !walk){
			execute_command(command,floor);}
	     }
	     else {
	         command = arr[i];
	         walk = 0;
	     if(is_valid_command(command) && walk){
			execute_command(command1,floor);}
		else if(is_valid_command(command)&& !walk){
			execute_command(command,floor);}
	     }
	 }
	     	 return 0;
}