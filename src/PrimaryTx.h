#pragma once

#include "List.h"


namespace eMumba_ad{
    namespace serialization{
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

            PrimaryTx(const ByteArray &b1, const uint64_t &f, const uint64_t &len){
                contract_name = b1;
                fee = f;
                resources.setLength(len);
                length = contract_name.getLength() + sizeof(fee) + resources.getLength();
            }

            void operator =(const PrimaryTx &obj2)
            {
                contract_name = obj2.contract_name;
                fee = obj2.fee;
                resources = obj2.resources;
                length = contract_name.getLength() + sizeof(fee) + resources.getLength();
            }

            void setResourcesLength(const int &len){
                resources.setLength(len);
            }

            void addResources(const ByteArray &b1){
                resources.add(b1);
                length = contract_name.getLength() + sizeof(fee) + resources.getLength();

            }

            void setFee(const uint64_t &f){
                fee = f;
            }
            
            void setContractName(const ByteArray &b1){
                contract_name = b1;
            }

            ~PrimaryTx(){

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

            void print(){
                contract_name.print();
                std::cout << fee ;
                resources.print();
            }
            
            uint64_t getLength(){
                return length;
            }

        };
        }
}