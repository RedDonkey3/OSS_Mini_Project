#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS] = {0, };

	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need
	if(!strcmp(input, "1")) 
    		add_a_record(records);
	else if(!strcmp(input, "2"))
		print_records(records);	
  	else if(!strcmp(input, "3"))
		write_to_file(records);	  
  	else if(!strcmp(input, "4"))
		load(records);	    
  	else if(!strcmp(input, "5"))
		write_report(records);
  	else if(!strcmp(input, "6"))
    		update_a_record(records);
  	else if(!strcmp(input, "7"))
    		delete_records(records);
	else if(!strcmp(input, "8"))
		defragment(records);
 	else if(!strcmp(input, "9"))
    		sort(records);
  	else if(!strcmp(input, "10"))
    		delete_nulls(records);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// Display the menu
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Bookstore management system \n");
	printf("******************************\n");
	printf(" 1. Add a new book\n");
	printf(" 2. Print all/specific books\n");
	printf(" 3. Write the records to a file\n");
	printf(" 4. Load the records from a file\n");
	printf(" 5. Write the report\n");
  	printf(" 6. Update book details\n");
  	printf(" 7. Delete books\n");
	printf(" 8. Optimize (defragment) the books\n");
  	printf(" 9. Sort the books\n");
  	printf(" 10. Delete empty records (use after defragment)\n");
	printf(" 99. Quit\n");
}
