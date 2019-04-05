#pragma once

#include"Signatory.h"

namespace eMumba_ad{
    namespace serialization{
        template<class T>
        class List{
            uint64_t number_of_list_items;
            T* listItems;
            uint64_t sizeforserializtion;
            uint64_t currentindex;

            public:
            List()
            {
                number_of_list_items = 0;
                sizeforserializtion = 0;
                currentindex = 0;
                listItems = NULL;    
            }

            List(uint64_t no):number_of_list_items(no){
                listItems = new T[number_of_list_items];
                sizeforserializtion = sizeof(number_of_list_items);
            }
            
            T* operator [](uint64_t i)
            {
                if(i >= number_of_list_items)
                    throw std::out_of_range("Index out of range");
                return &listItems[i];   
            }

            void setLength(const uint64_t &len)
            {
                number_of_list_items = len;
                listItems = new T[number_of_list_items];
                sizeforserializtion = sizeof(number_of_list_items);
            }

            void operator =(const List<T> &obj1){
                if(listItems)
                    delete[] listItems;
                number_of_list_items = obj1.number_of_list_items;
                sizeforserializtion = sizeof(number_of_list_items);
                listItems = new T[number_of_list_items]();
                for(int i = 0; i<number_of_list_items; i++)
                {
                    listItems[i] = obj1.listItems[i];
                    sizeforserializtion += listItems[i].getLength();
                }
            }

            void add(const T &b1)
            {
                if(currentindex >= number_of_list_items)
                    throw std::out_of_range("List is Full");
                else
                {
                    listItems[currentindex] = b1;
                    sizeforserializtion += listItems[currentindex].getLength();
                    currentindex += 1;
                }
            }

            auto serialize(Byte *buffer, const uint64_t &offset = 0)
            {

                Byte *ptr = buffer+offset;
                memcpy(ptr, &number_of_list_items, sizeof(number_of_list_items));
                uint64_t index = offset + sizeof(uint64_t);
                for(int i = 0; i<number_of_list_items; i++)
                {
                    listItems[i].serialize(buffer, index);
                    index = index + listItems[i].getLength();            

                }
                return sizeforserializtion;
            
            }

            void deserialize(Byte *buffer, const uint64_t &position = 0)
            {
                uint64_t index = position;
                Byte *ptr1 = buffer+index;
                if(listItems)
                    delete[] listItems;
                memcpy(&number_of_list_items, ptr1, sizeof(number_of_list_items));
                index = index + sizeof(uint64_t);
                listItems = new T[number_of_list_items];
                
                for(int i = 0; i< number_of_list_items; i++)
                {
                    listItems[i].deserialize(buffer, index);
                    index = index + listItems[i].getLength();
                }
                
                sizeforserializtion = index-position;     
                
            }

            void print()
            {
                std::cout << number_of_list_items;
                for(int i = 0; i < number_of_list_items; i++)
                {
                    listItems[i].print();
                }
            }

            uint64_t getLength()
            {
                return sizeforserializtion;
            }

            ~List()
            {
                if (listItems)
                    delete[] listItems;
            }
        };
    }
}