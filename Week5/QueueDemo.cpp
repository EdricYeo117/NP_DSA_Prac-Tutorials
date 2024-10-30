#include <string>
#include <iostream>
#include "QueuePointer.cpp"

using namespace std;
typedef string ItemType;


int main() {

}

// Client function to return last element of the queue, without changing queue
bool getLastElement(Queue& q, ItemType& item) {
    if (q.isEmpty()) {
        return false;
    } else {
        Queue temp;
        ItemType lastItem;

        // Transfer all elements from q to temp
        while (!q.isEmpty()) {
            ItemType tempItem;
            // Dequeue from q 
            q.dequeue(tempItem);
            // Enqueue to temp
            temp.enqueue(tempItem);
            // Set lastItem to the last item dequeued from q
            lastItem = tempItem; 
        }

        // Restore original queue
        while (!temp.isEmpty()) {
            ItemType tempItem;
            // Dequeue from temp and enqueue to q
            temp.dequeue(tempItem);
            // Enqueue to q
            q.enqueue(tempItem);
        }

        item = lastItem;
        return true;
    }
}