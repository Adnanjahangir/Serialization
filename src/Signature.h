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
        cout << "Enter Signature data: \n"; 
        try
        {
            Signature_data.setByteArray();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        cout << "Enter type of Signature: \n";
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

    auto Serialize(Byte *buffer, int offset = 0)
    {
        Signature_data.Serialize(buffer, offset);
        Signature_type.Serialize(buffer, Signature_data.getLength()+offset);
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        Signature_data.Deserialize(buffer, position);
        Signature_type.Deserialize(buffer, position + Signature_data.getLength());
        length = (Signature_data.getLength() + Signature_type.getLength());
    }
    
    void PrintSignature()
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