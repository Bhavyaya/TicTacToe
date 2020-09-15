#include<iostream>
using namespace std;
char k;
int turn;//global integer indicating which move is going to be played 1 means first 9 means last
int *board;//9 element vector representing the board
void display()
{
	char *temp;
	temp=new char[9];//storing symbols corresponding to numbers in a different char array
	for(int i=1;i<=9;i++)
	{
		if(board[i]==2)
		{
			temp[i]=' ';//2 means empty box
		}
		else if(board[i]==3)
		{
			temp[i]='X';//3 means X
		}
		else temp[i]='O';//5 means O
	}
	//displaying the board elements
	cout<<temp[1]<<" | "<<temp[2]<<" | "<<temp[3]<<"\n";
	cout<<"-----------\n";
	cout<<temp[4]<<" | "<<temp[5]<<" | "<<temp[6]<<"\n";
	cout<<"-----------\n";
	cout<<temp[7]<<" | "<<temp[8]<<" | "<<temp[9]<<"\n";
}
/*Returns 5 if the centre square of the board is blank, 
that is if board[5]=2. otherwise, this returns any non-blank square(2,4,6 or 8) */
int make2()
{
	if(board[5]==2)
	{
		return(5);
	}
	else 
	{
		for(int i=2;i<=9;i=i+2)
		{
			if(board[i]==2)
			{
			return(i);
			break;
		    }
		}
	}
}
/*returns any empty box available.*/
int empty()
{
	for(int i=1;i<=9;i++)
	{
		if(board[i]==2)
		{
			return(i);
			break;
		}
	}
}
/*makes a move into square n. 
This procedure sets the board [n] to 3 if turn is odd, or 5 if turn is even. It also increments the turn by one. */
void go(int n)
{
	if(turn%2)//if turn is odd, place X i.e the one who gets the first turn places X 
	{
		board[n]=3;
	}
	else//2nd player places O
	{
		board[n]=5;
	}
	turn++;//after every move, increment turn by one
}
/*Returns 0 if player p can not win on his next move; otherwise it returns the number of the square that constitutes the winning move.  
This function will enable the program both to win and to block the opponent’s win. 
Posswin operates by checking one row, column  & diagonal at a time. 
It multiplies the values in squares for a particular row, column or diagonal to check win as follows 
If product is 18(3*3*2) then  X can win 
If the product is 50(5*5*2) then O can win 
If we find a winning row then number of blank square is returned. */
int posswin(char p)
{
	int m;
	switch(p)
	{
		case('X'):
			m=18;
			break;
		case('O'):
		    m=50;
			break;	
	}
	/* checking row wise first, if O or X can win then return the empty box */
	if(board[1]*board[2]*board[3]==m) 
	{
		if (board[1]==2)
		{
			return(1);
		}
		else if (board[2]==2)
		{
			return(2);
		}
		else return(3);
	}
	else if(board[4]*board[5]*board[6]==m)
	{
		if (board[4]==2)
		{
			return(4);
		}
		else if (board[5]==2)
		{
			return(5);
		}
		else return(6);
	}	
    else if(board[7]*board[8]*board[9]==m)
	{
		if (board[7]==2)
		{
			return(7);
		}
		else if (board[8]==2)
		{
			return(8);
		}
		else return(9);
	}	 
	/* check column wise */
	else if(board[1]*board[4]*board[7]==m)
	{
		if (board[1]==2)
		{
			return(1);
		}
		else if (board[4]==2)
		{
			return(4);
		}
		else return(7);
	}	
	else if(board[2]*board[5]*board[8]==m)
	{
		if (board[2]==2)
		{
			return(2);
		}
		else if (board[5]==2)
		{
			return(5);
		}
		else return(8);
	}	
	else if(board[3]*board[6]*board[9]==m) 
	{
		if (board[3]==2)
		{
			return(3);
		}
		else if (board[6]==2)
		{
			return(6);
		}
		else return(9);
	}	
	/* check for diagonal1 */
	else if(board[1]*board[5]*board[9]==m)
	{
		if (board[1]==2)
		{
			return(1);
		}
		else if (board[5]==2)
		{
			return(5);
		}
		else return(9);
	}	 
	/*check for diagonal2*/
	else if((board[7]*board[5]*board[3]==m))
	{
		if (board[7]==2)
		{
			return(7);
		}
		else if (board[5]==2)
		{
			return(5);
		}
		else return(3);
    }
    else return(0);
    }
/* checking win condition i.e if product of 3 consecutive boxes is 27, X wins; if product is 125, O wins else return(0) */
int check_win(char k)
{
	if(k=='n')
    {
        if((board[1] * board[2] * board[3]) == 27 || (board[4] * board[5] * board[6]) == 27 || (board[7] * board[8] * board[9]) == 27 ||
           (board[1] * board[5] * board[9]) == 27 || (board[3] * board[5] * board[7]) == 27 ||
           (board[1] * board[4] * board[7]) == 27 || (board[2] * board[5] * board[8]) == 27 || (board[3] * board[6] * board[9]) == 27)
           {
            cout<<"You lose , computer wins!!\n";
            return 1;
           }
        else if((board[1] * board[2] * board[3]) == 125 || (board[4] * board[5] * board[6]) == 125 || (board[7] * board[8] * board[9]) == 125 ||
           (board[1] * board[5] * board[9]) == 125 || (board[3] * board[5] * board[7]) == 125 ||
           (board[1] * board[4] * board[7]) == 125 || (board[2] * board[5] * board[8]) == 125 || (board[3] * board[6] * board[9]) == 125)
           {
		   cout<<"You win , congratulations!!\n";
           return 1;
           }

    }
    else if(k=='y')
    {
         if((board[1] * board[2] * board[3]) == 125 || (board[4] * board[5] * board[6]) == 125 || (board[7] * board[8] * board[9]) == 125 ||
           (board[1] * board[5] * board[9]) == 125 || (board[3] * board[5] * board[7]) == 125 ||
           (board[1] * board[4] * board[7]) == 125 || (board[2] * board[5] * board[8]) == 125 || (board[3] * board[6] * board[9]) == 125)
           {
		   cout<<"You lose , computer wins!!\n";
           return 1;
           }
        else if((board[1] * board[2] * board[3]) == 27 || (board[4] * board[5] * board[6]) == 27 || (board[7] * board[8] * board[9]) == 27 ||
           (board[1] * board[5] * board[9]) == 27 || (board[3] * board[5] * board[7]) == 27 ||
           (board[1] * board[4] * board[7]) == 27 || (board[2] * board[5] * board[8]) == 27 || (board[3] * board[6] * board[9]) == 27)
           {
            cout<<"You win , congratulations!\n";
            return 1;
           }
    }
    else return(0); //not winning situation
}
int c_move()
{
	if(turn==1)//Turn-1 : Go(1) (upper left corner) 
	{
		go(1);
	}
	else if(turn==2)//Turn-2:  if Board[5] is blank then Go(5) else Go(1) 
	{
		if(board[5]==2)
		{
			go(5);
		}
		else go(1);
	}
	else if(turn==3)//Turn-3:  if Board[9] is blank then Go(9) else Go(3) 
	{
		if(board[9]==2)
		{
			go(9);
		}
		else go(3);
	}
	else if(turn==4)//Turn-4:  if posswin(X) is not 0, then Go(posswin(X)) else Go(Make2) 
	{
		if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		/* improvement in code by adding specific cases for computer's losing situations like 2,4,1 */
		else if(board[2]==3 && board[4]==3)
		{
			go(1);
		}
		else if(board[2]==3 && board[6]==3)
		{
			go(3);
		}
		else if(board[8]==3 && board[4]==3)
		{
			go(7);
		}
		else if(board[8]==3 && board[6]==3)
		{
			go(9);
		}
		/* improvement in code by adding specific cases for computer's losing situations like 3,4,8,9,6 */
		else if(board[1]==3 && board[8]==3)
		{
			go(7);
		}
		else if(board[3]==3 && board[8]==3)
		{
			go(9);
		}
		else if(board[9]==3 && board[2]==3)
		{
			go(3);
		}
		else if(board[7]==3 && board[2]==3)
		{
			go(1);
		}
		else if(board[3]==3 && board[4]==3)
		{
			go(1);
		}
		else if(board[1]==3 && board[6]==3)
		{
			go(3);
		}
		else if(board[6]==3 && board[7]==3)
		{
			go(9);
		}
		else if(board[4]==3 && board[9]==3)
		{
			go(7);
		}
		/* for case 5,9,3,7 */
		else if(board[5]==3 && board[9]==3)
		{
			go(3);
		}
		else go(make2());
	}
	else if(turn==5)/*Turn-5: if posswin(X) is not 0, then Go(posswin(X)) else if posswin(O) is not 0 then Go(Posswin(O))
	{i.e. block opponent’s Win; else if Board[7] is blank then Go(7) else Go(3). */
	{
		if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		else if(posswin('O')!=0)
		{
			go(posswin('O'));
		}
		else if(board[7]==2)
		{
			go(7);
		}
		else go(3);
	}
	else if(turn==6)/* Turn-6: if posswin(O) is not 0 then Go(Posswin(O)) else if posswin(X) is 
not 0, then Go(posswin(X)) else Go(make2). */
	{
		if (posswin('O')!=0)
		{
			go(posswin('O'));
		}
		else if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		else go(make2());
	}
	else if(turn==7)/*Turn-7: if posswin(X) is not 0, then Go(posswin(X)) else if posswin(O) is not 0 then Go(Posswin(O)) 
	else goanywhere that is blank.*/
	{
		if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		else if(posswin('O')!=0)
		{
			go(posswin('O'));
		}
		else
		{
			go(empty());
	    }
	}
	else if(turn==8)/*Turn-8: if posswin(O) is not 0 then Go(Posswin(O)) else if posswin(X) is 
not 0, then Go(posswin(X)) else go anywhere that is blank.  */
	{
		if(posswin('O')!=0)
		{
			go(posswin('O'));
		}
		else if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		else
		{
			go(empty());
		
		}
	} 
		else if(turn==9)/* Turn-9: if posswin(X) is not 0, then Go(posswin(X)) else if posswin(O) is 
not 0 then Go(Posswin(O)) else goanywhere that is blank. */
		{
			if(posswin('X')!=0)
		{
			go(posswin('X'));
		}
		else if(posswin('O')!=0)
		{
			go(posswin('O'));
		}
		else
		{
			go(empty());
		}
		}
	}
/* user's move  */
void u_move()
{
	int u;
	cout<<"enter place where you want to play: ";
	cin>>u;
	if(board[u]!=2)
	{
		cout<<"invalid move..place "<<u<<" already occupied \n";
		u_move();
	}
	else
	{
		go(u);
    }
}
int main()
{
	cout<<"| Play Tic Tac Toe |\n";
	board= new int[9];
	char choice;
	do
	{
	turn=1;
	for(int i=1;i<=9;i++)
	{
		board[i]=2;
	}	
	display();
	cout<<"Do you want to play first? :(y for yes, n for no) ";
	cin>>k;
	if(k=='y')
	{
		while(turn<=9)
		{
		    u_move();
		    display();
		    if(check_win(k)==1)
	      	{
	    	   goto last;
	    	   break;
		    }
			if(turn!=10)
			{
			    cout<<"computer's turn:\n";
			    c_move();
			    display();
			    if(check_win(k)==1)
		        {
		    	    goto last;
		    	    break;
			    }
		    }
		}
	}
	else 
	{
		while(turn<=9)
		{
			cout<<"computer's turn:\n";
			c_move();
			display();
			if(check_win(k)==1)
		    {
		    	goto last;
		    	break;
			}
			if(turn!=10)
			{
				u_move();
				display();
				if(check_win(k)==1)
			    {
			    	goto last;
			    	break;
				}
			}
		}
	}
	last: cout<<"\nGame over!\n";
	cout<<"Want to play again?(y/n): ";
	cin>>choice;}while(choice=='y');
	return(0);
}
