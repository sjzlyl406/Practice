/*************************************************************************
	> File Name: test132.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 09时31分13秒
 ************************************************************************/

/******************************************************************
 * 动态数组 
 * 功能：
 *		 Ret darray_insert(DArray *thiz, size_t index, void* data);
 *		 Ret darray_prepend(DArray *thiz, void *data);
 *		 Ret darray_append(DArray *thiz, void *data);
 *		 Ret darray_delete(DArray *thiz, size_t index);
 *		 Ret darray_get_by_index(DArray *thiz, size_t index, void **data);
 *		 Ret darray_set_by_index(DArray *thiz, size_t index, void *data);
 *		 Ret darray_find(DArray *thiz, DataCompareFunc cmp, void* ctx);
 *		 Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx);
 *		 size_t darray_length(DArray *thiz);
 *		 void darray_delete(DArray *thiz);
 * ***************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define RET_OK 0		//正确
#define RET_ERR	-1		//返回错误
#define RET_ERR_ARG	-2	//参数错误
#define MALL_ERR -3		//分配空间错误
#define NOT_FOUND 1		//没有查找结果

#define INITSPACE 5		//初始大小

typedef int Type;	//类型
typedef int Ret;	//返回结果

struct _DArray {
	Type *data;
	size_t length;
	size_t capacity;
};
typedef struct _DArray DArray;


Ret darray_create(DArray *thiz, void **array, size_t length);
Ret darray_insert(DArray *thiz, size_t index, void* data);
Ret darray_prepend(DArray *thiz, void *data);
Ret darray_append(DArray *thiz, void *data);
Ret darray_delete(DArray *thiz, size_t index);
Ret darray_get_by_index(DArray *thiz, size_t index, void **data);
Ret darray_set_by_index(DArray *thiz, size_t index, void *data);
Ret darray_find(DArray *thiz, DataCompareFunc cmp, void* ctx);
Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx);
size_t darray_length(DArray *thiz);
void darray_delete(DArray *thiz);


int main(void) {
	DArray darray;
	int array[] = {1,2,3};
	darray_create(&darray, (void*)array, 3);
	
	int i = 0;
	for(i = 0; i < darray.length; ++i) {
		printf("%d\t", darray.data[i]);
	}
	printf("capacity is : %d\n", darray.capacity);
	printf("\n");
	darray_insert(&darray, 0, (void*)3);
	darray_insert(&darray, 0, (void*)3);
	darray_insert(&darray, 0, (void*)5);
	for(i = 0; i < darray.length; ++i) {
		printf("%d\t", darray.data[i]);
	}
	printf("capacity is : %d\n", darray.capacity);
	printf("\n");
	darray_prepend(&darray, (void*)5);
	for(i = 0; i < darray.length; ++i) {
		printf("%d\t", darray.data[i]);
	}
	printf("capacity is : %d\n", darray.capacity);
	printf("\n");

	darray_append(&darray, (void*)5);
	for(i = 0; i < darray.length; ++i) {
		printf("%d\t", darray.data[i]);
	}
	printf("capacity is : %d\n", darray.capacity);
	printf("\n");
	
	darray_delete(&darray, 0);
	darray_delete(&darray, 0);
	darray_delete(&darray, 0);
	darray_delete(&darray, 0);
	darray_delete(&darray, 0);
	darray_delete(&darray, 0);
	for(i = 0; i < darray.length; ++i) {
		printf("%d\t", darray.data[i]);
	}
	printf("capacity is : %d\n", darray.capacity);
	printf("\n");
	return 0;
}
//通过数组array创建动态数组
//通过thiz指针返回，
Ret darray_create(DArray *thiz, void **array, size_t length) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	int i = 0;

	//空数组
	if(array == (void*)0 || length == 0) {
		thiz->data = (Type*) malloc(sizeof(Type*) * INITSPACE);
		if(thiz->data == (void*)0) 
			return MALL_ERR;
		thiz->length = 0;
		thiz->capacity = INITSPACE;
	}
	//非空数组时
	else {
		thiz->capacity = length + (length >> 1);	//比数组大0.5倍
		thiz->length = length;
		thiz->data = (Type*) malloc (sizeof(Type) * thiz->capacity);
		if(thiz->data == (void*)0) 
			return MALL_ERR;
		for(i = 0; i < length; ++i) {
			thiz->data[i] = ((Type*)array)[i];
		}
	}
	return RET_OK;
}
//申请空间
static Ret darray_realloc(DArray *thiz, size_t size) {
	if(thiz == (void*)0) return RET_ERR_ARG;

	if(thiz->capacity == size) return RET_OK;

	thiz->data = (Type*) realloc(thiz->data, sizeof(Type) * size);
	if(thiz->data == (void*)0) 
		return MALL_ERR;
	thiz->capacity = size;

	return RET_OK;
}
//申请2倍空间
Ret darray_realloc2(DArray *thiz) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	int new_capacity = thiz->capacity * 2;
	return darray_realloc(thiz, new_capacity);
}
//插入动态数组
Ret darray_insert(DArray *thiz, size_t index, void* data) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	int i = 0;

	//如果没有空间，则申请两倍空间
	if(thiz->capacity == thiz->length) {
		if(darray_realloc2(thiz) != RET_OK) return RET_ERR;
	}

	for(i = thiz->length; i > index; --i) {
		thiz->data[i] = thiz->data[i-1];
	}
	thiz->data[i] = (Type)data;
	thiz->length++;
	return RET_OK;
}
//增添在darray前面
Ret darray_prepend(DArray *thiz, void *data) {
	return darray_insert(thiz, 0, data);
}
//增添在darray后面
Ret darray_append(DArray *thiz, void *data) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	return darray_insert(thiz, thiz->length, data);
}
//删除一倍空间
Ret darray_dealloc2(DArray *thiz) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	int new_capacity = thiz -> capacity >> 1;
	return darray_realloc(thiz, new_capacity);
}
//按索引删除元素
Ret darray_delete(DArray *thiz, size_t index) {
	if(thiz == (void*)0) return RET_ERR_ARG;
	if(index > thiz->length) return RET_ERR;
	int i = 0;

	for(i = index; i < thiz->length; ++i) {
		thiz->data[i] = thiz->data[i+1];
	}
	thiz->length --;

	//如果空间超过长度的4倍，则释放一半空间
	if(thiz->length <= (thiz->capacity >> 2)) {
		if(darray_dealloc2(thiz) != RET_OK) return RET_ERR;
	}

	return RET_OK;
}
//通过索引查找数组元素
Ret darray_get_by_index(DArray *thiz, size_t index, void **data) {
	if(thiz == (void*)0 || data == (void*)0) return RET_ERR_ARG;
	if(index >= thiz->length) return RET_ERR;
	*(Type*)data = thiz->data[index];
	return RET_OK;
}
//通过索引改变数组中的元素
Ret darray_set_by_index(DArray *thiz, size_t index, void *data) {
	if( thiz == (void*)0 ) return RET_ERR_ARG;
	if(index >= thiz->length) return RET_ERR;
	thiz->data[index] = (Type)data;
	return RET_OK;
}
//找到满足cmp(ctx)函数的第一个
Ret darray_find(DArray *thiz, DataCompareFunc cmp, void* ctx) {
	Ret ret = RET_OK;
	int i = 0;
	if( thiz == (void*)0 ) {
		ret = RET_ERR_ARG;
	}
	else {
		for(i = 0; i < thiz->length; ++i) {
			if(cmp(thiz->data[i], ctx)) {
				break;
			}
		}
		if(i == thiz->length) {
			ret = NOT_FOUND;
		}
	}
	return ret;
}
//遍历动态数组中每一个元素
Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx) {
	Ret ret = RET_OK;
	int i = 0;
	if( thiz == (void*)0 ) {
		ret = RET_ERR_ARG;
	}
	else {
		for(i = 0; i < thiz->length; ++i) {
			ret = visit(thiz->data[i], ctx);
		}
	}
	return ret;
}
//返回动态数组的长度
size_t darray_length(DArray *thiz) {
	return thiz->length;
}
//销毁动态数组空间
void darray_delete(DArray *thiz) {
	free(thiz->data);
	thiz->data = (Type*)0;
	thiz->length = 0;
}




