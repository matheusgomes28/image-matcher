#
# We base our image from the alpine light image
FROM python:alpine3.17

#
# Environment variables needed for the
# build system
ENV CONAN_USER_HOME "/conan"
ENV TZ=Europe/London

#
# Identify the maintainer of an image
LABEL maintainer="matheusgarcia28@gmail.com"

#
# Install the necessary conan stuff
RUN apk add --no-cache python3
RUN apk add --no-cache py3-pip

RUN apk --no-cache --update add build-base

RUN mkdir "/conan"
RUN pip3 install --no-cache -q conan==1.59
RUN chmod -R 777 "/conan"

RUN pip3 install cmake --no-cache
