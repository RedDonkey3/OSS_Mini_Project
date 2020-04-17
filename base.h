#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void clear_buffer();

void add_a_record(Record[]);
void add_a_recordU(Record[]);
void add_a_recordD(Record[]);

void print_records(Record[]);
void print_all(Record[]);
void print_specific(Record[]);

void write_to_file(Record[]);
void load(Record[]);
void write_report(Record[]);

void update_a_record(Record[]);
void delete_records(Record[]);

#endif
