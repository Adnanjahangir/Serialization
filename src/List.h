#ifndef LIST
#define LIST



#include"Signatory.h"
#include<cstring>

template<class T>
class List{
    uint64_t number_of_list_items;
    T* ListItems;

    public:
    List()
    {
        number_of_list_items = 0;
        ListItems = new T;
    }
    List(uint64_t no):number_of_list_items(no)
    {
        ListItems = new T[number_of_list_items];
        auto x = 100;
        for(int i = 0; i<number_of_list_items; i++)
        {
            ListItems[i] = T(x);
            x+=1;
        }
    }

    void setListItems()
    {
        cout << "Enter length of List: ";
        cin >> number_of_list_items;
        if(cin.fail())
        {
            throw MyException();
        }
        delete ListItems;
        ListItems = new T [number_of_list_items]; 
        for(int i = 0; i< number_of_list_items; i++)
        {
            cin >> ListItems[i];
            if(cin.fail())
            {
                throw MyException();
            }
        }
    }

    auto Serialize(Byte *buffer, uint64_t index=0)
    {
        memcpy(buffer, &number_of_list_items, sizeof(uint64_t));
        
        Byte* ptr;     
        buffer[sizeof(uint64_t)] = ListItems[0];

        for(int i = 0,j=0; j<number_of_list_items; i=i+sizeof(T), j++)
        {
            // cout << "Location: " << (sizeof(uint64_t) + i) <<endl;
            // cout << "Value: " << ListItems[j] <<endl;
            buffer[(sizeof(uint64_t) + i)] = ListItems[j] ;
        }
        return (number_of_list_items*sizeof(T))+sizeof(uint64_t);
    }

    void Deserialize(Byte *buffer)
    {
        number_of_list_items = *buffer;
        delete ListItems;
        ListItems = new T [number_of_list_items];
        //T *ptr = buffer;
        for(int i = 0,j = 0; j < number_of_list_items; i+=sizeof(T), j++)
        {
            ListItems[j] = buffer[i + sizeof(uint64_t)];
        }
    }
    

    void printListArray()
    {
        cout << "Length is: " << number_of_list_items << endl;
        for(int i = 0; i < number_of_list_items; i++)
        {
            cout << ListItems[i] << " ";
        }
    }

    uint64_t getLength()
    {
        return ((sizeof(uint64_t)+ ((number_of_list_items)*sizeof(T))));
    }
    ~List()
    {
        cout << "List deleted" << endl;
        delete[] ListItems;
    }
    
};

template<>
class List<ByteArray>{
    uint64_t number_of_list_items;
    ByteArray* ListItems;
    uint64_t sizeforserializtion;

    public:
    List()
    {
        number_of_list_items = 0;
        sizeforserializtion = 0;
        ListItems = new ByteArray[number_of_list_items];
    }
    
    void setListItems()
    {
        cout << "Enter number of list items: " << endl;
        cin >> number_of_list_items;
        if(cin.fail())
        {
            throw MyException();
        }
        ListItems = new ByteArray[number_of_list_items];
        sizeforserializtion = sizeof(uint64_t);        
        for(int i =0; i < number_of_list_items; i++)
        {
            try{
                ListItems[i].setByteArray();
            }
            catch(const std::exception& e){
                throw MyException();
            }
            sizeforserializtion += ListItems[i].getLength();
        }
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_list_items;
        uint64_t index = offset + sizeof(uint64_t);
        uint64_t temp = 0;
        for(int i = 0; i<number_of_list_items; i++)
        {
            //cout << "Index: " << index << " i: " << i << endl;
            temp = ListItems[i].Serialize(buffer, index);
            index = index + temp;            

        }
        return sizeforserializtion;
        
    }

    void Deserialize(Byte *buffer,int position = 0)
    {
        uint64_t index = position;
        delete ListItems;
        number_of_list_items = buffer[index];
        index = index + sizeof(uint64_t);
        ListItems = new ByteArray[number_of_list_items];
        for(int i = 0; i< number_of_list_items; i++)
        {
            ListItems[i].Deserialize(buffer, index);
            index = index + ListItems[i].getLength();
        }
        sizeforserializtion = index-position;        
    }

    void printListArray()
    {
        for(int i = 0; i < number_of_list_items; i++)
        {
            cout << "ByteArray[" << i << "]" <<endl;
            ListItems[i].printByteArray();
        }
        cout << endl;
    }

    uint64_t getLength()
    {
        return sizeforserializtion;
    }

    ~List()
    {
        delete[] ListItems;
    }
};

template<>
class List<Signatory>{
    uint64_t number_of_list_items;
    Signatory* ListItems;
    uint64_t sizeforserializtion;

    public:
    List()
    {
        number_of_list_items = 0;
        sizeforserializtion = 0;
        ListItems = new Signatory;
    }
    
    void setListItems()
    {
        cout << "Enter number of list items: " << endl;
        cin >> number_of_list_items;
        ListItems = new Signatory[number_of_list_items];
        sizeforserializtion = sizeof(uint64_t);        
        for(int i =0; i < number_of_list_items; i++)
        {
            try{
            ListItems[i].setSignatory();
            }
            catch(const std::exception& e){
                throw MyException();
            }
            sizeforserializtion += ListItems[i].getLength();
        }
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_list_items;
        uint64_t index = offset + sizeof(uint64_t);
        uint64_t temp = 0;
        for(int i = 0; i<number_of_list_items; i++)
        {
            //cout << "Index: " << index << " i: " << i << endl;
            temp = ListItems[i].Serialize(buffer, index);
            index = index + temp;            

        }
        return sizeforserializtion;
        
    }

    void Deserialize(Byte *buffer,int position = 0)
    {
        uint64_t index = position;
        delete ListItems;
        number_of_list_items = buffer[index];
        index = index + sizeof(uint64_t);
        ListItems = new Signatory[number_of_list_items];
        for(int i = 0; i< number_of_list_items; i++)
        {
            ListItems[i].Deserialize(buffer, index);
            index = index + ListItems[i].getLength();
        }
        sizeforserializtion = index-position;        
    }

    void printListArray()
    {
        for(int i = 0; i < number_of_list_items; i++)
        {
            cout << "SignatoryArray[" << i << "]" <<endl;
            ListItems[i].printSignatory();
        }
        cout << endl;
    }

    uint64_t getLength()
    {
        return sizeforserializtion;
    }

    ~List()
    {
        delete[] ListItems;
    }

};

#endif