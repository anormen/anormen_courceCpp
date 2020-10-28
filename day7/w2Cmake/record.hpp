#ifndef RECORD_H
#define RECORD_H

#include <iostream>

enum enum_service{ CHANGE_OIL, CHANGE_TYRE, CHANGE_LAMP, NOSERVICE };
const std::string name_service[5] = { "Change Oil", "Change tyre", "Change lamp", "No Service", " xx"} ;
enum enum_part{ OIL, TYRES, LAMP };
const std::string name_part[4] = { "Oil", "Tyres", "Lamp", "  xx "} ;
enum enum_payment_method{ NONE, CASH, CARD};
const std::string name_payment_method[4] = { "None", "Cash", "Card", " yy"};

struct payment{
            enum_payment_method method;
            int amount;
        };

class Record {
    //Attributes
    public:

        std::string date;
        std::string vehicleRegNr;
        int serviceNr;
        enum_service service[10];
        int partNr;
        enum_part part[10];
        payment CustomerPay;


    //Constructor
    Record (std::string, std::string, enum_service);

    //Methods
    void printRecord ();
    void pay(enum_payment_method, int);
    void addService(enum_service _service);
    void addPart(enum_part _part);

    ~Record();

};
#endif
