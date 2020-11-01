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
}
// Index counted 0 based
void addAtIndex ( Item *head, int _index, int _value){
    Item* newItem = new Item;
    Item* temp;
    temp = head;
    for (int i = 0; ((i < _index-1)&& (temp->element != nullptr)); i++)
    {
        temp= temp->element;   
    }
    newItem->value = _value;
    newItem->element = temp->element;
    temp->element = newItem;
}
void removeAtIndex(Item *head, int _index){
    Item* temp, *temp2;
    temp = head;
    for (int i = 0; ((i < _index-1)&& (temp->element != nullptr)); i++)
    {
        temp = temp->element;
    }
    temp2 = temp->element;
    temp->element = temp2->element;
    delete temp2;
}

Item* initList(int _value)
{
    Item* head = new Item;
    head->value = _value;
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

    for (int i = 2; i < 8; i++)
    {
       append (head, i);
    }
    printListH(head);   
    addAtIndex(head, 2, 9);
    printListH(head); 
    removeAtIndex(head, 5);
    printListH(head);
    head = RemoveFront(head);
    deleteList(head);
}
