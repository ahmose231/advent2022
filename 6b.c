#include <stdio.h>
#include <string.h>

int main()
{
	int c;
	int word[14]={0};
	int count=0;
	int flag;
	int alphabet[26]={0};
	c=getchar();
	while(1)
	{
		count++;
		
		if(count>14)
			alphabet[word[0]-'a']--;
		
		for(int i=0;i<13;i++)
			word[i]=word[i+1];
		
		word[13]=c;
		alphabet[word[13]-'a']++;
		
		flag=1;
		for(int i=0;i<26;i++)
			if(alphabet[i]>1)
				flag=0;
			
		if(flag && count>13)
			break;
		
		c=getchar();
		
	}
	
	printf("%d\n",count);
	for(int i=0;i<14;i++)
		printf("%c",word[i]);
	return 0;
}
