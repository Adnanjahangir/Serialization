#ifndef SIGNINGTX
#define SIGNINGTX


#include"PrimaryTx.h"
#include"identity.h"


class SigningTx{
    PrimaryTx primary_data;
    Identity identity_data;
    uint64_t length;
    public:
    SigningTx(){
        length = 0;
    }
    ~SigningTx(){

    }
    void setSigningTx(){
        try{
            primary_data.setPrimaryTx();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        try{
            identity_data.SetIdentity();
        }
        catch(const std::exception& e){
            throw MyException();
        }
        length = (primary_data.getLength() + identity_data.getLength());
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = primary_data.Serialize(buffer);
        
        index = offset + temp;
        temp = identity_data.Serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        primary_data.Deserialize(buffer);
        index = index + primary_data.getLength();


        identity_data.Deserialize(buffer, index);
        length = index + identity_data.getLength();
    }

    uint64_t getLength(){
        return length;
    }

    void printSigningTx(){
        cout << "PRIMARY DATA: " <<endl;
        primary_data.Print();


        cout << endl << "IDENTITY DATA: " << endl;
        identity_data.PrintIdentity();
    }

};

#endif