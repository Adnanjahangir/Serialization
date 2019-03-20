#include<iostream>
#include"TxWireData.h"
using namespace std;

int main()
{

    PrimaryTx data;
    try
    {
        data.setPrimaryTx();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
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

    return EXIT_SUCCESS;
    
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

//CODE MAIN FOR SIGNATURE TYPE
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

//CODE MAIN FOR SIGNINGTx TYPE data
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

//CODE MAIN FOR TxWire DATA
/*
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

*/