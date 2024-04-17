#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"


Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), eModel_(-1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	eModel_ = Model::Load("box.fbx");
	assert(eModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.y = 0.5;
	transform_.position_.z = 50;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.2;

	if (transform_.position_.z <= 0)
		KillMe();
}

void Enemy::Draw()
{
	Model::SetTransform(eModel_, transform_);
	Model::Draw(eModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	
}
