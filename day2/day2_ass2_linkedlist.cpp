// Implement a single (forward) linked list for integers, your application should be able to

// - Add items to the end of the list
// - Remove items form the list
// - Print the list in the correct order


#include <iostream>
// Define the individual elements in the list
struct Item
{
     int value;
     item *element = nullptr;
};

// Insert new item at end of List
void append(struct item** tail, int value){
     // create new node
     struct item* newItem = new Item;
     //assigne data to the item
     newItem->data = value;

     //Set old tail to point at new item
     tail-> element = (*newItem);


}


int main ()
{


   item *head = new item;
   item *tail = new item;
   tail = head;

    for (int i = 1; i < 5; i++)
   {
       tail->value = i;
        item *nextPtr = new item;
        tail->element = nextPtr;
        // SomeDatatype *PointerName = new SomeDatatype;
        std::cout<<"adding" << i << std::endl;
        std::cout << head->value << " :start value  "<< std::endl;
        std::cout << tail->value << " :Added value  "<< std::endl;
   }


}
