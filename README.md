# OSS_Mini_Project / 21600153 / Junhee Kim / Bookstore management system

It is a program that makes it easy to access and handle information on books that exist in bookstore.
The program stores information on books that exist in bookstore in the form of a data set and has functions that deal with this data.
This program allows you to add or modify data and delete it.
It is also possible to store information in other data files, when it is possible to save it in a report format.
Finally, the program can help you easily find information about your saved books or sort them out according to specified conditions.

// type definition   
// This structure means the information of the books in booksotre   
typedef struct record {
	  int id; // id: identification number   
  	char title[64];   
  	char author[64];   
  	double price;   
  	int stock;   
} Record;

// Take user’s input and create a new record   
void add_a_recordU(Record[]);

// Create a new data record from a data file   
void add_a_recordD(Record[]);

// Print all records   
void print_all(Record[]);

// Print specific records (by title or author)   
void print_specific(Record[]);

// Write the entire records to a data file   
void write_to_file(Record[]);

// Load the data from a data file   
void load(Record[]);

// Export the entire records in a report format   
void write_report(Record[]);

// Update a specific record (by id)   
void update_a_record(Record[]);

// Delete specific records (by id)   
void delete_records(Record[]);

// Collect all the empty element in data array and move them to the end of the array   
int defragment(Record[]);

// Arrange the order of data records based on user specified conditions (by title or author)   
void sort(Record[]);

// Delete null records (You should use this function after invoking defragment())   
void delete_nulls(Record[]);
