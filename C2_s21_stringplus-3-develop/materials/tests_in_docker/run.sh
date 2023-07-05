#!/usr/bin/env bash

# run new container to test project, placed in /src folder
# -v  - mounts project files from src and docker_entrypoint.sh form entrypoint folder
# -it - allocate pseudo-TTY into container, so you can commands before container collapses
#       dont comment /bin/bash in script, if you want it to work
# -rm - removes container immediately after stopping
docker run -v $(pwd)/entrypoint:/usr/docker_files/entrypoint -v $(pwd)/src:/usr/docker_files/src --rm -it mebblera/valgrind:local