#!/bin/bash

# Verificación del número de argumentos
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <ruta_del_directorio>" >&2
    exit 1
fi

directory="$1"

# Verificación de la existencia y tipo de directorio
if [ ! -d "$directory" ]; then
    echo "Error: '$directory' no es un directorio válido." >&2
    exit 1
fi

# Función para mostrar información detallada de los archivos de forma recursiva
show_files_info_recursively() {
    local current_directory="$1"
    local file

    # Iterar sobre los archivos en el directorio actual
    for file in $(ls -a $current_directory); do
        if [ $file == "." ] || [ $file == ".." ];then
            continue
        fi

        ruta=$(realpath "$current_directory/$file")

        # Si el archivo es un directorio, continuar recursivamente
        if [ -d "$ruta" ]; then
            show_files_info_recursively "$ruta"
        # Si el archivo es un archivo regular, mostrar su información detallada
        elif [ -f "$ruta" ]; then
            filename=$(basename "$ruta")  # Nombre del archivo sin la ruta
            absolute_path=$(realpath "$ruta")  # Ruta absoluta del archivo
            modification_time=$(date -r "$ruta" +%s)  # Fecha de modificación en segundos desde la Época
            size=$(stat -c %s "$ruta")  # Tamaño del archivo en bytes
            permissions=$(stat -c %A "$ruta")  # Cadena de permisos del archivo
            # Mostrar información detallada del archivo en una fila con campos separados por tabuladores
            echo -e "$filename\t$absolute_path\t$modification_time\t$size bytes\t$permissions"
            #El comando sort se utiliza para ordenar las líneas de texto.
            #s-t$'\t': Especifica que el delimitador de campo es un tabulador. $'\t' es una expansión de secuencia de escape que representa un tabulador.
            #k3n: Indica que se debe ordenar según el tercer campo (-k3) de forma numérica (n), que en este caso es la fecha de modificación expresada en segundos desde la Época
        fi
    done
}

# Llamada a la función para mostrar información detallada de los archivos de forma recursiva
# Se ordena la lista de archivos por fecha de modificación ascendente utilizando "sort"
show_files_info_recursively "$directory" | sort -t$'\t' -k3n
