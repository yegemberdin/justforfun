#include <iostream>
using namespace std;
find(node,value){
	if node==NULL
		return false;
	if node.value==value
		return true;
	if value>node.value
		return find(node.right.value);

	return find(node.left.value);
}