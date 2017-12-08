#!/bin/bash
function getStat(){
  declare -a ARRAY
  count=0;
  for file in *.cpp
  do
    ARRAY[$count]=$file;
    ((count++));
  done
  for((i=0;i<${#ARRAY[@]};i++)){
    printf "%s -- " "${ARRAY[$i]}";
    stat -c %Z ${ARRAY[$i]};
  }
}
while :
do
  getStat;
  sleep 2;
  clear
done





#for file in *.cpp
#do
#  g++ -o ${file%.*} $file -lallegro;
#done
