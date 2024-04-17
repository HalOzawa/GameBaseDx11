#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), pModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pModel_ = Model::Load("Player.fbx");
	assert(pModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.y = 0;
	transform_.position_.z = 1.5;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.4f);
	AddCollider(collision);
}

void Player::Update()
{
	XMVECTOR move{ 0,0,0,0 };

	if (Input::IsKey(DIK_LEFT))
		transform_.position_.x -= 0.05;
	if (Input::IsKey(DIK_RIGHT))
		transform_.position_.x += 0.05;
	if (transform_.position_.x >= 1.7)
		transform_.position_.x = 1.7;
	if (transform_.position_.x <= -0.7)
		transform_.position_.x = -0.7;

	
}

void Player::Draw()
{
	Model::SetTransform(pModel_, transform_);
	Model::Draw(pModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	KillMe();
}
