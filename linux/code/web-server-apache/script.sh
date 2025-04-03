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

if false; then
# remove apache2 if it exist
if [ -d "/usr/local/apache2" ]; then
    warning "Removing existing Apache installation..."
    sudo apt-get remove -y apache2
    success "Existing Apache installation removed."
else
    echo "No existing Apache installation found."
fi

# remove unzip if it exists
if [ -f "/usr/bin/unzip" ]; then
    warning "Removing existing unzip installation..."
    sudo apt-get remove -y unzip
    success "Existing unzip installation removed."
else
    echo "No existing unzip installation found."
fi

fi

# installing apache2 and unzip
echo "Updating package list..."
sudo apt-get update
echo "Package list updated."
echo "Upgrading packages..."
sudo apt-get upgrade -y
echo "Packages upgraded."

sudo apt-get install -y apache2 unzip
success "Apache2 and unzip installed."

# Check if wget is installed
if ! command -v wget &> /dev/null
then
    warning "wget could not be found, installing..."
    sudo apt-get install -y wget
else
    echo "wget is already installed."
fi

# Change directory to /tmp
cd /tmp
echo "Changed directory to /tmp."

# Download files
echo "Downloading files..."
wget https://github.com/denilsonbonatti/linux-site-dio/archive/refs/heads/main.zip
echo "Files downloaded."

# Unzip the downloaded file
echo "Unzipping the downloaded file..."
unzip main.zip
echo "File unzipped."

# Move the unzipped files to the Apache directory
echo "Moving files to the Apache directory..."
sudo mv linux-site-dio-main/* /var/www/html/
echo "Files moved to the Apache directory."

# Restart Apache
echo "Restarting Apache..."
sudo systemctl restart apache2
echo "Apache restarted."

# Check if Apache is running
echo "Checking if Apache is running..."
if systemctl is-active --quiet apache2; then
    success "Apache is running."
else
    error "Apache is not running."
    exit 1
fi

# Print the IP address
echo "Printing the IP address..."
IP_ADDRESS=$(hostname -I | awk '{print $1}')
echo "Your IP address is: $IP_ADDRESS"

# Print the URL
echo "Printing the URL..."
echo "Your URL is: http://$IP_ADDRESS/index.html"

# Print the end message
echo "Script finished."
