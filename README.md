# C_Vector

简介：C 简易实现 C++ STL 中的 Vector 容器

## 使用说明  
1. 创建一个 Vector 容器 (以 int 类型举例）   
Vector cv = vector_Create(sizeof(int));  
  
2. 向已创建的 Vector 容器的尾部插入一个元素 (i）  
int i = 1;  
vector_Pushback(cv, &i);   
  
3. 向已创建的 Vector 容器的尾部删去一个元素 (k)  
vector_Popback(cv);
  
4. 将元素 (val) 插入到数组的下标 (pos) 上  
int val = 5;  
int pos = 2;  
vector_Insert(cv, pos, &val);  
  
5. 将数组下标区间 [begin,end] 的元素删除  
vector_Erase(cv, begin, end);  
  
6. 获取 Vector 的长度  
vector_Length(cv);  
  
7. 获取 Vector 的元素个数  
vector_Size(cv);  
  
8. Vector 遍历函数(打印Vector中的元素)  
void print_Int(void* cv){  
	printf("%d ", *(int*)cv);  
}  
vector_Traversal(cv, print_Int);  
  
9. 重置 Vector 的长度  
vector_Clear(cv);  
  
10. 释放 Vector 内存空间  
vector_Free(cv);  
## 求个Star 
  
