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

    auto Serialize(Byte *buffer, int offset = 0)
    {
        identity_data.Serialize(buffer, offset);
        signature_data.Serialize(buffer, identity_data.getLength()+offset);
        return length;
    }
    
    void Deserialize(Byte *buffer, int position=0)
    {
        identity_data.Deserialize(buffer, position);
        signature_data.Deserialize(buffer, (position + identity_data.getLength()));
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
        cout << "IDENTITY DATA LENGTH: " << identity_data.getLength() << endl;
        cout << "DATA: ";
        identity_data.PrintIdentity();
        cout << "\nSIGNATURE DATA: " << signature_data.getLength() <<endl;
        cout << "DATA: ";
        signature_data.PrintSignature();
        cout << endl;
    }

    auto getLength(){
        return length;
    }
};


#endif