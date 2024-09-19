#include "RunLength.h"
#include <ctime>

// ���캯��--��̬����DEM�ڴ沢�����ֵ
Runlength::Runlength(int nWidth, int nHeight) 
	: mnWidth(nWidth)
	, mnHeight(nHeight)
{
	//�������
	srand((unsigned int) time(nullptr));
	//��̬����ԭʼDEM���ݵ��ڴ�
	demBuf = new int* [nHeight];
	for (int i = 0; i < nHeight; i++) {
		demBuf[i] = new int[nWidth];
	}
	//��̬��ֵ
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth;) {
			int nStep = rand() % 5 + 5;	//���ò��� 5-10�������������ڵ����߳����
			int nValue = rand() % 101;  //�������0��100�ĸ߳�
			for (int k = 0; k < nStep && j < nWidth; k++, j++) {
				demBuf[i][j] = nValue;
			}
		}
	}
}

// ��������--���տ��ٵ��ڴ�
Runlength::~Runlength() {
	for (int i = 0; i < mnHeight; i++) {
		delete[] demBuf[i];
	}
	delete[] demBuf;
}

// ��ӡԭʼDEM����
void Runlength::printOriginalDEM() {
	for (int i = 0; i < mnHeight; i++) {
		for (int j = 0; j < mnWidth; j++) {
			std::cout << demBuf[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
// ��ӡ�г̱�����DEM����
void Runlength::printResultDEM() {
	for (const auto& dem : mvResultDEM) {
		std::cout << "Start Row: " << dem.nR << ", Start Col: " << dem.nC
			<< ", Value: " << dem.nValue << ", Length: " << dem.nLength << std::endl;
	}
}

// �г̱��뺯��
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
		// �������һ��
		mvResultDEM.push_back({ i, nStartCol, nValue, nLength });
	}
	return 0;
}

// ����ѹ����
double Runlength::calculateCompressionRatio() {
	int nOriginalDEMSize = mnWidth * mnHeight * sizeof(int);
	int nResultDEMSize = mvResultDEM.size() * sizeof(RunLengthDEM);
	return nOriginalDEMSize* 1.0f / nResultDEMSize ;
}