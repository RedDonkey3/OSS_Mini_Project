#include <stdio.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// collect all the empty element in data array and move them to the end of the array
int defragment(Record records[]){
  // TODO: Modify this function as you need
  int size = 0;   // size: size of the records[]
  int count = 0;  // count: the number of the empty element in data array
  int i = 0;      // i: index of empty element in records[]
  int j = 0;      // j: index of non-empty element to be swapped with records[i]
  Record temp;    // temp: A variable required for swapping
 
  while (records[size].id != 0) size++; // 'records[index].id == 0' means that no information has been entered in that index

  while (i <= size) {             // check all elements of records[]
    while (records[i].id != -1) { // find an index for an empty element
                                  // 'records[index].id == -1' means that deletion has occurred in that index
      if (i != size) i++;
      else break;
    }

    // i = index of empty element in records[]

    j = i;

    while (records[j].id == -1) { // find an index which is greater than i for an non-empty element
      if (j != size) j++;
      else break;
    }

    // j = index of non-empty element to be swapped with records[i]

    if (j == size) break; // There is no empty element in the middle of records[]
    else {                // swap
      temp = records[i];
      records[i] = records[j];
      records[j] = temp;

      i++;
      count++;           // count: the number of the empty element in data array
    }
  }

  // TODO: return 1 if defragment succeed; return 0 otherwise
  if (count != 0) {     // At least one swapping happened
    printf("\nSucceeded\n\n");
	  return 1;
  }
  else {
    printf("\nFailed\n\n");
    return 0;
  }
}


// Function: sort()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Arrange (sort) the order of data records based on user specified conditions
void sort(Record records[]){
  // TODO: Modify this function as you need
  int size = 0;       // size: size of the records[]
  char sort[64] = ""; // sort: string to receive menu input
  Record temp;        // temp: A variable required for swapping

  while (records[size].id != 0) size++;   // 'records[index].id == 0' means that no information has been entered in that index
  
  printf("\t1. Sort by title\n");
  printf("\t2. Sort by author\n");
  printf("\n\tSelect a menu> ");
  fgets(sort, 64, stdin);                 // receive menu input
  sort[strlen(sort) - 1] = '\0';

  if (!strcmp(sort, "1")) {               // select menu "Sort by title"
    for (int i = 0; i < size - 1; i++) {  // use bubble sort algorithm
      for (int j = 0; j < size - i - 1; j++) {
        if (strcmp(records[j].title, records[j + 1].title) > 0) { // ascending order
          temp = records[j];
          records[j] = records[j + 1];
          records[j + 1] = temp;
        }
      }
    }
    printf("\n\tSucceeded\n\n");
  }
  else if (!strcmp(sort, "2")) {          // select menu "Sort by author"
    for (int i = 0; i < size - 1; i++) {  // use bubble sort algorithm
      for (int j = 0; j < size - i - 1; j++) {
        if (strcmp(records[j].author, records[j + 1].author) > 0) { // ascending order
          temp = records[j];
          records[j] = records[j + 1];
          records[j + 1] = temp;
        }
      }
    }
    printf("\n\tSucceeded\n\n");
  }
  else printf("Unknown menu: %s\n", sort);
}


// TODO: Add more functions to fulfill the optional requirements
// Function: delete_nulls()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// delete null records (you should use this function after defragment!)
void delete_nulls(Record records[]){
  int size = 0;   // size: size of the records[]
  int i = 0;      // i: index of empty element in records[]
  int count = 0;  // count: the number of the empty element in the end of data array

  while (records[size].id != 0) size++; // 'records[index].id == 0' means that no information has been entered in that index
  
  while (i != size) {             // check all elements of records[]
    if (records[i].id != -1) i++; // find an first index for an empty element
                                  // 'records[index].id == -1' means that deletion has occurred
    else {
      while (i != size) {
        records[i].id = 0;        // delete null records
        i++;
        count++;                  // count: the number of the empty element in the data array
      }
    }
  }

  if (count != 0) {               // There was at least one null record
    size = size - count;
    printf("\nSucceeded\n\n");
  }
  else {
    printf("\nFailed\n\n");
  }
}
