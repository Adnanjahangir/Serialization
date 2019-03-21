#ifndef SIGNATORY
#define SIGNATORY


#include"identity.h"
#include"Signature.h"

class Signatory{
    Identity identity_data;
    Signature signature_data;
    uint64_t length;
    public:
    Signatory(){
        length = 0;
    }

    ~Signatory(){

    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        identity_data.serialize(buffer, offset);
        signature_data.serialize(buffer, identity_data.getLength()+offset);
        return length;
    }
    
    void deserialize(Byte *buffer, int position=0)
    {
        identity_data.deserialize(buffer, position);
        signature_data.deserialize(buffer, (position + identity_data.getLength()));
        length = (identity_data.getLength()) + (signature_data.getLength());
    }

    void setSignatory(){
        try
        {
            identity_data.SetIdentity();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
        try
        {
            identity_data.SetIdentity();
        }
        catch(const std::exception& e)
        {
            throw MyException();
        }
    }
    
    void printSignatory(){
        Byte *temp;
        temp = new Byte[sizeof(uint64_t)];
        *temp = identity_data.getLength();
        for(int i = 0; i<sizeof(uint64_t); i++)
        {
            if(int(temp[i]) <= 9)
                std::cout << "0"; 
            std::cout << int(temp[i]); 
        }
        
        identity_data.PrintIdentity();
        *temp = signature_data.getLength();
        for(int i = 0; i<sizeof(uint64_t); i++)
        {
            if(int(temp[i]) <= 9)
                std::cout << "0"; 
            std::cout << int(temp[i]); 
        }
        delete[] temp;
        signature_data.printSignature();
    }

    auto getLength(){
        return length;
    }
};


#endif