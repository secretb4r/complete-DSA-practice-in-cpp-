
#include<iostream>



//   base <- [  |  |  |  |  ] -> top

class Queue {
  
  public:
  
  int * queue, *head;
  int size, base, top, itemCounter;
  Queue() { queue = NULL;}
  Queue(int _size) {
    size = _size;
    queue = new int[size];
    head = NULL;
    base = -1, top = 0;
    itemCounter = 0;
  }
  
  int isFull();
  int isEmpty();
  
  void Enqueue(int Item);
   int Dequeue();   
  void showData();
  void updateData();
  void showHead();
  void showTail();
};

void Queue::showData() {
  int counter = 0;
  while(counter < size) {
    std::cout << queue[counter] << "\t";
    counter++;
  } 
}

int Queue::isEmpty() {
  if(base != -1) return 0;
  else return 1;
} 

int Queue::isFull() {
  if(itemCounter == size) return 1;
  else return 0;
  
}

void Queue::Enqueue(int Item) {
 if(isEmpty() || !isFull()) {
   queue[iteCounter] = Item;
   if(isEmpty()) base++;
   itemCounter++;
   head = queue[itemCounter];
 }
}

int Queue::Dequeue() {
  if(isEmpty()) {
   std::cout << "queue is empty " << std::endl;
   return base;
  }  
  
  int temp = queue[0];
  
}
int main() {
 return 0;
}
