#!/bin/bash

for i in *; 
do 
    mv $i ${i,,};
done

