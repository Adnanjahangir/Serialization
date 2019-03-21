# Serialization Library

This library helps you serialize and deserialize data in a specific format described in the document and store in some buffer. 

To install the dependencies of these libraries, a Docker file is provided which makes an image of Ubuntu installing all the required components and a container can be created in which you can work on.

The library has various classes depending on the the type of data format. 

Main header file to include in this library is TxWireData.h which includes all the other header files and all other classes 
can be used

All classes have basic functionalities such as:
1. Setting of class parameters
2. Printing of data
3. Serializtion of data in given buffer
4. Deserializtion of data from the given buffer
5. getLength() functions to get the number of bytes needed for data to be stored


All classes have the same way to serialize and deserialize data. Explanation of one refers to all the classes available.


Usage of Serialization function is through the object e.g. If there is an object created of type "TxWireData" named Object1
and it contains data which needs to be sent, you can serialize it by calling the Object1.serialize() function and giving one 
argument which will be a pointer to the buffer which will store the data. Pointer to Buffer should be of Byte type e.g.



Byte *Buffer; //makes a pointer to a buffer of Bytetype
Buffer = new Byte[<lengthofObject>]; //Ths will allocate memory required in terms of number of bytes to store the data
Object1.serialize(Buffer); //This statement will serialize all the data of Object1 in buffer and will return number of bytes                              // used


You can pass the serialize() function an index as a second parameter too if you want to serialize data in a buffer from a specific index. In this case you have to make sure that the buffer has enough space to store data after the specific index e.g. If the index you provided is 10 and the length of data is 20 bytes, the buffer should be atleast 30 bytes so that data can be stored.
This feature can be used when you want to serialize multiple objects into a single buffer


Usage of Deserialization function is also through the object in which you want to deserialize the data. e.g. If there is an object created of type "TxWireData" named Object2 and a buffer in which you have the data to be deserialized, you can deserialize it by calling the Object1.deserialize() function and giving one argument which will be a pointer to the buffer which will contains the data. Pointer to Buffer should be of Byte type e.g. if buffer2 contains the data to be deserialized you can use it as



Object2.deserialize(buffer2); // this will deserialize the data and store it in Object2


Like the serialize function, you can also give the deserializtion funtion a position as a second argument too. This will start deserializing the data from the position you give to it. But in this case you have to be sure that the data after the position you give must be of the type you want to deserialize otherwise it will not work.




