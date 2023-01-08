#!/bin/bash
​
if [ $# -ne 1 ];then
  echo "usage: ./create_class_file.sh [class_name_you_want]"
else
CLASS_NAME=$( echo $1 | tr '[a-z]' '[A-Z]' )
DEFINE_STRING="__"$CLASS_NAME"__"
​
#create target hpp file
cat << EOF >> $1.hpp
#ifndef $DEFINE_STRING
#define $DEFINE_STRING
​
#include <string>
using namespace std;
​
class $1 {
    private :
    protected :
    public :
        $1();
        $1($1 const &other);
        $1& operator=($1 const &other);
        ~$1();
};
​
#endif // $DEFINE_STRING
EOF
​
#create target cpp file
cat << EOF >> $1.cpp
#include "$1.hpp"
#include <string>
#include <iostream>
​
using namespace std;
​
$1::$1() {};
$1::$1($1 const &other) {};
$1 &$1::operator= ($1 const &other) {};
$1::~$1() {};
EOF
fi