#include "types.h"
#include "mp3data.h"

Status read_and_validate_args_view(char *argv[])
{
	if(argv[2]==NULL)
		return failure;
	FILE *fptr=fopen(argv[2],"r");
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
	if(strstr(argv[2],".mp3")!=NULL);
	//	printf("Extension Checked\n");
	else
		return failure;
	fclose(fptr);
	return success;
}

Status view_details(char *argv[],Details *details)
{
	FILE *fptr=fopen(argv[2],"r");
	if(fptr==NULL)
	{
		printf("Error in opening file\n");
		return failure;
	}
	fseek(fptr,10,SEEK_SET);
	char *name=malloc(4);
	for(int i=0;i<6;i++)
	{
		fread(name,4,1,fptr);
		int size=0;
		fread(&size,4,1,fptr);
		convert(&size);
		fseek(fptr,3,SEEK_CUR);
		if(strcmp(name,"TIT2")==0)
		{
			details->title=malloc(size);
			fread(details->title,size-1,1,fptr);
		}
		else if(strcmp(name,"TPE1")==0)
		{
			details->artist=malloc(size);
			fread(details->artist,size-1,1,fptr);
		}
		else if(strcmp(name,"TALB")==0)
		{
			details->album=malloc(size);
			fread(details->album,size-1,1,fptr);
		}
		else if(strcmp(name,"TYER")==0)
		{
			details->year=malloc(size);
			fread(details->year,size-1,1,fptr);
		}
		else if(strcmp(name,"TCON")==0)
		{
			details->content=malloc(size);
			fread(details->content,size-1,1,fptr);
		}
		else if(strcmp(name,"COMM")==0)
		{
			details->composer=malloc(size);
			fread(details->composer,size-1,1,fptr);
		}
	}
	return success;
}

void print_details(Details *details)
{
		printf("%-15.7s %-8.1s %-s\n","TITLE",":",details->title);
		printf("%-15.7s %-8.1s %-s\n","ARTIST",":",details->artist);
		printf("%-15.7s %-8.1s %-s\n","ALBUM",":",details->album);
		printf("%-15.7s %-8.1s %-s\n","YEAR",":",details->year);
		printf("%-15.7s %-8.1s %-s\n","MUSIC",":",details->content);
		printf("%-15.7s %-8.1s %-s\n","COMMENT",":",details->composer);
}

void convert(void *ptr)
{
	for(int i=0;i<2;i++)
	{
		char temp=*(char *)(ptr+i);
		*(char *)(ptr+i)=*(char *)(ptr+3-i);
		*(char *)(ptr+3-i)=temp;
	}
}
