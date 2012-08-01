// tinyXmlTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//#define TIXML_USE_STL

#include <iostream>
#include <sstream>
using namespace std;
#include "tinyxml.h"


int _tmain(int argc, _TCHAR* argv[])
{
//	printf( "okk\n" );

	const char* demoStart =
		"<?xml version=\"1.0\"  standalone='no' >\n"
		"<!-- Our to do list data -->"
		"<ToDo>aaa</ToDo>"
	"<Test>"
		"<attr name=\"ok\" />"
		"</Test>";

	TiXmlDocument doc( "demotest.xml" );
	doc.Parse( demoStart );

	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemEl2ement = 0;

	node = doc.FirstChild( "ToDo" );
	assert( node );
	todoElement = node->ToElement();
	assert( todoElement  );
	string v = todoElement->Value();
	string str = todoElement->GetText();
	TiXmlNode *testNode = doc.FirstChild( "Test" );
	TiXmlNode *attrNode = testNode->FirstChild( "attr" );
	TiXmlElement *attrEl = attrNode->ToElement();

	string str2 = attrEl->Attribute("name");

	doc.Print( stdout );

	TiXmlPrinter printer;
	printer.VisitEnter(doc);
	const char *pp = printer.CStr();
/**/

/*
	// 생성
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
	TiXmlElement * element = new TiXmlElement( "Hello" );
	TiXmlText * text = new TiXmlText( "World" );

	TiXmlElement *attr = new TiXmlElement( "attr" );
	element->LinkEndChild(attr);
	TiXmlText * text2 = new TiXmlText( "attr name" );
	attr->LinkEndChild( text2 );
	attr->SetAttribute( "name", "aaa" );
//	TiXmlNode * node = new TiXmlNode( NodeType

	element->LinkEndChild( text );
	doc.LinkEndChild( decl );
	doc.LinkEndChild( element );
	//doc.Print( stdout );
	const char *pp = doc.Parse(NULL);
	TiXmlElement *proot = doc.RootElement();
//	TiXmlText rtxt;
	//proot->Print(
	std::string str;
	str << doc;

//	const char * pp = doc.EncodeString(

	cout << str;

// 	dump_to_stdout( &doc );
// 	doc.SaveFile( "madeByHand.xml" );
/**/

	return 0;
}

