#ifndef PRIMARYTX
#define PRIMARYTX

#include "List.h"


class PrimaryTx{
    ByteArray contract_name;
    uint64_t fee;
    List<ByteArray> resources;
    uint64_t length;
    public:
    PrimaryTx(){
        fee = 0;
        length = 0;
    }

    ~PrimaryTx(){

    }
    
    void setPrimaryTx(){
        std::cout << "Enter contract name: ";
        try{
            contract_name.setByteArray();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        std::cout << "Enter length of fee: ";
        std::cin >> fee ;
        if(std::cin.fail())
        {
            throw MyException();
        }
        try{
                resources.setListItems();      
        }
        catch(const std::exception& e){
            throw MyException();
        }
        
        length = contract_name.getLength() + sizeof(fee) + resources.getLength();

    }

    auto serialize(Byte *buffer, const uint64_t &offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = contract_name.serialize(buffer, offset);
        
        index = offset + temp;

        Byte *ptr = buffer + index;
        memcpy(ptr, &fee, sizeof(fee));
        index = index + sizeof(fee);

        temp = resources.serialize(buffer, index);
        index = index + temp;
        return length;
    }

    void deserialize(Byte *buffer, const uint64_t &position=0)
    {
        
        uint64_t index = position;
        contract_name.deserialize(buffer, position);
        index = index + contract_name.getLength();
        Byte *ptr = buffer+index;
        memcpy(&fee, ptr, sizeof(fee));
                
        index = index + sizeof(uint64_t);
        resources.deserialize(buffer, index);
        
        length = contract_name.getLength() + sizeof(uint64_t) + resources.getLength();

    }

    void Print(){
        contract_name.printByteArray();
        Byte *temp;
        temp = new Byte[sizeof(uint64_t)];
        std::cout << fee ;
        resources.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

#endif