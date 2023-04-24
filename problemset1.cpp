class Queue
{
public:
    int front;
    int rear;
    int size;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "No size";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    void display() {
        int i = 0;
        if (front == rear)
        {
            cout << "Stack empty";
        }
        else
        {
            for (i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q(3);
    // q.display();

    q.push(32);
    q.push(12);
    q.push(11);
    q.push(88);
    q.display();

    // q.pop();
    // q.display();
}