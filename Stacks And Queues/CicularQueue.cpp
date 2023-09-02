#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue
{

private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularQueue(int k)
    {
        front = -1;
        rear = -1;
        size = k;
        arr = new int[size];
    }
    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front == (rear + 1) % size));
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : arr[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : arr[rear];
    }
};

int main()
{

    return 0;
}