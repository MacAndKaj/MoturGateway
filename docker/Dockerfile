FROM macandkaj/motur_base_img:243ab69a246a

ARG BOOST_MIN_VERSION=80
ARG CMAKE_VERSION=3.25.1
ARG NUM_JOBS=8

ENV BOOST_URL="https://boostorg.jfrog.io/artifactory/main/release/1.${BOOST_MIN_VERSION}.0/source/boost_1_${BOOST_MIN_VERSION}_0.tar.gz"
ENV DEV_PATH=/home/devel

WORKDIR ${DEV_PATH}

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        pkg-config \
        wget \
        tar \
        git \
        locales \
        locales-all \
        vim \
        gcc \
        cmake \
        ssh \
        bluez \
        bluez-hcidump \
        checkinstall \
        libusb-dev \
        libbluetooth-dev\
        libspdlog-dev \
        googletest \
    && apt-get clean

# System locale
# Important for UTF-8
ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

WORKDIR ${DEV_PATH}

RUN wget --no-check-certificate ${BOOST_URL} && \
    tar -xvf boost_1_${BOOST_MIN_VERSION}_0.tar.gz && \
    cd boost_1_${BOOST_MIN_VERSION}_0 && \
    ./bootstrap.sh && \
    ./b2 install &&\
    cd .. && \
    rm -rf boost_1_${BOOST_MIN_VERSION}_0 boost_1_${BOOST_MIN_VERSION}_0.tar.gz

RUN cd /usr/src/googletest && \
    mkdir build && cd build && \
    cmake .. && make && make install && \
    cd .. && rm -rf build && cd ${DEV_PATH}
