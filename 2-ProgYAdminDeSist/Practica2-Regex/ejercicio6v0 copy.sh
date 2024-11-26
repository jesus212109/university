#!/bin/bash

# Verificar que se haya proporcionado un argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <shell>"
    exit 1
fi

# Obtener la cadena de texto del shell proporcionado
shell=$1

# Variable para rastrear si se encontraron usuarios
found_users=0

# Leer el archivo /etc/passwd línea por línea y filtrar usuarios con el shell dado
while IFS=: read -r username x uid gid x home shell_entry; do
    if [ "$shell_entry" = "$shell" ]; then
        # Obtener el nombre del grupo primario
        groupname=$(grep -E "^$gid:" /etc/group | cut -d: -f1)
        
        # Mostrar información formateada
        echo "========="
        echo "Logname: $username"
        echo "->UID: $uid"
        echo "->Grupo: $groupname"
        echo "->GID: $gid"
        echo "->Shell por defecto: $shell_entry"
        
        found_users=1
    fi
done < /etc/passwd

# Si no se encontraron usuarios, mostrar un mensaje
if [ $found_users -eq 0 ]; then
    echo "No se encontraron usuarios con el shell especificado: $shell"
fi
