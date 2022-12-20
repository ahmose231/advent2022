#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 64

int stack[9][LEN];
int bigindex[9]={0};

void insert(int c, int stackno)
{
	for(int i=bigindex[stackno];i>0;i--)
		stack[stackno][i]=stack[stackno][i-1];
	
	stack[stackno][0]=c;
	bigindex[stackno]++;
	return;
}
		

int main()
{
	char line[LEN];

	
	for(int i=0;i<8;i++)
	{
		fgets(line,LEN,stdin);
		
		for(int j=0;j<9;j++)
			if(line[1+(j*4)]!=' ')
				insert(line[1+(j*4)], j);
	}
	
	fgets(line,LEN,stdin);
	fgets(line,LEN,stdin);
	
	int howmany, from, to;
	int len;
	char *token;
	while(fgets(line,LEN,stdin)!=NULL)
	{
		len=strlen(line);
		if(len<2) continue;
		if(line[len-1]=='\n' || line[len-1]==EOF)
			line[--len]='\0';
		
		token=strtok(line," ");
		token=strtok(NULL," ");
		howmany=atoi(token);
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		from=atoi(token) - 1;
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		to=atoi(token) - 1;	
		
	
		for(int i=0;i<howmany;i++)
		{
			bigindex[from]--;
			stack[to][bigindex[to]] = stack[from][bigindex[from]];
			bigindex[to]++;
			
		}
	}
	
	for(int i=0;i<9;i++)
		printf("%c", stack[i][bigindex[i]-1]);
		
	return 0;
}
		
