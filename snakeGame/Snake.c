#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<dos.h>

#define space()  printf("         ");
#define newLine() printf("\n");
#define border()  printf("0");

int ROW=32;
int COL=81;
int life=1;
char move;
int headX;
int headY;
int foodX;
int foodY;
int score;
int prevX=0;
int prevY=0;
int prev2X=0;
int prev2Y=0;
int tailX[30];
int tailY[30];
int TailLength=0;
char direction;

void init()
{
   headX=rand()%31;
   headY=rand()%81;
   foodX=rand()%31;
   foodY=rand()%81;
   tailX[0]=1323;
   tailY[0]=233;
}


void draw()
{
	int row;
	int column;
	int temp;

	// code for top edge
	newLine();
	newLine();
	printf("         ");
	for(temp=0;temp<=82;temp++)
	{
		printf("0");
	}

	// code for middle
	newLine();
	space();
	for(row=0;row<ROW;++row)
	{
		border();
		for(column=0;column<COL;++column)
		{
		    // code for snake
			int count;

			if(row==headX && column==headY)
			{
				printf("O");
			}
			else if(row==foodX && column==foodY)
			{
				printf("*");
			}
			else
			{
				int print=1;

				for(count=0;count<=TailLength;count++)
				{
					if( tailX[count]==row && tailY[count]==column)
					{
						printf("O");
						print=0;
					}
				}

				if(print)
				{
					printf(" ");
				}

			}
		}
		border();
		newLine();
		space();
	}

	// code for bottom edge
	for(temp=0;temp<=82;temp++)
	{
		printf("0");
	}

	newLine();
	newLine();
	space();
	printf("snake(%d,%d) food(%d,%d) score:%d ",headX,headY,foodX,foodY,score);
	newLine();
	newLine();
	space();
    printf("AUTHOR: NAVEEN PRAKASH");
}

void getInput()
{

    int firstMove=1;
	int done=1;

	prevX=headX;
	prevY=headY;

	while(done)
	{
	move=getch();
	direction=move;


	switch(move)
	{
	case 'w': if(firstMove==1 || direction!='s')
			  {
		      --headX;done=0;firstMove=0;
			  }
			  break;
	case 's': if(firstMove==1 || direction!='w')
			  {
		     ++headX;done=0;firstMove=0;
			  }
			  break;
	case 'a': if(firstMove==1 || direction!='d')
			  {
		     --headY;done=0;firstMove=0;
			  }
			  break;
	case 'd': if(firstMove==1 || direction!='a')
			  {
		      ++headY;done=0;firstMove=0;
			  }
			  break;
	case 'q':
		      life=0;done=0;break;
	default: break;
	}

   }

}




void logic()
{
	int count;
	int count1;
	if(headX<0||headX>31||headY<0||headY>81)
	{
		life=0;
	}

	if(foodX==headX && foodY==headY)
	{
		score=score+10;
	    foodX=rand()%31;
        foodY=rand()%81;
		TailLength=TailLength+1;
	}



	  tailX[0]=headX;
	  tailY[0]=headY;

	for(count=1;count<=TailLength;count++)
	{
		prev2X=tailX[count];
		prev2Y=tailY[count];
		tailX[count]=prevX;
		tailY[count]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}


}

void End()
{
	newLine();
	newLine();
	newLine();
	newLine();
	printf("                                         YOU ARE DEAD");
    getch();
	system("cls");
	newLine();
	newLine();
	newLine();
	newLine();
	printf("                                  YOUR SCORE: %d",score);
}

void main()
{
	int a,b;
	init();
	while(life)
	{
		draw();
		getInput();
		logic();
		system("cls");
	}

	End();

	getch();
}
