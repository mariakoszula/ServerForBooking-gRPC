FROM ubuntu:22.04

ARG build_type=Release

RUN apt-get update && apt-get -y install clang cmake gdb git \
    autoconf git pkg-config  automake libtool curl unzip && apt-get clean

ENV GRPC_RELEASE_TAG v1.47.5
RUN git clone -b ${GRPC_RELEASE_TAG} https://github.com/grpc/grpc /var/local/git/grpc && \
		cd /var/local/git/grpc && \
    git submodule update --init && \
    echo "--- installing protobuf ---" && \
    cd third_party/protobuf && \
    ./autogen.sh && ./configure --enable-shared && \
    make -j$(nproc) && make -j$(nproc) check && make install && make clean && ldconfig && \
    echo "--- installing grpc ---" && \
    cd /var/local/git/grpc && \
    make -j$(nproc) && make install && make clean && ldconfig

ENV PROJECT_PATH=/home/project
ENV BUILD_PATH=${PROJECT_PATH}/build

RUN mkdir ${PROJECT_PATH}
RUN mkdir ${BUILD_PATH}

WORKDIR ${PROJECT_PATH}
COPY src/ ./src/
COPY test/ ./test/
COPY CMakeLists.txt ./

WORKDIR ${BUILD_PATH}
RUN cmake .. -DCMAKE_BUILD_TYPE=${build_type} && \
    cmake --build .
