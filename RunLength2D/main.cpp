#include <iostream>
#include "RunLength.h"

int main() {
	// �Զ���������
	int nWidth, nHeight;
	printf("�������ѹ��DEM���ݵĳ��Ⱥ͸߶ȣ�\n");
	std::cin >> nWidth >> nHeight;
	// �����г̱������
	Runlength dem = Runlength(nWidth, nHeight);
	printf("ԭʼDEM����Ϊ��\n");
	dem.printOriginalDEM();
	// ִ���г̱���
	dem.Runlength2D();
	printf("�г̱�����DEM����Ϊ��\n");
	dem.printResultDEM();
	printf("ѹ����Ϊ��%f \n", dem.calculateCompressionRatio());

	
	return 0;
}