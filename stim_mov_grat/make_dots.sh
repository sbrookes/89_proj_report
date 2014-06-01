#!/bin/bash

for file in ./*.txt
do
  dot -Tpdf "$file" -o "${file%%.txt}.pdf"
done