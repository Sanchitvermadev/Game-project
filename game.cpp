#include<bits/stdc++.h>
using namespace std;
#define null NULL
class node
{
public:
	int data;
	node *next;
	node *random;
	
	
};

// function to generate a new node 
void createnode(node *itr, int val)
{
	itr->data=val;
	itr->next=NULL; itr->random=NULL;
}

// This function will construct the board numbered from 1 to 100. This will be achieved by using Linked-List.
// The function returns the pointer to the starting point of board that is named head.
node *construct_board()
{
	
	node *head= new node();
	head->data=0;
	head->random=NULL;
	node *itr= head;
	int val=1;
		while((val)<=100){
			itr->next= new node();
			createnode(itr->next,val); 
			itr=itr->next;
			val++;
		}

		return head;
		
}
//To add ladders, the function can generate amount of ladders user want to have on the board.
//Ladders are added randomly by using the concept of random number generation.
node *add_ladders(int valueofladder, node *head)
{
	while(valueofladder--){
			//adding ladder
			int ran1=0;
			int ran2=0;
			while(ran1==ran2){
				srand(time(0)); 
			 ran1=(rand()%98)+1;
			if(ran1==1){ran1=2;}
			 srand(time(0)); 
			 ran2=(rand()%98)+1;}
			if(ran1>ran2){
		      swap(ran1,ran2);
			}
			ran2-=ran1;
			node *itr=head->next;
			node *tempNode=null;
			while(ran1>0){
				ran1--;
				itr=itr->next;
			}
			tempNode=itr;
			while(ran2>0){
				ran2--;
				itr=itr->next;
			}
			tempNode->random=itr;
			
			
		}
		return head;
}

//To add Snakes, the function can generate amount of Snakes user want to have on the board.
//Snakes are added randomly by using the concept of random number generation.
node *add_snakes(int valueofsnakes, node *head)
{
	while(valueofsnakes--){
			int ran1=0;
			int ran2=0;
			while(ran1==ran2){
			srand(time(0)); 
			 ran1=(rand()%98)+1;
			if(ran1==1){ran1=2;}
			 srand(time(0)); 
			 ran2=(rand()%98)+1;}
			
			if(ran1<ran2){
		      swap(ran1,ran2);
			}
			node *itr=head->next;
			node *tempNode=null;
	
			while(ran1>0){
				ran1--;
				itr=itr->next;
			}
			tempNode=head->next;
			while(ran2>0){
				ran2--;
				tempNode=tempNode->next;
			}
			while(tempNode->random!=null)tempNode=tempNode->next;
			itr->random=tempNode;
}
return head;
}
// Driver Program
int main()
{
	cout<<"Initiating..Please Wait"<<endl;
	node *head= construct_board();
	head= add_ladders(8, head);
	head= add_snakes(8, head);
	cout<<endl;
	system("cls");
	cout<<"Welcome_To_Snake_&_Ladders_Game: Developed by Sanchit-Verma"<<endl;
	//itr1 and itr2 are respective pointers to maintain the current status of players that is player 1 and player 2.
	node *itr1,*itr2;              
	itr1= head;
	itr2=head;
	string p1="",p2="";
	int a;
	while(1)
	{
		cout<<"players number?"<<endl;
		cin>>a;
		if(a==2)break;
		if(a!=2)cout<<"sorry game supports 2 players only!"<<endl;
	}
	cout<<"player1 name:"<<endl;
	cin>>p1;
	cout<<"player2 name:"<<endl;
	cin>>p2;
	cout<<"Sucessfully Recorded  : "<<p1<<"  vs  "<<p2<<endl;
	bool flag=0;                                         //flag variable indicates the players turn if 0 then player1 else player2.
	while(1)
	{
		if(itr1->data==100)break;
		if(itr2->data==100)break;
			if(!flag)
			{
				int mod;
				flag^=1;
				fflush(stdin);
				cout<<p1<<" your turn: press 6 to roll a dice"<<endl;
				cin>>mod;
				srand(time(0)); 
				int r= (rand()%mod+1);
				cout<<"dice shows: "<<r<<endl;
				if(itr1->data+r<=100){
					while(r>0){
						r--;
						if(itr1->next!=null){
						itr1=itr1->next;}
					}}
					cout<<p1<<": your current position-> "<<itr1->data<<endl;
				while(itr1->random!=null){
						if(itr1->data<itr1->random->data){
							cout<<"Ladder!!"<<endl;
						}else{
							cout<<"Snakes!!"<<endl;
						}
						itr1=itr1->random;
						cout<<"Changed Position: "<<itr1->data<<endl;
					}

					
			}

			else
			{
				flag^=1;
				cout<<p2<<" your turn: press 6 to roll a dice"<<endl;
				int mod;
				cin>>mod;
				srand(time(0)); 
				int r= (rand()%mod+1);
				cout<<"dice shows: "<<r<<endl;
				if(itr2->data+r<=100){
					while(r>0){
						r--;
						if(itr2->next!=null){
						itr2=itr2->next;}
					}}
				if(itr2->random!=null){
						if(itr2->data<itr2->random->data){
							cout<<"Ladder!!"<<endl;
						}else{
							cout<<"Snakes!!"<<endl;
						}
						itr2=itr2->random;
					}

					cout<<p2<<": your current position-> "<<itr2->data<<endl;
			}


	}
	system("cls");
	if(itr1->data==100)cout<<p1<<" won"<<endl;
	else cout<<p2<<" won"<<endl;
	cout<<"Press Enter To exit"<<endl;
	int exit;
	cin>>exit;
	return 0;
}
