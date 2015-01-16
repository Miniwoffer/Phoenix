/*
* xml_parser.cpp
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#include "xml_parser.h"
#include <iostream>
namespace Phoenix{
	XML_Parser::XML_Parser(const std::string &filename)
	{
		using boost::property_tree::ptree;
		ptree pt;
		boost::property_tree::read_xml(filename, pt);

	}

	XML_Parser::~XML_Parser()
	{

	}
}
