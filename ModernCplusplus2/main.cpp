#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file_stream.h"
#include "xml_paser.h"
#include "tinyxml_test.h"

int main()
{		

	TinyXMLTest();
	/*XMLTest();*/

}

//DOM (Document Object Model)
//
//	W3C
//		XML - eXtensible Markup Language
//			HTML - Hyper Text Markup Language
//
//	<monster>
//			<name> 슬라임 </name>
//			<status>
//			<level>10</level>
//			<hp>10</10>
//			<mp>10</hp>
//		</status>
//		<items>
//			<item>
//				<name>단검</name>
//				<price>100</price>
//			</item>
//			<item>
//			<name>슬라임조각</name>
//			< price>100</price >
//			</item>
//		</items>
//	</monster>
//
//	ORACLE(Java)
//		Json - Javascript object Notation
//	{
//		"name" : "늑대",
//		"status" :
//		{
//			"level":10,
//			"hp":10,
//			"mp":10
//		},
//		"items" :
//		[
//			{"name" : "발톱", "price" : 10},
//			{"name" : "가죽", "price" : 100}
//		]
//	}
//
//	저작권 vs 오픈 소스(Open Source)
//
//			GPL		 general public license			라이선스 및 저작권 명시
//												모든 코드를 GPL로 공개
//
//			LGPL	 Lesser Genneral Public License 단순 사용은 공개하지 않아도 됨
//
//			BSD		Berkely Software Distribution	미국 정부가 버클리대와 함께 운영하는 오픈소스
//
//			arrayApache License						아파치 소유한 라이선스
//													자사제품 보호 조항
//			MIT		MIT License
//
//			------------------------------
//
//			WTFPL	WTF Public License
//			Beerware
//			Cofeeware

//	XML
//		declaration
//			<? ~ ?>
//		tag
//			<object> 원소 </object>	
//			<object/> : 빈 태그(원소가 없는 태그)
// 
//		elememt
//			시작 태그 ~ 끝 태그 사이의 내용
//			<text>안녕하세요</text>
//			<text>
//				<image/>
//			</text>
//		property
//		<monster name="WOLF" level="10" hp="10"></monster>
// 
// JSON
//