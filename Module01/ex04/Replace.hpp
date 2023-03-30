#ifndef HEADER_
#define HEADER_

# include <iostream>
# include <fstream>
# include <string>

class Replace {
private:
	std::string	seek_destroy(std::string line);
	static int	text_size;
	void 		get_file_size(std::ifstream &file, std::string line);
	void		write_text(std::string *text);

public:

    Replace();
    ~Replace();

	std::string	replac;
	std::string	search;
	std::string	file_path;
	void		read_file();
	void		write_file(std::string new_file);
    // Member function declarations here
};

#endif // HEADER_
