#!/usr/bin/env bash

echo "Starting script..."

# Function to print messages in different colors
# Usage: error "Error message"
function error() {
  echo -e "\e[1;31m[ERROR]\e[0m $1"
}

# Usage: warning "Warning message"
function warning() {
  echo -e "\e[1;33m[WARNING]\e[0m $1"
}

# Usage: success "Success message"
function success() {
  echo -e "\e[1;32m[SUCCESS]\e[0m $1"
}

# Get the current directory
PWD=$(pwd)
echo $PWD

# Check if the path contains "linux/code"
if [[ $PWD != *"linux/code" ]]; then
    error "The path does not contain or end with 'linux/code'!"
    echo "Please run the script from the 'linux/code' directory."
    echo "Current path: $PWD"
    warning "Expected path: */linux/code/"
    echo "Please change to the correct directory and try again."
    success "Exiting script."
    exit 1
else
    success "The path contains 'linux/code'."
fi

# Create a test directory
if [ ! -d $PWD/directories ]; then
    mkdir -p $PWD/directories
else
    echo "The directory already exists."
fi

# Delete previous files except the bash script
sudo find $PWD -type f -not -name "*.sh" -delete

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
sudo chmod 777 $PWD/directories/adm
echo "Adm" > $PWD/directories/adm/adm.txt
sudo chmod 770 $PWD/directories/adm
sudo chgrp GRP_ADM $PWD/directories/adm

sudo mkdir -p $PWD/directories/ven
sudo chmod 777 $PWD/directories/ven
echo "Ven" > $PWD/directories/ven/ven.txt
sudo chmod 770 $PWD/directories/ven
sudo chgrp GRP_VEN $PWD/directories/ven

sudo mkdir -p $PWD/directories/sec
sudo chmod 777 $PWD/directories/sec
echo "Sec" > $PWD/directories/sec/sec.txt
sudo chmod 770 $PWD/directories/sec
sudo chgrp GRP_SEC $PWD/directories/sec

# Create system users
if [ $(getent passwd carlos) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd carlos -c "Carlos Adm" -m -s /bin/bash -G GRP_ADM -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd maria) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd maria -c "Maria Adm" -m -s /bin/bash -G GRP_ADM -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd joao) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd joao -c "Joao Adm" -m -s /bin/bash -G GRP_ADM -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd debora) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd debora -c "Debora Ven" -m -s /bin/bash -G GRP_VEN -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd sebastiana) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd sebastiana -c "Sebastiana Ven" -m -s /bin/bash -G GRP_VEN -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd roberto) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd roberto -c "Roberto Ven" -m -s /bin/bash -G GRP_VEN -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd josefina) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd josefina -c "Josefina Sec" -m -s /bin/bash -G GRP_SEC -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd amanda) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd amanda -c "Amanda Sec" -m -s /bin/bash -G GRP_SEC -p $(openssl passwd -crypt 123456)
fi

if [ $(getent passwd rogerio) ]; then
    echo "The user already exists."
else
    echo "New user created."
    sudo useradd rogerio -c "Rogerio Sec" -m -s /bin/bash -G GRP_SEC -p $(openssl passwd -crypt 123456)
fi

# Undo the changes
if false; then
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
