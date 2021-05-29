#!/bin/bash

clear

platform=$(uname)
echo $plaform

cat ./.compiler | while read line

do

if [ "$platform" == "Darwin" ]; then 

    if [ "$line" == "IAR" ];then 
############################################################
        echo "prepare to backup IAR settings"
        rm       .DS_Store
        rm -rf   ./Debug
        rm -rf   ./projects/IAR/bkup4Eclipse/prev
        mv       ./projects/IAR/bkup4Eclipse/recent ./projects/IAR/bkup4Eclipse/prev 
        mkdir -p ./projects/IAR/bkup4Eclipse/recent 
        mv       ./.compiler ./.cproject ./.project ./.settings ./settings ./projects/IAR/bkup4Eclipse/recent/

        cp       ./projects/GCC/bkup4Eclipse/mac/recent/.compiler ./
        cp       ./projects/GCC/bkup4Eclipse/mac/recent/.cproject ./
        cp       ./projects/GCC/bkup4Eclipse/mac/recent/.project  ./
        cp -r    ./projects/GCC/bkup4Eclipse/mac/recent/.settings ./
        cat      ./.compiler
############################################################
    elif [ $line == "mac" ];then 
############################################################
        echo "prepare to backup mac settings"
        rm       .DS_Store
        rm -rf   ./Debug
        rm -rf   ./projects/GCC/bkup4Eclipse/mac/prev
        mv       ./projects/GCC/bkup4Eclipse/mac/recent ./projects/GCC/bkup4Eclipse/mac/prev 
        mkdir -p ./projects/GCC/bkup4Eclipse/mac/recent 
        mv       ./.compiler ./.cproject ./.project ./.settings ./projects/GCC/bkup4Eclipse/mac/recent/

        cp       ./projects/IAR/bkup4Eclipse/recent/.compiler  ./
        cp       ./projects/IAR/bkup4Eclipse/recent/.cproject  ./
        cp       ./projects/IAR/bkup4Eclipse/recent/.project   ./
        cp -r    ./projects/IAR/bkup4Eclipse/recent/.settings  ./
        cp -r    ./projects/IAR/bkup4Eclipse/recent/settings   ./
        cat      ./.compiler
############################################################
    elif [ $line == "ubuntu" ];then 
        echo "ubuntu"
    else 
        echo "I don't know the correct compiler to manipulate"
    fi

else 
    echo "not supported"
fi  

done

