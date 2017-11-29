#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

typedef struct {
	char alpha[2];
	char key[2];
}code;

int main ()
{
	code keys[36];
	
	FILE *fr_code;
	fr_code=fopen("codeTable.txt", "r");
	if(fr_code==NULL)
	{
		printf("File error !");
		return 1;
	}
	
	FILE *fr_encoded;
	fr_encoded=fopen("encodedText.txt", "r");
	if(fr_encoded==NULL)
	{
		printf("File error !");
		return 2;
	}
	
	int i;	
	int n=0;
	while(fscanf(fr_code, "%s%s", &keys[n].alpha, &keys[n].key) != EOF)
	{
		n++;
	}
	
	
	char z;
	while((z=fgetc(fr_encoded))!=EOF)
	{
		if(isupper(z))
		{
			for(i=0;i<n;i++)
			{
				if(keys[i].key[0]==z)
				{
					z=keys[i].alpha[0];
					break;
				}	
			}	
		}
		if(islower(z))
		{
			for(i=0;i<n;i++)
			{
				if(keys[i].key[0]==toupper(z))
				{
					z=tolower(keys[i].alpha[0]);
					break;
				}
			}
		}
		if(z=='%')
			{
				z=' ';
			}
		putchar(z);
	}
	
	fclose(fr_encoded);
	fclose(fr_code);
	return 0;
}
