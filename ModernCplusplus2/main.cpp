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
//			<name> ������ </name>
//			<status>
//			<level>10</level>
//			<hp>10</10>
//			<mp>10</hp>
//		</status>
//		<items>
//			<item>
//				<name>�ܰ�</name>
//				<price>100</price>
//			</item>
//			<item>
//			<name>����������</name>
//			< price>100</price >
//			</item>
//		</items>
//	</monster>
//
//	ORACLE(Java)
//		Json - Javascript object Notation
//	{
//		"name" : "����",
//		"status" :
//		{
//			"level":10,
//			"hp":10,
//			"mp":10
//		},
//		"items" :
//		[
//			{"name" : "����", "price" : 10},
//			{"name" : "����", "price" : 100}
//		]
//	}
//
//	���۱� vs ���� �ҽ�(Open Source)
//
//			GPL		 general public license			���̼��� �� ���۱� ���
//												��� �ڵ带 GPL�� ����
//
//			LGPL	 Lesser Genneral Public License �ܼ� ����� �������� �ʾƵ� ��
//
//			BSD		Berkely Software Distribution	�̱� ���ΰ� ��Ŭ����� �Բ� ��ϴ� ���¼ҽ�
//
//			arrayApache License						����ġ ������ ���̼���
//													�ڻ���ǰ ��ȣ ����
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
//			<object> ���� </object>	
//			<object/> : �� �±�(���Ұ� ���� �±�)
// 
//		elememt
//			���� �±� ~ �� �±� ������ ����
//			<text>�ȳ��ϼ���</text>
//			<text>
//				<image/>
//			</text>
//		property
//		<monster name="WOLF" level="10" hp="10"></monster>
// 
// JSON
//