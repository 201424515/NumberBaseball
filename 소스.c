#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define OFFENSECHANCE 10 //���� Ƚ��

void main()
{
	srand((unsigned)time(NULL));

	printf("================================================================================\n");
	printf("		                                                                        \n");
	printf("                                ���� �߱� ����                                  \n");
	printf("																			    \n");
	printf("================================================================================\n");

	int defense[4] = { -1,-1,-1,-1 };			//�������� ������ �� 4���� ����
	int offense[4]; // �Է¹��� �������� ������ �� 4���� ����
	int numAssignCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int offenseHistory[OFFENSECHANCE][4];	//[Ƚ��][4�ڸ���]
	int countHistory[OFFENSECHANCE][2];		//[Ƚ��][ī��Ʈ]

	printf("���ھ߱� �����Դϴ�.\n");
	printf("%d���� ��ȸ�ȿ� ��ǻ���� ���ڸ� ���߸� �¸��մϴ�.\n", OFFENSECHANCE);

	while (1)
	{
		printf("������ �����Ͻ÷��� �ƹ�Ű�� �����ּ���.\n\n");
		_getch();
		system("cls");

		printf("��ǻ�Ͱ� ���� ���߽��ϴ�.\n\n");
		//��ǻ�Ͱ� ������ �� �߻���Ų��.	
		while (1)
		{
			int num = rand() % 10;

			if (defense[0] != num && defense[1] != num && defense[2] != num && defense[3] != num)
			{
				defense[numAssignCount] = num;
				numAssignCount++;
			}

			if (numAssignCount >= 4)
			{
				break;
			}
		}

		//���� ����
		int offenseChanceCount = OFFENSECHANCE;
		for (int k = 0; k<OFFENSECHANCE; k++)
		{
			//�ƽ�Ű�� 48~57 = 0~9
			printf("ù° �ڸ��� �Է�:");
			offense[0] = _getch();
			offense[0] -= 48;
			printf("%d\n", offense[0]);

			while (1)
			{
				printf("��° �ڸ��� �Է�:");
				offense[1] = _getch();
				offense[1] -= 48;
				if (offense[0] != offense[1])
				{
					printf("%d\n", offense[1]);
					break;
				}
				else
				{
					printf("�ߺ��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}

			while (1)
			{
				printf("��° �ڸ��� �Է�:");
				offense[2] = _getch();
				offense[2] -= 48;
				if (offense[0] != offense[1] && offense[0] != offense[2] && offense[1] != offense[2])
				{
					printf("%d\n", offense[2]);
					break;
				}
				else
				{
					printf("�ߺ��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}

			while (1)
			{
				printf("��° �ڸ��� �Է�:");
				offense[3] = _getch();
				offense[3] -= 48;
				if (offense[0] != offense[1] && offense[0] != offense[2] && offense[0] != offense[3] && offense[1] != offense[2] && offense[1] != offense[3] && offense[2] != offense[3])
				{
					printf("%d\n", offense[3]);
					break;
				}
				else
				{
					printf("�ߺ��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}

			//��� ��
			for (int i = 0; i<4; i++)
			{
				for (int j = 0; j<4; j++)
				{
					if (offense[i] == defense[j])
					{
						if (i == j)
							strikeCount++;
						else
							ballCount++;
					}
				}
			}

			//�����丮 ó��
			for (int i = 0; i<4; i++)
				offenseHistory[OFFENSECHANCE - offenseChanceCount][i] = offense[i];

			countHistory[OFFENSECHANCE - offenseChanceCount][0] = strikeCount;
			countHistory[OFFENSECHANCE - offenseChanceCount][1] = ballCount;

			//��ȸ ����
			offenseChanceCount--;

			//���
			if (strikeCount == 4) //���� �¸�
			{
				break;
			}
			else
			{
				printf("\n%d��Ʈ����ũ %d��\n", strikeCount, ballCount);
				printf("------------------------\n");
				printf("%d���� ��ȸ�� ���ҽ��ϴ�.\n", offenseChanceCount);
				printf("------------------------\n\n");
			}

			printf("------����� ���------\n");
			//�����丮 ���
			for (int i = 0; i<(OFFENSECHANCE - offenseChanceCount); i++)
			{
				printf("%d%d%d%d %d��Ʈ����ũ %d��\n", offenseHistory[i][0], offenseHistory[i][1], offenseHistory[i][2], offenseHistory[i][3],
					countHistory[i][0], countHistory[i][1]);
			}
			printf("\n");

			//���� �ʱ�ȭ
			for (int i = 0; i<4; i++)
				offense[i] = -1;

			strikeCount = 0;
			ballCount = 0;
		}

		//���� ��
		printf("\n��ǻ���� ���� %d%d%d%d\n", defense[0], defense[1], defense[2], defense[3]);

		if (strikeCount == 4)
			printf("\n�¸��ϼ̽��ϴ�.\n\n");
		else
			printf("\n�й��Ͽ����ϴ�.\n\n");

		//���� �ʱ�ȭ
		for (int i = 0; i<4; i++)
		{
			offense[i] = -1;
			defense[i] = -1;
		}

		strikeCount = 0;
		ballCount = 0;
		numAssignCount = 0;
	}
}