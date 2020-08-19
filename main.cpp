#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
#include <vector>
#include<iterator>
void readInFile(std::vector<std::string>vector, std::string filename)
{
	std::ofstream out(filename);
	std::copy(vector.begin(), vector.end(), std::ostream_iterator<std::string>(out,"\n"));
}
void readFile(std::vector<std::string>&vector, std::string filename)
{
	std::ifstream in(filename);
	std::string str;
	std::stringstream ss(str);
	while (std::getline(in,str))
	{
		vector.push_back(str);
	}
	/*std::istream_iterator<std::stringstream>iter(in), current;

	std::copy(iter, current, std::back_inserter(vector));*/
}
//std::string removeSubstrs(std::string &s,	const std::string& w)
//{
//	auto size = w.length();
//
//	for (auto i = s.find(w); i != std::string::npos; i = s.find(w))
//	{
//		
//		
//			s.erase(i, size);
//	
//			
//	}
//	return s;
//}
std::string removeWord(std::string& string,  std::string& word)
{
	for (size_t i = 0; i < word.size(); i++)
	{
		word[i]=tolower(word[i]);

	}
	std::istringstream iss(string);
	std::string str;
	
	while (iss >> string)
	{
		auto temp = string;
		for (size_t i=0; i < temp.size(); i++)
		{
			temp[i] =tolower(temp[i]);
			
		}
		if (temp != word)
		{

			str += (string + " ");
		}

	}
	return str;
}
void removeWordFromVector(std::vector<std::string>&vector, std::string& word)
{
	for (size_t i = 0; i < vector.size(); ++i)
	{
		vector[i] = removeWord(vector[i], word);
	}
//	for(auto cur=vector.begin();  cur< vector.end(); cur++)
//	{
//		vector.insert(cur, removeWord(*cur, word));
//	}
}
void SortVector(std::vector<std::string>& vector)
{
	std::sort(vector.begin(), vector.end(), [](auto l, auto r)
		{


			return std::lexicographical_compare(std::begin(l), std::end(l), std::begin(r), std::end(r),
				[](char cl, char cr) { return tolower(cl) < tolower(cr); });


		});
}
int main()
{
	std::vector<std::string>vector;
	readFile(vector, "Text.txt");
	std::cout << "Enter  word for remove " << std::endl;
	std::string word;
	std::cin >> word;
	removeWordFromVector(vector, word);

	
	std::copy(vector.begin(), vector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout <<std::endl <<"sort----------------"<< std::endl;
	SortVector(vector);
	std::copy(vector.begin(), vector.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	readInFile(vector, "Output.txt");


	return 0;

}