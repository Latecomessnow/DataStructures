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

//�ҵ�ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);

//�������
int TreeDepth(BTNode* root);

//����������ٶ�����
void TreeDestroy(BTNode* root);

//�������
void LevelOrder(BTNode* root);

//�ж����Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);