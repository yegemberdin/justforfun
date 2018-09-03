#include <iostream>
using namespace std;
find(node,value){
	while(true)
		if (node.value==value)
			return (true);
		node=node.next;
		if(node==NULL)
			return (false);

}
