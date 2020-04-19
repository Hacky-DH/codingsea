#!/bin/bash -e
# copy and make code from Johnson9009
# requre a number
# make in MSYS

source ~/.bash_profile
basepath=$(cd `dirname $0`; pwd)
template_cmake=$basepath/template.cmake
if [[ ! -e $template_cmake ]];then
	echo "Tempate cmake file $template_cmake is not found!"
	exit 2
fi
num=$1

from_dir=$(realpath $basepath/../../Johnson9009/CodingInterviewChinese2/${num}_*/)
from_dirs=$(ls -d $from_dir 2>/dev/null)
if [[ $? -ne 0 ]];then
	echo "No files found in $from_dir"
	exit 2
fi
for dir in $from_dirs;do
	name=$(basename $dir)
	if [[ ! -e $name ]];then
		echo "$name found, copying"
		/bin/cp -af $dir .
		# remove vs files
		/bin/rm -fr $dir/*.vcxproj*
		echo "$name copy done"
	fi
	echo "$name making"
	/bin/cp -f $template_cmake $name/source.cmake
	mkdir -p $basepath/build
	pushd $basepath/build
	cmake -G "MSYS Makefiles" ..
	make
	popd
	/bin/rm -fr $name/source.cmake
	echo "$name make done"
done
