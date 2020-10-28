// A car serviceshop needs to keep track of the records of services they provide to their customer.
// Create a system for them so they could keep ATLEAST the below records:

// - Date the customer visited
// - Services performed (at least 2 different services)
// - Parts changed (at least2 different parts)
// - Payment (method & amount)

#include "record.hpp"
//#include "part.hpp"
// Constructor
Record::Record(std::string _regNr, std::string _date, enum_service _service){
    vehicleRegNr = _regNr;
    serviceNr = 0;
    service [serviceNr] = _service;
    serviceNr++;
    date = _date;
    CustomerPay.method = NONE;
    CustomerPay.amount = 0;
}

void Record::pay(enum_payment_method _method, int _payment){
    CustomerPay.amount = CustomerPay.amount + _payment;
    CustomerPay.method = _method;
}
void Record::addService(enum_service _service){
    service[serviceNr]  = _service;
    serviceNr++;
}
void Record::addPart(enum_part _part){
    part[partNr]  = _part;
    partNr++;
}



void Record::printRecord ()
{
    std::cout << "Reg Nr. "<< vehicleRegNr<<" Date: " << date<< std::endl;
    std::cout << "Service ";
    for (int i = 0; i < serviceNr; i++)
    {
        std::cout << name_service[service[i]] << ", "<< std::endl;

    }
    std::cout << "Parts ";
    for (int i = 0; i < partNr; i++)
    {
        std::cout << name_part[part[i]]  << ", ";

    }
    std::cout << std::endl;

    std::cout << "Payed: " << CustomerPay.amount <<" with " <<name_payment_method[CustomerPay.method] << std::endl << std::endl;
}


