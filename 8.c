#include <stdio.h>
#define LEN 99
#define MAX -1

int main()
{
	int k;
	char c;
	int grid[LEN][LEN];
	int shadow[LEN][LEN]={0};
	for(int i=0;i<LEN;i++)
	{
		k=0;
		c=getchar();
		while(c!='\n')
		{
			grid[i][k++]=c-'0';
			c=getchar();
		}
	}
	
	int max;
	int count=0;
	

	for(int i=0;i<LEN;i++)
	{
		max=MAX;
		for(int j=0;j<LEN;j++)
		{
			if(grid[i][j]>max)
			{
				max=grid[i][j];
				if(shadow[i][j]==0)
				{
					count++;
					shadow[i][j]=1;
					
				}
			}

		}
	}
		
	for(int i=0;i<LEN;i++)
	{
		max=MAX;
		for(int j=LEN-1;j>=0;j--)
		{
			if(grid[i][j]>max)
			{
				max=grid[i][j];
				if(shadow[i][j]==0)
				{
					count++;
					shadow[i][j]=1;
				}
			}

		}
	}
	for(int j=0;j<LEN;j++)
	{
		max=MAX;
		for(int i=0;i<LEN;i++)
		{
			if(grid[i][j]>max)
			{
				max=grid[i][j];
				if(shadow[i][j]==0)
				{
					count++;
					shadow[i][j]=1;
				}
			}

		}
	}
	for(int j=0;j<LEN;j++)
	{
		max=MAX;
		for(int i=LEN-1;i>=0;i--)
		{
			if(grid[i][j]>max)
			{
				max=grid[i][j];
				if(shadow[i][j]==0)
				{
					count++;
					shadow[i][j]=1;
				}
			}
		}
	}
	
	printf("%d\n",count);
	return 0;
	
}
