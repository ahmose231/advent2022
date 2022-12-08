#include <stdio.h>
#include <string.h>

#define LEN 64

int main()
{
	char line[LEN];
	int lower[26][2];
	int higher[26][2];
	int len;
	int total=0;
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		len=strlen(line);
		if(len<2) continue;
		if(line[len-1] == '\n' || line[len-1] == EOF)
			line[--len] = '\0';
		
		for(int i=0;i<26;i++)
			lower[i][0]=lower[i][1]=higher[i][0]=higher[i][1]=0;
		
		for(int i=0;i<len/2;i++)
			if(line[i]>='a' && line[i]<='z')
				lower[line[i]-'a'][0]++;
			else
				higher[line[i]-'A'][0]++;

		for(int i=len/2;i<len;i++)
			if(line[i]>='a' && line[i]<='z')
				lower[line[i]-'a'][1]++;
			else
				higher[line[i]-'A'][1]++;			
			
		for(int i=0;i<26;i++)
			if(lower[i][0] && lower[i][1])
				total += i+1;
			
		for(int i=0;i<26;i++)
			if(higher[i][0] && higher[i][1])
				total += i+27;		
			
	}
	
	printf("%d\n",total);
	return 0;
}
