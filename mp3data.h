#ifndef MP3DATA_H
#define MP3DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Details
{
	char *artist;
	char *title;
	char *album;
	char *year;
	char *content;
	char *composer;
}Details;

/*checking operation type*/
OperationType check_operation(char *argv[]);

/*Validating Command line arguments for view*/
Status read_and_validate_args_view(char *argv[]);

/*reading details*/
Status view_details(char *argv[],Details *details);

/*printig details*/
void print_details(Details *details);

/*Validating Command line arguments for edit*/
Status read_and_validate_args_edit(char *argv[]);

Status edit_details(char *argv[],char *tag);
Status edit_call(char *argv[]);
void convert(void *ptr);
#endif
