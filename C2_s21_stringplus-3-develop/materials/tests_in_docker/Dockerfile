FROM ubuntu:22.04

MAINTAINER Dmitry Treskov <dtreskov@gmail.com>
LABEL Description="Application builds and run your project, placed in /src folder. \
 Then test it fith valgrind and linters, specified in docker_entrypoint.sh"

USER root

WORKDIR /usr/docker_files/src

COPY entrypoint/docker_entrypoint.sh /usr/docker_files/entrypoint/

#SHELL ["/bin/bash", "-c"]

RUN apt-get -y update && \
    apt-get install -y build-essential && \
    apt-get install -y clang-format && \
    apt-get install -y cpplint && \
    apt-get install -y cppcheck && \
    apt-get -y install check && \
    apt-get install -y valgrind; \
    apt-get -y upgrade && \
    rm -rf /var/lib/apt/lists

SHELL ["/bin/bash", "-c"]

ENTRYPOINT /usr/docker_files/entrypoint/docker_entrypoint.sh

#valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s