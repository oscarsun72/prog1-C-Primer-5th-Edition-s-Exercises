#ifndef BINSTRTREE_H
#define BINSTRTREE
#include"TreeNode.h"
class BinStrTree
{
public:
	//BinStrTree():root(nullptr){}//預設建構器
	BinStrTree(const std::string& s=std::string()):root(new TreeNode(s)),user_cntr(new size_t(1)){}
	BinStrTree(TreeNode* tnp):root(tnp),user_cntr(new size_t(1)){}
	//拷貝建構器
	BinStrTree(const BinStrTree& bst) :root(bst.root), user_cntr(bst.user_cntr){++* user_cntr;}
	//拷貝指定運算子
	BinStrTree& operator=(const BinStrTree & bst ){
		++*bst.user_cntr;
		if (--*user_cntr==0)
		{
			delete root;
			delete user_cntr;
		}
		root = bst.root;
		user_cntr = bst.user_cntr;
		return *this;
	}
	//解構器
	~BinStrTree() {
		if (-- * user_cntr == 0) {
			delete root;
			delete user_cntr;
		}
	}
private:
	TreeNode* root;
	size_t* user_cntr;
};



#endif // !BINSTRTREE_H
