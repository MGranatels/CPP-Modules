#include "Replace.hpp"

Replace::Replace(std::string replac, std::string search, std::string file_path) {
	this->_replac = replac;
	this->_search = search;
	this->_file_path = file_path;
}

Replace::~Replace() {
}

int Replace::text_size = 0;

void	Replace::read_file()
{
	int			i;

	std::string line;
	std::ifstream file(this->_file_path.c_str());
	if (!file.is_open())
	{
		std::cout << "Failed to open file!" << std::endl;
		return ;
	}
	this->get_file_size(file, line);
	std::string *file2 = new std::string[this->text_size];
	i = 0;
	while (std::getline(file, line, '\n'))
	{
		file2[i] = seek_destroy(line);
		i++;
	}
	this->write_text(file2);
	file.close();
	delete [] file2;
}

std::string	Replace::seek_destroy(std::string line)
{
	std::size_t pos;

	pos = 0;
	while (1)
	{
		pos = line.find(this->_search);
		if (pos == std::string::npos)
			break ;
		line.erase(pos, this->_search.length());
		line.insert(pos, this->_replac);
	}
	return (line);
}

void		Replace::write_text(std::string *text)
{
	std::ofstream outFile("Altered.replace");
	if (!outFile.is_open()){
		std::cerr << "Error opening File" << std::endl;
		return ;
	}
	for (int i = 0; i < this->text_size; i++){
		outFile << text[i] << std::endl;
	}
}

void	Replace::get_file_size(std::ifstream &file, std::string line)
{
	while (std::getline(file, line))
		this->text_size++;
	file.clear();
	file.seekg(0, std::ios::beg);
}
