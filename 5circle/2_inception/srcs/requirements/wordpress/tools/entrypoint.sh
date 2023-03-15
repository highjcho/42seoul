#!/bin/bash

echo start setting wordpress
apt-get -y update &&
apt-get -y upgrade &&
apt-get -y install \
php7.3 \
php-fpm \
php-cli \
wget \
curl \
php-mysql \
php-mbstring \
php-xml \
sendmail \
vim

service php7.3-fpm start;
apt-get -y install mariadb-client
sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.3/fpm/pool.d/www.conf

if [ ! -f /var/www/html/wp-config.php ]; then
  curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
  chmod +x wp-cli.phar
  mv wp-cli.phar /usr/local/bin/wp

  wp core download --allow-root --path=/var/www/html/
  wp core config --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PWD --dbhost=$WORDPRESS_DB_HOST --dbprefix=wp_ --allow-root --path=/var/www/html/
  wp core install --url=https://$DOMAIN_NAME --title="Hyunjcho's inception" --admin_user=$ADMIN_NAME --admin_password=$ADMIN_PWD --admin_email=$ADMIN_EMAIL --allow-root --path=/var/www/html/
  wp user create "$USER_NAME" "$USER_EMAIL" --role=subscriber --user_pass="$USER_PWD" --allow-root --path=/var/www/html/
fi

service php7.3-fpm stop;
echo finish setting wordpress
exec "$@"