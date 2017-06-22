#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define OFFENSECHANCE 10 //도전 횟수

void main()
{
	srand((unsigned)time(NULL));

	printf("================================================================================\n");
	printf("		                                                                        \n");
	printf("                                숫자 야구 게임                                  \n");
	printf("																			    \n");
	printf("================================================================================\n");

	int defense[4] = { -1,-1,-1,-1 };			//수비자의 임의의 수 4개를 저장
	int offense[4]; // 입력받은 공격자의 임의의 수 4개를 저장
	int numAssignCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int offenseHistory[OFFENSECHANCE][4];	//[횟수][4자리수]
	int countHistory[OFFENSECHANCE][2];		//[횟수][카운트]

	printf("숫자야구 게임입니다.\n");
	printf("%d번의 기회안에 컴퓨터의 숫자를 맞추면 승리합니다.\n", OFFENSECHANCE);

	while (1)
	{
		printf("게임을 시작하시려면 아무키나 눌러주세요.\n\n");
		_getch();
		system("cls");

		printf("컴퓨터가 수를 정했습니다.\n\n");
		//컴퓨터가 임의의 수 발생시킨다.	
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

		//게임 시작
		int offenseChanceCount = OFFENSECHANCE;
		for (int k = 0; k<OFFENSECHANCE; k++)
		{
			//아스키값 48~57 = 0~9
			printf("첫째 자리수 입력:");
			offense[0] = _getch();
			offense[0] -= 48;
			printf("%d\n", offense[0]);

			while (1)
			{
				printf("둘째 자리수 입력:");
				offense[1] = _getch();
				offense[1] -= 48;
				if (offense[0] != offense[1])
				{
					printf("%d\n", offense[1]);
					break;
				}
				else
				{
					printf("중복된 숫자입니다. 다시 입력해주세요.\n");
				}
			}

			while (1)
			{
				printf("셋째 자리수 입력:");
				offense[2] = _getch();
				offense[2] -= 48;
				if (offense[0] != offense[1] && offense[0] != offense[2] && offense[1] != offense[2])
				{
					printf("%d\n", offense[2]);
					break;
				}
				else
				{
					printf("중복된 숫자입니다. 다시 입력해주세요.\n");
				}
			}

			while (1)
			{
				printf("넷째 자리수 입력:");
				offense[3] = _getch();
				offense[3] -= 48;
				if (offense[0] != offense[1] && offense[0] != offense[2] && offense[0] != offense[3] && offense[1] != offense[2] && offense[1] != offense[3] && offense[2] != offense[3])
				{
					printf("%d\n", offense[3]);
					break;
				}
				else
				{
					printf("중복된 숫자입니다. 다시 입력해주세요.\n");
				}
			}

			//결과 비교
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

			//히스토리 처리
			for (int i = 0; i<4; i++)
				offenseHistory[OFFENSECHANCE - offenseChanceCount][i] = offense[i];

			countHistory[OFFENSECHANCE - offenseChanceCount][0] = strikeCount;
			countHistory[OFFENSECHANCE - offenseChanceCount][1] = ballCount;

			//기회 감소
			offenseChanceCount--;

			//결과
			if (strikeCount == 4) //게임 승리
			{
				break;
			}
			else
			{
				printf("\n%d스트라이크 %d볼\n", strikeCount, ballCount);
				printf("------------------------\n");
				printf("%d번의 기회가 남았습니다.\n", offenseChanceCount);
				printf("------------------------\n\n");
			}

			printf("------당신의 기록------\n");
			//히스토리 출력
			for (int i = 0; i<(OFFENSECHANCE - offenseChanceCount); i++)
			{
				printf("%d%d%d%d %d스트라이크 %d볼\n", offenseHistory[i][0], offenseHistory[i][1], offenseHistory[i][2], offenseHistory[i][3],
					countHistory[i][0], countHistory[i][1]);
			}
			printf("\n");

			//변수 초기화
			for (int i = 0; i<4; i++)
				offense[i] = -1;

			strikeCount = 0;
			ballCount = 0;
		}

		//게임 끝
		printf("\n컴퓨터의 숫자 %d%d%d%d\n", defense[0], defense[1], defense[2], defense[3]);

		if (strikeCount == 4)
			printf("\n승리하셨습니다.\n\n");
		else
			printf("\n패배하였습니다.\n\n");

		//변수 초기화
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