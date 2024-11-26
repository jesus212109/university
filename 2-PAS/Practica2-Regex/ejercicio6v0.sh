#!/bin/bash

# Verificar que se haya proporcionado un argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <shell> (recomindo probar \"/bin/sh\" como shell)"
    exit 1
fi


# Variable para rastrear si se encontraron usuarios
found_users=0

# Leer el archivo /etc/passwd línea por línea y filtrar usuarios con el shell dado
#IFS=::(Internal Field Separator) es una variable de entorno que define el separador de campos. En este caso, lo estamos configurando como :
#Esto significa que el bucle leerá cada línea del archivo /etc/passwd y dividirá la línea en campos cada vez que encuentre un :
while IFS=: read username x uid gid x home shell; do
    #if [ "$shell" = "$1" ]; then
        # Obtener el nombre del grupo primario
        groupname=$(egrep "^.*?:[^:]*:$gid:" /etc/group | cut -d: -f1)
        #cut -d: -f1 se está utilizando para dividir cada línea del archivo de entrada en campos usando : como delimitador, 
        #Luego, -f1 indica que solo se debe extraer el primer campo de cada línea
        
        # Mostrar información formateada
        echo "========="
        echo "Logname: $username"
        echo "->UID: $uid"
        echo "->Grupo: $groupname"
        echo "->GID: $gid"
        echo "->Shell por defecto: $shell"
        
        found_users=1
    #fi
done < /etc/passwd

# Si no se encontraron usuarios, mostrar un mensaje
if [ $found_users -eq 0 ]; then
    echo "No se encontraron usuarios con el shell especificado: $shell"
fi
