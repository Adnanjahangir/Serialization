#ifndef BYTEARRAY
#define BYTEARRAY

#include<iostream>
using namespace std;

typedef unsigned char Byte;

class ByteArray{

    uint64_t number_of_bytes;
    Byte* Bytes;
    
    public:
    ByteArray()
    {
        Bytes = new Byte;
        number_of_bytes = 0;
    }
    ByteArray(uint64_t no):number_of_bytes(no)
    {
        Bytes = new Byte[number_of_bytes];
        auto b = 0x47;  
        for(int i = 0; i<number_of_bytes; i++)
        {
            Bytes[i] = char(b);
            b += 1;
        }
    }

    void setByteArray()
    {
        cout << "Enter length: ";
        cin >> number_of_bytes;
        delete Bytes;
        cout << "Enter " << number_of_bytes << " bytes: ";
        Bytes = new Byte [number_of_bytes]; 
        for(int i = 0; i< number_of_bytes; i++)
        {
            cin >> Bytes[i];
        }

    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_bytes;
        
        for(int i = 0; i < number_of_bytes; i++)
        {
            buffer[(sizeof(uint64_t) + i + offset)] = Bytes[i] ;
        }
        return number_of_bytes+sizeof(uint64_t);
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        number_of_bytes = buffer[position];
        delete Bytes;
        Bytes = new Byte [number_of_bytes];
        for(int i = 0; i < number_of_bytes; i++)
        {
            Bytes[i] = buffer[i + sizeof(uint64_t) + position];
        }
    }
    
    void printByteArray()
    {
        for(int i = 0; i < number_of_bytes; i++)
        {
            cout << Bytes[i] << " ";
        }
        cout << endl;
    }

    uint64_t getLength()
    {
        return (number_of_bytes+sizeof(uint64_t));
    }
    ~ByteArray()
    {
        delete[] Bytes;
    }
};

#endif