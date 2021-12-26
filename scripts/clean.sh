#!/usr/bin/env bash

cd "$(dirname $0)"

# Delete binary files
cd ../bin
find . -type f ! -name ".gitkeep"  -delete

# Delete output files
cd ../out
find . -type f ! -name ".gitkeep"  -delete
