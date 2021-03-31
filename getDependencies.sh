#!/bin/bash

if [ ! -d ncurses ]
then 
    echo "Start building dependencies..."
    echo "Start downloading ncurses"
    git clone https://github.com/mirror/ncurses.git
    echo "Downloaded successfully"

    cd ncurses
    echo "Configuring..."
    mkdir ~/local
    ./configure --prefix ~/local

    echo "Installing..."
    make -j
    make -j install
    
fi

echo "You're all set"