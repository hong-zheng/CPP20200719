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

	// һ��������ɫ����ν
	// �˴�����Ĭ�Ϲ���
	RBNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{}

};

// �����
// ���Ǻ�ɫ��
// ��ɫ������������ɫ��������
// �սڵ���Ϊ��ɫ��
// �·�������·��������
template<class K,class V>
class RBTree{
public:
	typedef RBNode<K, V>* Node;

	RBTree()// �˴�����ɫ����ν
		:_header(new Node){
		_header->_left = _header->_right = _header;
		//_header->_parent = _header;
	}

	bool insert(const pair<K, V>& val){
		// ����
		if (_header->_parent == nullptr){
			//������һ�����ڵ�
			Node* root = new Node(val);
			// ���ڵ�Ϊ��ɫ������Ҫ��֤
			root->_color = BLACK;

			_header->_parent = root;
			root->_parent = _header;

			_header->_left = root;
			_header->_right = root;

			return true;
		}
		// �ǿ����Ĳ���
		Node* cur = _header->_parent;
		Node* parent = nullptr;

		while (cur){
			// ����keyֵ���бȽϣ�pair.first
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

		// ��ת

		// �������޸���ɫ����ת
		// cur���Ǹ��ڵ�ͬʱ���׽ڵ����ɫΪ��ɫ
	// cur�Ų���ҲΪ��ɫ
		while (cur != _header->_parent && cur->_parent->_color == RED){
			Node* p = cur->_parent;
			Node* g = p->_parent;

			if (g->_left ==p){
				Node* u = g->_right;

				if (u&&u->_color == RED){
					//�޸���ɫ
					u->_color = p->_color = BLACK;
					g->_color = RED;
					//�������ϲ鿴
					cur = g;
				}
				else{
					// ˫�����������п���û��
					// u������/u������Ϊ��
					
					// cur����p����ߣ������ұ�
					if (cur == p->_right){
						ROTATEL(p);
						swap(cur, p);
					}

					//��ת,����
					ROTATER(g);
					// �޸���ɫ
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
			//		// �޸���ɫ
			//		u->_color = p->_color = BLACK;
			//		g->_color = RED;

			//		//�������ϲ鿴
			//		cur = g;
			//	}
			//}
			//else{
			//	Node* u = g->_left;

			//	if (u&&u->_color == RED){
			//		//�޸���ɫ
			//		u->_color = p->_color = BLACK;
			//		g->_color = RED;
			//		//��������
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
	// �������Ч�ڵ�ĳ�ʼ�ڵ�
	Node* _header; // ����ʵ�ֵ�����
};
//template <class K,class V>
//class RBTree{
//public:
//	typedef RBNode<K, V> Node;
//
//	RBTree()
//		:_header(new Node) // ��ɫ����ν����Ϊ��ʼ���ĺ�ɫ
//	{
//		_header->_left = _header->_right = _header;
//	}
//
//
//	bool insert(const pair<K,V>& val){
//
//		// ����
//		if (_header->_parent == nullptr){
//			// ��������ڵ�
//			Node* root = nwe Node(val);
//
//			// ���ڵ��Ǻ�ɫ
//			root->_color = BLACK;
//
//			_header->_parent = root;
//			root->_parent = _header;
//			
//			_header->_left = root;
//			_header->_right = root;
//			return true;
//		}
//		//�ǿ���
//
//		Node* cur = _header->_parent;
//		Node* parent = nullptr;
//
//		while (cur){
//			if (cur->_value.first == val)
//		}
//
//
//		// �������֮��
//		// �������޸���ɫ����ת
//		// �����ɫ�ڵ�Ӱ��ȫ��
//		// �����ɫ�ڵ�Ӱ���Ǿֲ���
//
//	}
//private:
//	Node* _header; //ͷ�ڵ�
//};
void test(){
	vector<pair<int,string>> vis;
	for (int i = 0; i < 10; i++){
		//pair<int, string> iss(i, string("����pair:"+i));
		vis.push_back(make_pair(i, string("cheshi" + i)));
	}
	for (int i = 0; i < vis.size(); ++i){
		cout << vis[i].first << "-" << vis[i].second << endl;
	}

	typedef pair<string, string> Author;
	Author p("as", "jack");

	// �����µ�pair����
	// ����make_pair�����µ�pair����

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
//		:_header(new Node) // ��ɫ����ν����Ϊ��ʼ���ĺ�ɫ
//	{
//		_header->_left = _header->_right = _header;
//	}
//
//
//	bool insert(const pair<K,V>& val){
//
//		// ����
//		if (_header->_parent == nullptr){
//			// ��������ڵ�
//			Node* root = nwe Node(val);
//
//			// ���ڵ��Ǻ�ɫ
//			root->_color = BLACK;
//
//			_header->_parent = root;
//			root->_parent = _header;
//			
//			_header->_left = root;
//			_header->_right = root;
//			return true;
//		}
//		//�ǿ���
//
//		Node* cur = _header->_parent;
//		Node* parent = nullptr;
//
//		while (cur){
//			if (cur->_value.first == val)
//		}
//
//
//		// �������֮��
//		// �������޸���ɫ����ת
//		// �����ɫ�ڵ�Ӱ��ȫ��
//		// �����ɫ�ڵ�Ӱ���Ǿֲ���
//
//	}
//private:
//	Node* _header; //ͷ�ڵ�
//};