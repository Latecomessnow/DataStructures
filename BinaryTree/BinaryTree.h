#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* CreatBinaryTree();

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

void TreeSize1(BTNode* root);

int TreeSize2(BTNode* root);

int TreeLeafSize(BTNode* root);

int TreeKLevel(BTNode* root, int k);

//找到值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);

//树的深度
int TreeDepth(BTNode* root);

//后序遍历销毁二叉树
void TreeDestroy(BTNode* root);

//层序遍历
void LevelOrder(BTNode* root);

//判断树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);