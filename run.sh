#!/bin/sh

TAG=platformio_string_util

docker ps | grep $TAG | awk '{print $1}' | xargs docker stop
docker ps -a | grep $TAG | awk '{print $1}' | xargs docker container rm
#docker image ls | grep $TAG | awk '{print $3}' | xargs docker image rm

docker build . -t $TAG

docker run -it $TAG test

