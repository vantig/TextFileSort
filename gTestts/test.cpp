#include "pch.h"
#include"E:\VisualStudio Projects\TextFileSort\Header.h"

TEST(TCheckFile, isOpenIn) {
	std::ifstream inv("E:\\VisualStudio Projects\\TextFileSort\\Text.txt");
	
	ASSERT_EQ(1, inv.is_open());
}


TEST(TCheckFile, isOpenOut) {
	std::ofstream outv;
	outv.open("E:\\VisualStudio Projects\\TextFileSort\\Output.txt");
	ASSERT_EQ(1, outv.is_open());
}

TEST(CheckFile, IsEmpty) {
	std::vector<std::string> vec;
	readFile(vec,"E:\\VisualStudio Projects\\TextFileSort\\Text.txt");
	ASSERT_EQ(0, vec.empty());
}

TEST(CheckString, DeleteWord) {
	std::string str;
	str = removeWord("HI hi hi  ho .Yo hi ho .","hi");
	EXPECT_EQ(str, "ho .Yo ho . ");

}


TEST(CheckText, DeleteWord) {
	std::vector<std::string> vec{ "Hi","hi","HI" };
	std::string str("hi");
	removeWordFromVector(vec, str);
	EXPECT_EQ(1, vec.empty());
}


