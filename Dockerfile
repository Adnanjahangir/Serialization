FROM ubuntu

RUN apt-get update && apt-get install build-essential -y
RUN apt-get install cmake -y
RUN apt-get install cmake gcc g++
ADD . /Files 

WORKDIR /Files/build
