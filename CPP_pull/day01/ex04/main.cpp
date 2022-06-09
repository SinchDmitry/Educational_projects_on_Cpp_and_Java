#include "Replace.hpp"

void	printUsage(void)
{
	std::cout << "./cppSed fileName stringToReplace replacement" << std::endl;
}
int	printError(std::string errorMsg)
{
	if (errorMsg != "")
		std::cerr << "Error: " << errorMsg << std::endl;
	printUsage();
	return (1);
}
int	main(int argc, char **argv)
{
	Replace sed;
	if (argc != 4)
		return (printError("Wrong number of arguments"));
	if (!sed.open(argv[1]))
		return (printError(""));
	if (!sed.swap(argv[2], argv[3]))
		return (printError(""));
}
