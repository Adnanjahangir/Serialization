#include"gtest/gtest.h"
#include"TxWireData.h"


TEST(bytearray, serializefunc)
{
    ByteArray temp(3);
    Byte *buffer;

    buffer = new Byte[(sizeof(uint64_t) + 3)]();
    
    uint64_t x = 3;
    *buffer = x;
    buffer[8] = char(0x47);
    buffer[9] = char(0x48);
    buffer[10] = char(0x49);
    Byte *buffer2;
    buffer2 = new Byte[temp.getLength()]();
    temp.serialize(buffer2);
    for(int i = 0; i < 11; i++)
    {
        ASSERT_EQ(buffer[i], buffer2[i]) << "ERROR IN Serialize funtion of ByteArray";
    }

    delete[] buffer;
    delete[] buffer2;
}

TEST(bytearray, deserializefunc)
{
    ByteArray temp(3);
    Byte *buffer;
    buffer = new Byte[(sizeof(uint64_t) + 3)]();
    uint64_t x = 3;
    *buffer = x;
    buffer[8] = char(0x47);
    buffer[9] = char(0x48);
    buffer[10] = char(0x49);
    std::cout << std::endl;
    ByteArray temp2;
    temp2.deserialize(buffer);
    ASSERT_TRUE((temp == temp2)) << "ERROR IN deSerialize funtion of ByteArray";
    delete buffer;
}

TEST(listTest, serializefuncgeneral)
{
    List<int> temp(3);
    Byte *buffer;

    buffer = new Byte[temp.getLength()]();
    uint64_t x = 3;
    *buffer = x;
    buffer[8] = int(100);
    buffer[12] = int(101);
    buffer[16] = int(102);
    Byte *buffer2;
    buffer2 = new Byte[temp.getLength()]();
    temp.serialize(buffer2);
    for(int i = 0; i < 20; i++)
    {
        ASSERT_EQ(buffer[i], buffer2[i]) << "ERROR IN Serialize funtion of GeneralListArray";
    }

    delete[] buffer;
    delete[] buffer2;
}

TEST(listTest, deserializefuncgeneral)
{
    List<int> temp(3);
    Byte *buffer;
    buffer = new Byte[temp.getLength()]();
    uint64_t x = 3;
    *buffer = x;
    buffer[8] = int(100);
    buffer[12] = int(101);
    buffer[16] = int(102);
    List<int> temp2;
    temp2.deserialize(buffer);
    ASSERT_TRUE((temp==temp2)) << "ERROR IN deSerialize funtion of GeneralListArray";
    delete buffer;
}

TEST(listTest, ByteArray)
{
    Byte *buffer;
    buffer = new Byte[28]();
    buffer[0] = int(2);
    buffer[8] = int(2);
    buffer[16] = 'a';
    buffer[17] = 'b';
    buffer[18] = int(2);
    buffer[26] = 'c';
    buffer[27] = 'd';
    List<ByteArray> l1;
    l1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[28]();
    l1.serialize(buffer2);
    
    for(int i = 0; i<28; i++)
        ASSERT_EQ(buffer[i], buffer2[i]) << "ERROR IN LIBRARY: List<ByteArray> ";

    delete[] buffer;
    delete[] buffer2;
}

TEST(listTest, Signatory)
{
    Byte *buffer;
    buffer = new Byte[88]();
    buffer[0] = int(2);
    buffer[8] = int(2);
    buffer[16] = 'a';
    buffer[17] = 'b';
    buffer[18] = int(2);
    buffer[26] = 'a';
    buffer[27] = 'b';
    buffer[28] = int(2);
    buffer[36] = 'a';
    buffer[37] = 'b';
    buffer[38] = int(2);
    buffer[46] = 'a';
    buffer[47] = 'b';
    buffer[48] = int(2);
    buffer[56] = 'a';
    buffer[57] = 'b';
    buffer[58] = int(2);
    buffer[66] = 'a';
    buffer[67] = 'b';
    buffer[68] = int(2);
    buffer[76] = 'a';
    buffer[77] = 'b';
    buffer[78] = int(2);
    buffer[86] = 'a';
    buffer[87] = 'b';
    List<Signatory> l1;
    l1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[88]();
    l1.serialize(buffer2);

    for(int i = 0; i<88; i++)
        ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: List<Signatory> ";

    delete[] buffer;
    delete[] buffer2;
}

TEST(signatureTest, both)
{
    Signature s1;
    Byte *buffer;
    buffer = new Byte[25]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(2);
    buffer[18] = 'c';
    buffer[19] = 'd';
    
    

    s1.deserialize(buffer);
    std::cout << std::endl;
    Byte *buffer2;
    
    buffer2 = new Byte[25]();
    
    s1.serialize(buffer2);
    
    for(int i = 0; i<20; i++)
       ASSERT_EQ(buffer[i], buffer2[i]) << "ERROR IN LIBRARY: Signature.h \n";
       
    delete[] buffer2; 
    delete[] buffer;

}

TEST(identityTest, both)
{
    Identity s1;
    Byte *buffer;
    buffer = new Byte[25]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(2);
    buffer[18] = 'c';
    buffer[19] = 'd';
    
    

    s1.deserialize(buffer);
    std::cout << std::endl;
    Byte *buffer2;
    
    buffer2 = new Byte[25]();
    
    s1.serialize(buffer2);
    
    for(int i = 0; i<20; i++)
       ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: Identity.h \n";
       
    delete[] buffer2; 
    delete[] buffer;
    
}

TEST(primaryTxTest, both)
{
    PrimaryTx d1;

    Byte *buffer;
    buffer = new Byte[46]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(3);
    buffer[18] = int(2);
    buffer[26] = int(2);
    buffer[34] = 'c';
    buffer[35] = 'd';
    buffer[36] = int(2);
    buffer[44] = 'e';
    buffer[45] = 'f';
    
    d1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[d1.getLength()]();
    d1.serialize(buffer2);
    for(int i = 0; i<46; i++)
       ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: primaryTx.h \n";
       
    delete[] buffer2; 
    delete[] buffer;

}

TEST(signingTxTest, both)
{
    SigningTx st1;
    Byte *buffer;
    buffer = new Byte[66]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(3);
    buffer[18] = int(2);
    buffer[26] = int(2);
    buffer[34] = 'c';
    buffer[35] = 'd';
    buffer[36] = int(2);
    buffer[44] = 'e';
    buffer[45] = 'f';

    buffer[46] = int(2);
    buffer[54] = 'a';
    buffer[55] = 'b';
    buffer[56] = int(2);
    buffer[64] = 'c';
    buffer[65] = 'd';
    st1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[st1.getLength()]();
    st1.serialize(buffer2);
    for(int i = 0; i<66; i++)
       ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: SigningTx.h \n";
       
    delete[] buffer2; 
    delete[] buffer;

}

TEST(signatoryTest, both)
{
    Signatory s1;
    Byte *buffer;
    buffer = new Byte[40]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(2);
    buffer[18] = 'a';
    buffer[19] = 'b';
    buffer[20] = int(2);
    buffer[28] = 'a';
    buffer[29] = 'b';
    buffer[30] = int(2);
    buffer[38] = 'a';
    buffer[39] = 'b';

    s1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[40]();
    s1.serialize(buffer2);
    
    for(int i = 0; i<40; i++)
        ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: Signatory.h \n";
   
    delete[] buffer;
    delete[] buffer2;
}

TEST(txWiredataTest, both)
{   
    Byte *buffer;
    buffer = new Byte[134]();
    buffer[0] = int(2);
    buffer[8] = 'a';
    buffer[9] = 'b';
    buffer[10] = int(3);
    buffer[18] = int(2);
    buffer[26] = int(2);
    buffer[34] = 'c';
    buffer[35] = 'd';
    buffer[36] = int(2);
    buffer[44] = 'e';
    buffer[45] = 'f';  
    buffer[46] = int(2);
    buffer[54] = int(2);
    buffer[62] = 'a';
    buffer[63] = 'b';
    buffer[64] = int(2);
    buffer[72] = 'a';
    buffer[73] = 'b';
    buffer[74] = int(2);
    buffer[82] = 'a';
    buffer[83] = 'b';
    buffer[84] = int(2);
    buffer[92] = 'a';
    buffer[93] = 'b';
    buffer[94] = int(2);
    buffer[102] = 'a';
    buffer[103] = 'b';
    buffer[104] = int(2);
    buffer[112] = 'a';
    buffer[113] = 'b';
    buffer[114] = int(2);
    buffer[122] = 'a';
    buffer[123] = 'b';
    buffer[124] = int(2);
    buffer[132] = 'a';
    buffer[133] = 'b';

    TxWireData dat1;
    dat1.deserialize(buffer);
    Byte *buffer2;
    buffer2 = new Byte[134]();
    dat1.serialize(buffer2);
    for(int i = 0; i<66; i++)
       ASSERT_EQ(buffer[i], buffer2[i])<< "ERROR IN LIBRARY: TxWireData.h \n";
       
    delete[] buffer2; 
    delete[] buffer;

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
