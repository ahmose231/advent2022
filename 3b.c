#include <stdio.h>
#include <string.h>

#define LEN 64

int main()
{
	char line[LEN];

	int lower[26][3];
	int higher[26][3];
	int len;
	int total=0;
	int count=0;
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		len=strlen(line);
		if(len<2) continue;
		
		for(int i=0;i<26;i++)
			lower[i][0]=lower[i][1]=lower[i][2]=higher[i][0]=higher[i][1]=higher[i][2]=0;
		
		for(int m=0;m<2;m++)
		{
			len=strlen(line);

			if(line[len-1] == '\n' || line[len-1] == EOF)
				line[--len] = '\0';
			
			for(int i=0;i<len;i++)
				if(line[i]>='a' && line[i]<='z')
					lower[line[i]-'a'][m]++;
				else
					higher[line[i]-'A'][m]++;
				
			fgets(line,LEN,stdin);
		}
		
		len=strlen(line);

		if(line[len-1] == '\n' || line[len-1] == EOF)
			line[--len] = '\0';
		
		for(int i=0;i<len;i++)
			if(line[i]>='a' && line[i]<='z')
				lower[line[i]-'a'][2]++;
			else
				higher[line[i]-'A'][2]++;

		
			
		for(int i=0;i<26;i++)
			if(lower[i][0] && lower[i][1] && lower[i][2])
				total += i+1;
			
		for(int i=0;i<26;i++)
			if(higher[i][0] && higher[i][1] && higher[i][2])
				total += i+27;
	}
	
	printf("%d\n",total);
	return 0;
}
