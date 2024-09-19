#include <iostream>
#include "RunLength.h"

int main() {
	// 自定义输入规格
	int nWidth, nHeight;
	printf("请输入待压缩DEM数据的长度和高度：\n");
	std::cin >> nWidth >> nHeight;
	// 创建行程编码对象
	Runlength dem = Runlength(nWidth, nHeight);
	printf("原始DEM数据为：\n");
	dem.printOriginalDEM();
	// 执行行程编码
	dem.Runlength2D();
	printf("行程编码后的DEM数据为：\n");
	dem.printResultDEM();
	printf("压缩比为：%f \n", dem.calculateCompressionRatio());

	
	return 0;
}