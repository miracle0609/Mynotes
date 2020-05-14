# 平衡二叉查找树

## 二叉排序树
	名称：二叉排序树、二叉搜索树
	性质: 
	     1、左子树 < 根节点
	     2、右子树 > 根节点
	用途:
		 解决与排名有关的检所需求
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200421224112168.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
## 二叉查找树插入
例如插入10, 10 < 20插入到左子树，10<17插入到左子树,10 > 3插入到右子树，右子树为空放置10
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200421224509351.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
## 二叉查找树的删除
>1、删除叶子节点
>2、删除出度为1的结点
>3、删除出度为2的结点

(1)删除出度为1的结点，提升３的唯一子树
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200421225000699.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
(2)删除出度为2的结点
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200421230205133.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {//结构定义二叉树
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *predeccessor(Node *root) {//找到前驱,就是最左边的最右结点
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *insert(Node *root, int key) {//插入
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;//如果插入的值等于根，插入失败
    if (root->key > key) root->lchild = insert(root->lchild, key);//如果插入的值小于root往左插入
    else root->rchild = insert(root->rchild, key);//如果插入的值大于root往右递归插入
    return root;
}

Node *erase(Node *root, int key) {//删除节点
    if (root == NULL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);//如果删除的值小于root那么向左递归查找删除
    } else if (root->key < key) {//如果删除的值大于于root那么向右递归查找删除
        root->rchild = erase(root->rchild, key);
    } else {//找到
        if (root->lchild == NULL || root->rchild == NULL) {//如果度为0或者1时
            Node *temp = root->lchild ? root->lchild : root->rchild;//建立一个中间变量记录左右结点，0度结点记录为空
            free(root);//释放此节点
            return temp;//返回记录的他的做孩子还是右孩子
        } else {//删除度为２
            Node *temp = predeccessor(root);//找到前驱，左边最大的一个节点，最右边的
            root->key = temp->key;//赋值为根
            root->lchild = erase(root->lchild, temp->key);//然后从根把其左子树递归删除释放掉
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->key);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 30
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 20;
        switch (op) {
            case 2:
            case 3:
            case 4:
            case 0: {
                printf("insert %d to binary search tree\n", val);
                root = insert(root, val);
            } break;
            case 1: {
                printf("earse %d from binary search tree\n", val);
                root = erase(root, val);
            } break;
        }
        output(root), printf("\n");
    }
    return 0;
}
```





#　红黑树

省`cpu `

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges2uqo6fhj30ns0d4gob.jpg)

NIL值的虚拟空节点

最长路径是最短路径的二倍

插入：<font color = red>祖父结点看</font>

删除:   <font color = red> 父节点看</font>

### 插入调整情况:

<font color = red>**情况一、**(插入调整就是解决两红相邻)</font>

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges6jnidd0j30my0b8gnr.jpg)

> 　　发生冲突节点的叔叔结点，如果也是红色的，那么根节点改为红色，父节点叔叔结点改为黑色

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges6l7batcj30qm0bxadj.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges6n7wwr1j30sb09e0vr.jpg)

<font color = red>**情况二、**</font>

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges6x64032j30sm0dk0vp.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges76rv5icj312x0g810j.jpg)

图中只有17不是固定的；

### 删除调整的情况





<img src="http://ww1.sinaimg.cn/large/006Uqzbtly1ges84p60dlj30ek0nadhr.jpg" alt="image.png" style="zoom: 50%;" />



**度为０时**

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges8ayl07bj30nz0e3gph.jpg)

删除后相当于合成双重黑



**度为１时**

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges8dgytshj30lx0jzgpw.jpg)

<font color = red>情况一、</font>

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges8kafxo8j30qh0faacq.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges8l7tydjj30n701q3z0.jpg)

开始95是双重黑，相当于双重黑向上走一层（双重黑上扶）

<font color = red>情况二、</font>



![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges9swkdmvj30kv0fwq4g.jpg)



<font color = red>情况三、</font>

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges8ye4mtej318p0lz7hi.jpg)

遇到ＲＲ类型直接大左旋，干掉双重黑，颜色不变的黑色小帽子

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ges92dbb86j30dv06sjsy.jpg)

51变为38的颜色，38和72变成黑色





![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gesc2n1fk0j30hh0jtaev.jpg)