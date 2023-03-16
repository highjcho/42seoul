#!/bin/bash

echo start setting mariadb
apt-get -y update
apt-get -y upgrade
apt-get -y install \
mariadb-server \
vim

service mysql start

sed -i "s/bind-address/#bind-address/" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s/password =/password = $MARIADB_ROOT_PWD/g" /etc/mysql/debian.cnf

echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PWD}';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "CREATE USER IF NOT EXISTS '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "GRANT ALL PRIVILEGES ON mysql.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PWD';" | mysql -uroot -p$MARIADB_ROOT_PWD
echo "FLUSH PRIVILEGES;" | mysql -uroot -p$MARIADB_ROOT_PWD
service mysql stop
echo finish setting mariaDB
exec "$@"