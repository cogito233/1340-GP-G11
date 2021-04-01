#!/bin/bash

if [ ! -d ../ncurses ]
then 
    git clone https://github.com/mirror/ncurses.git

    cd ncurses
    mkdir ~/local
    ./configure --prefix ~/local

    make -j
    make -j install
fi

echo "You're all set"