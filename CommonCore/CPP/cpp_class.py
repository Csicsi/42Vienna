import os

def get_class_name():
	return input("Enter class name: ")

def get_class_attributes():
	print("Enter private attributes (e.g., 'int age, std::string name'). Leave empty for no attributes.")
	attributes_input = input("Attributes: ")
	attributes = [attr.strip() for attr in attributes_input.split(",") if attr.strip()]
	return attributes

def create_directories(includes_dir, srcs_dir):
	os.makedirs(includes_dir, exist_ok=True)
	os.makedirs(srcs_dir, exist_ok=True)

def generate_hpp_file(class_name, attributes, includes_dir):
	attributes_str = ";\n\t".join(attributes) if attributes else "// No private members"
	includes = "#include <iostream>\n"
	if any("std::string" in attr for attr in attributes):
		includes += "#include <string>\n"

	hpp_content = f"""#ifndef {class_name.upper()}_HPP
#define {class_name.upper()}_HPP

{includes}
class {class_name} {{
public:
	{class_name}();
	~{class_name}();
	{class_name}(const {class_name} &other);
	{class_name} &operator=(const {class_name} &other);

private:
	{attributes_str};
}};

#endif
"""
	hpp_path = os.path.join(includes_dir, f"{class_name}.hpp")
	with open(hpp_path, "w") as hpp_file:
		hpp_file.write(hpp_content)
	print(f"Header file created: {hpp_path}")

def generate_cpp_file(class_name, attributes, srcs_dir):
	copy_assignment_lines = ""
	if attributes:
		for attr in attributes:
			attr_name = attr.split()[-1]
			copy_assignment_lines += f"\t\t{attr_name} = other.{attr_name};\n"

	cpp_content = f"""#include \"{class_name}.hpp\"

{class_name}::{class_name}() {{
	std::cout << "{class_name} default constructor called" << std::endl;
}}

{class_name}::~{class_name}() {{
	std::cout << "{class_name} destructor called" << std::endl;
}}

{class_name}::{class_name}(const {class_name} &other) {{
	std::cout << "{class_name} copy constructor called" << std::endl;
	*this = other;
}}

{class_name} &{class_name}::operator=(const {class_name} &other) {{
	std::cout << "{class_name} assignation operator called"
		<< std::endl;
	if (this != &other) {{
{copy_assignment_lines}\t}}
	return *this;
}}
"""
	cpp_path = os.path.join(srcs_dir, f"{class_name}.cpp")
	with open(cpp_path, "w") as cpp_file:
		cpp_file.write(cpp_content)
	print(f"Source file created: {cpp_path}")

def main():
	"""Main function to generate class files."""
	class_name = get_class_name()
	attributes = get_class_attributes()
	includes_dir = "includes"
	srcs_dir = "srcs"

	create_directories(includes_dir, srcs_dir)
	generate_hpp_file(class_name, attributes, includes_dir)
	generate_cpp_file(class_name, attributes, srcs_dir)

if __name__ == "__main__":
	main()
