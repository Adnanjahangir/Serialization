#ifndef IDENTITY
#define IDENTITY

#include<iostream>
#include"ByteArray.h"

class Identity{
    uint64_t length;
    ByteArray identifier;
    ByteArray type;
    
    public:
    Identity()
    {
        length = 0;
    }

    void SetIdentity()
    {
        std::cout << "Enter identifier data: "; 
        try
        {
            identifier.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        
        std::cout << "Enter type of identifier: ";
        try
        {
            type.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        length = (identifier.getLength()) + (type.getLength());
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
    
    void PrintIdentity()
    {
        identifier.printByteArray();
        type.printByteArray();
    }
    uint64_t getLength()
    {
        return length;
    }
    ~Identity()
    {

    }

};

#endif