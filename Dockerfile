FROM ubuntu

RUN apt update
RUN apt install -y g++
RUN apt install -y cmake
RUN apt install -y libboost-all-dev