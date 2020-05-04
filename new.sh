#!/bin/bash

# create a new problem
# make dirs and files

dir_name=$1
name=${2:-${dir_name#*_}}
path=$dir_name/$name.cpp

mkdir -pv $dir_name

cat << EOF > $path
/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

int main(int argc, char* argv[]) {
	return 0;
}
EOF

echo "Created $path done"
