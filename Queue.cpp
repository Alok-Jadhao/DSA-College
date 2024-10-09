#include <iostream>

using namespace std;

struct Queue {
    int front;
    int rear;
    int size;
    int *arr[50];
};

bool isEmpty(Queue q) {
    return q.rear < q.front;
}

bool isFull(Queue q) {
    return q.rear == q.arr.size() - 1;
}

void enqueue(Queue q, int x) {
    if (isFull(q)) {
      cout << "Queue is full" << endl;
      return;
      }
    else {
        q.arr[q.rear] = x;
        q.rear++;
        }


}

int dequeue(Queue q) {
  if (isEmpty(q)) {
    cout << "Queue is empty" << endl;
    return -1;
    } else {
      int x = q.arr[q.front];
      q.front++;
      return x;

}

int main() {
    return 0;
}