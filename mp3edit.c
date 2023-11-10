#include "mp3data.h"
#include "types.h"
Status read_and_validate_args_edit(char *argv[])
{
	if(argv[4]==NULL)
		return failure;
	FILE *fptr=fopen(argv[4],"r");
	if(fptr==NULL)
	{
		printf("Error in opening file\n");
		return failure;
	}
	char *file=malloc(3);
	fread(file,3,1,fptr);
	if(!strcmp(file,"ID3"));
	//	printf("it is ID3\n");
	else
		return failure;
	short int version;
	fread(&version,2,1,fptr);
	//	printf("%hx\n",version);
	if(version==3);
	//	printf("it is 0300 version\n");
	else
		return failure;
	if(strstr(argv[4],".mp3")!=NULL);
	//	printf("Extension Checked\n");
	else
		return failure;
	fclose(fptr);
	
	return success;
}

Status edit_call(char *argv[])
{
	char *tag=malloc(4);
	if(strcmp(argv[2],"-t")==0)
	{
		strcpy(tag,"TIT2");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------TITLE Changed Succesfully-----------------\n");
		}
	}
	else if(strcmp(argv[2],"-a")==0)
	{
		strcpy(tag,"TPE1");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------ARTIST Changed Succesfully-----------------\n");
		}
	}
	else if(strcmp(argv[2],"-A")==0)
	{
		strcpy(tag,"TALB");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------ARTIST Changed Succesfully------------------\n");
		}
	}
	else if(strcmp(argv[2],"-y")==0)
	{
		strcpy(tag,"TYER");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------YEAR Changed Succesfully------------------\n");
		}
	}
	else if(strcmp(argv[2],"-m")==0)
	{
		strcpy(tag,"TCON");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------CONTENT Changed Succesfully------------------\n");
		}
	}
	else if(strcmp(argv[2],"-c")==0)
	{
		strcpy(tag,"COMM");
		if(edit_details(argv,tag)==success)
		{
			printf("----------------COMMENT Changed Succesfully------------------\n");
		}
	}
	else
	{
		printf("Enter correct change option -t/-a/-A/-m/-y/-c\n");
	}
	return success;
}
Status edit_details(char *argv[],char *tag)
{
	FILE *fptr=fopen(argv[4],"r+");
	if(fptr==NULL)
	{
		printf("Error in opening file in edit\n");
		return failure;
	}
	fseek(fptr,10,SEEK_SET);
	char *tname=malloc(4);
	for(int i=0;i<6;i++)
	{
		fread(tname,4,1,fptr);
		int size=0;
		fread(&size,4,1,fptr);
		convert(&size);
		fseek(fptr,3,SEEK_CUR);
		if(strcmp(tname,tag)==0)
		{
			fwrite(argv[3],size-1,1,fptr);
			return success;
		}
		else
			fseek(fptr,size-1,SEEK_CUR);
	}
	fclose(fptr);
	return success;
}
