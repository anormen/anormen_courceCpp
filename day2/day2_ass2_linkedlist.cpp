// Implement a single (forward) linked list for integers, your application should be able to

// - Add items to the end of the list
// - Remove items form the list
// - Print the list in the correct order


#include <iostream>
// Define the individual elements in the list
struct Item
{
     int value;
     Item *element = nullptr;
};

Item * findTail(Item *head)
{
     Item * next; // = new Item;
     next = head;

     while(next->element != nullptr)
     {
          next = next->element;
     }
     return next;
}

// Insert new item at end of List
void append(Item *head, int _value){
     // create new node
     Item* newItem = new Item;
     Item* oldtail = findTail(head);
     //assigne data to the item
     newItem->value = _value;
     //Find old tail and make it point to newItem

     oldtail->element = newItem;
     std::cout << "append"  <<  newItem->value << std::endl;   
}

Item* initList(int _value)
{
     Item* head = new Item;
     head->value = _value;
     std::cout << "initlist"  <<  head->value << std::endl;
     return head;
}
void printListH( Item *head){
     Item *next;
     next = head;
     while ( next != nullptr)
     {
          std::cout << next->value << std::endl;
          next = next->element;
     }
}
Item* RemoveFront (Item *_head){
     Item *temp;
     temp = _head;
     _head = temp->element;
     delete temp;
     return _head;
}

void deleteList(Item *head)
{
     Item *temp = head, *temp2; 
     temp = head;
     while(temp != nullptr)
     {
          temp2 = temp->element;
          delete  temp;
          temp = temp2;
     }
     std::cout << "deleting list" << std::endl;
}


int main ()
{
    Item *head;
   
    head = initList(1);

    for (int i = 2; i < 5; i++)
    {
        append (head, i);
    }
    printListH(head);
    head = RemoveFront(head);
    printListH(head);


    deleteList(head);
}
