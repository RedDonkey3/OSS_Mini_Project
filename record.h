#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
// This structure means the information of the books in bookstore
typedef struct record {
	int id; // id: identification number
  	char title[64];
  	char author[64];
  	double price;
  	int stock;
} Record;

#endif
