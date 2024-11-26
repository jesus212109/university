#!/bin/bash

# Función para comprobar los permisos de un archivo
check_permissions() {
    file="$1"
    permissions=$(stat -c "%a" "$file")
    #Usa el comando stat para obtener los permisos del archivo especificado por $file. El modificador -c "%a" se usa para obtener los permisos en formato numérico.
    echo "Permisos de $file: $permissions" # Agregar esta línea para depurar
    echo "Ruta del archivo: $file" # Agregar esta línea para depurar

    if ! [[ "$permissions" =~ ^(000|100|200|300|400|500|600|700)$ ]]; then #a expresión [[ ]] en Bash es una extensión más potente y flexible que [ ], también conocida como test extendido. Permite realizar comparaciones más complejas 
    #Se puede sacar con una tubería y el comando cut -c2 o -c3 el 2º o 3er caracter para compararlo, tendriamos que comprobar la dir de usuario, de ssh y la id de rsa
        echo "La clave privada $file no está correctamente protegida."

        # Obtener el nombre de usuario del directorio del archivo
        user_dir=$(dirname "$file")
        user=$(whoami)

        # Crear archivo de advertencia en el escritorio del usuario
        warning_file="/home/$user/Desktop/ADVERTENCIA_CLAVE_DESPROTEGIDA.txt"
        touch $warning_file
        echo "Su clave privada está desprotegida. Por favor, asegúrese de establecer los permisos adecuados." > "$warning_file"
        echo "Se ha creado un archivo de advertencia en el escritorio del usuario: $warning_file"

        return 1
    else
        echo "Clave protegida"
        return 0
    fi
}

# Verificar las claves privadas de SSH para todos los usuarios
for home_dir in /home/*; do #Lo recorro en bucle para repetir el proceso para cada usuario
        echo $home_dir
    ssh_dir="$home_dir/.ssh"    #Construye la ruta al directorio .ssh dentro del directorio de inicio del usuario actual
        echo $ssh_dir
    key_file="$home_dir/.ssh/id_rsa"  #Construye la ruta al archivo de clave privada id_rsa dentro del directorio .ssh
        echo $key_file


    if [ -d "$ssh_dir" ] && [ -f "$key_file" ]; then    #Verifica si el directorio .ssh y el archivo de clave privada id_rsa existen.
     #-d es un operador de prueba que devuelve verdadero si el argumento es un directorio.
     #-f es un operador de prueba que devuelve verdadero si el argumento es un archivo regular.
        echo "Verificando la clave privada de $home_dir..."
            # echo hola
        # Comprobar permisos del archivo clave
        check_permissions "$key_file" && check_permissions "$ssh_dir" && check_permissions "$home_dir"
        if [ $? -eq 0 ]; then
            echo "La clave privada de $home_dir está correctamente protegida."
        fi
    else 
        echo "No existe o el directorio $ssh_dir o el archivo $key_file que contieene las claves"
    fi
done
