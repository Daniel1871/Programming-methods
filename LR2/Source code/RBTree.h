/*!
	\file
	\brief Заголовочный файл с описанием красно-черного дерева.

	Данный файл содержит в себе определение класса красно-черного дерева.
*/
#ifndef RBTREE_H
#define RBTREE_H

#include "Military.h"

/// Цвет узла дерева: красный или черный
enum class Color { RED, BLACK }; 

/*!
	\brief Класс, содержащий данные об узле красно-черного дерева.

	Данный класс содержит указатель на левого и правого потомка и на родителя данного узла, ключ, данные военнослужащего и цвет.
*/
class RBNode{ // Узел красно-черного дерева
public:
    RBNode *left; ///< Указатель на левого потомка узла красно-черного дерева
    RBNode *right; ///< Указатель на правого потомка узла красно-черного дерева
    RBNode *parent; ///< Указатель на родителя узла красно-черного дерева
    string key; ///< Ключ (ФИО военнослужащего), соответствуюший узлу красно-черного ерева
    Military data; ///< Данные военнослужащего, хранящиеся в узле красно-черного дерева
    Color color; ///< Цвет узла красно-черного дерева дерева
    
    /*!
	\brief Конструктор с параметрами
	\param[in] data Данные военнослужащего
	\param[in] color Цвет узла красно-черного дерева (по умолчанию красный)
	\param[in] left Указатель на левого потомка узла красно-черного дерева (по умолчанию NULL)
	\param[in] right Указатель на правого потомка узла дкрасно-черного дерева (по умолчанию NULL)
	\param[in] parent Указатель на родителя узла красно-черного дерева (по умолчанию NULL)
	*/
    RBNode(Military data, const Color &color = Color::RED, RBNode *left = NULL, RBNode *right = NULL, RBNode *parent = NULL)
    	 : data(data), key(data.getFullName()), color(color), left(left), right(right), parent(parent) {} 
};

/*!
	\brief Класc красно-черного дерева.

	Данный класс содержит указатель на корень красно-черного дерева и на nil - нулевой узел дерева.
*/
class RBTree{
    RBNode *root; ///< Указатель на корень красно-черного дерева
    RBNode *nil; ///< Нулевой узел красно-черного дерева
   
    /*!
	\brief Метод выполнения левогостороннего поворота в красно-черном дереве
	
	\param[in] x Узел красно-черного дерева, с которого начинается левосторонний поворот
	*/
	void leftRotate(RBNode* x);
	
	/*!
	\brief Метод выполнения правостороннего поворота в красно-черном дереве
	
	\param[in] x Узел красно-черного дерева, с которого начинается правосторонний поворот
	*/
	void rightRotate(RBNode* x);
	
	/*!
	\brief Метод для BST-вставки узла красно-черного дерева
	
	Вставляет узел красно-черного дерева аналогично вставке в бинарном дереве.
	\param[in] parent Указатель на узел родителя всталяемого узла
	\param[in] start Указатель на текущий/исходный узел
	\param[in] data Данные военнослужащего
	\return Указатель на вставленный узел красно-черного дерева
	*/
	RBNode* insertBST(RBNode* parent, RBNode* start, Military data);

public:
    RBTree(); ///< Конструктор умолчания
    
    /*!
	\brief Метод для поиска узла красно-черного дерева по ключу
	
	Проверяет, содержится ли элемент с переданным ключом в красно-черном дереве
	\param[in] key Ключ искомого узла
	\return Результат поиска: истина или ложь
	*/
    bool find(const string &key);
    
    /*!
	\brief Метод для вставки элемента в бинарное дерево
	
	Вставляет узел с переданными данными о военнослужащем в красно-черное дерево
	\param[in] data Данные военнослужащего
	*/
    void insert(Military data);
};

#endif
