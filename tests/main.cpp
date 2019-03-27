#include"gtest/gtest.h"
#include"ByteArray.h"
#include"List.h"


TEST(bytearray, serializefunc)
{
    ByteArray temp(3);
    Byte *buffer;
    buffer = new Byte[(sizeof(uint64_t) + 3)];
    uint64_t x = 3;
    for(int i = 0; i<(sizeof(uint64_t) + 3); i++)
        std::cout << int(buffer[i]);
    *buffer = x;
    buffer[8] = char(0x47);
    buffer[9] = char(0x48);
    buffer[10] = char(0x49);
    Byte *buffer2;
    buffer2 = new Byte[temp.getLength()];
    temp.serialize(buffer2);
    for(int i = 0; i < 11; i++)
    {
        EXPECT_EQ(buffer[i], buffer2[i]);
    }
    delete buffer;
    delete buffer2;
   
}

TEST(bytearray, deserializefunc)
{
    
    ByteArray temp(3);
    Byte *buffer;
    buffer = new Byte[(sizeof(uint64_t) + 3)];
    for(int i = 0; i<(sizeof(uint64_t) + 3); i++)
        std::cout << int(buffer[i]) << " ";
    uint64_t x = 3;
    *buffer = x;
    buffer[8] = char(0x47);
    buffer[9] = char(0x48);
    buffer[10] = char(0x49);
    std::cout << std::endl;
    for(int i = 0; i<(sizeof(uint64_t) + 3); i++)
        std::cout << int(buffer[i]) << " ";
    ByteArray temp2;
    temp2.deserialize(buffer);
    temp2.printByteArray();
    EXPECT_TRUE((temp == temp2));
}


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