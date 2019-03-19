#ifndef TXWIREDATA
#define TXWIREDATA



#include"PrimaryTx.h"
#include"List.h"
#include"ByteArray.h"

using namespace std;

class TxWireData{
    PrimaryTx Tx_data;
    List<Signatory> list_data;
    uint64_t length;

    public:
    TxWireData(){
        length = 0;
    }
    
    void setTxWireData(){
        Tx_data.setPrimaryTx();
        list_data.setListItems();
        length = Tx_data.getLength() + list_data.getLength();
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = Tx_data.Serialize(buffer);
        
        index = offset + temp;
        temp = list_data.Serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        Tx_data.Deserialize(buffer);
        index = index + Tx_data.getLength();


        list_data.Deserialize(buffer, index);
        length = index + list_data.getLength();
    }
    
    void printTxWireData(){
        Tx_data.Print();
        list_data.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

#endif