#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 16

int main()
{
	char crt[240];
	char line[LEN];
	int cycle=0;
	int sum=0;
	int len;
	char *token;
	int r=1;
	while(fgets(line,LEN,stdin)!=NULL)
	{
		len=strlen(line);
		if(line[len-1]=='\n' || line[len-1]==EOF)
			line[--len]='\0';
		if(len<2) continue;
		
		if(strcmp(line,"noop")==0)
		{
			
			if(cycle%40==r || cycle%40==r-1 || cycle%40==r+1)
				crt[cycle]='#';
			else
				crt[cycle]=' ';
			cycle++;
			continue;
		}
		
		token=strtok(line," ");
		token=strtok(NULL," ");
		
			
			if(cycle%40==r || cycle%40==r-1 || cycle%40==r+1)
				crt[cycle]='#';
			else
				crt[cycle]=' ';
		cycle++;
			
			if(cycle%40==r || cycle%40==r-1 || cycle%40==r+1)
				crt[cycle]='#';
			else
				crt[cycle]=' ';
		cycle++;
		r += atoi(token);
	}
	
	
	int m=0;
	for(int i=0;i<6;i++)
	{	
		for(int j=0;j<40;j++)
			printf("%c",crt[m++]);
		printf("\n");
	}
	return 0;
}
