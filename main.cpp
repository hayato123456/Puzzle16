//����
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int _i = 3, _j = 3;
int num[4][4];

int result(int y, int x) {//�I������
	int count = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (i == (num[i][j] - 1) / 4 && j == ((num[i][j] - 1) % 4)) //���l��4�Ŋ��������Ɨ]�肪��v���Ă���True
				count++;
		}
	}
	printf("\n�������ʒu�ɂ��鐔:%d", count);
	if (count == 16)
		return 1;
	else
		return 0;
}

void shuffle() {//�����_���Ȑ��l�̐���
	int array[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };//�g��ꂽ�ԍ��v���p
	int i = 16, j = 0, v = 0;
	time_t t = time(NULL);//�����̎擾
	while (i >= 1) {//16��if�ɓ���܂ŌJ��Ԃ�
		int z = (rand() + t) % 16;//�����̐���
		if (array[z] == -1) {
			array[z] = z;//�z��𖄂߂Ă���
			if (i % 4 == 0)
				v++;
			num[j % 4][v - 1] = z + 1;//2�����z��̓K���ȏꏊ�ɓ����
			i--;
			j++;
		}
	}
}

void swap(int y, int x) {//����ւ�//�X���b�v
	int swap;
	swap = num[x][y];
	num[x][y] = num[_i][_j];
	num[_i][_j] = swap;
}

int check(int y, int x) {//�������邩�`�F�b�N
	if (num[x][y - 1] == 16 || num[x][y + 1] == 16 ||//�󂢂Ă��Ԃ���݂ĉ������ꏊ���㉺���E��������TRUE
		num[x + 1][y] == 16 || num[x - 1][y] == 16)
		return 1;
	else
		return 0;
}

int main() {//���C������
	int x = 0;
	int player_x = 0, player_y = 0;
	printf("�L�[�������Ă��������I");
	shuffle();//�����_���ɕ��ёւ�
	while (x != 1) {
		switch (_getch()) {//�L�[����
		case('s'):
			if (player_x < 3)
				player_x++;
			break;
		case('w'):
			if (player_x > 0)
				player_x--;
			break;
		case('d'):
			if (player_y < 3)
				player_y++;
			break;
		case('a'):
			if (player_y > 0)
				player_y--;
			break;
		case('v'):
			x = 1;//�����𔲂���
			break;
		case('k'):
			if (check(player_y, player_x))//�`�F�b�N�t���O����������X���b�v
				swap(player_y, player_x);
			break;
		}
		system("cls");//��ʃ��Z�b�g
		printf("������@\n");
		printf("A:���Ɉړ� D:�E�Ɉړ� W:��Ɉړ� S:���Ɉړ� K:������ V:�Q�[�����I��\n\n");
		printf("--------------\n");
		//*****************�`��****************************
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				if (i == 4) {
					if (j == player_y)
						printf("��");
					else
						printf("�@ ");
				}

				else if (j == 4) {
					if (i == player_x)
						printf("�� ");
					else
						printf(" �@");
				}
				else if (j == player_y && i == player_x) {
					if (num[i][j] / 10 == 0)
						printf("\x1b[31m %d \x1b[m", num[i][j]);//�o�͂̐F��ς���
					else if (num[i][j] == 16)
						printf("\x1b[31m�� \x1b[m");//�o�͂̐F��ς���
					else
						printf("\x1b[31m%d \x1b[m", num[i][j]);//�o�͂̐F��ς���
				}
				else if (num[i][j] == 16) {
					_i = i, _j = j;
					printf("�@ ");
				}
				else {
					if (num[i][j] / 10 == 0)
						printf(" %d ", num[i][j]);
					else
						printf("%d ", num[i][j]);
				}
			}
			printf("\n");
		}
		printf("--------------\n");
		//****************************************************
		if (result(player_x, player_y)) {//�I������
			system("cls");//��ʃ��Z�b�g
			printf("�N���A�I�I");//���U���g���
			x = 1;
		}
	}
}
