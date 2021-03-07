#!/bin/bash

read -r N L
declare -a S=()

for (( i = 0; i < N; i++ ))
do
  read INPUT
  S+=($INPUT)
done

sorted_arr=( $( printf "%s\n" "${S[@]}" | sort ) )
IFS=; 
echo "${sorted_arr[*]}"

