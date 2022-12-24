#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 32 
#define MAX 100000

struct node {
	char name[LEN]; 
	
	int subdirs_count; 
	struct node *subdirs[LEN];
	
	int files_size;
	
	struct node *parent_dir;
};

int sum=0;

int delve(struct node *input)
{	

	int total = input->files_size;
	for(int i=0;i<input->subdirs_count;i++)
		total += delve(input->subdirs[i]);
		

	if(total<MAX) sum+=total;
	
	return total;

}

int main()
{
	char line[LEN];
	char *token;
	int len;
	
	struct node *root, *current;
	
	root = malloc(sizeof(struct node));
	root -> parent_dir = NULL;
	
	strcpy(root -> name, "/");
	root -> files_size=0;
	root -> subdirs_count=0;
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		len = strlen(line);
		if(len<2) continue;
		if(line[len-1]=='\n' || line[len-1]==EOF)
			line[--len]='\0';
	
		here:
	
		token = strtok(line," ");
		
		if(strcmp(token, "$")==0)
		{
			token = strtok(NULL," ");
			if(strcmp(token, "cd")==0)
			{
				token = strtok(NULL," ");
				
				if(strcmp(token,"/") == 0)
				{
					current = root;
					continue;
				}
				
				if(strcmp(token,"..")==0)
				{
					current = current -> parent_dir;
					continue;
				}
				
				for(int i=0; i < current -> subdirs_count; i++)
				{
					if(strcmp(current -> subdirs[i] -> name, token) == 0)
					{
						current = current -> subdirs[i];
						continue;
					}
				}
			}
			else {
				while(1)
				{

					fgets(line,LEN,stdin);
					
					len = strlen(line);
					if(len<2) goto here;
					if(line[len-1]=='\n' || line[len-1]==EOF)
						line[--len]='\0';
						
					if(line[0]=='$')
						goto here;
					
					token = strtok(line," ");
					
					if(strcmp(token,"dir")==0)
					{
						current -> subdirs[current -> subdirs_count] = malloc(sizeof(struct node));
						
						token = strtok(NULL," ");
						strcpy(current -> subdirs[current -> subdirs_count] -> name, token);
						current -> subdirs[current -> subdirs_count] -> files_size = 0;
						current -> subdirs[current -> subdirs_count] -> subdirs_count = 0;
						current -> subdirs[current -> subdirs_count] -> parent_dir = current;
						
						current -> subdirs_count++;
					}
					else
					{
						current -> files_size += atoi(token);

					}
				}
			}
		}
	}

	delve(root);
	printf("%d\n",sum);
	
	return 0;
		
}


			
