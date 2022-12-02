#include <stdio.h>
#define LEN 8

int main()
{
	char line[LEN];
	int total=0;
	int score;
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		switch(line[0])
		{
			case 'A':
			switch(line[2])
			{
				case 'X':
				score=1+3;
				break;
				
				case 'Y':
				score=2+6;
				break;
				
				case 'Z':
				score=3+0;
				break;
			}
			break;
			
			case 'B':
			switch(line[2])
			{
				case 'X':
				score=1+0;
				break;
				
				case 'Y':
				score=2+3;
				break;
				
				case 'Z':
				score=3+6;
				break;
			}
			break;

			case 'C':
			switch(line[2])
			{
				case 'X':
				score=1+6;
				break;
				
				case 'Y':
				score=2+0;
				break;
				
				case 'Z':
				score=3+3;
				break;
			}
			break;
		}
		
		total += score;
	}
	
	printf("%d\n", total);
	return 0;
}
