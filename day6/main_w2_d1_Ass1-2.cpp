
#include <iostream>
#include <bitset>         // std::bitset


int main(){

    uint16_t inputData_Packed = 0b1011101001011011;
    decode (inputData_Packed);

    // Data to send
    uint16_t speed = 100;
    uint16_t front = 0;
    uint16_t rear = 750;
    uint16_t right = 900;
    uint16_t left = 900;

    std::cout<< "Data sent to send:  " << std::bitset<16>(encode(speed, front, rear, right, left) )<< std::endl;


    detect_crash(front, rear, right, left);
}


void decode( uint16_t _dataPacked){

    struct fieldIn{
        unsigned lights:3;
        unsigned doors:4;
        unsigned windows:4;
        unsigned seatbelts:5;
    };

    union {
        uint16_t dataPacked;
        fieldIn inData;
    } inputData;

    inputData.dataPacked = _dataPacked;

    // Light
    std::cout<< "Frontlight is " << ((inputData.inData.lights & 0b001)? "on" :"of" )<< std::endl;
    std::cout<< "Stoplight is " << ((inputData.inData.lights & 0b010)? "on" :"of" )<< std::endl;
    std::cout<< "Reverselight is " << ((inputData.inData.lights & 0b100)? "on" :"of" )<< std::endl;
    std::cout << "----------------------------------" << std::endl;

    //Doors
    std::cout<< "Driver door is " << ((inputData.inData.doors & 0b0001)? "open" :"closed" )<< std::endl;
    std::cout<< "Passenger door is " << ((inputData.inData.doors & 0b0010)? "open" :"closed" )<< std::endl;
    std::cout<< "Rear left door is " << ((inputData.inData.doors & 0b0100)? "open" :"closed" )<< std::endl;
    std::cout<< "Rear right door is " << ((inputData.inData.doors & 0b1000)? "open" :"closed" )<< std::endl;
    std::cout << "----------------------------------" << std::endl;

    //Windows
    std::cout<< "Driver window is " << ((inputData.inData.windows & 0b0001)? "up" :"down" )<< std::endl;
    std::cout<< "Passenger window is " << ((inputData.inData.windows & 0b0010)? "up" :"down" )<< std::endl;
    std::cout<< "Rear left window is " << ((inputData.inData.windows & 0b0100)? "up" :"down" )<< std::endl;
    std::cout<< "Rear right window is " << ((inputData.inData.windows & 0b1000)? "up" :"down" )<< std::endl;
    std::cout<< "All windows are " << ((inputData.inData.windows & 0b1111)? "up" :"not up" )<< std::endl;
    std::cout << "----------------------------------" << std::endl;

    // Seatbelts
    std::cout<< "Driver is  " << ((inputData.inData.seatbelts & 0b00001)? "belted" :"unbelted" )<< std::endl;
    std::cout<< "Front passenger is  " << ((inputData.inData.seatbelts & 0b00010)? "belted" :"unbelted" )<< std::endl;
    std::cout<< "Rear left passenger is  " << ((inputData.inData.seatbelts & 0b00100)? "belted" :"unbelted" )<< std::endl;
    std::cout<< "Rear mid passenger is  " << ((inputData.inData.seatbelts & 0b01000)? "belted" :"unbelted" )<< std::endl;
    std::cout<< "Rear right passenger is  " << ((inputData.inData.seatbelts & 0b10000)? "belted" :"unbelted" )<< std::endl;
    std::cout << "----------------------------------" << std::endl;

}
uint16_t encode(uint16_t _speed, uint16_t _front, uint16_t _rear, uint16_t _right, uint16_t _left) {
    // Output data
    struct fieldOut{
        unsigned left:3;
        unsigned right:3;
        unsigned rear:3;
        unsigned front:3;
        unsigned speed:4;
    };
    union {
        uint16_t outDataPacked;
        fieldOut outDataField;
    } outputData;

    // Scaling speed
    const u_int8_t speed_scale = 20;
    // Scaling distance
    const u_int8_t distance_scale = 150;
    fieldOut _output;

    outputData.outDataField.left = _left/distance_scale;
    outputData.outDataField.right = _right/distance_scale;
    outputData.outDataField.rear = _rear/distance_scale;
    outputData.outDataField.front = _front/distance_scale;
    outputData.outDataField.speed = _speed/speed_scale;
    return outputData.outDataPacked;

}

bool detect_crash(uint16_t _front, uint16_t _rear, uint16_t _right, uint16_t _left){
    if ((_front == 0)|| (_rear == 0)|| (_right== 0)|| _left == 0))
   {
       std::cout << "We have a crash" << std::endl;
   }
}

