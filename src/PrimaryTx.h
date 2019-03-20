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

    auto serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = contract_name.serialize(buffer, offset);
        
        index = offset + temp;


        buffer[index] = fee;
        index = index + sizeof(uint64_t);
        
        temp = resources.serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        contract_name.deserialize(buffer, position);
        index = index + contract_name.getLength();
        fee = buffer[index];
        index = index + sizeof(uint64_t);
        resources.deserialize(buffer, index);
        //index += resources.getLength();
        length = contract_name.getLength() + sizeof(uint64_t) + resources.getLength();

    }


    void Print(){
        contract_name.printByteArray();
        std::cout << "fee: " << fee <<std::endl;
        resources.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

#endif