#!/bin/bash

mkdir ./new
touch ./new/new.txt
echo 'welcome to banyuan' >> ./new/new.txt
mkdir -p ./newother/sub
cp ./new/new.txt ./newother/sub
mv ./new/new.txt ./new/new1.txt
mv ./newother/sub ./new2
find . -type d -name 'new*' | xargs rm -r

