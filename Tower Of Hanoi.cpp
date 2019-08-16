#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
	public :
				int Disk[5]={0,0,0,0,0};
				int top=-1;
				
		bool push(int D)
		{
			if(top==sizeof(Disk)-1)
			{
				cout<<"max";
				return false;
			}
			
			top++;
			
			Disk[top]=D;
			
			
			return true;
		}
		int pop()
		{
			if(top==-1)
			{
				cout<<"Min";
				return NULL;
			}
			int c=Disk[top];
			Disk[top]=0;
			top--;
			return c;
		}

		bool checkDescending(int D)
		{
			
			for(int i=1;i<D;i++)
			{
				
				if(Disk[i]>Disk[i-1] || Disk[i-1]==0)
					return false;
			}
			return true;
		}
		
		bool checkEmpty(int D)
		{
			for(int i=0;i<D;i++)
				if(Disk[i]!=0)
					return false;
			return true;
		}
};

class DisplayManager
{
	public :
				Stack *A,*B,*C;
				int selected;
				
				
				DisplayManager(Stack *a,Stack *b,Stack *c)
				{
					A=a;
					B=b;
					C=c;	
				}
				
				void Display(int hover,bool pop)
				{
				
					cout<<"\n\n\n";
					cout<<"\t\t";
					printDisk(-1);printDiskWithGap(-1,NULL);printDiskWithGap(-1,NULL);
					cout<<"\n";
					selected=4;
					while(selected>=0)
					{
						cout<<"\t\t";
						printDisk(A->Disk[selected]);
						printDiskWithGap(B->Disk[selected],A);
						printDiskWithGap(C->Disk[selected],B);
						
						cout<<"\n";
						
						selected--;
					}
					//cout<<"\t\t";
				//	printDisk(-1);printDiskWithGap(-1,NULL);printDiskWithGap(-1,NULL);
					cout<<"\t     ";
					for(int i=0;i<51;i++)
						cout<<"-";
					cout<<"\n\t     |\t      A";
					if(hover==1)
						if(pop)
							cout<<"^";
						else
							cout<<"v";
					else
						cout<<" ";
					
					cout<<"\t      B";
					if(hover==2)
						if(pop)
							cout<<"^";
						else
							cout<<"v";
					else
						cout<<" ";
						
					cout<<"\t      C";
					if(hover==3)
						if(pop)
							cout<<"^";
						else
							cout<<"v";
					else
						cout<<" ";
						
					cout<<"       |\n\t     ";
					for(int i=0;i<51;i++)
						cout<<"-";
						
					
				}
				
				void DisplayTitle(bool x)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tTOWER OF HANOI";
					if(x)
						cout<<"\n\t\t\t\t  *complete*";
					else
						cout<<"\n";
				}
				void printDisk(int size)
				{
				
					int s=6;
					s-=(size)/2;
					while(s>0)
					{
						cout<<" ";
						s--;
					}
					if(size==0||size==-1)
						cout<<"|";
					else
					for(int i=0;i<=size;i++)
						cout<<"*";
				}
				
				void printDiskWithGap(int size, Stack *previous)
				{
					
					int s=6;
					if(size!=-1)
						s-=previous->Disk[selected]/2;
					while(s>0)
					{
					
						cout<<" ";
					
						s--;
					}	cout<<"   ";
					printDisk(size);
					
				}
	
				void printBuffer(int b)
				{
					cout<<"\n\n\t\t\t\t";
					int space=6;
					space-=b/2;
					for(int i=0;i<space;i++)
						cout<<' ';
					for(int i=0;i<b;i++)
						cout<<"*";
				}
};
main()
{
	Stack A[3];
	DisplayManager DSP(&A[0],&A[1],&A[2]);
	int hover=1,buffer=0,moves=0;
	bool pop=true;
	
	bool complete=false;
	int Difficulty;
	char Df;
	cout<<"Select Difficulty:\n(Easy:e  Normal:n  Hard:h):";
	cin>>Df;
	switch(Df)
	{
		case 'e':Difficulty=3;
				break;
		case 'n':Difficulty=4;
				break;
		case 'h':Difficulty=5;
				break;
		default:Difficulty=4;
				break;
	}
	
	for(int i=0,Dsk=12;i<Difficulty;i++,Dsk-=2)
	{
		A[0].push(Dsk);
	}
//	A[0].push(12);
//	A[0].push(10);
//	A[0].push(8);
	//A[0].push(6);
	//A[0].push(4);
	;
	//A[1].push(4);
	//A[1].push(0);
	//A[1].push(0);
	//A[1].push(0);
	//A[1].push(0);
	
//	A[2].push(0);
//	A[2].push(0);
//	A[2].push(0);
//	A[2].push(0);
//	A[2].push(0);
	
	//DSP.Display(hover,pop);
	while(!complete)
	{
		if( A[0].checkEmpty(Difficulty) && A[1].checkEmpty(Difficulty) && buffer==0 && A[2].checkDescending(Difficulty))
		{
			//	cout<<"\n\nWINNNNNNNNNN!!!!! by "<<moves;
				complete=true;	
		}
		
		DSP.DisplayTitle(complete);
		DSP.Display(hover,pop);
		DSP.printBuffer(buffer);
		
		cout<<"\n\t\t\t\t   Moves:"<<moves;
		
		//else cout<<"\n\nNOOOOOOOOOOOOO!!!!!!!!!!!";
		
			
		char c=getch();
		switch(c)
		{
			case 77:
					if(hover<3)
						hover++;
					
					break;	
			case 75:
					if(hover>1)
						hover--;		
					
					break;
			case ' ':
					if(pop && buffer==0 && A[hover-1].top!=-1)
					{
						buffer=A[hover-1].pop();
						pop=!pop;
					}	
					else if(!pop && buffer!=0)
					{
						if(buffer < A[hover-1].Disk[A[hover-1].top] || A[hover-1].top==-1 )
						 {
							A[hover-1].push(buffer);
							buffer=0;
							moves++;
							pop=!pop; 	
						 }
						
					}
					
					break;	
					
		}
		
		
			
		
	}
	
	//DSP.Display(1,false);
	getch();
}
