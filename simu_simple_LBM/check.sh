#!/bin/sh 

for i in {1..200..1}
do
  CMD1=$(./display --checksum resultat.raw $i)
  CMD2=$(./display --checksum ../ref_resultat_200.raw $i)
  if [ "$CMD1" == "$CMD2" ]; then
    continue
  else
    echo "An issue at frame $i"
    echo $CMD1
    echo $CMD2
  fi
done
