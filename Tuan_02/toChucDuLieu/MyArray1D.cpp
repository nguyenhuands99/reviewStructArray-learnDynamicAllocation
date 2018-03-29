#pragma
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "MyArray1D.h"

static int sz_nItem, sz_sizeItem;
static int headSize = sizeof(sz_nItem) + sizeof(sz_sizeItem);

static int memSize(int nItem, int sizeItem)
{
	if (sizeItem < 0)
	{
		sizeItem = -sizeItem;
	}
	if (sizeItem == 0)
	{
		sizeItem = 1;
	}
	if (nItem < 0)
	{
		nItem = -nItem;
	}
	return headSize + sizeItem*nItem;
}
static void *origin_addr(void *aData)
{
	if (aData != NULL)
	{
		return (char *)aData - headSize;
	}
	return NULL;
}
static void *data_addr(void *aOrigin)
{
	if (aOrigin != NULL)
	{
		return (char *)aOrigin + headSize;
	}
	return NULL;
}

static void *nItem_addr(void *aData)
{
	return origin_addr(aData);
}

static void *sizeItem_addr(void *aData)
{
	if (aData != NULL)
	{
		return (char *)aData - sizeof(sz_sizeItem);
	}
	return NULL;
}

void *arrInit(int nItem, int sizeItem)
{
	void *aOrigin = NULL, *aData = NULL;
	int sz = memSize(nItem, sizeItem);
	aOrigin = malloc(sz);
	if (aOrigin != NULL)
	{
		memset(aOrigin, 0, sz);
		aData = data_addr(aOrigin);
		*(int *)nItem_addr(aData) = nItem;
		*(int *)sizeItem_addr(aData) = sizeItem;
	}
	return aData;
}
int arrSize(void *aData)
{
	if (aData != NULL)
	{
		return *(int *)nItem_addr(aData);
	}
	return 0;
}
int arrItemSize(void *aData)
{
	if (aData != NULL)
	{
		return *(int *)sizeItem_addr(aData);
	}
	return 0;
}

void *arrPushBack(void *aData, void *x)
{
	int nItem = arrSize(aData), szItem = arrItemSize(aData);
	void *anew = arrResize(aData, 1 + nItem);
	if (anew != NULL)
	{
		memcpy((char *)anew + nItem*szItem, x, szItem);
		aData = anew;
	}
	return aData;
}

void *arrResize(void *aData, int nItem)
{
	int sz, sizeItem;
	void *aNew = NULL, *aOrigin = NULL;
	if (aData == NULL || nItem < 0)
	{
		return NULL;
	}
	aOrigin = origin_addr(aData);
	sizeItem = *(int *)sizeItem_addr(aData);
	sz = memSize(nItem, sizeItem);
	aNew = realloc(aOrigin, sz);
	if (aNew != NULL)
	{
		aData = data_addr(aNew);
		*(int *)nItem_addr(aData) = nItem;
		return aData;
	}
	return NULL;

}

void *arrPopBack(void *aData)
{
	int nItem = arrSize(aData), szItem = arrItemSize(aData);
	void *x = NULL;
	if (aData != NULL && nItem > 0)
	{
		nItem--;
		x = (char *)aData + nItem*szItem;
		*(int *)nItem_addr = nItem;
	}
	return x;
}

void arrFree(void *aData)
{
	if (aData != NULL)
	{
		free(origin_addr(aData));
	}
}
