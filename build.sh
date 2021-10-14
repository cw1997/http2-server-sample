#!/usr/bin/env bash

sudo -v

#sudo apt update && sudo apt install -y g++ make binutils autoconf automake autotools-dev libtool pkg-config \
#  zlib1g-dev libcunit1-dev libssl-dev libxml2-dev libev-dev libevent-dev libjansson-dev \
#  libc-ares-dev libjemalloc-dev libsystemd-dev \
#  cython python3-dev python-setuptools

sudo rm -rf ./lib && mkdir lib

BOOST_VERSION=1_77_0
rm -rf ./lib/boost_${BOOST_VERSION} ./lib/boost_${BOOST_VERSION}.tar.bz2
cd lib && \
  wget https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_${BOOST_VERSION}.tar.bz2 && \
  tar xf boost_${BOOST_VERSION}.tar.bz2 && \
#  cd boost_${BOOST_VERSION} && \
#  ./bootstrap.sh && \
#  ./b2 && \
#  ./b2 install && \
#  cd ../

NGHTTP2_VERSION=1.45.1
rm -rf ./lib/nghttp2-${NGHTTP2_VERSION} ./lib/nghttp2-${NGHTTP2_VERSION}.tar.bz2
cd lib && \
  wget https://github.com/nghttp2/nghttp2/releases/download/v${NGHTTP2_VERSION}/nghttp2-${NGHTTP2_VERSION}.tar.bz2 && \
  tar xf nghttp2-${NGHTTP2_VERSION}.tar.bz2 && \
#  cd nghttp2-${NGHTTP2_VERSION} && \
#  ./configure --enable-asio-lib && \
#  make && \
  cd ../
