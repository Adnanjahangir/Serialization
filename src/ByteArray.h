#pragma once

#include <iostream>
#include <cstring>
#include <cstdarg>

typedef unsigned char Byte;

namespace eMumba_ad{
    namespace serialization{
        class ByteArray{

        uint64_t number_of_bytes;
        Byte* bytes;
        
        public:
        ByteArray()
        {
            number_of_bytes = 0;
            bytes = NULL;
        }
        
        ByteArray(uint64_t no, ... )
        {
            va_list args;
            va_start(args, no);
            number_of_bytes = no;
            bytes = new Byte[number_of_bytes]();
            for(int i = 0; i < number_of_bytes; i++)
            {
                bytes[i] = va_arg(args, int);
            }
        }
        
        Byte* operator [](uint64_t i)
        {
            if(i >= number_of_bytes)
                throw std::out_of_range("Index out of range");
            return &bytes[i];   
        }

        void set(uint64_t no, ... )
        {
            va_list args;
            va_start(args, no);
            if (bytes)
                delete[] bytes;
            number_of_bytes = no;
            bytes = new Byte[number_of_bytes]();

            for(int i = 0; i < number_of_bytes; i++)
            {
                bytes[i] = va_arg(args, int);
            }
        }

        auto serialize(Byte *buffer, const uint64_t &offset = 0)
        {
            Byte *ptr = buffer+offset;
            memcpy(ptr, &number_of_bytes, sizeof(uint64_t));
            for(int i = 0; i < number_of_bytes; i++)
            {
                buffer[(sizeof(uint64_t) + i + offset)] = bytes[i] ;
            }
            return number_of_bytes+sizeof(uint64_t);
        }

        void deserialize(Byte *buffer, const uint64_t &position=0)
        {
            Byte *ptr = buffer+position;
            memcpy(&number_of_bytes, ptr, sizeof(uint64_t));
            
            if(bytes)
                delete[] bytes;
            bytes = new Byte [number_of_bytes]();
            for(int i = 0; i < number_of_bytes; i++)
            {
                bytes[i] = buffer[i + sizeof(uint64_t) + position];
            }
        }
        
        void print()
        {
            std::cout  << (number_of_bytes) ;
            
            for(int i = 0; i < number_of_bytes; i++)
            {
                std::cout  << int(bytes[i]) << " ";
            }
            
        }

        void operator =(const ByteArray &obj2)
        {
            number_of_bytes = obj2.number_of_bytes;
            if(bytes)
                delete[] bytes;
            bytes = new Byte[number_of_bytes]();
            for(int i = 0; i < number_of_bytes; i++)
            {
                bytes[i] = obj2.bytes[i];
            }
        }

        bool operator ==(ByteArray &obj2)
        {
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
            if (bytes)
                delete[] bytes;
        }
    };
}
}
