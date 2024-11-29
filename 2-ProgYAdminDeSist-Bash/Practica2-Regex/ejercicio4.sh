#!/bin/bash

# Obtener la carpeta personal del usuario
home_dir=$HOME
#Listar los ficheros ocultos en la carpeta personal, ordenados por número de caracteres
echo -e "\n1) Ficheros ocultos de $home_dir\n"
ls -a $home_dir | grep "^\." | while read -r file; do
    echo ${#file} $file #${#file} representa el número de caracteres en el nombre del fichero.
done | sort -n | grep -o "[^ ]*$"

#sort -n -k -> ordename la primera columna por numeros
#awk agrega una columna que te dice el numero de caracteres de cara palabra
# ls -a /home/$USER | sed "s/ /\n/g" | sed -n -r "s/(\..*)/\1/p" | awk '{ print length($0), $0 }' | sort -n -k 1 | sed -r -n "s/[0-9]*//p"


# Obtener el nombre de usuario actual
username=$(whoami)

# Listar los procesos del usuario actual 
echo -e "\n\n\n2) Listado de los procesos ejecutados por el usuario $username\n" 
ps -ux | sed -r -e 's/^[^ ]+ +([^ ]+) +[^ ]+ +[^ ]+ +[^ ]+ +[^ ]+ +[^ ]+ +[^ ]+ +([^ ]+) +[^ ]+ ([^ ]+.*)$/PID: \1   Hora: "\2"     Ejecutable: "\3"/' | sort -k6 -r
#ps -ux | grep $(whoami) | grep -v grep | grep -v $0 | awk '{print "PID:", $2, "Hora:", $9 " ", "Ejecutable:", $11 " " $12 " " $13}' 