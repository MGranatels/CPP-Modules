#!/bin/bash

# Get user input for class name
echo "Enter class name:"
read class_name

# Create header file
header_filename="$class_name.hpp"
touch "$header_filename"

# Write include statements and preprocessor directives to header file
echo "#ifndef $(echo $class_name | tr '[:lower:]' '[:upper:]')_HPP" >> "$header_filename"
echo "#define $(echo $class_name | tr '[:lower:]' '[:upper:]')_HPP" >> "$header_filename"
echo "" >> "$header_filename"
echo "#include <iostream>" >> "$header_filename"
echo "#include <string>" >> "$header_filename"
echo "" >> "$header_filename"

# Write class declaration to header file
echo "class $class_name {" >> "$header_filename"
echo "public:" >> "$header_filename"

# Add member variables
echo "Add member variables (enter q to quit):"
while true; do
    echo "Is the variable private, public or protected?"
    read access_specifier
    if [ "$access_specifier" == "q" ]; then
        break
    fi
    echo "Enter the variable name:"
    read variable_name
    echo "Enter the variable type:"
    read variable_type
    echo "    $access_specifier:"
    echo "    $variable_type $variable_name;" >> "$header_filename"
done

# Write member functions to header file
echo "" >> "$header_filename"
echo "    $class_name();" >> "$header_filename"
echo "    $class_name(const $class_name& other);" >> "$header_filename"
echo "    $class_name& operator=(const $class_name& other);" >> "$header_filename"
echo "    ~$class_name();" >> "$header_filename"
echo "" >> "$header_filename"
echo "    // Member function declarations here" >> "$header_filename"
echo "};" >> "$header_filename"

# Write #endif directive to header file
echo "" >> "$header_filename"
echo "#endif // $class_name"_HPP >> "$header_filename"

# Create source file
source_filename="$class_name.cpp"
touch "$source_filename"

# Write include statement to source file
echo "#include \"$header_filename\"" >> "$source_filename"
echo "" >> "$source_filename"

# Write constructor, copy constructor, copy assignment operator, and destructor definitions to source file
echo "$class_name::$class_name() {" >> "$source_filename"
echo "}" >> "$source_filename"
echo "" >> "$source_filename"

echo "$class_name::$class_name(const $class_name& copy) {" >> "$source_filename"
echo "    // Copy constructor code here" >> "$source_filename"
echo "}" >> "$source_filename"
echo "" >> "$source_filename"

echo "$class_name& $class_name::operator=(const $class_name& assign) {" >> "$source_filename"
echo "    this-> = other.  " >> "$source_filename"
echo "        // Copy assignment operator code here" >> "$source_filename"
echo "    return *this;" >> "$source_filename"
echo "}" >> "$source_filename"
echo "" >> "$source_filename"

echo "$class_name::~$class_name() {" >> "$source_filename"
echo "    // Destructor code here" >> "$source_filename"
echo "}" >> "$source_filename"

# Print confirmation message
echo "Class $class_name successfully created!"