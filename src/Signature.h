#pragma once
#include"ByteArray.h"

namespace eMumba_ad{
    namespace serialization{
        class Signature{
            uint64_t length;
            ByteArray signature_data;
            ByteArray signature_type;
            
            public:
            Signature(){
            }

            Signature(const ByteArray &obj1, const ByteArray &obj2){
                signature_data = obj1;
                signature_type = obj2;
                length = signature_data.getLength() + signature_type.getLength();
            }

            void operator =(const Signature &obj2)
            {
                signature_data = obj2.signature_data;
                signature_type = obj2.signature_type;
                length = signature_data.getLength() + signature_type.getLength();

            }

            void setData(const ByteArray &obj1){
                signature_data = obj1;    
                length = signature_data.getLength() + signature_type.getLength();

            }
            
            void setType(const ByteArray &obj1){
                signature_type = obj1;    
                length = signature_data.getLength() + signature_type.getLength();

            }

            auto serialize(Byte *buffer, const uint64_t &offset = 0)
            {
                signature_data.serialize(buffer, offset);
                signature_type.serialize(buffer, signature_data.getLength()+offset);
                return length;
            }

            void deserialize(Byte *buffer, const uint64_t &position=0)
            {
                signature_data.deserialize(buffer, position);
                signature_type.deserialize(buffer, position + signature_data.getLength());
                length = (signature_data.getLength() + signature_type.getLength());
            }
            
            void print()
            {
                signature_data.print();
                signature_type.print();
            }
            uint64_t getLength()
            {
                return length;
            }
            ~Signature()
            {
            }

        };
    }
}