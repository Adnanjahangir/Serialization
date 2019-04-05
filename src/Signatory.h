#pragma once

#include"identity.h"
#include"Signature.h"

namespace eMumba_ad{
    namespace serialization{
        class Signatory{
            Identity identity_data;
            Signature signature_data;
            uint64_t length;
            public:
            Signatory(){
                length = 0;
            }
            
            Signatory(const Identity &i1, const Signature &s1){
                identity_data = i1;
                signature_data = s1;
                length = identity_data.getLength() + signature_data.getLength();
            }

            void operator =(const Signatory &s1){
                identity_data = s1.identity_data;
                signature_data = s1.signature_data;
                length = identity_data.getLength() + signature_data.getLength();
            }

            void setIdentity(const Identity &i1){
                identity_data = i1;
                length = identity_data.getLength() + signature_data.getLength();
            }
            
            void setSignature(const Signature &s1){
                signature_data = s1;
                length = identity_data.getLength() + signature_data.getLength();
            }

            ~Signatory(){

            }

            auto serialize(Byte *buffer, const uint64_t &offset = 0){
                identity_data.serialize(buffer, offset);
                signature_data.serialize(buffer, identity_data.getLength()+offset);
                return length;
            }
            
            void deserialize(Byte *buffer, const uint64_t &position=0){
                identity_data.deserialize(buffer, position);
                signature_data.deserialize(buffer, (position + identity_data.getLength()));
                length = (identity_data.getLength()) + (signature_data.getLength());
            }
            
            void print(){
                
                identity_data.print();
                signature_data.print();
            }

            auto getLength(){
                return length;
            }
        };
    }
}