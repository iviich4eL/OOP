#include <iostream>
#include <iomanip>
#include "tree.h"
using namespace std;
int main()
{
	Tree<int> intTree;
	int a;
	cout<<"10 numbers:"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>a;
		intTree.insert_node(a);
	}
	cout<<endl<<"inorder_walk:"<<endl;
	intTree.inorder_walk(intTree.get_root());
	cout<<endl<<"Minimum is: "<<(intTree.find_min(intTree.get_root()))->get_data()<<endl;
	cout<<endl<<"Maximum is: "<<(intTree.find_max(intTree.get_root()))->get_data()<<endl;
	cout<<"Enter node value U want to delete:";
	cin>>a;
	intTree.delete_node(intTree.find_node(intTree.get_root(),a));
	cout<<endl<<"Now inorder_walk:"<<endl;
	intTree.inorder_walk(intTree.get_root());

}