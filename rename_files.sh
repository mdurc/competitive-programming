#!/bin/bash
for file in p*.cpp; do
    num_part=$(echo "$file" | sed -E 's/^p([0-9]+)_.*/\1/')
    rest_of_name=$(echo "$file" | sed -E 's/^p[0-9]+_(.*)/\1/')

    new_num=$(printf "%04d" "$num_part")

    new_rest=$(echo "$rest_of_name" | tr '_' '-')

    new_file="${new_num}-${new_rest}"

    mv "$file" "$new_file"
    echo "Renamed $file to $new_file"
done

