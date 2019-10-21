#include "RB head.h"

node* grand(node* n)
{
	return n->pa->pa;
}
node* uncle(node* n)
{
	if (n->pa == grand(n)->left)
		return grand(n)->right;
	else
		return grand(n)->left;
}
void left_rotate(node *x)
{
	node* tmp;

	if (x != head)
	{
		tmp = x->right;

		x->pa->left = tmp;
		tmp->pa = x->pa;
		x->pa = tmp;
		x->right = tmp->left;
		tmp->left = x;
	}
	else
	{
		tmp = x->right;

		x->right = x->right->left;
		tmp->left = x;
		x->pa = tmp;
		head = tmp;
		head->pa=NULL;
	}
}
void right_rotate(node *x)
{
	node* tmp;

	if (x != head)
	{
		tmp = x->left;

		x->pa->right = tmp;
		tmp->pa = x->pa;
		x->pa = tmp;
		x->left = tmp->right;
		tmp->right = x;
	}
	else
	{
		tmp = x->left;

		x->left = x->left->right;
		tmp->right = x;
		x->pa = tmp;
		head = tmp;
		head->pa = NULL;
	}	
}
int RB_insert(node* p,int data)
{
	node *q;

	if (p == NULL )
	{
		q = (node*)malloc(sizeof(node));

		q->key = data;

		q->right = NIL;
		q->left = NIL;
		q->pa = NULL;
		q->color = RED;
		head = q;
		DataNum++;
		RB_insertfix(q);
		return 0;
	}
	else
	{
		if (p->key > data)
		{
			if (p->left == NIL)
			{
				q = (node*)malloc(sizeof(node));
				q->key = data;
				q->right = NIL;
				q->left = NIL;
				q->color = RED;
				q->pa = p;
				p->left = q;
				DataNum++;
				RB_insertfix(q);
				return 0;
			}
			else
				return RB_insert(p->left, data);
		}
		else
		{
			if (p->right == NIL)
			{
				q = (node*)malloc(sizeof(node));
				q->key = data;
				q->right = NIL;
				q->left = NIL;
				q->color = RED;
				q->pa = p;
				p->right = q;
				DataNum++;
				RB_insertfix(q);
				return 0;
			}
			else
				return RB_insert(p->right, data);
		}
	}
}
int RB_insertfix(node *p)
{
	node *q = NULL;
	node *un, *gp;

	if (p->pa == NULL)
		p->color = BLACK;
	else
	{
		if (p == p->pa->left)
		{
			if (p->pa->color == BLACK)
				return 0;
			else
			{
				un = uncle(p);
				gp = grand(p);
				if (un->color == RED)
				{
					p->color = BLACK;
					un->color = BLACK;
					gp->color = RED;

					RB_insertfix(gp);
				}
				else
				{
					if (p->pa == gp->right)
					{
						right_rotate(p->pa);
						p = p->right;
					}
					p->pa->color = BLACK;
					gp->color = RED;

					if (p == p->pa->left && p->pa == gp->left)
						right_rotate(gp);
					else if (p == p->pa->right && p->pa == gp->right)
						left_rotate(gp);
				}
			}
		}
		else
		{
			if (p->pa->color == BLACK)
				return 0;
			else
			{
				un = uncle(p);
				gp = grand(p);
				if (un->color == RED)
				{
					p->color = BLACK;
					un->color = BLACK;
					gp->color = RED;

					RB_insertfix(gp);
				}
				else
				{
					if (p->pa == gp->left)
					{
						left_rotate(p->pa);
						p = p->left;
					}
					p->pa->color = BLACK;
					gp->color = RED;

					if (p == p->pa->left && p->pa == gp->left)
						right_rotate(gp);
					else if (p == p->pa->right && p->pa == gp->right)
						left_rotate(gp);
				}
			}
		}
	}
	return 0;
}