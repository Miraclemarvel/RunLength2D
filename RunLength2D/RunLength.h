#pragma once
#include <iostream>
#include <vector>

// �г�ѹ����DEM���ݿ�
struct RunLengthDEM {
	int nC;		 //��ʼ��
	int nR;		 //��ʼ��
	int nValue;	 //�߳�ֵ
	int nLength; //���ݿ鳤��
};

// �г̱�����
class Runlength {
public:
	// ���캯��--��̬����DEM�ڴ沢�����ֵ
	Runlength(int nWidth, int nHeight);
	//��������--���տ��ٵ��ڴ�
	~Runlength();
	// ��ӡԭʼDEM����
	void printOriginalDEM();
	// ��ӡ�г̱�����DEM����
	void printResultDEM();
	// �г̱��뺯��
	int Runlength2D();
	// ����ѹ����
	double calculateCompressionRatio();


	int** demBuf;	//ԭʼDEM����
	int mnWidth;	//ԭʼDEM���ݵ�����
	int mnHeight;	//ԭʼDEM���ݵ�����
	std::vector<RunLengthDEM> mvResultDEM;	//�г̱�����DEM����
};
