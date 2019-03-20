#ifndef LIST
#define LIST



#include"Signatory.h"
#include<cstring>

template<class T>
class List{
    uint64_t number_of_list_items;
    T* listItems;

    public:
    List()
    {
        number_of_list_items = 0;
        listItems = new T;
    }
    List(uint64_t no):number_of_list_items(no)
    {
        listItems = new T[number_of_list_items];
        auto x = 100;
        for(int i = 0; i<number_of_list_items; i++)
        {
            listItems[i] = T(x);
            x+=1;
        }
    }

    void setListItems()
    {
        std::cout << "Enter length of List: ";
        std::cin >> number_of_list_items;
        if(std::cin.fail())
        {
            throw MyException();
        }
        delete listItems;
        listItems = new T [number_of_list_items]; 
        for(int i = 0; i< number_of_list_items; i++)
        {
            std::cin >> listItems[i];
            if(std::cin.fail())
            {
                throw MyException();
            }
        }
    }

    auto serialize(Byte *buffer, uint64_t index=0)
    {
        memcpy(buffer, &number_of_list_items, sizeof(uint64_t));
        
        Byte* ptr;     
        buffer[sizeof(uint64_t)] = listItems[0];

        for(int i = 0,j=0; j<number_of_list_items; i=i+sizeof(T), j++)
        {
            // std::cout << "Location: " << (sizeof(uint64_t) + i) <<std::endl;
            // std::cout << "Value: " << listItems[j] <<std::endl;
            buffer[(sizeof(uint64_t) + i)] = listItems[j] ;
        }
        return (number_of_list_items*sizeof(T))+sizeof(uint64_t);
    }

    void deserialize(Byte *buffer)
    {
        number_of_list_items = *buffer;
        delete listItems;
        listItems = new T [number_of_list_items];
        //T *ptr = buffer;
        for(int i = 0,j = 0; j < number_of_list_items; i+=sizeof(T), j++)
        {
            listItems[j] = buffer[i + sizeof(uint64_t)];
        }
    }
    

    void printListArray()
    {
        std::cout << "Length is: " << number_of_list_items << std::endl;
        for(int i = 0; i < number_of_list_items; i++)
        {
            std::cout << listItems[i] << " ";
        }
    }

    uint64_t getLength()
    {
        return ((sizeof(uint64_t)+ ((number_of_list_items)*sizeof(T))));
    }
    ~List()
    {
        std::cout << "List deleted" << std::endl;
        delete[] listItems;
    }
    
};

template<>
class List<ByteArray>{
    uint64_t number_of_list_items;
    ByteArray* listItems;
    uint64_t sizeforserializtion;

    public:
    List()
    {
        number_of_list_items = 0;
        sizeforserializtion = 0;
        listItems = new ByteArray[number_of_list_items];
    }
    
    void setListItems()
    {
        std::cout << "Enter number of list items: " << std::endl;
        std::cin >> number_of_list_items;
        if(std::cin.fail())
        {
            throw MyException();
        }
        listItems = new ByteArray[number_of_list_items];
        sizeforserializtion = sizeof(uint64_t);        
        for(int i =0; i < number_of_list_items; i++)
        {
            try{
                listItems[i].setByteArray();
            }
            catch(const std::exception& e){
                throw MyException();
            }
            sizeforserializtion += listItems[i].getLength();
        }
    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_list_items;
        uint64_t index = offset + sizeof(uint64_t);
        uint64_t temp = 0;
        for(int i = 0; i<number_of_list_items; i++)
        {
            //std::cout << "Index: " << index << " i: " << i << std::endl;
            temp = listItems[i].serialize(buffer, index);
            index = index + temp;            

        }
        return sizeforserializtion;
        
    }

    void deserialize(Byte *buffer,int position = 0)
    {
        uint64_t index = position;
        delete listItems;
        number_of_list_items = buffer[index];
        index = index + sizeof(uint64_t);
        listItems = new ByteArray[number_of_list_items];
        for(int i = 0; i< number_of_list_items; i++)
        {
            listItems[i].deserialize(buffer, index);
            index = index + listItems[i].getLength();
        }
        sizeforserializtion = index-position;        
    }

    void printListArray()
    {
        for(int i = 0; i < number_of_list_items; i++)
        {
            std::cout << "ByteArray[" << i << "]" <<std::endl;
            listItems[i].printByteArray();
        }
        std::cout << std::endl;
    }

    uint64_t getLength()
    {
        return sizeforserializtion;
    }

    ~List()
    {
        delete[] listItems;
    }
};

template<>
class List<Signatory>{
    uint64_t number_of_list_items;
    Signatory* listItems;
    uint64_t sizeforserializtion;

    public:
    List()
    {
        number_of_list_items = 0;
        sizeforserializtion = 0;
        listItems = new Signatory;
    }
    
    void setListItems()
    {
        std::cout << "Enter number of list items: " << std::endl;
        std::cin >> number_of_list_items;
        listItems = new Signatory[number_of_list_items];
        sizeforserializtion = sizeof(uint64_t);        
        for(int i =0; i < number_of_list_items; i++)
        {
            try{
            listItems[i].setSignatory();
            }
            catch(const std::exception& e){
                throw MyException();
            }
            sizeforserializtion += listItems[i].getLength();
        }
    }

    auto serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_list_items;
        uint64_t index = offset + sizeof(uint64_t);
        uint64_t temp = 0;
        for(int i = 0; i<number_of_list_items; i++)
        {
            //std::cout << "Index: " << index << " i: " << i << std::endl;
            temp = listItems[i].serialize(buffer, index);
            index = index + temp;            

        }
        return sizeforserializtion;
        
    }

    void deserialize(Byte *buffer,int position = 0)
    {
        uint64_t index = position;
        delete listItems;
        number_of_list_items = buffer[index];
        index = index + sizeof(uint64_t);
        listItems = new Signatory[number_of_list_items];
        for(int i = 0; i< number_of_list_items; i++)
        {
            listItems[i].deserialize(buffer, index);
            index = index + listItems[i].getLength();
        }
        sizeforserializtion = index-position;        
    }

    void printListArray()
    {
        for(int i = 0; i < number_of_list_items; i++)
        {
            std::cout << "SignatoryArray[" << i << "]" <<std::endl;
            listItems[i].printSignatory();
        }
        std::cout << std::endl;
    }

    uint64_t getLength()
    {
        return sizeforserializtion;
    }

    ~List()
    {
        delete[] listItems;
    }

};

#endif