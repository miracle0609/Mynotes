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

