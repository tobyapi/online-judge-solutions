#!/bin/bash

read -r A B C
if (( A == 5 && B == 5 && C == 7 )) ||
   (( A == 5 && B == 7 && C == 5 )) ||
   (( A == 7 && B == 5 && C == 5 ))
then
  echo "YES"
else
  echo "NO"
fi
