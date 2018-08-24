#!/bin/bash
source env.bash
for file in ./sync*
do
	if test -d $file
	then 
        echo " Working on $file " 
		TARGET=dusg2 bitbake ${file##*/} >compilelog/${file##*/}32.log
        if test -n|grep ERROR compilelog/${file##*/}32.log
        then
            grep ERROR compilelog/${file##*/}32.log>compilelog/ERROR_${file##*/}32.log
        else
		grep WARNING compilelog/${file##*/}32.log>compilelog/Warning_${file##*/}32.log
        fi

		TARGET=dusg3 bitbake ${file##*/} >compilelog/${file##*/}64.log
        if test -n|grep ERROR compilelog/${file##*/}64.log
        then
            grep ERROR compilelog/${file##*/}64.log>compilelog/ERROR_${file##*/}64.log
        else
		grep WARNING compilelog/${file##*/}64.log>compilelog/Warning_${file##*/}64.log	
        fi
	fi
done