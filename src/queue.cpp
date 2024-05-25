
#include<iostream>



//   base <- [  |  |  |  |  ] -> top

class Queue {
  
  public:
  
  int * queue, *front, *back;
  int queueSize, size, itemCounter;
  Queue() { queue = NULL;}
  Queue(int _size) {
    queueSize = _size;
    queue = new int[queueSize];
    front = back = &queue[0];
    itemCounter = 0;
    size = -1;
  }
  
  // queueSize -> total size of queue
  // size -> total length of present item in queue
  // itemCounter -> 
  
  int isFull();
  int isEmpty();
  
  void Enqueue(int Item);
   int Dequeue();   
  void showQueue();
  void updateQueueData(int position, int value);
  void showHead();
  void showTail();
};


int Queue::isEmpty() {
  if(size != -1) return 0;
  else return 1;
} 

int Queue::isFull() {
  if(size == queueSize -1) return 1;
  else return 0;
  
}

void Queue::Enqueue(int Item) {
 if(isEmpty() || !isFull()) {
   size++;
   queue[size] = Item;
   back = &queue[size];
   itemCounter++;
  } else {
   std::cout << "can't push queue is full " << std::endl;
  }
}

int Queue::Dequeue() {
  if(isEmpty()) {
   std::cout << "queue is empty " << std::endl;
   return size;
  }  
  int temp = queue[0];
  int index = 0;
  while(index < size) {
   queue[index] = queue[index + 1];
   index++;
  }
  size--;
  itemCounter--;  
  return temp;
}

void Queue::showHead() {
  std::cout << "front: " << *front << std::endl;
}

void Queue::showTail() {
 std::cout << "back: " << *back << std::endl;
}


void Queue::showQueue() {
  int index = 0;
  while(index < itemCounter) {
   std::cout << queue[index] << std::endl;
   index++; 
  }
}


void Queue::updateQueueData(int position, int value) {
  if(position > queueSize -1 || position < 0) {
   std::cout << "position out of range , give valid position" << std::endl; 
  } else if( position > itemCounter-1) {
   std::cout << " position should be less than or equal size of the queue" <<std::endl;
  }
  
  queue[position] = value;
}
 

int main() {

Queue first(6);

first.Enqueue(12);
first.Enqueue(23);
first.Enqueue(34);
first.Enqueue(67);


first.showQueue();
first.showHead();
first.showTail();
std::cout << "size: " << first.itemCounter << "\n";


first.Dequeue();

first.showQueue();
first.showHead();
first.showTail();
std::cout << "size: " << first.itemCounter << "\n";
 return 0;
}
