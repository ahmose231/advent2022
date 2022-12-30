#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LEN 128
#define TOTALROUND 20
#define TOTALMONKEY 8
#define TOTALITEMS 100

struct proto_monkey {
	int item_count;
	long long int item[TOTALITEMS];
	char operation;
	int operator;
	int test;
	int truefalse[2];
} monkey[TOTALMONKEY];

int monkeybusiness[TOTALMONKEY];

int main()
{
	char line[LEN];
	char *token;
	int len;
	
	for(int i=0;i<TOTALMONKEY;i++)
	{
		fgets(line,LEN,stdin);
		
		fgets(line,LEN,stdin);
		token=strtok(line," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		while(token!=NULL)
		{
			len=strlen(token);
			if(token[len-1]==',') token[len-1]='\0';
			monkey[i].item[monkey[i].item_count++] = atoll(token);
			token=strtok(NULL," ");
		}
		
		fgets(line,LEN,stdin);
		token=strtok(line," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		monkey[i].operation=token[0];
		token=strtok(NULL," ");
		if(token[0]=='o')
			monkey[i].operator=-1;
		else
			monkey[i].operator=atoi(token);
		
		fgets(line,LEN,stdin);
		token=strtok(line," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		monkey[i].test=atoi(token);
		
		fgets(line,LEN,stdin);
		len=strlen(line);
		monkey[i].truefalse[0]=line[len-2]-'0';
		
		fgets(line,LEN,stdin);
		len=strlen(line);
		monkey[i].truefalse[1]=line[len-2]-'0';

		fgets(line,LEN,stdin);
	}
	

	
	long long int operand1, operand2;

	
	for(int round=0;round<TOTALROUND;round++)
	{
		for(int i=0;i<TOTALMONKEY;i++)
		{

			for(int j=0;j<monkey[i].item_count;j++)
			{

				
				operand1=monkey[i].item[j];
				
				if(monkey[i].operator==-1) 
					operand2=operand1;
				else
					operand2=monkey[i].operator;

			
				
				if(monkey[i].operation=='+')
					monkey[i].item[j] = operand1 + operand2;
				else
					monkey[i].item[j] = operand1 * operand2;
				


				monkey[i].item[j] /= 3;
				
				
				
				if(monkey[i].item[j] % monkey[i].test == 0)
					monkey[monkey[i].truefalse[0]].item[monkey[monkey[i].truefalse[0]].item_count++] = monkey[i].item[j];
				else
					monkey[monkey[i].truefalse[1]].item[monkey[monkey[i].truefalse[1]].item_count++] = monkey[i].item[j];
				
				
				
				monkeybusiness[i]++;
			
			}
			
		
			monkey[i].item_count=0;
		}
		
	}

	
	int max1=0;
	int maxindex1;
	for(int i=0;i<TOTALMONKEY;i++)
		if(max1<monkeybusiness[i])
		{
			max1=monkeybusiness[i];
			maxindex1=i;
		}
		
	int max2=0;
	for(int i=0;i<TOTALMONKEY;i++)
		if(i!=maxindex1)
			if(max2<monkeybusiness[i])
				max2=monkeybusiness[i];
	
	
	printf("%d\n",max1*max2);
	return 0;
}
