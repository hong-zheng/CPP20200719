#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
using namespace std;


enum Color{
	BLACK,
	RED
};

template<class K,class V>
struct RBNode{
	pair<K, V> _value;
	Color _color;
	//	RBNode(const pair<K, V>& value=pair<K,V>())
	//		:__value(value)
	//		, _color(RED)
	//		, _parent(nullptr)
	//		, _left(nullptr)
	//		, _right(nullptr)
	//	{}

	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	// 一个空树颜色无所谓
	// 此处调用默认构造
	RBNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{}

};

// 红黑树
// 根是黑色的
// 红色不能连续，黑色不能连续
// 空节点算为黑色的
// 最长路径是最短路径的两倍
template<class K,class V>
class RBTree{
public:
	typedef RBNode<K, V>* Node;

	RBTree()// 此处的颜色无所谓
		:_header(new Node){
		_header->_left = _header->_right = _header;
		//_header->_parent = _header;
	}

	bool insert(const pair<K, V>& val){
		// 空树
		if (_header->_parent == nullptr){
			//创建第一个根节点
			Node* root = new Node(val);
			// 根节点为黑色，必须要保证
			root->_color = BLACK;

			_header->_parent = root;
			root->_parent = _header;

			_header->_left = root;
			_header->_right = root;

			return true;
		}
		// 非空树的插入
		Node* cur = _header->_parent;
		Node* parent = nullptr;

		while (cur){
			// 按照key值进行比较：pair.first
			if (cur->_value.first == val.first){
				return false;
			}
			if (cur->_value.first < val.first){
				cur = cur->_right;
			}
			else{
				cur = cur->_left;
			}
		}

		cur = new Node(val);

		if (parent->_value.first < val.first)
			parent->_right = cur;
		else
			parent->_left = cur;

		cur->_parent = parent;

		// 旋转

		// 调整：修改颜色，旋转
		// cur不是根节点同时父亲节点的颜色为红色
	// cur才插入也为红色
		while (cur != _header->_parent && cur->_parent->_color == RED){
			Node* p = cur->_parent;
			Node* g = p->_parent;

			if (g->_left ==p){
				Node* u = g->_right;

				if (u&&u->_color == RED){
					//修改颜色
					u->_color = p->_color = BLACK;
					g->_color = RED;
					//继续向上查看
					cur = g;
				}
				else{
					// 双旋，可能有有可能没有
					// u不存在/u存在且为黑
					
					// cur不在p的左边，而在右边
					if (cur == p->_right){
						ROTATEL(p);
						swap(cur, p);
					}

					//旋转,右旋
					ROTATER(g);
					// 修改颜色
					p->_color = BLACK;
					g->_color = RED;
					break;
				}
			}

			//Node* rightMost(){
			//	Node* cur = _header->_parent;

			//	while (cur  &&cur->)
			//}

			void ROTATER(Node* parent){

			}
			//if (g->_left == p){
			//	Node* u = g->_right;

			//	if (u && u->_color == RED){
			//		// 修改颜色
			//		u->_color = p->_color = BLACK;
			//		g->_color = RED;

			//		//继续向上查看
			//		cur = g;
			//	}
			//}
			//else{
			//	Node* u = g->_left;

			//	if (u&&u->_color == RED){
			//		//修改颜色
			//		u->_color = p->_color = BLACK;
			//		g->_color = RED;
			//		//继续向上
			//		cur = g;
			//	}
			//}
		}

	}


	Node* rightMost(){
		Node* cur = _header->_parent;
		while (cur && cur->_right){
			cur = cur->_right;
		}
		return cur;
	}

	Node* leftMost(){
		Node* cur = _header->_parent;
		while (cur && cur->_parent){
			cur = cur->_left;
		}
		return cur;
	}
private:
	// 不存放有效节点的初始节点
	Node* _header; // 便于实现迭代器
};
//template <class K,class V>
//class RBTree{
//public:
//	typedef RBNode<K, V> Node;
//
//	RBTree()
//		:_header(new Node) // 颜色无所谓，就为初始化的红色
//	{
//		_header->_left = _header->_right = _header;
//	}
//
//
//	bool insert(const pair<K,V>& val){
//
//		// 空树
//		if (_header->_parent == nullptr){
//			// 创建插入节点
//			Node* root = nwe Node(val);
//
//			// 根节点是黑色
//			root->_color = BLACK;
//
//			_header->_parent = root;
//			root->_parent = _header;
//			
//			_header->_left = root;
//			_header->_right = root;
//			return true;
//		}
//		//非空树
//
//		Node* cur = _header->_parent;
//		Node* parent = nullptr;
//
//		while (cur){
//			if (cur->_value.first == val)
//		}
//
//
//		// 插入完成之后
//		// 调整：修改颜色，旋转
//		// 插入黑色节点影响全局
//		// 插入红色节点影响是局部的
//
//	}
//private:
//	Node* _header; //头节点
//};
void test(){
	vector<pair<int,string>> vis;
	for (int i = 0; i < 10; i++){
		//pair<int, string> iss(i, string("测试pair:"+i));
		vis.push_back(make_pair(i, string("cheshi" + i)));
	}
	for (int i = 0; i < vis.size(); ++i){
		cout << vis[i].first << "-" << vis[i].second << endl;
	}

	typedef pair<string, string> Author;
	Author p("as", "jack");

	// 创建新的pair对象
	// 利用make_pair创建新的pair对象

	pair<int, double> p1;
	p1 = make_pair(1, 1.1);
	cout << p1.first << "-->" << p1.second << endl;

	

}

std::pair<std::string, int> getPerson(){
	return std::make_pair("Jack", 25);
}

void tst(){
	std::string name;
	int ages=0;

	//std::tie(name, ages) = getPerson();

	cout << name << "-" << ages << endl;
}

int main(){


	//test();

	//cout << "begin" << endl;
	//string s("sdafjlij" + 12);
	//cout << s.c_str() << endl;
	//cout << "end" << endl;

	system("pause");
	return 0;
}
//
//enum Color{
//	BLACK,
//	RED
//};
//
//template<class K,class V>
//struct  RBNode
//{
//	pair<K, V> _value;
//	Color _color;
//
//	RBNode<K, V>* _parent;
//	RBNode<K, V>* _left;
//	RBNode<K, V>* _right;
//
//	RBNode(const pair<K, V>& value=pair<K,V>())
//		:__value(value)
//		, _color(RED)
//		, _parent(nullptr)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template <class K,class V>
//class RBTree{
//public:
//	typedef RBNode<K, V> Node;
//
//	RBTree()
//		:_header(new Node) // 颜色无所谓，就为初始化的红色
//	{
//		_header->_left = _header->_right = _header;
//	}
//
//
//	bool insert(const pair<K,V>& val){
//
//		// 空树
//		if (_header->_parent == nullptr){
//			// 创建插入节点
//			Node* root = nwe Node(val);
//
//			// 根节点是黑色
//			root->_color = BLACK;
//
//			_header->_parent = root;
//			root->_parent = _header;
//			
//			_header->_left = root;
//			_header->_right = root;
//			return true;
//		}
//		//非空树
//
//		Node* cur = _header->_parent;
//		Node* parent = nullptr;
//
//		while (cur){
//			if (cur->_value.first == val)
//		}
//
//
//		// 插入完成之后
//		// 调整：修改颜色，旋转
//		// 插入黑色节点影响全局
//		// 插入红色节点影响是局部的
//
//	}
//private:
//	Node* _header; //头节点
//};