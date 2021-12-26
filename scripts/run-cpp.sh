#!/usr/bin/env bash

FILE_DIR=$1
FILE_BASE=$2
FILE_EXT=$3
LOG_MODE=$4

WORKSPACE="$(pwd)"
SOURCE="${FILE_DIR}/${FILE_BASE}.cpp"
BIN="${WORKSPACE}/bin/${FILE_BASE}"
OUT="${WORKSPACE}/out/${FILE_BASE}.out"
INCLUDE="${WORKSPACE}/headers/"

if [ "$FILE_EXT" = ".cpp" ]; then
    cd $FILE_DIR

    # Compile
    # g++ -I "${INCLUDE}" "$SOURCE" -o "${BIN}"
    # Run
    if [ $? = 0 ]; then
        if [ "$LOG_MODE" = "ON" ]; then
            "${BIN}" > "${OUT}"
        else
            "${BIN}"
        fi
    fi

    cd $WORKSPACE
else
    echo "Not a .cpp file!"
fi

