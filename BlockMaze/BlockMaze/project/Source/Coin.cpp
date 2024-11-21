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
		v += 0.6f; //落ちる速さ
		counter -= 1;
		if (counter == 0) {
			DestroyMe();
		}
		return;
	}
	Player* p = FindGameObject<Player>();//相手のインスタンスを取得
	VECTOR2 playerPos = p->position;//相手の座標を取得
	if (CircleHit(playerPos, position, 40)) {//円の当たり判定
		got = true;
		counter = 456;
		v = -100.0f;
	}
}

void Coin::Draw()
{
	DrawRectGraph(position.x, position.y, 120, 0, 40, 40, hImage, TRUE);
}
