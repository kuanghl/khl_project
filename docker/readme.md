- `docker build -t images_name:tag .`
- `sudo docker run --name comtainer_name -p 6999:22 --ipc=host -it -v /dev/shm/:/dev/shm  -dit images_name:tag /bin/bash`
- docker权限问题:尽量以root用户执行，对open及修改文件权限管理比较到位。