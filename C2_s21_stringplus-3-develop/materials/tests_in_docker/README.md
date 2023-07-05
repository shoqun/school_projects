# tests_in_docker
Dockerfile and script to fast build-and-run docker container to check your project for leaks, programming errors, bugs, stylistic errors and suspicious constructs.

## Project content

- `build.sh` - script to build docker image based on `Dockerfile`, required to run only once.
- `run.sh` - script to run container from build image
- `Dockerfile` - file with command lines to assemble docker image. Here we defined:
  <details>
  <summary>Brief description of Dockerfile commands</summary>
  
  - `FROM ubuntu:22.04` - Creates a base layer from to future operation. Pulls it from official repository.
  - `USER root` - set user to run subsequent commands, better to create new one and give it required right, but we'll stay as root for now.
  - `COPY docker_entrypoint.sh /usr/docker_files/` - copying script, which we'll run when as entrypoint of container(command, which runs in container as it booted) 
  - `RUN ...` - set of commands that will be run on first container boot. Installation of the required libraries for compilation and check checking.
  - `SHELL ["/bin/bash", "-c"]` - setting bash as current shell
  - `ENTRYPOINT /usr/docker_files/docker_entrypoint.sh` - script, which runs in container each time it booted. Compiles C program from files, placed in src directory, checks it with linters/valgrind.
  - More info at https://docs.docker.com/engine/reference/builder/
  </details>

- `/src` - folder to store your project to compile and test
- `/entrypoint` - folder with entrypoint script and auxiliary files, which can be used by script - configs for linters, for example.
- `/entrypoint/docker_entrypoint.sh` - bash script, which you can edit to perform various operations on your code, simple example:

```shell
#!/usr/bin/env bash

#   You got `test` target in your makefile, which compile your code to
#   `./build/test` executable, which you want to test for leaks

make test
valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./build/test

/bin/bash
```

## Installing / Getting started

  - You should have Docker application installed to build and run docker containers.
  - To build container image run `build.sh` script or `docker build . -t <your_name:your_tag>` command. You only need to do it once, if you don't need to install additional libraries in the future.
  - To install additional libraries add them to RUN field in `Dockerfile` and rebuild image with script.
  - Then edit `/entrypoint/docker_entrypoint.sh`, write command which you want to run inside container.
  - Copy your project files to `/src` folder
  - Run `run.sh` script or `docker run -v $(pwd)/entrypoint:/usr/docker_files/entrypoint -v $(pwd)/src:/usr/docker_files/src --rm -it <your_name:your_tag>` command. Be carefully with mapped volumes.
  - In my sample file results of `valgrind`, `cpplint`, `cppcheck` and `clang-format` commands stored in /src/logs files, you can edit `/entrypoint/docker_entrypoint.sh` to perform checks you want.
