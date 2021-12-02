#include<iostream>
using namespace std;
class circularqueue
{
	int size=5;
	int *element;
	int front;
	int rear;
	int count;
	int noOfdelection=0;
	public:
		circularqueue()
		{
			element=new int[size];
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
		void enqueue(int val)
		{
			
    		if(is_full())
			{
				cout<<"over flow "<<endl;
			}
			else
			{
				front = front == -1 ? 0 : front;
				rear=(rear+1)%size;
				element[rear]=val;
				count++;
					
			} 
		}
		void dequeue()
		{
			if(!is_full())
			{
			
					cout << "Element Removed: " << element[front] << "\n";		
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
					cout<<" "<<element[i]<<" "<<endl;
				}
			}
			else
			{
				for(int i=front;i<size;i++)
				{
					cout<<" "<<element[i]<<" "<<endl;
				}
				for(int i=0;i<=rear;i++)
				{
					cout<<" "<<element[i]<<" "<<endl;
				}
			}
		}
};
int main()
{
	int vl,s;
	char ch;int value;
	bool isRunning = true;
	circularqueue cr;
	do
	{
	
		
		
			cout << "\nPress 1 to Enqueue\n";
			cout << "Press 2 to Dequeue\n";
			cout << "Press 3 to Display Elements\n";
			cout << "Press 5 to Exit\n";
			int ch;
			cin>>ch;
			switch (ch) {
			case 1:cout << "Enter Value: ";
				cin >> value;
				cin.ignore();
				cr.enqueue(value);
				break;
			case 2:cr.dequeue();
				break;
			case 3:cr.display();
				break;
			case 4:isRunning = false;
				break;
			
			default:cout << "Error!! You entered invalid\n";
				
			}
		
	} while (isRunning);
}

