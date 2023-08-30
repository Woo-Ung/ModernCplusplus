#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


//������ġ
//	1�� ��� ��ġ : RAM
//		�ֹ߼�
//		Random Access
//
//	2�� ��� ��ġ : HDD
//		���ֹ߼�
//		Sequential (SSD ����)
//
//File Stream
//	File Stream Object
//		std::ifstream
//		���� �б�
//
//	File Operation
//
//	Close()
// 
//	���� üũ
//		goodbit - ���� ����
//		eofbit	- ehd of File (������ �ƴ� ���� ����)
//		failbit	- �� �̽�
//		badbit	- �ɰ��� ����
//
// OS�� File System
//	Window
//		C:\Users\fightdog\Lesson\File\Data
//		"C:\\Users\\"
//		R"(C;\Users\)"
//
//	Unix
//		Users/fightdog/Lesson/File/Data

//path��Ģ
//	absolute path ���� ���
//		C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem/Data/SimpleData.txt
// 
//	relative ��� ���
//		�� ��ġ : C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem
//		/Data/SimpleData.txt
//
//	Current Directory
//	

struct Header
{
	int version{ 1 };
	int itemCount{};
};

class Monster
{
private:
	std::string mName{};
	int mLevel{};
	int mHP{};
	int mMP{};

public:
	Monster() = default;
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{

	}

	void SetName(std::string name) { mName = name; }
	void SetLevel(int level) { mLevel = level; }
	void SetHP(int hp) { mHP = hp; }
	void SetMP(int mp) { mHP = mp; }

	void ReadText(std::istream& is)
	{
		std::string line;

		try
		{
			std::getline(is, line, ',');
			mName = line;
			std::getline(is, line, ',');
			mLevel = std::stoi(line);
			std::getline(is, line, ',');
			mHP = std::stoi(line);
			std::getline(is, line);
			mMP = std::stoi(line);
		}
		catch (std::exception e)
		{
			std::cerr << "���� ������ �ùٸ��� �ʽ��ϴ�" << std::endl;
		}
	}

	void WriteText(std::ostream& os)
	{
		os << mName << "," << mLevel << "," << mHP << "," << mMP << std::endl;
	}

	void WriteBinary(std::ostream& os)
	{
		int nameLen = static_cast<int>(mName.size());
		os.write(reinterpret_cast<char*>(&nameLen), sizeof(int));
		os.write(mName.c_str(), nameLen);
		os.write(reinterpret_cast<char*>(&mLevel), sizeof(int));
		os.write(reinterpret_cast<char*>(&mHP), sizeof(int));
		os.write(reinterpret_cast<char*>(&mMP), sizeof(int));
	}

	void ReadBinary(std::istream& is)
	{
		int nameLen{};
		is.read(reinterpret_cast<char*>(&nameLen), sizeof(int));
		//is.read(reinterpret_cast<char*>(&mName), nameLen);
		is.read(&mName[0], nameLen);
		is.read(reinterpret_cast<char*>(&mLevel), sizeof(int));
		is.read(reinterpret_cast<char*>(&mHP), sizeof(int));
		is.read(reinterpret_cast<char*>(&mMP), sizeof(int));
	}

	friend std::ostream& operator << (std::ostream& os, Monster m)
	{
		m.WriteText(os);
		m.WriteBinary(os);
		return os;
	}

	friend std::istream& operator >> (std::istream& is, Monster& m)
	{
		m.ReadText(is);
		m.ReadBinary(is);
		return is;
	}
};

bool LoadFile(const std::string& filename, std::vector<Monster>& monsters)
{
	//file stream
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	//file operation
	try
	{
		ifs.open(filename);

		char ch;
		std::string line;

		std::getline(ifs, line);
		while (!ifs.eof())
		{
			Monster m;
			//// Parsing - split by delimeter
			//std::getline(ifs, line,',');
			//m.SetName(line);
			//std::getline(ifs, line, ',');
			//m.SetLevel(std::stoi(line));
			//std::getline(ifs, line, ',');
			//m.SetHP(std::stoi(line));
			//std::getline(ifs, line);
			//m.SetMP(std::stoi(line));

			m.ReadText(ifs);

			monsters.push_back(m);
		}
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ifs.close();
		return false;
	}

	//while (ifs >> ch)
	//{
	//	std::cout << ch;
	//}
	//while (true)
	//{
	//	ifs >> ch;
	//	if (ifs.eof())		// eof = end of file
	//	{
	//		std::cerr << "end of file!! <<std::endl;
	//		break;
	//	}
	// 
	// if (ifs.file())
	//	{
	//		std::cerr << "logical error! <<std::endl;
	//		break;
	//	}
	// 
	// if (ifs.bad())		
	//	{
	//		std::cerr << "fatal error! <<std::endl;
	//		break;
	//	}
	// 
	//	std::cout << ch;
	//}

	//while (ifs.get(ch))
	//{
	//	std::cout << ch;
	//}

	//char buffer[1024];
	//while (ifs.getline(buffer, 1024))
	//{
	//	std::cout << buffer << std::endl;
	//}
	// 		
	return true;
}

bool SaveFile(std::string filename, std::vector<Monster>& monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit);

	try
	{
		ofs.open(filename);

		ofs << "--- MONSTER DATA ---" << std::endl;
		for (auto& e : monsters)
		{
			e.WriteText(ofs);
		}
		ofs.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ofs.close();
		return false;
	}

	return true;
}

bool SaveFileBinary(std::string filename, std::vector<Monster>& monsters)
{
	std::ofstream ostream;

	ostream.exceptions(std::ofstream::badbit);

	try
	{
		ostream.open(filename, std::ofstream::binary);

		Header header{ 1, static_cast<int>(monsters.size()) };
		ostream.write(reinterpret_cast<char*>(&header), sizeof(Header));
		for (auto& e : monsters)
		{
			e.WriteBinary(ostream);
		}

		ostream.close();
	}

	catch (std::ofstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ostream.close();
		return false;
	}

	return true;
}

bool LoadFileBinary(std::string filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		ifs.open(filename, std::ifstream::binary);

		Header header;
		ifs.read(reinterpret_cast<char*>(&header), sizeof(Header));
		for (int i = 0; i < header.itemCount; ++i)
		{
			Monster m;
			m.ReadBinary(ifs);
			monsters.push_back(m);
		}

		ifs.close();
	}

	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ifs.close();
		return false;
	}

	return true;
}

void FileTest()
{
	std::vector<Monster> monsters;

	// path (directory or folder, file)
	LoadFile("C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem/Data/SimpleData.txt", monsters);

	//for (const auto& e : monsters)
	//{
	//	std::cout << e << std::endl;
	//}

	monsters.push_back(Monster("ORC", 15, 15, 15));

	SaveFile("C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem/Data/SimpleData_copy.txt", monsters);

	///////////////////////////////////////

	SaveFileBinary("C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem/Data/SimpleData.bin", monsters);
	std::vector<Monster> v;
	LoadFileBinary("C:/Users/ehddn/Desktop/C#/ModernCplusplus/FileSystem/Data/SimpleData.bin", v);
}

//Byte Order
//
//	int x = 1;
//	0x 00 00 00 01
//
//	Bing Endian						Little Endian
//	Most Significant Bit (MSB)		Least Significant Bit (LSB)
//	�����͸� ������� ���			�����͸� �������� ���
//	00 00 00 01						01 00 00 00
//	��������� ����					��������� ����
//	�񱳿����� ����					�񱳿����� ����
//	Ÿ�� ��ȯ�� ��ƴ�				Ÿ�� ������ ����
//	���α׷��Ӱ� ������� ����		����װ� ������
//
//	������(����)					������
//	�ȵ���̵�						������
//	����(��Ʈ��ũ ��������)			Ŭ���̾�Ʈ