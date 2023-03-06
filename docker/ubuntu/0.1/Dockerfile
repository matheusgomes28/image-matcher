#
# We base our image from the alpine light image
FROM ubuntu:lunar-20230301

#
# Environment variables needed for the
# build system
ENV CONAN_USER_HOME "/conan"
ENV TZ=Europe/London

#
# Identify the maintainer of an image
LABEL maintainer="matheusgarcia28@gmail.com"

# install build dependencies 
RUN apt-get update \
    && apt-get install -y \
    g++ \
    make \
    pkg-config \
    python3 \
    python3-pip \
    && mkdir "/conan" \
    && pip3 install --no-cache -q conan==1.59 \
    && chmod -R 777 "/conan" \
    && pip3 install cmake --no-cache \
    && apt-get clean \
    && apt-get autoremove
