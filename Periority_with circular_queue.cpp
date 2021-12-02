#include<iostream>
using namespace std;
class periorty_Queue
{
	int size;
	int* element;
	int front;
	int rear;
	int count;
public:
	periorty_Queue()
	{
		size = 5;
		element = new int[size];
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
	void enqueue(int val)
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
						if (element[i] > element[j])
						{
							int temp = element[i];
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
						if (element[i] > element[j])
						{
							int temp = element[i];
							element[i] = element[j];
							element[j] = temp;
						}
					}

				}
				for (int i = 0; i <= rear; i++)
				{
					for (int j = i + 1; j <= rear; j++)
					{
						if (element[0] > element[size - 1])
						{

							int temp = element[0];
							element[0] = element[size - 1];
							element[size - 1] = temp;
						}
					}
				}
				for (int i = front; i < size; i++)
				{
					for (int j = i + 1; j < size; j++)
					{
						if (element[i] > element[j])
						{

							int temp = element[i];
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
				cout << element[i] << " ";
			}
		}
		else
		{
			for (int i = front; i < size; i++)
			{
				cout << element[i] << " ";
			}
			for (int i = 0; i <= rear; i++)
			{
				cout << element[i] << " ";
			}
			
		}
	}

};
int main()
{
	int c;
	periorty_Queue p_q;
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
			cout<<"Enter value "<<endl;
			cin>>v;
			p_q.enqueue(v);
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
