#pragma once
#include <iostream>
#include <vector>

// 行程压缩的DEM数据块
struct RunLengthDEM {
	int nC;		 //起始行
	int nR;		 //起始列
	int nValue;	 //高程值
	int nLength; //数据块长度
};

// 行程编码类
class Runlength {
public:
	// 构造函数--动态开辟DEM内存并随机赋值
	Runlength(int nWidth, int nHeight);
	//析构函数--回收开辟的内存
	~Runlength();
	// 打印原始DEM数据
	void printOriginalDEM();
	// 打印行程编码后的DEM数据
	void printResultDEM();
	// 行程编码函数
	int Runlength2D();
	// 计算压缩比
	double calculateCompressionRatio();


	int** demBuf;	//原始DEM数据
	int mnWidth;	//原始DEM数据的行数
	int mnHeight;	//原始DEM数据的列数
	std::vector<RunLengthDEM> mvResultDEM;	//行程编码后的DEM数据
};
