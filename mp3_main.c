/*
Name		  : Swathi Gajaram
Date		  : 
Description   : 
Sample input  : 
Sample output : 
 */

#include <stdio.h>
#include "types.h"
#include "mp3data.h"
#include <string.h>

int main(int argc,char **argv)
{
	Details details;
	if(argc==3)
	{
		if(check_operation(argv)==view)
		{
			printf("------------------------SELECTED VIEWING DETAILS--------------------------\n\n");
			if(read_and_validate_args_view(argv)==success)
			{
				//printf("File validated\n");
				if(view_details(argv,&details)==success)
				{
					print_details(&details);
				}
			}
			printf("\n--------------------------------------------------------------------------\n");
		}
		else
		{
			printf("To view please pass like : ./a.out -v mp3filename\n");
		}
	}
	else if(argc==5)
	{
		if(check_operation(argv)==edit)
		{
			printf("------------------------SELECTED EDIT DETAILS--------------------------\n\n");
			if(read_and_validate_args_edit(argv)==success)
			{
				if(edit_call(argv)==success)
				{
					printf("Edit Successfull\n");
				}
			}
		}
	}
	else if(argc==2)
	{
		if(check_operation(argv)==help)
		{
			printf("\n------------------------HELP MENU--------------------------\n\n");
			printf("1. -v -> to view mp3 file contents\n2. -e -> to edit mp3 file contents\n");
			printf("\t2.1 -t -> to edit song title\n\t2.2 -a -> to edit artist name\n\t2.3 -A -> to edit album name\n\t2.4 -y -> to edit year\n\t2.5 -m -> to edit content\n\t2.6 -c -> to edit comment\n\n");
			printf("-----------------------------------------------------------\n\n");
		}

	}
	else
	{
		printf("--------------------------------------------------\n");
		printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
		printf("USAGE :\n");
		printf("To view please pass like : ./a.out -v mp3filename\n");
		printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_texy mp3filename\n");
		printf("To get help pass like : ./a.out --help\n");
		printf("--------------------------------------------------\n");
	}


	return 0;
}


OperationType check_operation(char *argv[])
{
	if(!strcmp(argv[1],"-v"))
		return view;
	else if(!strcmp(argv[1],"-e"))
		return edit;
	else if(!strcmp(argv[1],"--help"))
		return help;
	else
		return unsupported;
}
