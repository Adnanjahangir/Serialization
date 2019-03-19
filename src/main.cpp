#include<iostream>
#include<cstring>
#include<typeinfo>
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
        Bytes = new Byte [number_of_bytes]; 
        for(int i = 0; i< number_of_bytes; i++)
        {
            cin >> Bytes[i];
        }

        // cout << "------------------------\n";
        // printByteArray();
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        buffer[offset] = number_of_bytes;
        
        for(int i = 0; i < number_of_bytes; i++)
        {
            //cout << "location: " << (sizeof(uint64_t) + i + offset) << "   value: " << Bytes[i] << endl;
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

class Identity{
    uint64_t length;
    ByteArray Identifier;
    ByteArray type;
    
    public:
    Identity()
    {
    }

    void SetIdentity()
    {
        cout << "Enter Identifier data: "; 
        Identifier.setByteArray();
        cout << "Enter type of Identifier: ";
        type.setByteArray();
        length = (Identifier.getLength()) + (type.getLength());
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        Identifier.Serialize(buffer, offset);
        type.Serialize(buffer, offset + Identifier.getLength());
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        Identifier.Deserialize(buffer, position);
        type.Deserialize(buffer, (position + Identifier.getLength()));
        length = (Identifier.getLength()) + (type.getLength());
    }
    
    void PrintIdentity()
    {
        Identifier.printByteArray();
        type.printByteArray();
    }
    uint64_t getLength()
    {
        return length;
    }
    ~Identity()
    {

    }

};

class Signature{
    uint64_t length;
    ByteArray Signature_data;
    ByteArray Signature_type;
    
    public:
    Signature(){
    }

    void SetSignature(){
        cout << "Enter Signature data: \n"; 
        Signature_data.setByteArray();
        cout << "Enter type of Signature: \n";
        Signature_type.setByteArray();
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
        identity_data.SetIdentity();
        signature_data.SetSignature();
        length = identity_data.getLength() + signature_data.getLength();
    }
    
    void printSignatory(){
        cout << "IDENTITY DATA: " <<endl;
        identity_data.PrintIdentity();
        cout << "SIGNATURE DATA: " <<endl;
        signature_data.PrintSignature();
    }

    auto getLength(){
        cout << identity_data.getLength() << endl;
        cout << signature_data.getLength() <<endl;
        return length;
    }
};

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
        delete ListItems;
        ListItems = new T [number_of_list_items]; 
        for(int i = 0; i< number_of_list_items; i++)
        {
            cin >> ListItems[i];

        }
    }

    auto Serialize(Byte *buffer)
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
        delete ListItems;
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
        ListItems = new ByteArray;
    }
    
    void setListItems()
    {
        cout << "Enter number of list items: " << endl;
        cin >> number_of_list_items;
        ListItems = new ByteArray[number_of_list_items];
        sizeforserializtion = sizeof(uint64_t);        
        for(int i =0; i < number_of_list_items; i++)
        {
            ListItems[i].setByteArray();
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
            ListItems[i].setSignatory();
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
    }

};

class PrimaryTx{
    ByteArray Contract_name;
    uint64_t Fee;
    List<ByteArray> Resources;
    uint64_t length;
    public:
    PrimaryTx(){
        Fee = 0;
        length = 0;
    }

    ~PrimaryTx(){

    }
    
    void setPrimaryTx(){
        cout << "Enter contract name: ";
        Contract_name.setByteArray();
        cout << "Enter length of Fee: ";
        cin >> Fee ;
        Resources.setListItems();
        length = Contract_name.getLength() + sizeof(Fee) + Resources.getLength();

    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = Contract_name.Serialize(buffer, offset);
        
        index = offset + temp;


        buffer[index] = Fee;
        index = index + sizeof(uint64_t);
        
        temp = Resources.Serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        Contract_name.Deserialize(buffer, position);
        index = index + Contract_name.getLength();
        Fee = buffer[index];
        index = index + sizeof(uint64_t);
        Resources.Deserialize(buffer, index);
        //index += Resources.getLength();
        length = Contract_name.getLength() + sizeof(uint64_t) + Resources.getLength();

    }


    void Print(){
        Contract_name.printByteArray();
        cout << "Fee: " << Fee <<endl;
        Resources.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};

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
        primary_data.setPrimaryTx();
        identity_data.SetIdentity();
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


        cout << endl << "Identity DATA: " << endl;
        identity_data.PrintIdentity();
    }

};

class TxWireData{
    PrimaryTx Tx_data;
    List<Signatory> list_data;
    uint64_t length;

    public:
    TxWireData(){
        length = 0;
    }
    
    void setTxWireData(){
        Tx_data.setPrimaryTx();
        list_data.setListItems();
        length = Tx_data.getLength() + list_data.getLength();
    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        uint64_t index = 0, temp = 0;
        temp = Tx_data.Serialize(buffer);
        
        index = offset + temp;
        temp = list_data.Serialize(buffer, index);
        index = index + temp;
        length = index;
        return length;
    }

    void Deserialize(Byte *buffer, int position=0)
    {
        uint64_t index = position;
        Tx_data.Deserialize(buffer);
        index = index + Tx_data.getLength();


        list_data.Deserialize(buffer, index);
        length = index + list_data.getLength();
    }
    
    void printTxWireData(){
        Tx_data.Print();
        list_data.printListArray();
    }
    
    uint64_t getLength(){
        return length;
    }

};


int main()
{
    TxWireData l1;
    l1.setTxWireData();
    l1.printTxWireData();
    
    Byte *buff;
    buff = new Byte[l1.getLength()];
    l1.Serialize(buff);
    cout << "AFTER DESERIALIZATION\n\n\n";
    TxWireData l2;
    l2.Deserialize(buff);
    l2.printTxWireData();

    return 0;
}


//CODE MAIN FOR BYTEARRAY
/*
    ByteArray b1(15);
    uint64_t size = b1.getLength();
    Byte *buffer;
    buffer = new Byte [size];
    
    auto len = b1.Serialize(buffer);

    for(int i = 0; i < len; i++)
    {
        if(i < sizeof(uint64_t))
            cout << int(buffer[i]) << " ";
        else
            cout << buffer[i] << " ";
    }
    cout << endl << endl;
    ByteArray b2;
    b2.Deserialize(buffer);
    b2.printByteArray();
*/

//CODE MAIN FOR GENERAL LIST ARRAY
/*
    List<double> l1(10);
    auto size = l1.getLength();
    Byte *buffer;
    buffer = new Byte [size];
    l1.printListArray();
    auto len = l1.Serialize(buffer);
    for(int i = 0; i < len; i++)
    {
        if(i < sizeof(uint64_t))
            cout << int(buffer[i]) << " ";
        else
            cout << int(buffer[i]) << " ";
    }
    cout << len << endl;
    List<double> l2;
    l2.Deserialize(buffer);
    l2.printListArray();

*/

//CODE MAIN FOR LIST ARRAY of type BYTEARRAY
/*
    List<ByteArray> l1;
    uint64_t size = 0;
    l1.setListItems();
    l1.printListArray();
    Byte * buff;
    buff = new Byte[l1.getLength()];
    uint64_t len = l1.Serialize(buff);
   
    List<ByteArray> l2;
    l2.Deserialize(buff);
    l2.printListArray();
    return 0;
*/

//CODE MAIN FOR LIST<Signatory>
/*
    List<Signatory> l1;
    l1.setListItems();
    l1.printListArray();
    
    Byte *buff;
    buff = new Byte[l1.getLength()];
    l1.Serialize(buff);
    cout << "AFTER DESERIALIZATION\n\n\n";
    List<Signatory> l2;
    l2.Deserialize(buff);
    l2.printListArray();
*/

//CODE MAIN FOR IDENTITY TYPE
/*
    Identity I1;
    I1.SetIdentity();
    I1.PrintIdentity();

    Byte *buff;
    buff = new Byte[I1.getLength()];

    I1.Serialize(buff);

    Identity I2;
    I2.Deserialize(buff);
    I2.PrintIdentity();

*/

//CODE MAIN FOR IDENTITY TYPE
/*
    Signature I1;
    I1.SetSignature();
    I1.PrintSignature();

    Byte *buff;
    buff = new Byte[I1.getLength()];

    I1.Serialize(buff);

    Signature I2;
    I2.Deserialize(buff);
    I2.PrintSignature();

*/

//CODE MAIN FOR PRIMARYTx TYPE data
/*
    PrimaryTx data;
    data.setPrimaryTx();
    //data.Print();

    Byte *buff;
    buff = new Byte[data.getLength()];
    cout << "LENGTH: " << data.getLength() <<endl;
    for(int i=0; i<data.getLength(); i++)
    {
        cout << int(buff[i]);
    }
    cout << endl;
    data.Serialize(buff);
    
    cout << "LENGTH: " << data.getLength() <<endl;

    PrimaryTx data2;


    data2.Deserialize(buff);
    data2.Print(); 

    return 0;
*/

//CODE MAIN FOR PRIMARYTx TYPE data
/*
    SigningTx T1;
    T1.setSigningTx();
    T1.printSigningTx();
    Byte *buffer;
    buffer = new Byte[T1.getLength()];
    cout << "--------------------LENGTH IS----------------------    " << T1.getLength() <<endl; 
    T1.Serialize(buffer);
    cout << "-----------------------AFTER SERIALIZTION------------------------\n\n";
    SigningTx T2;
    T2.Deserialize(buffer);
    T2.printSigningTx();  
*/

//CODE MAIN FOR SIGNATORY TYPE data
/*
    Signatory T1;
    T1.setSignatory();
    T1.printSignatory();
    Byte *buffer;
    buffer = new Byte[T1.getLength()];
    cout << "--------------------LENGTH IS----------------------    " << T1.getLength() <<endl; 
    T1.Serialize(buffer);
    cout << "-----------------------AFTER SERIALIZTION------------------------\n\n";
    Signatory T2;
    T2.Deserialize(buffer);
    T2.printSignatory();  

    return 0;
*/

