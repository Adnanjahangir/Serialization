#ifndef BYTEARRAY
#define BYTEARRAY

#include<iostream>
#include<cstring>

typedef unsigned char Byte;


struct MyException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Input Error";
    }
};



class ByteArray{

    uint64_t number_of_bytes;
    Byte* bytes;
    
    public:
    ByteArray()
    {
        number_of_bytes = 0;
        bytes = new Byte[number_of_bytes];
    }
    ByteArray(uint64_t no):number_of_bytes(no)
    {
        bytes = new Byte[number_of_bytes];
        auto b = 0x47;  
        for(int i = 0; i<number_of_bytes; i++)
        {
            bytes[i] = char(b);
            b += 1;
            if (b>0x73)
                b=b-0x26;
        }
    }
    
    void setByteArray()
    {
        std::cout << "Enter length: ";
        std::cin >> number_of_bytes;
        if(std::cin.fail())
        {
            throw MyException();
        }
        delete bytes;
        std::cout << "Enter " << number_of_bytes << " bytes: ";
        bytes = new Byte [number_of_bytes]; 
        for(int i = 0; i< number_of_bytes; i++)
        {
            std::cin >> bytes[i];
            if(std::cin.fail())
            {
                throw MyException();
            }
        }

    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        Byte *ptr = buffer+offset;
        memcpy(ptr, &number_of_bytes, sizeof(uint64_t));

        for(int i = 0; i < number_of_bytes; i++)
        {
            buffer[(sizeof(uint64_t) + i + offset)] = bytes[i] ;
        }
        return number_of_bytes+sizeof(uint64_t);
    }

    void deserialize(Byte *buffer, int position=0)
    {
        Byte *ptr = buffer+position;
        memcpy(&number_of_bytes, ptr, sizeof(uint64_t));
        delete bytes;
        bytes = new Byte [number_of_bytes];
        for(int i = 0; i < number_of_bytes; i++)
        {
            bytes[i] = buffer[i + sizeof(uint64_t) + position];
        }
    }
    
    void printByteArray()
    {
        std::cout  << (number_of_bytes) ;
        
        for(int i = 0; i < number_of_bytes; i++)
        {
            std::cout  << int(bytes[i]) ;
        }
        
    }

    bool operator ==(ByteArray obj2)
    {
        bool isEqual = true;
        if(getLength() != obj2.getLength())
        {
            return false;
        }

        for(int i = 0; i < number_of_bytes; i++)
        {
            if(bytes[i] != obj2.bytes[i])
            {
                return false;
            }
        }
        return true;
    }

    uint64_t getLength()
    {
        return (number_of_bytes+sizeof(uint64_t));
    }

    ~ByteArray()
    {
        delete[] bytes;
    }
};


#endif