#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main ()
{
	FILE *fr;
	fr=fopen("data.txt", "r");
	if(fr==NULL)
	{
		printf("File error !");
		return 1;
	}

	char z;
	while((z=fgetc(fr)) != EOF)
	{
		
		if(isalpha(z))
		{
			if(z=='y')
			{
				putchar('i');
			}else if(z=='Y')
			{
				putchar('I');
			}else if(z=='i')
			{
				putchar('y');
			}else if(z=='I')
			{
				putchar('Y');
			}
			putchar(z-1);	
		}else if(z=='%')
			{
			putchar(' ');	
			}
	 
	}
	
	fclose(fr);
	return 0;
}
