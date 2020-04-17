#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

// Function: clear_buffer()
// Input: none
// Output: none
// Clear line from read buffer
void clear_buffer() {
  while (getchar() != '\n');
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Create a new record
void add_a_record(Record records[]) {
  // TODO: Modify this function as you need
  char add[64] = "";
  int size = 0;

  while (records[size].id != 0) size++;

  printf("\t1. Add a new book from the standard input\n");
  printf("\t2. Add a new book from a data file\n");
  printf("\n\tSelect a menu> ");
  fgets(add, 64, stdin);
  add[strlen(add) - 1] = '\0';

  if (!strcmp(add, "1")) add_a_recordU(records);
  else if (!strcmp(add, "2")) add_a_recordD(records);
  else printf("Unknown menu: %s\n", add);
}


// Function: add_a_recordU()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Take user's input and create a new record
void add_a_recordU(Record records[]){
  int size = 0;

  while (records[size].id != 0) size++;

  printf("\n\tEnter the title of book: ");
  fgets(records[size].title, 64, stdin);
  records[size].title[strlen(records[size].title) - 1] = '\0';
  printf("\tEnter the author of the book: ");
  fgets(records[size].author, 64, stdin);
  records[size].author[strlen(records[size].author) - 1] = '\0';
  printf("\tEnter the price($) of the book: ");
  scanf("%lf", &records[size].price);
  clear_buffer();
  printf("\tEnter the stock of the book: ");
  scanf("%d", &records[size].stock);
  clear_buffer();
  records[size].id = size + 1;
  printf("\n\tSucceeded\n\n");
}


// Function: add_a_recordD()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Create a new data record from a data file
void add_a_recordD(Record records[]){
  int size = 0;
  int ch;
  int i = 0, j = 0;
  char content[64] = "";

  while (records[size].id != 0) size++;

  FILE * fp = fopen("datum.txt", "rt");
  if (fp == NULL) {
    printf("\n\tFailed\n\n");
    return;
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ';') content[i++] = ch;
    else {
      content[i] = 0;
      if (j == 0)  strcpy(records[size].title, content);
      else if (j == 1) strcpy(records[size].author, content);
      else if (j == 2) records[size].price = atof(content);

      j++;
      i = 0;
      content[0] = 0;
    }
  }

  content[i - 1] = 0;
  records[size].stock = atoi(content);
  records[size].id = size + 1;
  printf("\n\tSucceeded\n\n");
  fclose(fp);
}


// Function: print_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Print all/specific records
void print_records(Record records[]){
	// TODO: Modify this function as you need
  char print[64] = "";
  int size = 0;

  while (records[size].id != 0) size++;
  if (size == 0) {
    printf("The book does not exist\n\n");
    return;
  }
  
  printf("\t1. Print all books\n");
  printf("\t2. Print specific books\n");
  printf("\n\tSelect a menu> ");
  fgets(print, 64, stdin);
  print[strlen(print) - 1] = '\0';

  if (!strcmp(print, "1")) print_all(records);
  else if (!strcmp(print, "2")) print_specific(records);
  else printf("Unknown menu: %s\n", print);
  printf("\n");
}


// Function: print_all()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Print all records
void print_all(Record records[]){
  int size = 0;

  printf("\n%2s\t\t%18s\t\t%32s\t%18s\t%3s\n", "ID", "Title", "Author", "Price", "Stock");

  while (records[size].id != 0) {
    printf("%4d\t%-40s\t%-24s\t%6.2lf\t %3d\n", records[size].id, records[size].title, records[size].author, records[size].price, records[size].stock);
    size++;
  }
}


// Function: print_specific()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Print specific records
void print_specific(Record records[]){
  char print[64] = "";
  int size = 0;
  char title[64] = "";
  char author[64] = "";
  int i = 0;

  while (records[size].id != 0) size++;
  
  printf("\t\t1. Find the Title\n");
  printf("\t\t2. Find the Author\n");
  printf("\n\t\tSelect a menu> ");
  fgets(print, 64, stdin);
  print[strlen(print) - 1] = '\0';

  if (!strcmp(print, "1")) {
    printf("\t\t\tEnter the title: ");
    fgets(title, 64, stdin);
    title[strlen(title) - 1] = '\0';

    printf("\n%2s\t\t%18s\t\t%32s\t%18s\t%3s\n", "ID", "Title", "Author", "Price", "Stock");
    while (i < size) {
      if (!strcmp(title, records[i].title))
        printf("%4d\t%-40s\t%-24s\t%6.2lf\t %3d\n", records[i].id, records[i].title, records[i].author, records[i].price, records[i].stock);
      i++;
    }
  }
  else if (!strcmp(print, "2")) {
    printf("\t\t\tEnter the author: ");
    fgets(author, 64, stdin);
    author[strlen(author) - 1] = '\0';

    printf("\n%2s\t\t%18s\t\t%32s\t%18s\t%3s\n", "ID", "Title", "Author", "Price", "Stock");
    while (i < size) {
      if (!strcmp(author, records[i].author))
        printf("%4d\t%-40s\t%-24s\t%6.2lf\t %3d\n", records[i].id, records[i].title, records[i].author, records[i].price, records[i].stock);
      i++;
    }
  }
  else printf("Unknown menu: %s\n", print);
}


// TODO: Add more functions to fulfill the requirements
// Function: write_to_file()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Write the entire records to a data file
void write_to_file(Record records[]){
  int size = 0;
  int i = 0;

  while (records[size].id != 0) size++;

  FILE * fp = fopen("result.txt", "wt");
  if (fp == NULL) {
    printf("\n\tFailed\n\n");
    return;
  }

  while (i < size) {
    fprintf(fp, "%s;%s;%.2lf;%d\n", records[i].title, records[i].author, records[i].price, records[i].stock);
    i++;
  }

  printf("\nSucceeded\n\n");
  fclose(fp);
}


// Function: load()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Load the data from a data file
void load(Record records[]){
  int size = 0;
  int ch;
  int i = 0, j = 0, k = 0;
  char content[64] = "";

  while (records[size].id != 0) size++;

  FILE * fp = fopen("data.txt", "rt");
  if (fp == NULL) {
    printf("\n\tFailed\n\n");
    return;
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ';') {
      if (ch != '\n') content[i++] = ch;
      else {
        content[i] = 0;
        records[k].stock = atoi(content);
        records[k].id = k + 1;
        k++;
        j = 0;
        i = 0;
        content[0] = 0;
      }
    }
    else {
      content[i] = 0;
      if (j == 0) strcpy(records[k].title, content);
      else if (j == 1) strcpy(records[k].author, content);
      else if (j == 2) records[k].price = atof(content);

      j++;
      i = 0;
      content[0] = 0;
    }
  }

  printf("\nSucceeded\n\n");
  fclose(fp);
}


// Function: write_report()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Export the entire records in a report format
void write_report(Record records[]){
  int size = 0;
  int i = 0;

  while (records[size].id != 0) size++;

  FILE * fp = fopen("report.txt", "wt");
  if (fp == NULL) {
    printf("\n\tFailed\n\n");
    return;
  }

  fputs("******************************************************************************************\n", fp);
  fputs("\tID\t\t\t\t\t\t\tTitle\t\t\t\t\t\t\t\t\t\t\t\t\tAuthor\t\t\t\t\t\t\t\t\t\tPrice\t\tStock\n", fp);
  fputs("******************************************************************************************\n", fp);

  while (i < size) {
    fprintf(fp, "%4d\t%-40s\t%-24s\t%6.2lf\t %3d\n", records[i].id, records[i].title, records[i].author, records[i].price, records[i].stock);
    i++;
  }

  printf("\nSucceeded\n\n");
  fclose(fp);
}


// Function: update_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Update a specific record
void update_a_record(Record records[]){
  int size = 0;
  int id = 0;

  while (records[size].id != 0) size++;

  printf("\tEnter the id which you want to update: ");
  scanf("%d", &id);
  clear_buffer();

  for (int i = 0; i < size; i++) {
    if (records[i].id == id) {
      printf("\n\tEnter the new title of book: ");
      fgets(records[i].title, 64, stdin);
	    records[i].title[strlen(records[i].title) - 1] = '\0';
      printf("\tEnter the new author of the book: ");
      fgets(records[i].author, 64, stdin);
	    records[i].author[strlen(records[i].author) - 1] = '\0';
      printf("\tEnter the new price($) of the book: ");
      scanf("%lf", &records[i].price);
      clear_buffer();
      printf("\tEnter the new stock of the book: ");
      scanf("%d", &records[i].stock);
      clear_buffer();
      printf("\n\tSucceeded\n\n");
      return;
    }
  }
}


// Function: delete_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Delete specific records
void delete_records(Record records[]){
  int size = 0;
  int n = 0, a= 0, b = 0, c = 0;
  int* arr;
  char arrstr[256];
  char temp[128];

  while (records[size].id != 0) size++;

  printf("\tHow many books would you like to delete?: ");
  scanf("%d", &n);
  clear_buffer();

  arr = (int*)malloc(sizeof(int) * n);
  printf("\tEnter the ids to delete in sequence: ");
  fgets(arrstr, 256, stdin);
  arrstr[strlen(arrstr) - 1] = '\0';

  while (arrstr[c] != '\0') {
    if (arrstr[c] != ' ') {
      temp[a] = arrstr[c];
      a++;
    }
    else {
      arr[b] = atoi(temp);
      b++;
      temp[0] = 0;
      a = 0;
    }
    c++;
  }

  arr[b] = atoi(temp);
  a = 0;

  for (int i = 0; i < size; i++) {
    if (i + 1 == arr[a]) {
      records[i].title[0] = 0;
      records[i].author[0] = 0;
      records[i].price = 0;
      records[i].stock = 0;
      records[i].id = -1;
      a++;
    }
  }
  printf("\n\tSucceeded\n\n");
}

