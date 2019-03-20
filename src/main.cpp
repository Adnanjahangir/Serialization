#include<iostream>
#include"TxWireData.h"

int main()
{

    std::cout << "Helloworld";
    
}


//CODE MAIN FOR BYTEARRAY
/*
    ByteArray b1(15);
    uint64_t size = b1.getLength();
    Byte *buffer;
    buffer = new Byte [size];
    
    auto len = b1.serialize(buffer);

    for(int i = 0; i < len; i++)
    {
        if(i < sizeof(uint64_t))
            std::cout << int(buffer[i]) << " ";
        else
            std::cout << buffer[i] << " ";
    }
    std::cout << std::endl << std::endl;
    ByteArray b2;
    b2.deserialize(buffer);
    b2.printByteArray();
*/

//CODE MAIN FOR GENERAL LIST ARRAY
/*
    List<double> l1(10);
    auto size = l1.getLength();
    Byte *buffer;
    buffer = new Byte [size];
    l1.printListArray();
    auto len = l1.serialize(buffer);
    for(int i = 0; i < len; i++)
    {
        if(i < sizeof(uint64_t))
            std::cout << int(buffer[i]) << " ";
        else
            std::cout << int(buffer[i]) << " ";
    }
    std::cout << len << std::endl;
    List<double> l2;
    l2.deserialize(buffer);
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
    uint64_t len = l1.serialize(buff);
   
    List<ByteArray> l2;
    l2.deserialize(buff);
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
    l1.serialize(buff);
    std::cout << "AFTER DESERIALIZATION\n\n\n";
    List<Signatory> l2;
    l2.deserialize(buff);
    l2.printListArray();
*/

//CODE MAIN FOR IDENTITY TYPE
/*
    Identity I1;
    I1.SetIdentity();
    I1.PrintIdentity();

    Byte *buff;
    buff = new Byte[I1.getLength()];

    I1.serialize(buff);

    Identity I2;
    I2.deserialize(buff);
    I2.PrintIdentity();

*/

//CODE MAIN FOR SIGNATURE TYPE
/*
    Signature I1;
    I1.SetSignature();
    I1.PrintSignature();

    Byte *buff;
    buff = new Byte[I1.getLength()];

    I1.serialize(buff);

    Signature I2;
    I2.deserialize(buff);
    I2.PrintSignature();

*/

//CODE MAIN FOR PRIMARYTx TYPE data
/*
    PrimaryTx data;
    data.setPrimaryTx();
    //data.Print();

    Byte *buff;
    buff = new Byte[data.getLength()];
    std::cout << "LENGTH: " << data.getLength() <<std::endl;
    for(int i=0; i<data.getLength(); i++)
    {
        std::cout << int(buff[i]);
    }
    std::cout << std::endl;
    data.serialize(buff);
    
    std::cout << "LENGTH: " << data.getLength() <<std::endl;

    PrimaryTx data2;


    data2.deserialize(buff);
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
    std::cout << "--------------------LENGTH IS----------------------    " << T1.getLength() <<std::endl; 
    T1.serialize(buffer);
    std::cout << "-----------------------AFTER SERIALIZTION------------------------\n\n";
    SigningTx T2;
    T2.deserialize(buffer);
    T2.printSigningTx();  
*/

//CODE MAIN FOR SIGNATORY TYPE data
/*
    Signatory T1;
    T1.setSignatory();
    T1.printSignatory();
    Byte *buffer;
    buffer = new Byte[T1.getLength()];
    std::cout << "--------------------LENGTH IS----------------------    " << T1.getLength() <<std::endl; 
    T1.serialize(buffer);
    std::cout << "-----------------------AFTER SERIALIZTION------------------------\n\n";
    Signatory T2;
    T2.deserialize(buffer);
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
    l1.serialize(buff);
    std::cout << "AFTER DESERIALIZATION\n\n\n";
    TxWireData l2;
    l2.deserialize(buff);
    l2.printTxWireData();

    return 0;

*/