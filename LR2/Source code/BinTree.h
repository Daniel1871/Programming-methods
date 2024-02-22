/*!
	\file
	\brief Заголовочный файл с описанием бинарного дерева.

	Данный файл содержит в себе определение класса бинарного дерева.
*/
#ifndef BINTREE_H
#define BINTREE_H

#include "Military.h"

/*!
	\brief Класс, содержащий данные об узле бинарного дерева.

	Данный класс содержит указатель на левого и правого потомка данного узла, ключ, и данные военнослужащего.
*/
class BinNode{
public:
	BinNode *left; ///< Указатель на левого потомка узла дерева
	BinNode *right; ///< Указатель на правого потомка узла дерева
	string key; ///< Ключ (ФИО военнослужащего), соответствуюший узлу дерева
	Military data; ///< Данные военнослужащего, хранящиеся в узле дерева
	
	/*!
	\brief Конструктор с параметром
	\param[in] data Данные военнослужащего, с помощью которых инициализируется текущий узел бинарного дерева
	*/
	BinNode(Military data) : left(NULL), right(NULL), key(data.getFullName()), data(data) {}
};

/*!
	\brief Класc бинарного дерева.

	Данный класс содержит указатель на корень бинарного дерева.
*/
class BinTree{
	BinNode *root; ///< Указатель на корень бинарного дерева
	
	/*!
	\brief Метод для рекурсивного удаления узлов бинарного дерева
	
	Рекурсивно удаляет левого, правого потомка и текущий узел дерева
	\param[in] node Указатель на текущий узел бинарного дерева
	*/
	void deleteBinTree(BinNode *node);

public:
	/*!
	\brief Конструктор умолчания
	
	Создает пустое дерево
	*/
 	BinTree() : root(NULL) {}
 	
 	/*!
	\brief Деструктор
	
	Удаляет дерево (все его элементы) вызовом рекурсивного метода deleteBinTree, передавая корень дерева.
	*/
 	~BinTree() { deleteBinTree(root); }
 	
 	/*!
	\brief Метод для поиска узла бинарного дерева по ключу
	
	Проверяет, содержится ли элемент с переданным ключом в бинарном дереве
	\param[in] key Ключ искомого узла
	\return Результат поиска: истина или ложь
	*/
 	bool find(const string &key);
 	
 	/*!
	\brief Метод для вставки элемента в бинарное дерево
	
	Вставляет узел с переданными данными о военнослужащем в бинарное дерево
	\param[in] data Данные военнослужащего
	*/
 	void insert(Military data);
};

#endif
