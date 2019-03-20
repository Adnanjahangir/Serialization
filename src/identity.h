#ifndef IDENTITY
#define IDENTITY

#include<iostream>
#include"ByteArray.h"

class Identity{
    uint64_t length;
    ByteArray Identifier;
    ByteArray type;
    
    public:
    Identity()
    {
        length = 0;
    }

    void SetIdentity()
    {
        cout << "Enter Identifier data: "; 
        try
        {
            Identifier.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        
        cout << "Enter type of Identifier: ";
        try
        {
            type.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        length = (Identifier.getLength()) + (type.getLength());
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        Identifier.Serialize(buffer, offset);
        type.Serialize(buffer, offset + Identifier.getLength());
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        Identifier.Deserialize(buffer, position);
        type.Deserialize(buffer, (position + Identifier.getLength()));
        length = (Identifier.getLength()) + (type.getLength());
    }
    
    void PrintIdentity()
    {
        Identifier.printByteArray();
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