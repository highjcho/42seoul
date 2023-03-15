FROM debian:buster

COPY ./tools/entrypoint.sh /entrypoint.sh
COPY ./conf/default /var/www/html/default
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]