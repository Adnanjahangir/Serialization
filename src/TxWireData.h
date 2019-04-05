#pragma once


#include"PrimaryTx.h"
#include"List.h"
#include"ByteArray.h"
#include"SigningTx.h"


namespace eMumba_ad{
    namespace serialization{
        class TxWireData{
            PrimaryTx tx_data;
            List<Signatory> list_data;
            uint64_t length;

            public:
            TxWireData(){
                length = 0;
            }
            
            TxWireData(const PrimaryTx &pt1, const uint64_t &len){
                tx_data = pt1;
                list_data.setLength(len);
            }

            void setdataLength(const int &len){
                list_data.setLength(len);
            }

            void addData(const Signatory &b1){
                list_data.add(b1);
                length = tx_data.getLength() + list_data.getLength();

            }

            void setTxData(const PrimaryTx &pt1){
                tx_data = pt1;
                length = tx_data.getLength() + list_data.getLength();
            }


            auto serialize(Byte *buffer, const uint64_t &offset = 0)
            {
                uint64_t index = 0, temp = 0;
                temp = tx_data.serialize(buffer);
                
                index = offset + temp;
                temp = list_data.serialize(buffer, index);
                index = index + temp;
                length = index;
                return length;
            }

            void deserialize(Byte *buffer, const uint64_t &position=0)
            {
                uint64_t index = position;
                tx_data.deserialize(buffer);
                index = index + tx_data.getLength();


                list_data.deserialize(buffer, index);
                length = index + list_data.getLength();
            }
            
            void print(){
                tx_data.print();
                list_data.print();
            }
            
            uint64_t getLength(){
                return length;
            }

        };
    }
}
