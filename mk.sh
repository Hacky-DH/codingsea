#!/bin/bash
# make dirs in MSYS
# requre a prefix
# make all match *_* if prefix=all
# if the dir is not found, try to copy it from Johnson9009

source ~/.bash_profile
basepath=$(cd `dirname $0`; pwd)

# check template cmake file
template_cmake=$basepath/template.cmake
if [[ ! -e $template_cmake ]];then
	echo "Tempate cmake file $template_cmake is not found!"
	exit 2
fi

prefix=$1

# check current dir
all_dirs=$(ls -d ${prefix}_* 2>/dev/null)
if [[ -z $all_dirs ]];then
	if [[ $prefix = all ]];then
		# find all dirs
		all_dirs=$(ls -d *_* 2>/dev/null)
		if [[ -z $all_dirs ]];then
			echo "no dir match with *_*"
			exit 2
		fi
	else
		# find in Johnson9009 dir
		from_dir=$(realpath $basepath/../../Johnson9009/CodingInterviewChinese2/${prefix}_*/)
		all_dirs=$(ls -d $from_dir 2>/dev/null)
		if [[ -z $all_dirs ]];then
			echo "No dir match with $from_dir"
			exit 2
		fi
	fi
fi

# copy and make
for dir in $all_dirs;do
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
