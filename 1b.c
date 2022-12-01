#include <stdio.h>
#define LEN 8
int main()
{
	int max=0;
	int max2=0, max3=0;
	int total=0;
	char line[LEN];
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		if(line[0]==' ' || line[0]=='\n')
		{
			if(max<total)
			{
				max3=max2;
				max2=max;
				max=total;
			}
			else if(max2<total)
			{
				max3=max2;
				max2=total;
			}
			else if(max3<total)
				max3=total;
			
			total=0;
		}
		else
			total += atoi(line);
	}
	
	if(max<total)
	{
		max3=max2;
		max2=max;
		max=total;
	}
	else if(max2<total)
	{
		max3=max2;
		max2=total;
	}
	else if(max3<total)
		max3=total;
	
	
	printf("%d\n",max+max2+max3);
	
	return 0;
}
