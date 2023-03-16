#!/bin/bash
echo start setting nginx

apt-get -y update &&
apt-get -y upgrade &&
apt-get -y install \
nginx \
openssl \
vim

openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/ssl/private/server_pkey.pem \
		-out /etc/ssl/certs/server.crt \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=./CN=hyunjcho.42.fr/emailAddress=hyunjcho@student.42seoul.kr"
yes | cp var/www/html/default /etc/nginx/sites-available/default

echo finish setting nginx
exec "$@"