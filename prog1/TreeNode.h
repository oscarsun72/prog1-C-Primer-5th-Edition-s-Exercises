#ifndef TREENODE_H
#define TREENODE_H
#include<string>
class TreeNode
{
public:
	TreeNode() : count(0), left(nullptr), right(nullptr), user_cntr(new size_t(1)) {};//預設建構器（default constructor）
	TreeNode(const std::string& s) :value(s),
		count(s.size()), left(new TreeNode[s.size()]), right(left + s.size() - 1), user_cntr(new size_t(1)) {}//預設建構器
	//拷貝建構器
	TreeNode(const TreeNode& tn) :
		value(tn.value), count(tn.count), left(tn.left), right(tn.right),user_cntr(tn.user_cntr) {
		++* user_cntr;
	}
	~TreeNode() {
		if (-- * user_cntr == 0) {
			delete[]left;
			//left = nullptr; right = nullptr;
			delete user_cntr;
		}
	}
	TreeNode& operator=(const TreeNode& rhs) {
		++* rhs.user_cntr;
		if (--*user_cntr==0)
		{
			delete[]left;
			//left = nullptr; right = nullptr;
			delete user_cntr;
		}
		value = rhs.value;
		count = rhs.count;
		left = rhs.left;
		right = rhs.right;
		user_cntr = rhs.user_cntr;
		return *this;
	}
private:
	std::string value;
	int count;
	TreeNode* left;//由此想到動態陣列（動態配置多個物件）；再由new[]想到要解構delete[]
	TreeNode* right;
	size_t* user_cntr;
};

#endif // !TREENODE_H