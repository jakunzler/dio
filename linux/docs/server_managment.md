# 🧭 Linux Server Administration Roadmap

A structured guide for becoming proficient in managing Linux systems as a server administrator.

---

## 📌 Stage 1: Foundation - Linux Basics

- [ ] Understand Linux distributions (Ubuntu, CentOS, Debian, Arch)
- [ ] Learn basic shell commands (cd, ls, cp, mv, rm, touch)
- [ ] File and directory permissions (chmod, chown, umask)
- [ ] Understand file system structure (`/etc`, `/var`, `/home`, etc.)
- [ ] Working with text editors (nano, vim)
- [ ] Users and groups management (`adduser`, `usermod`, `passwd`)
- [ ] Understand systemd & service management (`systemctl`, `journalctl`)

---

## 📌 Stage 2: Networking Essentials

- [ ] IP addressing, DNS, DHCP, Subnets
- [ ] `ping`, `traceroute`, `dig`, `nslookup`, `netstat`, `ss`
- [ ] Configuring static IPs & hostname
- [ ] SSH (Secure Shell) setup and keys
- [ ] Managing the firewall (`ufw`, `firewalld`, `iptables`)

---

## 📌 Stage 3: Package & Software Management

- [ ] APT / DNF / YUM / Pacman basics
- [ ] Add and manage repositories (PPAs, `.repo` files)
- [ ] Compile from source (tarballs, `make`, `gcc`)
- [ ] Install and remove software packages

---

## 📌 Stage 4: Server & Services Configuration

- [ ] Web servers: Nginx / Apache
- [ ] Database servers: MySQL / PostgreSQL / MongoDB
- [ ] FTP/SFTP servers
- [ ] File sharing: Samba / NFS
- [ ] Mail server basics (Postfix, Sendmail)
- [ ] DNS server basics (BIND, dnsmasq)

---

## 📌 Stage 5: Monitoring & Logging

- [ ] Understand system logs (`/var/log`)
- [ ] `top`, `htop`, `iotop`, `du`, `df`
- [ ] Log rotation (`logrotate`)
- [ ] Monitor disk, memory, CPU usage
- [ ] Setup alerts with `cron`, `mail`, or external tools (e.g., Nagios, Zabbix)

---

## 📌 Stage 6: Automation & Scripting

- [ ] Shell scripting basics (`bash`, `zsh`)
- [ ] Automate with `cron` and `at`
- [ ] Environment variables and shell config files
- [ ] Scheduled backups (rsync, tar, cron jobs)

---

## 📌 Stage 7: Security & Hardening

- [ ] Enable and configure firewall (ufw, iptables)
- [ ] Disable root login and unnecessary services
- [ ] Configure fail2ban for SSH brute-force protection
- [ ] Keep system up-to-date (`unattended-upgrades`, `yum-cron`)
- [ ] Setup regular backups and disaster recovery plans

---

## 📌 Stage 8: Advanced Topics

- [ ] Virtualization (KVM, VirtualBox, VMWare)
- [ ] Containers (Docker, Podman, LXC)
- [ ] Configuration management (Ansible, Puppet)
- [ ] High availability and load balancing
- [ ] System performance tuning
- [ ] SELinux / AppArmor basics

---

## 📌 Stage 9: Cloud and DevOps Integration

- [ ] Work with cloud instances (AWS EC2, GCP Compute Engine, Azure VMs)
- [ ] Setup and manage SSH key pairs for cloud
- [ ] Automate deployments (CI/CD tools)
- [ ] Use cloud CLI tools (AWS CLI, GCP SDK)
- [ ] Infrastructure as Code (Terraform, Ansible)

---

## 🧰 Recommended Tools

- [ ] `tmux` or `screen` (session management)
- [ ] `ncdu` (disk usage viewer)
- [ ] `fail2ban` (security)
- [ ] `rsync` (backups)
- [ ] `nmap` (network scanning)
- [ ] `ufw` / `iptables` (firewall)

---

## 📚 Learning Resources

- [Linux Journey](https://linuxjourney.com/)
- [The Linux Command Line by William Shotts](https://linuxcommand.org/tlcl.php)
- [DigitalOcean Community Tutorials](https://www.digitalocean.com/community/tutorials)
- [Linux Handbook](https://linuxhandbook.com/)

## 🛠️ Linux Server Admin Command Example: Setup a Basic Web Server

This example walks you through:

- Updating the system
- Creating a user
- Installing and starting an Nginx web server
- Managing firewall rules
- Automating updates with cron
- Checking logs and system status

---

### 📦 1. Update Your System

```bash
sudo apt update && sudo apt upgrade -y
```

---

### 👤 2. Add a New User and Grant Sudo Access

```bash
sudo adduser webadmin
sudo usermod -aG sudo webadmin
```

#### 👤 1. Create a New User

```bash
sudo adduser johndoe
```

This will:

- Create the user `johndoe`
- Create a home directory `/home/johndoe`
- Set up default shell
- Prompt for a password and user details

---

#### 🔑 2. Change or Reset a User's Password

```bash
sudo passwd johndoe
```

You’ll be prompted to enter a new password for the user.

---

#### 👮 3. Add User to a Group

##### Add to a single group

```bash
sudo usermod -aG developers johndoe
```

##### Add to multiple groups

```bash
sudo usermod -aG sudo,developers johndoe
```

> Note: The `-aG` option appends groups without removing the user from existing ones.

---

#### 🧑‍🤝‍🧑 4. Create a New Group

```bash
sudo groupadd developers
```

---

#### ❌ 5. Remove a User

```bash
sudo deluser johndoe
```

To also remove the user's home directory:

```bash
sudo deluser --remove-home johndoe
```

---

#### ❌ 6. Remove a Group

```bash
sudo groupdel developers
```

---

#### 🔄 7. Modify an Existing User

##### Change username

```bash
sudo usermod -l newname johndoe
```

##### Change home directory

```bash
sudo usermod -d /home/newhome -m johndoe
```

##### Lock/Unlock user account

```bash
sudo usermod -L johndoe   # Lock
sudo usermod -U johndoe   # Unlock
```

---

#### 📃 8. View User and Group Info

##### List all users

```bash
cat /etc/passwd
```

##### List all groups

```bash
cat /etc/group
```

##### View groups of a user

```bash
groups johndoe
```

---

#### 🛂 9. Switch User

```bash
su - johndoe
```

> Use `exit` to return to your original session.

---

#### 🧠 Tips

- Always use `sudo` for user management on servers.
- Group permissions can be used for controlling file and service access.
- Avoid modifying `/etc/passwd` or `/etc/group` manually unless necessary.

### 🔐 3. Secure SSH (optional but recommended)

```bash
sudo nano /etc/ssh/sshd_config
# Change or add:
# PermitRootLogin no
# PasswordAuthentication no

sudo systemctl restart ssh
```

---

### 🌐 4. Install Nginx Web Server

```bash
sudo apt install nginx -y
sudo systemctl enable nginx
sudo systemctl start nginx
```

Test it:

```bash
curl http://localhost
```

---

### 🔥 5. Configure Firewall (UFW)

```bash
sudo ufw allow OpenSSH
sudo ufw allow 'Nginx Full'
sudo ufw enable
sudo ufw status
```

---

### ⏰ 6. Schedule Auto Updates with Cron

Edit crontab:

```bash
sudo crontab -e
```

Add this to run updates every day at 2 AM:

```cron
0 2 * * * apt update && apt upgrade -y
```

---

### 📁 7. Monitor Disk and Memory Usage

```bash
df -h     # Disk usage
free -m   # Memory usage
top       # Real-time process viewer
```

---

### 📜 8. View Logs

```bash
sudo journalctl -xe          # View system logs
sudo tail -f /var/log/syslog # Monitor syslog in real time
```

---

### 🧹 9. Clean Up

```bash
sudo apt autoremove -y
sudo apt clean
```

---

### ✅ Bonus: Backup Website Files (e.g., from /var/www)

```bash
sudo tar -czvf website-backup.tar.gz /var/www/html
```
