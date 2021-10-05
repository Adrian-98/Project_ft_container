#!/bin/bash


san=""
if [ ${@: -1} = "san" ]
then
	san="-fsanitize=address"
fi

if [ $# = 0 ] || [ $1 = "1" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	rm -f a.out ft.bin std.bin
	c++ tester1.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester1.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 01 Vector test 1 vvvvvvvv"
	diff ft std

fi

if [ $# =  0 ] || [ $1 = "2" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then
	rm -f a.out ft.bin std.bin
	c++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
			cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi


	echo "vvvvvvvv DIFF 02 Vector test 2 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "3" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester3.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester3.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 03 Vetor test 3  vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "4" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester4.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester4.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 04 Vector test 4 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "5" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester5.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester5.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 05 Vector test 5 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "11" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester11.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester11.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 11 Map test 1 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "12" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester12.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester12.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 12 Map test 2 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "13" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester13.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester13.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 13 Map test 3 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "14" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester14.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester14.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 14 Map test 4 vvvvvvvv"
	diff ft std

fi
if [ $# = 0 ] || [ $1 = "15" ] || [ $1 = "map" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester15.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester15.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 15 Map test 5 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "21" ] || [ $1 = "stack" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester21.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester21.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 21 Stack test 1 vvvvvvvv"
	diff ft std

fi

#test 22 set

if [ $# = 0 ] || [ $1 = "22" ] || [ $1 = "stack" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester22.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester22.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFF 22 Stack test 2 vvvvvvvv"
	diff ft std

fi

