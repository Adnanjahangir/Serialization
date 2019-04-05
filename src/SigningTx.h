#pragma once


#include"PrimaryTx.h"
#include"identity.h"

namespace eMumba_ad{
    namespace serialization{
        class SigningTx{
            PrimaryTx primary_data;
            Identity identity_data;
            uint64_t length;
            public:
            SigningTx(){
                length = 0;
            }

            SigningTx(const PrimaryTx &pt1, const Identity &i1){
                primary_data = pt1;
                identity_data = i1;
                length = primary_data.getLength() + identity_data.getLength();
            }

            ~SigningTx(){

            }
            void setPrimary(const PrimaryTx &pt1){
                primary_data = pt1;
                length = primary_data.getLength() + identity_data.getLength();
            }

            void setIdentity(const Identity &i1){
                identity_data = i1;
                length = primary_data.getLength() + identity_data.getLength();
            }

            auto serialize(Byte *buffer, const uint64_t &offset = 0)
            {
                uint64_t index = 0, temp = 0;
                temp = primary_data.serialize(buffer);
                
                index = offset + temp;
                temp = identity_data.serialize(buffer, index);
                index = index + temp;
                length = index;
                return length;
            }

            void deserialize(Byte *buffer, const uint64_t &position=0)
            {
                uint64_t index = position;
                primary_data.deserialize(buffer);
                index = index + primary_data.getLength();


                identity_data.deserialize(buffer, index);
                length = index + identity_data.getLength();
            }

            uint64_t getLength(){
                return length;
            }

            void print(){
                primary_data.print();
                identity_data.print();
            }

        };
    }
}