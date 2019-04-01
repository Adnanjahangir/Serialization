#ifndef SIGNATURE
#define SIGNATURE

#include"ByteArray.h"

class Signature{
    uint64_t length;
    ByteArray Signature_data;
    ByteArray Signature_type;
    
    public:
    Signature(){
    }

    void SetSignature(){
        std::cout << "Enter Signature data: \n"; 
        try
        {
            Signature_data.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        std::cout << "Enter type of Signature: \n";
        try
        {
            Signature_type.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        length = Signature_data.getLength() + Signature_type.getLength();
    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        Signature_data.serialize(buffer, offset);
        Signature_type.serialize(buffer, Signature_data.getLength()+offset);
        return length;
    }

    void deserialize(Byte *buffer, int position=0)
    {
        Signature_data.deserialize(buffer, position);
        Signature_type.deserialize(buffer, position + Signature_data.getLength());
        length = (Signature_data.getLength() + Signature_type.getLength());
    }
    
    void printSignature()
    {
        Signature_data.printByteArray();
        Signature_type.printByteArray();
    }
    uint64_t getLength()
    {
        return length;
    }
    ~Signature()
    {
    }

};

#endif