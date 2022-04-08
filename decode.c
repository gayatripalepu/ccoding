#include<stdio.h>
struct phone
{
	int num;
	char ch;
};

void loadCodes(struct phone keys[],int size)
{
	keys[0].num =2;
	keys[0].ch='a';
	keys[1].num =22;
	keys[1].ch='b';
	keys[2].num =222;
	keys[2].ch='c';
	keys[3].num =3;
	keys[3].ch='d';
	keys[4].num =33;
	keys[4].ch='e';
	keys[5].num =333;
	keys[5].ch='f';
	keys[6].num =4;
	keys[6].ch='g';
	keys[7].num =44;
	keys[7].ch='h';
	keys[8].num =444;
	keys[8].ch='i';
	keys[9].num =5;
	keys[9].ch='j';
	keys[10].num =55;
	keys[10].ch='k';
	keys[11].num =555;
	keys[11].ch='l';
	keys[12].num =6;
	keys[12].ch='m';
	keys[13].num =66;
	keys[13].ch='n';
	keys[14].num =666;
	keys[14].ch='o';
	keys[15].num =7;
	keys[15].ch='p';
	keys[16].num =77;
	keys[16].ch='q';
	keys[17].num =777;
	keys[17].ch='r';
	keys[18].num =7777;
	keys[18].ch='s';
	keys[19].num =8;
	keys[19].ch='t';
	keys[20].num =88;
	keys[20].ch='u';
	keys[21].num =888;
	keys[21].ch='v';
	keys[22].num =9;
	keys[22].ch='w';
	keys[23].num =99;
	keys[23].ch='x';
	keys[24].num =999;
	keys[24].ch='y';
	keys[25].num =9999;
	keys[25].ch='z';
}
char getChar(struct phone c[],int size, int code)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(c[i].num ==code)
		 return c[i].ch;
	}
	return -1;
}
int getcode(struct phone c[],int size,char ch)
{
int i;
	if(ch == ' ')
	return '0';
	for(i=0;i<size;i++)
	{
		if(c[i].ch ==ch)
		 return c[i].num;
	}
	return -1;	
}
void decode(char code[])
{
	char dstr[80];
	int i,c=0,j=0;
	struct phone cc[26];
	loadCodes(cc,26);
	for(i=0;code[i]!='\0';i++)
	{
			if(code[i]=='#')
			{
				continue;				
			}
			else
			{
				if(code[i]==code[i+1])
				{
					c = c*10+(code[i]-'0');
				}		
				else
				{
					if(code[i] != code[i+1])
					{
						c = c*10+(code[i]-'0');
						dstr[j++]=getChar(cc,26,c);
						c=0;
					}
					else
					{
						if(code[i]=='0') 
							 dstr[j++]= ' ';
					}
				}
			}
	}
	dstr[j]='\0';
	printf("%s",dstr);
}
void encode(char str[])
{
	int i,j;
	char estr[80];
	struct phone cc[26];
	loadCodes(cc,26);
	printf("\n");
	for(i=0;str[i] !='\0';i++)
	{
		if(str[i]==' ')
			printf("%d",0);
		else
		{
			if((getcode(cc,26,str[i])%10)==(getcode(cc,26,str[i-1])%10))
				printf("#");
			printf("%d",getcode(cc,26,str[i]));
		}
	}
	
}
int main()
{
	char msg[]= "4433555#5556660707777232777744#444888";
	decode(msg);
	encode("hello p sadashiv");
	return 1;
}
