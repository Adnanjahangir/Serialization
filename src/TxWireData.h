#ifndef TXWIREDATA
#define TXWIREDATA



#include"PrimaryTx.h"
#include"List.h"
#include"ByteArray.h"
#include"SigningTx.h"


class TxWireData{
    PrimaryTx tx_data;
    List<Signatory> list_data;
    uint64_t length;

    public:
    TxWireData(){
        length = 0;
    }
    
    void setTxWireData(){
        try{
            tx_data.setPrimaryTx();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        try{
            list_data.setListItems();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        length = tx_data.getLength() + list_data.getLength();
    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = tx_data.serialize(buffer);
        
        index = offset + temp;
        temp = list_data.serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        tx_data.deserialize(buffer);
        index = index + tx_data.getLength();


        list_data.deserialize(buffer, index);
        length = index + list_data.getLength();
    }
    
    void printTxWireData(){
        tx_data.Print();
        list_data.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

#endif