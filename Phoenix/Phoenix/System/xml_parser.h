/*
 * Copyright 2014, Odin Hultgren Van Der Horst
 */

#ifndef XML_PARSER_H
#define XML_PARSER_H
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>

class XML_Parser
{
public:
XML_Parser(const std::string &filename);
~XML_Parser();
private:
};

#endif // XML_PARSER_H
