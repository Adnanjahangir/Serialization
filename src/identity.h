#pragma once

#include<iostream>
#include"ByteArray.h"


namespace eMumba_ad{
    namespace serialization{
        class Identity{
            uint64_t length;
            ByteArray identifier;
            ByteArray type;
            
            public:
            Identity()
            {
                length = 0;
            }

            Identity(const ByteArray &obj1, const ByteArray &obj2)
            {
                identifier = obj1;
                type = obj2;
                length = identifier.getLength() + type.getLength();
            }
            
            void operator =(const Identity &obj2)
            {
                identifier = obj2.identifier;
                type = obj2.type;
                length = identifier.getLength() + type.getLength();

            }

            void setIdentifier(const ByteArray &obj1)
            {
                identifier = obj1;
                length = identifier.getLength() + type.getLength();
            }

            void setType(const ByteArray &obj1)
            {
                type = obj1;
                length = identifier.getLength() + type.getLength();
            }

            auto serialize(Byte *buffer, const uint64_t &offset = 0)
            {
                identifier.serialize(buffer, offset);
                type.serialize(buffer, offset + identifier.getLength());
                return length;
            }

            void deserialize(Byte *buffer, const uint64_t &position=0)
            {
                identifier.deserialize(buffer, position);
                type.deserialize(buffer, (position + identifier.getLength()));
                length = (identifier.getLength()) + (type.getLength());
            }
            
            void print()
            {
                
                identifier.print();
                type.print();
                
            }
            uint64_t getLength()
            {
                return length;
            }
            ~Identity()
            {

            }

        };
    }
}