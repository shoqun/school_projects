#!/usr/bin/env bash

docker rmi -f mebblera/valgrind:local
docker build . -t mebblera/valgrind:local
chmod +x run.sh
chmod +x entrypoint/docker_entrypoint.sh
