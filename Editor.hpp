class Library
{
private:
	std::fstream file;
	std::size_t file_size;
	bool file_open;

public:
	Library(std::string file_path);
	std::size_t size() const;
	void open(std::string file_path);
	void close();
	void edit(std::size_t offset, std::uint8_t value);
	void display(std::ostream &out, std::size_t offset, std::size_t limit);
	~Library();
};

Library::Library(std::string file_path)
	: file(file_path, std::ios::binary | std::ios_base::ate | std::ios::in | std::ios::out)
{
	if (!file.is_open())
	{
		throw std::logic_error("File problem occured");
	}

	file_size = file.tellg();
	file.seekg(0, std::ios_base::beg);
}

std::size_t Library::size() const
{
	return file_size;
}

void Library::open(std::string file_path)
{
	//check if file is already opened
	if (file.is_open())
	{
		return;
	}

	file = std::fstream(file_path, std::ios::binary | std::ios_base::ate | std::ios::in | std::ios::out);
	if (!file.is_open())
	{
		throw std::logic_error("File problem occured");
	}

	file_size = file.tellg();
	file.seekg(0, std::ios_base::beg);
}

void Library::close()
{
	if (file.is_open())
	{
		file.close();
	}
}

void Library::edit(std::size_t offset, std::uint8_t value)
{
	if (offset > file_size)
	{
		throw std::invalid_argument("Position out of range");
	}

	file.seekg(offset, std::ios_base::beg);

	file.write((char *)&value, sizeof(value));
}

void Library::display(std::ostream &out, std::size_t offset, std::size_t limit)
{
	if (offset > file_size)
	{
		throw std::invalid_argument("Position out of range");
	}

	std::size_t cnt = offset;
	int cur;

	while (cnt < limit && cnt < file_size)
	{
		file.read((char *)& cur, 1);
		out << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)cur;

		//out << cur;
		cnt++;
	}
}

Library::~Library()
{
	if (file.is_open())
	{
		file.close();
	}
}