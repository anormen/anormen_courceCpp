// A car serviceshop needs to keep track of the records of services they provide to their customer.
// Create a system for them so they could keep ATLEAST the below records:

// - Date the customer visited
// - Services performed (at least 2 different services)
// - Parts changed (at least2 different parts)
// - Payment (method & amount)

#include "record.hpp"
//#include "part.hpp"



int main ()
{
    Record *rec1 = new Record("ABC123", "maj 23", CHANGE_OIL);
    Record *rec2 = new Record("DEF456", "june 20", CHANGE_TYRE);

    rec1->pay(CARD,199);
    rec1->addPart(LAMP);
    rec1->addPart(LAMP);
    rec2->addPart(TYRES);
    rec2->addService(CHANGE_TYRE);
    rec1->printRecord();
    rec2->printRecord();

    std::cout << std::endl;


}
