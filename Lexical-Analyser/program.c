#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
int main()
	{
	FILE *F1;
	char c, str[10];
	int lineno=0,num=0,i=0;
	printf("\n Enter the c program \n");
	F1=fopen("input.txt","w");
	while((c=getchar())!=EOF)
		putc(c,F1);
	fclose(F1);
	F1=fopen("input.txt","r");
	while((c=getc(F1))!=EOF)
		{
		if(isdigit(c))
			{
			num=c-48;
			c=getc(F1);
			while(isdigit(c))
				{
				num=num*10+(c-48);
				c=getc(F1);
				}
			printf("%d is a number \n",num);
			ungetc(c,F1);
			}
		else if(isalpha(c))
			{
			str[i++]=c;
			c=getc(F1);
			while ((isdigit(c))||(isalpha(c))||(c=='_')||(c=='$'))
			{
				str[i++]=c;
				c=getc(F1);
			}
		str[i++]='\0';
		if((strcmp("for",str)==0)||(strcmp("while",str)==0)||(strcmp("do",str)==0)||(strcmp("int",str)==0)||(strcmp("float",str)==0)||(strcmp("char",str)==0)||(strcmp("double",str)==0)||(strcmp("static",str)==0)||(strcmp("switch",str)==0)||(strcmp("case",str)==0))
			printf("%s is a keyword \n",str);
		else
			printf("%s is an identifier \n",str);
		ungetc(c,F1);
		i=0;
			}
		else if(c==' '||c=='\t')
			printf("\n");
		else if(c=='\n')
			lineno++;
		else
			printf("%c is a special symbol \n",c);
	}
	printf("Total number of lines are : %d \n",lineno);
	fclose(F1);
	getch();
	return 0;
	}
