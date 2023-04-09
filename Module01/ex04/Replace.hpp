#ifndef HEADER_
#define HEADER_

# include <iostream>
# include <fstream>
# include <string>

class Replace {
private:
	static int	text_size;
	std::string	_replac;
	std::string	_search;
	std::string	_file_path;
	std::string	seek_destroy(std::string line);
	void 		get_file_size(std::ifstream &file, std::string line);
	void		write_text(std::string *text);
	void		write_file(std::string new_file);

public:
    Replace(std::string replac, std::string search, std::string file_path);
    ~Replace();

	void		read_file();
    // Member function declarations here
};

#endif // HEADER_
