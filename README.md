# Serialization Library

This library helps you serialize and deserialize data in a specific format described in the document and store in some buffer. 
The library has various classes depending on the the type of data format. 

Main header file to include in this library is TxWireData.h which includes all the other header files and all other classes 
can be used

All classes have basic functionalities such as:
1. Setting of class parameters
2. Printing of data
3. Serializtion of data in given buffer
4. Deserializtion of data from the given buffer
5. getLength() functions to get the number of bytes needed for data to be stored

Usage of Serialization function is through the object e.g. If there is an object created of type "TxWireData" named Object1
and it contains data which needs to be sent, you can serialize it by calling the Object1.serialize() function and giving one 
argument which will be a pointer to the buffer which will store the data. 

(incomplete)
