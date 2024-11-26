#!/bin/bash

generate_index_html() {
    local directory="$1"
    local index_file="index.html"

    # Verificar si el directorio existe
    if [ ! -d "$directory" ]; then
        echo "El directorio '$directory' no existe."
        return 1
    fi

    # Crear el archivo de índice HTML
    echo "<!DOCTYPE html>" > "$index_file"
    echo "<html>" >> "$index_file"
    echo "<head>" >> "$index_file"
    echo "<title>Índice de $directory</title>" >> "$index_file"
    echo "</head>" >> "$index_file"
    echo "<body>" >> "$index_file"
    echo "<h1>Índice de $directory</h1>" >> "$index_file"
    echo "<ul>" >> "$index_file"

    # Listar los archivos y directorios en el directorio dado
    for item in "$directory"/*; do
        item_name=$(basename "$item")
        echo "<li><a href=\"$item_name\">$item_name</a>" >> "$index_file"
        if [ -d "$item" ]; then
            echo "<a href=\"$item_name/index.html\">(Ver Índice)</a>" >> "$index_file"
        fi
        echo "</li>" >> "$index_file"
    done

    echo "</ul>" >> "$index_file"
    echo "</body>" >> "$index_file"
    echo "</html>" >> "$index_file"

    echo "Se ha generado el archivo de índice '$index_file' para el directorio '$directory'."
}

# Función para generar el índice HTML de un directorio y sus subdirectorios de forma recursiva
generate_recursive_indexes() {
    local directory="$1"

    # Verificar si el directorio existe
    if [ ! -d "$directory" ]; then
        echo "El directorio '$directory' no existe."
        return 1
    fi

    # Generar el índice HTML para el directorio actual
    generate_index_html "$directory"

    # Recorrer los subdirectorios de forma recursiva
    for subdir in "$directory"/*; do
        if [ -d "$subdir" ]; then
            generate_recursive_indexes "$subdir"
        fi
    done
}

# Verificar el número de argumentos
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <ruta_del_directorio>"
    exit 1
fi

# Directorio proporcionado como argumento
target_directory="$1"

# Generar los índices de forma recursiva
generate_recursive_indexes "$target_directory"
