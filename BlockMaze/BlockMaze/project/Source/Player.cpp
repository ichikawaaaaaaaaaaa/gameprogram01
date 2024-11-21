#include "Player.h"
#include "Stage.h"

const float Gravity = 0.3f;
const float JumpHeight = 40 * 2;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);

Player::Player()
{
	hImage = LoadGraph("data/image/chara.png");
	position.x = 0;
	position.y = 0;
	
}

Player::~Player()
{
}

void Player::Update()
{
	Stage* s = FindGameObject<Stage>();

	if (CheckHitKey(KEY_INPUT_W)) {
		position.y -= 2;
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		position.y += push;
		push = s->IsWallUp(position + VECTOR2(39, 0));
		position.y += push;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		position.y += 2;
		// ���ɕǂ����邩���ׂ�
		int push = s->IsWallDown(position + VECTOR2(0, 39));
		position.y -= push;
		push = s->IsWallDown(position + VECTOR2(39, 39));
		position.y -= push;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 2;
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x += push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		position.x += 2;
		// �E�ɕǂ����邩���ׂ�
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;
	}


	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (prevJumpKey == false) {
			if (onGround) {


				//�W�����v����
				velocity = V0; //���������߂�
			}
		}
		prevJumpKey = true;
	}

	else {
		prevJumpKey = false;
	}

	position.y += velocity; //���W�̂͑��x�𑫂�
	velocity += Gravity; // ���x�ɂ͏d�͂𑫂�
	onGround = false;
	int push = s->IsWallDown(position + VECTOR2(0, 40));

	if (push > 0)
	{
		velocity = 0.0f; //�n�ʂɐG�����瑬�x��0�ɂ���
		position.y -= push-1;
		onGround = true;
	}

	

	
	push = s->IsWallDown(position + VECTOR2(39, 40));
	if (push > 0)
	{
		velocity = 0.0f;
		position.y -= push-1;
		onGround = true;
	}
	
}

void Player::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 40, 40, hImage, TRUE);
}
