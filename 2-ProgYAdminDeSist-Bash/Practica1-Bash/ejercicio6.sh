#!/bin/bash

# Verifica si se ha proporcionado exactamente un argumento al script
if [ $# -ne 1 ]; then
    echo "Uso: $0 <directorio>"
    exit 1
fi

# Función para recorrer recursivamente los directorios y generar los archivos index.html
function recur_recorrer(){
    local dir="$1"               # Almacena el directorio actual
    local archivos=$(ls -a "$dir")  # Obtiene la lista de archivos y directorios en el directorio actual
    local index_dir="$dir/index.html"  # Ruta del archivo index.html para el directorio actual

    # Agrega la estructura inicial del archivo index.html
    echo "<head><tittle>Contenido de $dir</title>" >> $index_dir
    echo "<ul>" >> $index_dir

    # Itera sobre los archivos y directorios en el directorio actual
    for archivo in $archivos; do
        # Omite los directorios . y ..
        if [ $archivo == "." ] || [ $archivo == ".." ]; then
            continue
        fi

        # Obtiene la ruta completa del archivo o directorio
        ruta=$(realpath "$dir/$archivo")

        # Si es un directorio, genera un enlace al index.html del subdirectorio y llama a la función recursivamente
        if [ -d $ruta ]; then
            # Genera el enlace al index.html del subdirectorio
            echo "<li><a href="$ruta/index.html">$archivo</a></li>" >> $index_dir
            # Imprime un mensaje indicando que se ha creado un archivo index.html para el directorio actual
            echo "Se ha creado el fichero $index_dir con el contenido del directorio $dir"
            # Llama recursivamente a la función para procesar el subdirectorio
            recur_recorrer "$dir/$archivo"
        else
            # Si es un archivo normal, simplemente agrega un elemento de lista al index.html
            echo "<li>$archivo</li>" >> $index_dir
            # Imprime un mensaje indicando que se ha creado un archivo index.html para el directorio actual
            echo "Se ha creado el fichero $index_dir con el contenido del directorio $dir"
        fi
    done

    # Agrega la estructura de cierre del archivo index.html
    echo "</ul>" >> $index_dir
}

# Llama a la función para iniciar el proceso de generación de archivos index.html
recur_recorrer "$1"
