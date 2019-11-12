#include <iostream>
#include "Queue.h"

using namespace std;


// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
    arr = new int[INITIAL_SIZE];
} // constructor


// Desc: Destructor
Queue::~Queue(){
    delete [] arr;
};


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    
    //if reached capacity and front index overlap with backindex, create new dynamic array with double the capacity
    if(size == capacity && frontindex == backindex){
        int * newArr;
        newArr = new int[2*capacity];

        //copy all elements of arr to newArr
        for(int i = 0; i < capacity; i++){
            newArr[i] = arr[(frontindex + i) % capacity];
        };
        
        delete [] arr;   //recycle old Array
        arr = newArr;   //assign pointer arr to newArr
        frontindex = 0;     //frontindex becomes 0
        backindex = size;   //backindex becomes orginal size
        capacity = capacity*2;  //double original capacity  
    };

    size++;
    arr[backindex] = x;
    backindex = (backindex + 1) % capacity;  
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    
    //if queue is empty, return
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    };
    
    //if size of queue is less than a quarter for the capacity and th current capacity is not the initial capacity, create new array with half the current capacity
    if(size < (capacity/4) && capacity != INITIAL_SIZE){
        int * newArr;
        newArr = new int[capacity/2];

        //copy all current queue elements into new array
        for(int i = 0; i < size; i++){
            newArr[i] = arr[frontindex + i];
        };

        frontindex = 0;     //front index becomes 0
        backindex = size;   //back index is original value of size

        delete [] arr;      //recycle old array
        arr = newArr;       //assign arr to point to new array
        capacity = capacity/2;  //halve the original capacity
    };

    size--;
    frontindex = (frontindex + 1) % capacity;
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    return arr[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty




