OLD_IMAGE=$(docker image ls | grep ubuntu_os | awk '{print $1}')
OLD_PROCESS=$(docker container ps | grep ubuntu-os-con | awk '{print $12}')
echo $OLD_PROCESS

if [ "$OLD_PROCESS" == "ubuntu-os-con" ]; then
    echo "Stop running ubuntu-os-con container"
    docker container stop ubuntu-os-con
fi

if [ "$OLD_IMAGE" == "ubuntu_os" ]; then
    echo "Remove the existing ubuntu_os docker image"
    docker image rm -f ubuntu_os
else
    echo "NO ubuntu_os image"
fi