/*
* xml_parser.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef XML_PARSER_EXPORTS
#define XML_PARSER_API __declspec(dllexport) 
#else
#define XML_PARSER_API __declspec(dllimport) 
#endif
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
namespace Phoenix{
	class XML_PARSER_API XML_Parser
	{
	public:
		XML_Parser(const std::string &filename);
		~XML_Parser();
	private:
	};
}
