#include "Coin.h"
#include "Player.h"
Coin::Coin()
{
	hImage = LoadGraph("data/image/parts.png");
	got = false;
}

Coin::~Coin()
{
}

void Coin::Update()
{
	if (got) {
		position.y += v;
		v += 0.6f; //�����鑬��
		counter -= 1;
		if (counter == 0) {
			DestroyMe();
		}
		return;
	}
	Player* p = FindGameObject<Player>();//����̃C���X�^���X���擾
	VECTOR2 playerPos = p->position;//����̍��W���擾
	if (CircleHit(playerPos, position, 40)) {//�~�̓����蔻��
		got = true;
		counter = 456;
		v = -100.0f;
	}
}

void Coin::Draw()
{
	DrawRectGraph(position.x, position.y, 120, 0, 40, 40, hImage, TRUE);
}
