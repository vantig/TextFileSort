#include"Header.h"
int main()
{
	std::vector<std::string>vector;
	
	std::cout << "Enter  word for remove " << std::endl;
	std::string word;
	std::cin >> word;
	readFile(vector, "Text.txt");
	removeWordFromVector(vector, word);

	
	/*std::copy(vector.begin(), vector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout <<std::endl <<"sort----------------"<< std::endl;*/
	SortVector(vector);
	std::copy(vector.begin(), vector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	readInFile(vector, "Output.txt");


	return 0;

}