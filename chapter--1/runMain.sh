#!/bin/bash

CCX=g++
EXEC=main
SRC=main.cpp

if [ "$SRC" -nt "$EXEC" ]
then
        echo "Build $EXEC ..."
        $CCX -o $EXEC $SRC
fi

start_time=$(date +%3N)

RES=`./$EXEC`
echo "$RES"

end_time=$(date +%3N)

echo "Time elapsed: $(($end_time - $start_time)) milliseconds"