#include <iostream>
using namespace std;
#define max 1000

struct Queue
{
    int a[max];
    int Front; 
    int Rear;
}q1;

void CreateQueue(Queue& q)
{
    q.Front = -1;
    q.Rear = -1;
}

int DeQueue(Queue& q, int& x) 
{
    if (q.Front != -1) 
    {
        x = q.a[q.Front];
        q.Front++;
        if (q.Front > q.Rear)//truong hop co mot phan tu
        {
            q.Front = -1;
            q.Rear = -1;
        }
        return 1;
    }
    else //queue trong
    {
        cout << "Queuerong";
        return 0;
    }
}

int EnQueue(Queue& q, int x) 
{
    int i;
    int f, r;
    if (q.Rear - q.Front + 1 == max)//queue bi day khong the them vao duoc nua
        return 0;
    else
    {
        if (q.Front == -1) // Truong hop queue chua co phan tu nao
        {
            q.Front = 0;
            q.Rear = 0;
        }
        if (q.Rear == max - 1) //Queue day ao
        {
            f = q.Front;
            r = q.Rear;
            for (i = f; i <= r; i++)
                q.a[i - f] = q.a[i];
            q.Front = 0;
            q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x;
        return 1;
    }
}

bool isEmpty(Queue q) {
    if (q.Front == -1)
        return 1;
    else
        return 0;
}

int count(Queue q) {
    if (q.Front == -1)
        return 0;
    else
        return q.Rear - q.Front + 1;
}

void deleteAll(Queue q) {
    q.Rear = q.Front = -1;
}

int main()
{
    CreateQueue(q1);
    EnQueue(q1, 10);
    EnQueue(q1, 9);

    int x;
    DeQueue(q1, x);
    cout << count(q1);
    cout << "\n" << isEmpty(q1);
    deleteAll(q1);
}

