#!/bin/bash

# Check if the user already exists to avoid errors on container restart
if ! id "$FTP_USER" &>/dev/null; then
    echo "Creating FTP user: $FTP_USER"
    
    # Create the user and set their home directory to the shared volume
    useradd -m -d /var/www/html -s /bin/bash "$FTP_USER"
    
    # Set the password using the environment variable
    echo "$FTP_USER:$FTP_PASS" | chpasswd
    
    # Add the user to the www-data group so they don't break WordPress permissions
    usermod -aG www-data "$FTP_USER"
    
    # Give ownership of the folder to the FTP user
    chown -R "$FTP_USER":"$FTP_USER" /var/www/html
fi

# Ensure the secure empty directory vsftpd needs exists
mkdir -p /var/run/vsftpd/empty

# Start the FTP server in the foreground (PID 1)
echo "Starting FTP Server..."
exec vsftpd /etc/vsftpd.conf
