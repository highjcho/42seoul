{
    "OCCP": {
        "prefix": "#if", 
        "body": [
            "#ifndef ${1:${TM_FILENAME_BASE}}_H",
            "# define ${1:${TM_FILENAME_BASE}}_H",
            "",
            "class ${1:${TM_FILENAME_BASE}}{",
            "\tprivate:",
            "\t\t${2:${TM_DATA}};",
            "\tpublic:",
            "\t\t${1:${TM_FILENAME_BASE}}();",
            "\t\t${1:${TM_FILENAME_BASE}}(const ${1:${TM_FILENAME_BASE}}& obj);",
            "\t\t${1:${TM_FILENAME_BASE}}(${2:${TM_DATA}});",
            "\t\t~${1:${TM_FILENAME_BASE}}();",
            "",
            "\t\t${1:${TM_FILENAME_BASE}}& operator=(const ${1:${TM_FILENAME_BASE}} &obj);",
            "\t\t${4}",
            "};",
            "",
            "#endif"
        ],
        //${TM_FILENAME_BASE/([A-Z])/${1:/downcase}/} 첫 글자를 소문자로 만들기
        //${1:${TM_FILENAME_BASE/[\\.]/_/g}} .을 _로 바꾸기
        "description": "make OCCP form of {FILE_NAME}.hpp"
    },
    "HPP": {
        "prefix": "HPP",
        "body": [
            "#ifndef ${TM_FILENAME/$|(^|[.])([^.]+)/${1:+_}${2:/upcase}/g}",
            "# define ${TM_FILENAME/$|(^|[.])([^.]+)/${1:+_}${2:/upcase}/g}",
            "",
            "class ${1:${TM_FILENAME_BASE/[\\.]/_/g}}",
            "{",
            "private:",
            "\t/* data */",
            "",
            "public:",
            "\t${1:${TM_FILENAME_BASE/[\\.]/_/g}}();",
            "\t${1:${TM_FILENAME_BASE/[\\.]/_/g}}(const ${1:${TM_FILENAME_BASE/[\\.]/_/g}}& ref);",
            "\t~${1:${TM_FILENAME_BASE/[\\.]/_/g}}();",
            "",
            "\t${1:${TM_FILENAME_BASE/[\\.]/_/g}}&\toperator=(const ${1:${TM_FILENAME_BASE/[\\.]/_/g}}& ref);",
            "};",
            "",
            "#endif",
            ""
        ],
        "description": "make class of {FILE_NAME}.hpp"
    },
    "CPP": {
        "prefix": "CPP",
        "body": [
            "#include <iostream>",
            "#include \"${TM_FILENAME_BASE}.hpp\"",
            "",
            "${1:${TM_FILENAME_BASE/[\\.]/_/g}}::${1:${TM_FILENAME_BASE/[\\.]/_/g}}(){",
            "}",
            "",
            "${1:${TM_FILENAME_BASE/[\\.]/_/g}}::${1:${TM_FILENAME_BASE/[\\.]/_/g}}(const ${1:${TM_FILENAME_BASE/[\\.]/_/g}}& obj){",
            "\t*this = obj;",
            "}",
            "",
            "${1:${TM_FILENAME_BASE/[\\.]/_/g}}::~${1:${TM_FILENAME_BASE/[\\.]/_/g}}()",
            "{",
            "}",
            "",
            "${1:${TM_FILENAME_BASE/[\\.]/_/g}}&\t${1:${TM_FILENAME_BASE/[\\.]/_/g}}::operator=(const ${1:${TM_FILENAME_BASE/[\\.]/_/g}}& obj){",
            "\tif (this != &obj)",
            "\t{",
            "\t\t",
            "\t}",
            "\treturn (*this);",
            "}",
            ""
        ],
        "description": "make Orthodox canonical of {FILE_NAME.cpp}"
    },
    "MAIN": {
        "prefix": "MAIN",
        "body": [
            "#include <iostream>",
            "#include ${1:header}",
            "",
            "int main(${2:args}){",
            "\t${3:body}",
            "\treturn (0);",
            "}",
        ],
        "description": "make main.cpp"
    }

}