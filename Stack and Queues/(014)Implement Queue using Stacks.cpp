/*
Link: https://leetcode.com/problems/implement-queue-using-stacks/
232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty). Implement the MyQueue 

class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

*/
#include<bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> st1, st2;
    MyQueue()
    {
    }
    void fillIntoSt2()
    {
        if (st2.size() == 0)
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
    void fillIntoSt1()
    {
        if (st1.size() == 0)
        {
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    void push(int x)
    {
        fillIntoSt1();
        st1.push(x);
    }

    int pop()
    {

        fillIntoSt2();
        int ans = st2.top();
        st2.pop();
        return ans;
    }

    int peek()
    {
        if (st2.size() == 0)
            fillIntoSt2();

        return st2.top();
    }

    bool empty()
    {
        if (st1.size() == 0 && st2.size() == 0)
            return true;
        return false;
    }
};