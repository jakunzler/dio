#!/usr/bin/env bash

echo "Starting script..."

# Get the current directory
PWD=$(pwd)
echo $PWD

# Create a test directory
if [ ! -d $PWD/directories ]; then
    mkdir -p $PWD/directories
else
    echo "The directory already exists."
fi

# Delete previous files except the bash script
sudo find $PWD -type f -not -name "provisionning.sh" -delete

# Force to delete all previous folders
if [ -d $PWD/directories ]; then
    sudo rm -rf $PWD/directories/*
else
    echo "The directory does not exist."
fi

# Create system groups
if [ $(getent group GRP_ADM) ]; then
    echo "The group GRP_ADM already exists."
else
    echo "The group GRP_ADM does not exist. It will be created."
    sudo groupadd GRP_ADM
fi

if [ $(getent group GRP_VEN) ]; then
    echo "The group GRP_VEN already exists."
else
    echo "The group GRP_VEN does not exist. It will be created."
    sudo groupadd GRP_VEN
fi

if [ $(getent group GRP_SEC) ]; then
    echo "The group GRP_SEC already exists."
else
    echo "The group GRP_SEC does not exist. It will be created."
    sudo groupadd GRP_SEC
fi

# Create system directories with permissions
sudo mkdir -p $PWD/directories/publico
sudo chmod 777 $PWD/directories/publico
echo "Publico" > $PWD/directories/publico/publico.txt

sudo mkdir -p $PWD/directories/adm
sudo chmod 770 $PWD/directories/adm
sudo chgrp GRP_ADM $PWD/directories/adm
sudo echo "Adm" > $PWD/directories/adm/adm.txt

sudo mkdir -p $PWD/directories/ven
sudo chmod 770 $PWD/directories/ven
sudo chgrp GRP_VEN $PWD/directories/ven
sudo echo "Ven" > $PWD/directories/ven/ven.txt

sudo mkdir -p $PWD/directories/sec
sudo chmod 770 $PWD/directories/sec
sudo chgrp GRP_SEC $PWD/directories/sec
sudo echo "Sec" > $PWD/directories/sec/sec.txt

# Create system users
if [ $(getent passwd carlos) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd carlos -c "Carlos Adm" -m -s /bin/bash -G GRP_ADM
fi

if [ $(getent passwd maria) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd maria -c "Maria Adm" -m -s /bin/bash -G GRP_ADM
fi

if [ $(getent passwd joao) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd joao -c "Joao Adm" -m -s /bin/bash -G GRP_ADM
fi

if [ $(getent passwd debora) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd debora -c "Debora Ven" -m -s /bin/bash -G GRP_VEN
fi

if [ $(getent passwd sebastiana) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd sebastiana -c "Sebastiana Ven" -m -s /bin/bash -G GRP_VEN
fi

if [ $(getent passwd roberto) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd roberto -c "Roberto Ven" -m -s /bin/bash -G GRP_VEN
fi

if [ $(getent passwd josefina) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd josefina -c "Josefina Sec" -m -s /bin/bash -G GRP_SEC
fi

if [ $(getent passwd amanda) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd amanda -c "Amanda Sec" -m -s /bin/bash -G GRP_SEC
fi

if [ $(getent passwd rogerio) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd rogerio -c "Rogerio Sec" -m -s /bin/bash -G GRP_SEC
fi

# Undo the changes
if true; then
    sudo userdel -r carlos
    sudo userdel -r maria
    sudo userdel -r joao
    sudo userdel -r debora
    sudo userdel -r sebastiana
    sudo userdel -r roberto
    sudo userdel -r josefina
    sudo userdel -r amanda
    sudo userdel -r rogerio

    sudo groupdel GRP_ADM
    sudo groupdel GRP_VEN
    sudo groupdel GRP_SEC

    sudo rm -rf $PWD/directories
fi

echo "Script finished."
