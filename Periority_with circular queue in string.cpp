#include<iostream>
using namespace std;
class stringdata
{
	
	int id;
	string name;
	int age;
	public:
		int p;
		void input()
		{
			cout<<"Enter id ";
			cin>>id;
			cin.ignore();
			cout<<"Enter name  ";
			
			getline(cin,name);
			cout<<"Enter age ";
			cin>>age;	
		}	
		void display()
		{
			cout<<"ID = "<<id<<endl;;
			cout<<"NAme = "<<name<<endl;
			cout<<"Age = "<<age<<endl;
		}
};
class periorty_Queue
{
	int size;
	stringdata* element;
	int front;
	int rear;
	int count;
public:
	periorty_Queue()
	{
		size = 5;
		element = new stringdata[size];
		front = -1;
		rear = -1;
		count = 0;
	}
	bool is_full()
	{
		return rear == size - 1 ? true : false;
	}
	bool is_empty()
	{
		return rear == -1 ? true : false;
	}
	void enqueue(stringdata val)
	{
		if (is_full())
		{
			cout << "Periorty queue is full " << endl;
		}
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			rear = (rear + 1) % size;
			element[rear] = val;
			count++;
			if (front <= rear)
			{
				for (int i = front; i <= rear; i++)
				{
					for (int j = i + 1; j <= rear; j++)
					{
						if (element[i].p < element[j].p)
						{
							stringdata temp = element[i];
							element[i] = element[j];
							element[j] = temp;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i <= rear; i++)
				{
					for (int j = i + 1; j <= rear; j++)
					{
						if (element[i].p < element[j].p)
						{
							stringdata temp = element[i];
							element[i] = element[j];
							element[j] = temp;
						}
					}

				}
				for (int i = 0; i <= rear; i++)
				{
					for (int j = i + 1; j <= rear; j++)
					{
						if (element[0].p < element[size - 1].p)
						{

							stringdata temp = element[0];
							element[0] = element[size - 1];
							element[size - 1] = temp;
						}
					}
				}
				for (int i = front; i < size; i++)
				{
					for (int j = i + 1; j < size; j++)
					{
						if (element[i].p < element[j].p)
						{

							stringdata temp = element[i];
							element[i] = element[j];
							element[j] = temp;
						}
					}
				}
			}
		}
	}
	void dequeue()
	{
		if (is_empty())
		{
		cout << "Periorty queue is empty " << endl;
			
		}
		else
		{
			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				front = (front + 1) % size;

			}
		}
	}
	void display()
	{
		if (front <= rear)
		{
			for (int i = front; i <= rear; i++)
			{
				 element[i].display();
			}
		}
		else
		{
			for (int i = 0; i <= rear; i++)
			{
				element[i].display();
			}
			for (int i = front; i < size; i++)
			{
				element[i].display();
			}
		}
	}

};
int main()
{
	stringdata s;
	int c;
	periorty_Queue p_q;
	int v;
	cout<<"Enter periority value ";
	cin>>v;

	bool datafalse = true;
	do
	{
		int v;
		
		cout << "\nPress 1 for insert " << endl;
		cout << "Press 2 for delete " << endl;
		cout << "Press 3 for display " << endl;
		cout << "Press 4 for exit " << endl;
		cin >> c;
		cin.ignore();
		if (c == 1)
		{
			s.input();
			p_q.enqueue(s);
		}
		else if (c == 2)
		{
			p_q.dequeue();
		}
		else if (c == 3)
		{
			p_q.display();
		}
		else if (c == 4)
		{
			datafalse = false;
		}
	} while (datafalse);


}
