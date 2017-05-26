#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int RemainingCount=2;
char nameOne[20];
char nameTwo[20];

void getInput()
{
	int inputSuccessful=1;
	char edit;
	char firstName[20];
	char secondName[20];

	int a,b;

	puts("\n                             AUTHOR:NAVEEN PRAKASH");
	while(inputSuccessful)
	{
	puts("\n   Enter first name:");
	printf("   ");
	gets(firstName);
	puts("\n   Enter second name:");
	printf("   ");
	gets(secondName);

	//system("cls");
	puts("\n   Entered name correctly? y:n ");
	printf("   ");
	edit=getch();
	//system("cls");
	if(edit=='n')
	{
	}
	else
	{
		inputSuccessful=0;
	}
	}
	for(a=0;a<=20;a++)
	{
	nameOne[a]=firstName[a];
	nameTwo[a]=secondName[a];
	}
}


void findRemainingCount()
{
	int a,b;
	int same=0;
	int remain=0;
	int total=(strlen(nameOne)+strlen(nameTwo));

	for(a=0;a<strlen(nameOne);a++)
	{
		for(b=0;b<strlen(nameTwo);b++)
		{
			if(nameOne[a]==nameTwo[b] && nameOne[a]!='*')
			{
				nameOne[a]='*';
				nameTwo[b]='*';
				total=total-2;
			}
		}
	}

	RemainingCount=total;
	//printf("%d",total);
}

void calculateflames()
{
	char flames[7]={'*','f','l','a','m','e','s'};
	int maxPosition=6;
	int currentPosition=1;
	int fCount=1;
	int getIn=1;
	int stop=RemainingCount;
	int out=0;

	while(getIn==1)
	{
		if(currentPosition>maxPosition)
		{
			currentPosition=1;
		}

		if(fCount==stop)
		{
			int temp;

			++out;
			--maxPosition;
			for(temp=currentPosition;temp<=maxPosition;temp++)
			{
				flames[temp]=flames[temp+1];
			}

			//printf("%s \n",flames);

			if(out==5)
			{
				getIn=0;
			}

			--currentPosition;
			fCount=0;
		}
		++fCount;
		++currentPosition;
	}

	printf("\n\n                             ");

	switch(flames[1])
	{
	case 'f': printf("   FRIENDS");break;
	case 'l': printf("   LOVE  ");break;
	case 'a': printf("   AFFECTION");break;
	case 'm': printf("   MARRAIGE");break;
	case 'e': printf("   ENEMY");break;
	case 's': printf("   SISTER");break;
	default:printf("    TWINS");
	}
	
}

void main()
{
	char retry='n';
		do
		{
	   getInput();
	   findRemainingCount();
	   calculateflames();
	   printf("\n   RETRY?: y:n "); 
	   printf("\n   ");
	   retry=getch();
	   if(retry=='y')
	   {
		   system("cls");
		   retry='y';
	   }
		}
		while(retry=='y');
	
	getch();
}