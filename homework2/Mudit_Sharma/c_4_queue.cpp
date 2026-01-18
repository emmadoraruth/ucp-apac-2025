// Queues are not a “first-class” data structure – they are an API or interface implemented using another underlying data structure. Queues should have O(1) insertion and deletion; because insertion and deletion occur at opposite ends, the underlying data structure is normally a linked list to satisfy this requirement. Implement a queue class according to the following definition; you may copy-paste and reuse any parts of your solution to Question 1 or 2. Again, for simplicity, you can make your queue store integers rather than generic data types. Queues are necessary auxiliary data structures to implement breadth-first traversals of graphs and trees. For those problems, you should use your language’s built-in; we are asking you to implement a queue here for two reasons: to demonstrate one of the use cases of linked lists and to give you an  understanding of how they work.

// class Queue {
//     int peek() // returns the first item in the queue. O(1) time.
//     void enqueue(int x) // adds x to the back of the queue. O(1) time.
//     int dequeue() // removes and returns the first item in the queue. O(1) time.
//     bool isEmpty() // returns a boolean indicating whether the queue is empty. O(1) time.
// }

//By mistake previously done by array then i again i read the question and got to know need to do by linked list
//first spent:20 min
//for linked list solution spent:28 min

#include <iostream>

// Node class for linked list
class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = NULL;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;  // points to first element
    Node* rear;   // points to last element

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Returns the first item in the queue
    int peek() {
        if (isEmpty()) return -1;
        return front->val;
    }

    // Adds x to the back of the queue
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == NULL) { // queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Removes and returns the first item in the queue
    int dequeue() {
        if (isEmpty()) return -1;
        int val = front->val;
        Node* temp = front;
        front = front->next;
        if (front == NULL) { // queue became empty
            rear = NULL;
        }
        delete temp;
        return val;
    }

    // Checks if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Prints the queue
    void print() {
        if (isEmpty()) {
            std::cout << "Queue is Empty";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            std::cout << " " << temp->val;
            temp = temp->next;
        }
    }
};

int main() {
    Queue q;
    q.print();
    std::cout << std::endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(110);
    q.enqueue(150);

    q.print();
    std::cout << std::endl;

    std::cout << "First Element is: " << q.peek() << std::endl;

    std::cout << "Removed Integer: " << q.dequeue() << std::endl;
    std::cout << "Removed Integer: " << q.dequeue() << std::endl;
    std::cout << "Removed Integer: " << q.dequeue() << std::endl;

    q.print();
    std::cout << std::endl;
    std::cout << "First Element is: " << q.peek() << std::endl;

    std::cout << "Queue is Empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    while (!q.isEmpty()) {
        std::cout << "Removed Integer: " << q.dequeue() << std::endl;
    }

    q.print();
    std::cout << std::endl;
    std::cout << "Queue is Empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}


// #include <bits/stdc++.h>

// class Queue{
//    public:
//    std::vector<int> queue;
//    int start;
//    int end;

//    Queue(){
//     start=-1;      //-1 signifies empty
//     end=-1;
//    }  
   
//    int peek(){
//       if(start==-1){
//         return -1;
//       }
//       return queue[start];
//    }
//    void enqueue(int x){
//     if(start==end && end==-1){
//         start++;
//     }
//      end++;
//      queue.push_back(x);
//    }
//    int dequeue(){
//     if(start==-1){
//         return -1;
//     }
//     else{
//         start++;
//         return queue[start-1];
//     }
//    }
//    bool isempty(){
//     if((start==-1 && end==-1) || start>end){
//         return true;
//     }
//     return false;
//    }
//    void print(){
//       if(start!=-1 && end!=-1 && start<=end){
//            for(int i=start;i<=end;i++){
//             std::cout<<"  "<<queue[i];
//            }
//       }
//       else std::cout<<" Queue is Empty ";
//    }
// };
// int main(){
//     Queue q;
//     q.print();
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(50);
//     q.enqueue(70);
//     q.enqueue(80);
//     q.enqueue(90);
//     q.enqueue(110);
//     q.enqueue(150);

//     std::cout<<std::endl;
//     q.print();
//     std::cout<<std::endl;
//     std::cout<<"First Element is : " << q.peek()<<std::endl; 

//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;

//     q.print();
//     std::cout<<std::endl;
//     std::cout<<"First Element is : " << q.peek()<<std::endl; 

//     std::cout<<"Queue is Empty : "<<(q.isempty()?"Yes":"No")<<std::endl;

//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;
//     std::cout<<"Removed Integer is  "<< q.dequeue()<<std::endl;

//     q.print();
   
//     std::cout<<"Queue is Empty : "<<(q.isempty()?"Yes":"No")<<std::endl;
//     return 0;
// }

