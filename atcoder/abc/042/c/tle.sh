#!/bin/bash

function check(){
  N="$2"

  for a in $1; do
    if [[ $(grep "$a" <<< "$2") ]]
    then
      echo "false"
      return 0
    fi
  done
  echo "true"
}

read -r N K
read -r D

for (( i = N; ; i++ ))
do
  if [[ "$(check "$D" "$i")" = "true" ]]
  then
    echo "$i"
    exit 0
  fi
done

