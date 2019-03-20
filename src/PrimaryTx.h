#ifndef PRIMARYTX
#define PRIMARYTX

#include "List.h"


class PrimaryTx{
    ByteArray Contract_name;
    
    uint64_t Fee;
    List<ByteArray> Resources;
    uint64_t length;
    public:
    PrimaryTx(){
        Fee = 0;
        length = 0;
    }

    ~PrimaryTx(){

    }
    
    void setPrimaryTx(){
        cout << "Enter contract name: ";
        try{
            Contract_name.setByteArray();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        cout << "Enter length of Fee: ";
        cin >> Fee ;
        if(cin.fail())
        {
            throw MyException();
        }
        try{
                Resources.setListItems();      
        }
        catch(const std::exception& e){
            throw MyException();
        }
        
        length = Contract_name.getLength() + sizeof(Fee) + Resources.getLength();

    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = Contract_name.Serialize(buffer, offset);
        
        index = offset + temp;


        buffer[index] = Fee;
        index = index + sizeof(uint64_t);
        
        temp = Resources.Serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        Contract_name.Deserialize(buffer, position);
        index = index + Contract_name.getLength();
        Fee = buffer[index];
        index = index + sizeof(uint64_t);
        Resources.Deserialize(buffer, index);
        //index += Resources.getLength();
        length = Contract_name.getLength() + sizeof(uint64_t) + Resources.getLength();

    }


    void Print(){
        Contract_name.printByteArray();
        cout << "Fee: " << Fee <<endl;
        Resources.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

#endif