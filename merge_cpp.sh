#!/bin/bash

OUTPUT="full_project.txt"

# Очищаем файл перед началом
> "$OUTPUT"

# Перечисляем расширения, которые нам нужны
for file in include/*.{cpp,hpp,h}; do
    # Проверка на случай, если файлов с таким расширением нет
    [ -e "$file" ] || continue

    echo "Processing: $file"
    
    echo "----------------------------------------" >> "$OUTPUT"
    echo "SOURCE FILE: $file" >> "$OUTPUT"
    echo "----------------------------------------" >> "$OUTPUT"
    
    cat "$file" >> "$OUTPUT"
    
    # Добавляем отступ между файлами
    echo -e "\n\n" >> "$OUTPUT"
done


for file in source/*.{cpp,hpp,h}; do
    # Проверка на случай, если файлов с таким расширением нет
    [ -e "$file" ] || continue

    echo "Processing: $file"
    
    echo "----------------------------------------" >> "$OUTPUT"
    echo "SOURCE FILE: $file" >> "$OUTPUT"
    echo "----------------------------------------" >> "$OUTPUT"
    
    cat "$file" >> "$OUTPUT"
    
    # Добавляем отступ между файлами
    echo -e "\n\n" >> "$OUTPUT"
done

echo "Done! All code is now in $OUTPUT"
