// C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nl << "\n"
#define invalid -1 // return when function fails

struct Node
{
    int val;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int a)
    {
        val = a;
    }
};

struct linkedList
{
    Node *head = nullptr;
    Node *tail = nullptr;
    void insertFirst(int a)
    {
        Node *newNode = new Node(a);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    virtual void insertLast(int a)
    {
        Node *newNode = new Node(a);
        if (head == nullptr)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteFirst()
    {
        if (head != nullptr)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        }
    }
    void deleteLast()
    {
        if (tail != nullptr)
        {
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
        }
    }

    void deleteX(int x)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->val == x)
            {
                if (temp == head)
                    deleteFirst();
                if (temp = tail)
                    deleteLast();
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            temp = temp->next;
        }
        temp = nullptr;
    }
    int front()
    {
        if (head)
            return head->val;
        else
            return invalid;
    }
    int back()
    {
        if (tail)
            return tail->val;
        else
            return invalid;
    }
};

struct stack : linkedList
{
    int pop()
    {
        int temp = tail->val;
        deleteLast();
        return temp;
    }
    int peek()
    {
        return tail->val;
    }
    void push(int val)
    {
        insertFirst(val);
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
}