#!/bin/bash


san=""
if [ ${@: -1} = "san" ]
then
	san="-fsanitize=address"
fi

if [ $# = 0 ] || [ $1 = "1" ] || [ $1 = "stack" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	echo "STACK TEST "
	echo "-----------"
	rm -f a.out ft.bin std.bin
	echo "FT::"
	/usr/bin/time clang++ stdtester1.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std
	echo "-----------"
	echo "STD::"
	/usr/bin/time clang++ tester1.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
fi

if [ $# = 0 ] || [ $1 = "1" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	echo
	echo "VECTOR TEST "
	echo "-----------"
	rm -f a.out ft.bin std.bin
	echo "FT::"
	time clang++ stdtester2.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std
	echo "-----------"
	echo "STD::"
	time clang++ tester2.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
fi


if [ $# = 0 ] || [ $1 = "1" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	echo
	echo "MAP TEST "
	echo "-----------"
	rm -f a.out ft.bin std.bin

	echo "FT::"
	time clang++ stdtester11.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std
	echo "-----------"
	echo "STD::"
	time clang++ tester11.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
fi

if [ $# = 0 ] || [ $1 = "1" ] || [ $1 = "map2" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	echo
	echo "MAP TEST2"
	echo "-----------"
	rm -f a.out ft.bin std.bin

	echo "FT::"
	time clang++ stdtester12.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std
	echo "-----------"
	echo "STD::"
	time clang++ tester12.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
fi
