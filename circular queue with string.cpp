#include<iostream>
using namespace std;
class student
{
	int id;
	string name;
		public:
			void input()
			{
				cout<<"Enter name  ";
				cin>>name;
				cout<<"Enter id ";
				cin>>id;
			}
			void display()
			{
				cout<<"Name "<<name<<endl;
				cout<<"id = "<<id<<endl;
				cout<<"\n\n";	
			}	
};
class circularqueue
{
	int size=5;
	student *element;
	int front;
	int rear;
	int count;
	public:
		circularqueue()
		{
			element=new student[size];
			front=rear=-1;
			count=0;
		}
		bool is_full()
		{
			return (count==size)? true:false;
		}
		bool is_empty()
		{
			return (count==0)?true:false;
		}
		void enqueue(student val)
		{
			
    		if(is_full())
			{
				cout<<"over flow "<<endl;
			}
			else
			{
				if(front==-1)
					front=0;
					
				rear=(rear+1)%size;
				element[rear]=val;
				count++;	
				
			} 
		}
		void dequeue()
		{
			int vl;
			if(!is_full())
			{		
					count--;
				
				if(front==rear)
				{
					front=rear=-1;
				}
				else
					{
						front=(front+1)%size;
						
					}
			}
			else
			{
				cout<<"List is full "<<endl;
			}
		}
		void display()
		{
			if(front<=rear)
			{
				for(int i=front;i<=rear;i++)
				{
					element[i].display();
				}
			}
			else
			{
				for(int i=front;i<size;i++)
				{
					element[i].display();
				}
				for(int i=0;i<=rear;i++)
				{
					element[i].display();
				}
			}
		}
};
int main()
{
	student st;
		int vl,s;
	char ch;int value;
	bool isRunning = true;
	circularqueue cr;
	do
	{
		bool user_choice;
		do {
		
		user_choice = true;
			cout << "\nPress 1 to Enqueue\n";
			cout << "Press 2 to Dequeue\n";
			cout << "Press 3 to Display Elements\n";
			cout << "Press 5 to Exit\n";
			int ch;
			cin>>ch;
			switch (ch) {
			case 1:
				st.input();
				cr.enqueue(st);
				break;
			case 2:cr.dequeue();
				break;
			case 3:cr.display();
				break;
			case 4:isRunning = false;
				break;
			
			default:cout << "Error!! You entered invalid\n";
				user_choice = false;
			}
		} while (user_choice == false);
	} while (isRunning);
}

