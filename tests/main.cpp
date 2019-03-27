#include"gtest/gtest.h"
#include"ByteArray.h"
#include"List.h"


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
        EXPECT_EQ(buffer[i], buffer2[i]);
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
    EXPECT_TRUE((temp == temp2));
    delete buffer;
}

TEST(DISABLED_listTest, serializefuncgeneral)
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
        EXPECT_EQ(buffer[i], buffer2[i]);
    }

    delete[] buffer;
    delete[] buffer2;
}

TEST(DISABLED_listTest, deserializefuncgeneral)
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
    EXPECT_TRUE((temp==temp2));
    delete buffer;
}

TEST(DISABLED_listTest, ByteArray)
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
        EXPECT_EQ(buffer[i], buffer2[i]);

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
       EXPECT_EQ(buffer[i], buffer2[i]);
       
    delete[] buffer2; 
    delete[] buffer;

}

/*
TEST(listTest, SignatoryArray)
{
    Byte *buffer;
    buffer = new Byte[88]();
    buffer[0] = int(2);
    buffer[8] = int(2);
    buffer[16] = 'a';
    buffer[17] = 'b';
    buffer[18] = int(2);
    buffer[26] = 'c';
    buffer[27] = 'd';
    buffer[28] = int(2);
    buffer[36] = 'e';
    buffer[37] = 'f';
    buffer[38] = int(2);
    buffer[46] = 'g';
    buffer[47] = 'h';
    buffer[48] = int(2);
    buffer[56] = 'a';
    buffer[57] = 'b';
    buffer[58] = int(2);
    buffer[66] = 'c';
    buffer[67] = 'd';
    buffer[78] = int(2);
    buffer[76] = 'e';
    buffer[77] = 'f';
    buffer[88] = int(2);
    buffer[86] = 'g';
    buffer[87] = 'h';
    /*
    for(int i=0; i<88; i++)
        std::cout << int(buffer[i]) << " ";

    List<Signatory> l1;
    */
    //l1.deserialize(buffer);
    /*
    Byte *buffer2;
    buffer2 = new Byte[88]();
    l1.serialize(buffer2);
    l1.printListArray();
    
    for(int i = 0; i<88; i++)
        EXPECT_EQ(buffer[i], buffer2[i]);
    
    delete[] buffer;
}
*/

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
/*
TEST(list, serializefunc)
{
    Byte *buff;
    buff = new Byte[32];
    uint64_t x = 3;
    //*buff = x;
    for(int i = 0; i<32; i++)
    {
        buff[i] = Byte(0x00) ;
    }
    *buff = x;
    buff[8] = double(100);
    buff[16] = double(101);
    buff[24] = double(103);
    for(int i = 0; i<32; i++)
    {
        std::cout << int(buff[i]) ;
    }
    std::cout <<std::endl;
    List<double> temp(3);
    Byte *buffer2;
    buffer2 = new Byte[temp.getLength()];
    for(int i = 0; i<32; i++)
    {
        buffer2[i] = Byte(0x00) ;
    }
    temp.serialize(buffer2);
    for(int i = 0; i<32; i++)
    {
        std::cout << int(buffer2[i]) ;
    }
    for(int i = 0; i < 11; i++)
    {
        EXPECT_EQ(buff[i], buffer2[i]);
    }
}
*/