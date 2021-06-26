#include <iostream>
using namespace std;

class Tree
{
public:
	Tree* left_;
	Tree* right_;
	Tree(int value);
	Tree(int numerator, int denominator);
	Tree(Tree* tree_);
	Tree();
	~Tree();
	int get_numerator();
	int get_denominator();
	int get_value();
	void print_fraction();	
	void set_value(int value);
	void set_fraction(int numerator,int denominator);
private:
	int numerator_;
	int denominator_;
	int value_;
};

void Tree::set_value(int value)
{
	if (this != nullptr)
		this->value_ = value;
}

void Tree::set_fraction(int numerator,int denominator)
{
	this->numerator_ = numerator;
	this->denominator_ = denominator;
}

Tree:: Tree(int value)
{
	this->value_ = value;
}

Tree::Tree(int numerator, int denominator)
{
	this->numerator_ = numerator;
	this->denominator_ = denominator;
}

Tree::Tree(Tree* tree)
{
	this->value_ = tree->value_;
}

int Tree::get_value()
{
	return this->value_;
}

void Tree::print_fraction()
{
	cout << numerator_ << '/' << denominator_ << endl;
}

Tree::Tree()
{
	this->value_ = 0;
}

Tree::~Tree()
{
	delete left_;
	delete right_;
}

int Tree::get_numerator()
{
	return this->numerator_;
}

int Tree::get_denominator()
{
	return this->denominator_;
}

int sum_of_trees(Tree* tree, int& sum)
{
	sum += tree->get_value();
	if (tree->right_ != nullptr)
	{
		sum_of_trees(tree->right_,sum);
	}
	if (tree->left_ != nullptr)
	{
		sum_of_trees(tree->left_,sum);
	}
	return sum;
}

void PrintValues(Tree* tree)
{
	tree->print_fraction();
	if (tree->left_ != nullptr)
	{
		PrintValues(tree->left_);
	}
	if (tree->right_ != nullptr)
	{
		PrintValues(tree->right_);
	}
}

void set_trees_values(Tree* tree)
{

	if (tree->left_ != nullptr)
	{
		set_trees_values(tree->left_);
	}
	if (tree->right_ != nullptr)
	{
		set_trees_values(tree->right_);
	}
	if (tree->left_ == nullptr)
	{
		tree->left_ = new Tree(tree->get_numerator(), tree->get_denominator()+tree->get_numerator());
	}
	if (tree->right_ == nullptr)
	{
		tree->right_ = new Tree(tree->get_denominator()+tree->get_numerator(), tree->get_denominator());
	}

}

int main()
{
	Tree* t1 = new Tree(1, 1);
	for (int i = 0; i < 2; i++)
	{
		set_trees_values(t1);
	}
	PrintValues(t1);
	delete t1;
	return 0;
}