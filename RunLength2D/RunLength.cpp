#include "RunLength.h"
#include <ctime>

// 构造函数--动态开辟DEM内存并随机赋值
Runlength::Runlength(int nWidth, int nHeight) 
	: mnWidth(nWidth)
	, mnHeight(nHeight)
{
	//随机种子
	srand((unsigned int) time(nullptr));
	//动态分配原始DEM数据的内存
	demBuf = new int* [nHeight];
	for (int i = 0; i < nHeight; i++) {
		demBuf[i] = new int[nWidth];
	}
	//动态赋值
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth;) {
			int nStep = rand() % 5 + 5;	//设置步长 5-10，尽量满足相邻地区高程相等
			int nValue = rand() % 101;  //随机生成0到100的高程
			for (int k = 0; k < nStep && j < nWidth; k++, j++) {
				demBuf[i][j] = nValue;
			}
		}
	}
}

// 析构函数--回收开辟的内存
Runlength::~Runlength() {
	for (int i = 0; i < mnHeight; i++) {
		delete[] demBuf[i];
	}
	delete[] demBuf;
}

// 打印原始DEM数据
void Runlength::printOriginalDEM() {
	for (int i = 0; i < mnHeight; i++) {
		for (int j = 0; j < mnWidth; j++) {
			std::cout << demBuf[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
// 打印行程编码后的DEM数据
void Runlength::printResultDEM() {
	for (const auto& dem : mvResultDEM) {
		std::cout << "Start Row: " << dem.nR << ", Start Col: " << dem.nC
			<< ", Value: " << dem.nValue << ", Length: " << dem.nLength << std::endl;
	}
}

// 行程编码函数
int Runlength::Runlength2D() {
	for (int i = 0; i < mnHeight; i++) {
		int nStartCol = 0;
		int nValue = demBuf[i][0];
		int nLength = 1;

		for (int j = 0; j < mnWidth; j++) {
			if (demBuf[i][j] == nValue) {
				nLength++;
			}
			else {
				mvResultDEM.push_back({ i, nStartCol, nValue, nLength });
				nStartCol = j;
				nValue = demBuf[i][j];
				nLength = 1;
			}
		}
		// 保存最后一段
		mvResultDEM.push_back({ i, nStartCol, nValue, nLength });
	}
	return 0;
}

// 计算压缩比
double Runlength::calculateCompressionRatio() {
	int nOriginalDEMSize = mnWidth * mnHeight * sizeof(int);
	int nResultDEMSize = mvResultDEM.size() * sizeof(RunLengthDEM);
	return nOriginalDEMSize* 1.0f / nResultDEMSize ;
}