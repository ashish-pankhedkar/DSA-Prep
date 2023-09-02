#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = -1;
        rear = -1;
        arr = new int[k];
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + size) % size;
        }

        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
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

    bool deleteFront()
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

    bool deleteLast()
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
            rear = (rear - 1 + size) % size;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front == (rear + 1) % size));
    }
};

int main()
{

    return 0;
}